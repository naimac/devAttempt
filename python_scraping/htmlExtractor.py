#!/usr/bin/python3
import csv, os, re, sys
import more_itertools as mit # permet de reset un iterator
from bs4 import BeautifulSoup #lib de webScraping

# parse le fichier html et recuprere les champs interessants #webScraping
def scraper(file_fullpath):
	with open(file_fullpath, 'r') as fp:
		soup = BeautifulSoup(fp, "lxml")

		msgId = soup.find(class_='pUeberschrift1').get_text() # de la forme compNr_msgNr
		html_field_value_list = soup.find_all(class_='pStandard')
		html_field_title_list = soup.find_all(class_='pUeberschrift3')
		param_list = soup.find_all(class_='pTabelle_Standard')

		# to keep for syntax reminder
		# param_count = len(soup.find_all('tr'))

		return html_field_value_list, html_field_title_list, param_list, msgId

# rempli la premiere ligne du fichier excel
def csvHeaderFiller(max_param_size):

	# initialisation d une liste vide
	header = []
	
	header.append('objShortName')
	header.append('objFullName')
	header.append('msg_id')
	header.append('compNR')
	header.append('msgNR')
	header.append('msg_object')
	header.append('Message ClassID')
	header.append('Message ClassName')
	header.append('Reason')
	header.append('Effect')
	header.append('Solution')

	# to keep for syntax reminder
	# for i in range(len(html_field_title_list)):
	# 	if (html_field_title_list[i].get_text() != "Parameter:"):
	# 		header.append(html_field_title_list[i].get_text()[0:-1]) #lit la chaine en excluant le dernier caractere
	
	for i in range(max_param_size):
		header.append("Parameter_" + str(i + 1)) # concatene Parameter_ avec la position du parametre (parametre_1, parametre_2 ...)

	header_count = len(header)

	return header, header_count

# cree un tableau a 2 dimension contenant les compNR rencontres et dont les informations (compNR, shortname, longname) sont splittes
# rempli la liste de compNr existant parmi tous les messages keba possibles
def getCompNrSplit(dir, compNR_split):

	# syntax pour parcourir les fichiers / dossiers d'un dossier (dir)
	# meme si root et dirs ne sont pas utilises je les laisse
	for (root, dirs, files) in os.walk(dir):
		for filename in files:
			# on recupere les fichier qui ne represente que les categories (composant) de message (exemple : 50.html)
			if (filename.endswith(".html") and ("_" not in filename)): 
				absolute_filepath = os.path.abspath(os.path.join(dir, filename))
				with open(absolute_filepath, 'r') as fp:
					# il existe 3 parser possibles : lxml, html.parser, html5lib
					soup = BeautifulSoup(fp, "lxml")
					msgId = soup.find(class_='pUeberschrift1').get_text()

					# on split le champ des informations relatif au composant : numero, shortname, fullname
					# le champ est de la forme "id - shortname / longname" (exemple : "50 - Rc / RobotControl")
					# on split la valeur du msgId selon " - " et " / "
					split = re.split(' - | \/ ', msgId)

					# on append le resultat du split (liste) dans une liste
					# compNR_split est un "tableau" a 2 dimensions
					compNR_split.append(split)

# separe les infos compNr / msgNr du code erreur keba (compNr_msgNr)
# associe les infos de composant pour chaque message : colonnes 1 et 2 du fichier excel avec shortname et longname
# insertion dans le fichier resultat si le code erreur ne fait pas partie de la liste "irrelevant"
# cette methode est execute pour chaque fichier html (appelee par methode csvfiller)
def csvCompNrFiller(row, msgId, compNRList):

	# tricks pour tester que le compNR de l'msgId en cours de lecture correspond a un des compNR deja rencontre
	# permets de remplir les champs "shortname" et "longname" par des valeur vides le cas echeant
	found = 0

	if ("_" in msgId):
		msgId_split = re.split('_', msgId)

		# attribution des valeur "shortname" et "longname" relatifs au code erreur en cours
		for i in range(len(compNRList)):
			if (msgId_split[0] == compNRList[i][0]):
				row.append(compNRList[i][1]) #shortName
				row.append(compNRList[i][2]) #longName
				found = 1
		if (found == 0):
			row.append("")
			row.append("")
		row.append(msgId)
	
# methode principale de remplissage du fichier csv
def csvFiller(param_list, html_field_value_list, msgId, writer, header_count, max_param_count, compNrList):

	row = []

	csvCompNrFiller(row, msgId, compNrList) # append row with 3 first column

	msgIdSplit = re.split('_', msgId)
	row.append(msgIdSplit[0])
	row.append(msgIdSplit[1])
	row.append(html_field_value_list[0].get_text())

	msgClassIdSplit = re.split(' -', html_field_value_list[1].get_text())
	row.append(msgClassIdSplit[0])
	row.append(msgClassIdSplit[1])

	for i in range(2, len(html_field_value_list)): # en plus de la liste de content il y a les colonnes short/fullName
		row.append(html_field_value_list[i].get_text())
	
	for i in range(max_param_count):
		if (i < len(param_list) and i % 2 != 0):
			row.append(param_list[i].get_text())

	writer.writerow(row)

# retourne le nombre max de parametres rencontres parmi l ensemble des messages d erreur
# va servir a remplir les entetes, les entetes pour les parametres portent le nom parameter_ suivi de la position du parametre
# donc on a besoin de savoir a l'avance le nombre maximum de parametres pour savoir comment suffixer les champs parametres 
# parameter_1;parameter_2;...;parameter_max
def get_max_param_size():
	max_param_size = 0
	for (root, dirs, files) in os.walk("./html"):
		for filename in files:
			if filename.endswith(".html"):
				absolute_filepath = os.path.abspath(os.path.join("./html", filename))

				html_field_value_list, html_field_title_list, param_list, msgId = scraper(absolute_filepath)

				current_max_param_size = len(param_list)
				max_param_size = current_max_param_size if (current_max_param_size > max_param_size) else max_param_size
	return max_param_size

# main ...
def main():

	dir = "./html"
	result_filepath = "./script_result/extraction.csv"

	if (os.path.exists(result_filepath)):
		os.remove(result_filepath)
	
	# "a" --> append
	with open(result_filepath, "a") as output_file:

		msgCount = 0
		writer = csv.writer(output_file, delimiter=";") # on precise le format csv qu'on veut en sortie (par defaut delimiter = ',')

		header, header_len = csvHeaderFiller(get_max_param_size())
		writer.writerow(header)

		max_param_size = get_max_param_size()
	
		# on passe une premiere fois sur tous les fichiers pour en extraire les fichier qui concerne les categories de messages
		# ce sont des fichiers qui n ont pas de "_" dans leur nom
		# on en extrait les informations relatif au composant : numero, shortname, fullname
		compNrList = []
		getCompNrSplit(dir, compNrList)

		# on parcours le fichier contenant les message d erreur a ignorer : [compNr],[msgNr]
		# si le champs msgNr est vide on ignore tous les messages en fonction de leur compNr
		# sinon on regarde le msgNr et on ignore que les messages specifiques
		with open('documentation/filter.csv', newline='') as csvfile:
			irrelevant_reader = csv.DictReader(csvfile)
			it = mit.seekable(irrelevant_reader)
			isRelevant = 1

			# syntax du os.walk meme si root et dirs ne sont pas utilises je les mets dans le for
			# oui il y a des for et des ifs imbriques ET ALORS ?!

			# on parcours tous les fichiers .html
			# la syntaxe prends un root, dirs, files, meme si root et dirs ne sont pas utilises on les renseigne
			for (root, dirs, files) in os.walk(dir):
				for filename in files:
					if filename.endswith(".html") and "_" in filename:
						# chaque fichier html dont le nom est de type numero_numero correspond a la description d une erreur
						# le nom du fichier html "numero_numero" correspond au "code erreur" (msgId) correspondant
						# le premier champ (filename_split[0]) "numero" correspond au numero de composant (compNr)
						# le deuxieme champ "numero" correspond (filename_split[1]) au numero de msg d'erreur (msgNr)
						filename_split = re.split('_', filename)

						# ************************************* [ PHASE CRITIQUE : FILTRE ] ********************************************
						# Cette partie conditionne les messages keba qu on va considerer afin de les faire traduire
						# on verifie que le fichier html en cours de lecture n est pas a ignorer
						# certains messages sont systematiquement a ignorer si ils ont un certain compNr
						# certains messages sont a ignorer seulement si leur code erreur (compNr, msgNr) a une valeur precise
						# le critere de filtre est contenu dans le fichier filter.csv
						# on va au debut du fichier (reset de l iterateur)
						it.seek(0)
						isRelevant = 1

						# on test chaque ligne du fichier filter.csv
						for filter_row in it:
							# le champ compNr du fichier html a le meme compNr qu'une ligne du fichier filter.csv
							# il pourrait etre a ignorer
							if filename_split[0] == filter_row['compNr']:

								# pour ce compNr il n y a pas de champ msgNr existant
								# on le supprime qq soit son msgNr
								if not filter_row['msgNr']:
									isRelevant = 0
								# pour ce compNr il y a un champ msgNr on le test
								elif filename_split[1] != filter_row['msgNr']:
									isRelevant = 1

						if isRelevant == 1:
							absolute_filepath = os.path.abspath(os.path.join(dir, filename))
							html_field_value_list, html_field_title_list, param_list, msgId = scraper(absolute_filepath)
							if (len(html_field_value_list) >= 1):
								classValue = html_field_value_list[1].get_text().lower()
								classID = re.split(' -', classValue)
								# on ne traite que les messages qui ne sont pas de type info parmi les classes entre 1 et 12 exclu
								# se referer a la documentation jira chapitre : NEW SEPRO CLASS ID RULES 
								# http://vmjira/confluence/pages/viewpage.action?pageId=39684092#id-5-ReporterMessage-NEWSEPROCLASSIDSETTINGRULES
								if 1 <= int(classID[0]) and int(classID[0]) < 12 and (classID[0] != 5 or classID[0] != 9 ):
									msgCount += 1 
									csvFiller(param_list, html_field_value_list, msgId, writer, header_len, max_param_size, compNrList)

						# **************************************************************************************************************

	if sys.version_info[0] == 3 :
		if sys.version_info[1] == 5 :
			print("Total of messages : [%d]" % (msgCount))
		elif sys.version_info[1] == 7 :
			print(f"Total of messages : [{msgCount}]") # python3.7

# syntax pour dire :
# si ce fichier est passe a l interpreteur python et contient une methode "main"
# alors lance le main
if __name__ == "__main__":
  	main()

# RESULTAT
# total avec filtre sur msg de type info --> 6168 msg
# total avec filtre sur warning / default et classe de 1 a 12 --> 6475
# total avec filtre sur msg declares useless par lukas --> 2413