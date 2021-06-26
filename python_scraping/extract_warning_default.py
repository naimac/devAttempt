import csv, os, re
from bs4 import BeautifulSoup #lib de webScrapping

# parse le fichier html et recuprere les champs interessants #webScrapping
def scrapper(file_fullpath):

	with open(file_fullpath, 'r') as fp:
		soup = BeautifulSoup(fp, "lxml")

		error_code = soup.find(class_='pUeberschrift1').get_text()
		list_content = soup.find_all(class_='pStandard')
		list_header= soup.find_all(class_='pUeberschrift3')
		list_param = soup.find_all(class_='pTabelle_Standard')

		# to keep for syntax reminder
		# param_count = len(soup.find_all('tr'))

		return list_content, list_header, list_param, error_code

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
	# for i in range(len(list_header)):
	# 	if (list_header[i].get_text() != "Parameter:"):
	# 		header.append(list_header[i].get_text()[0:-1]) #lit la chaine en excluant le dernier caractere
	
	for i in range(max_param_size):
		header.append("Parameter_" + str(i + 1)) # concatene Parameter_ avec la position du parametre (parametre_1, parametre_2 ...)

	header_count = len(header)

	return header, header_count

# cree un tableau a 2 dimension contenant les compNR rencontres et dont les informations (compNR, shortname, longname) sont splittes
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

# rempli les colonnes 1 et 2 du fichier excel avec shortname et longname du composant (compNR) extrait de error_code
# cette methode est execute pour chaque fichier html (appelee par methode csvfiller)
def csvCompNrFiller(row, error_code, compNRList):

	# tricks pour tester que le compNR de l'error_code en cours de lecture correspond a un des compNR deja rencontre
	# permets de remplir les champs "shortname" et "longname" par des valeur vides le cas echeant
	found = 0

	if ("_" in error_code):
		error_code_split = re.split('_', error_code)
		for i in range(len(compNRList)):
			if (error_code_split[0] == compNRList[i][0]):
				row.append(compNRList[i][1]) #shortName
				row.append(compNRList[i][2]) #longName
				found = 1
		if (found == 0):
			row.append("")	
			row.append("")	
		row.append(error_code)

# methode principale de remplissage du fichier csv
def csvFiller(list_param, list_content, error_code, writer, header_count, max_param_count, compNrList):

	row = []

	csvCompNrFiller(row, error_code, compNrList) # append row with 3 first column

	msgIdSplit = re.split('_', error_code)
	row.append(msgIdSplit[0])
	row.append(msgIdSplit[1])
	row.append(list_content[0].get_text())

	msgClassIdSplit = re.split(' -', list_content[1].get_text())
	row.append(msgClassIdSplit[0])
	row.append(msgClassIdSplit[1])

	for i in range(2, len(list_content)): # en plus de la liste de content il y a les colonnes short/fullName
		row.append(list_content[i].get_text())
	
	for i in range(max_param_count):
		if (i < len(list_param) and i % 2 != 0):
			row.append(list_param[i].get_text())

	writer.writerow(row)

# retourne le nombre max de parametres rencontres parmi l ensemble des messages d erreur
def get_max_param_size():
	max_param_size = 0
	for (root, dirs, files) in os.walk("./html"):
		for filename in files:
			if filename.endswith(".html"):
				absolute_filepath = os.path.abspath(os.path.join("./html", filename))

				list_content, list_header, list_param, error_code = scrapper(absolute_filepath)

				current_max_param_size = len(list_param)
				max_param_size = current_max_param_size if (current_max_param_size > max_param_size) else max_param_size
	return max_param_size

# main ...
def main():

	dir = "./html"
	result_filepath = "./script_result/error_warning_extraction.csv"

	if (os.path.exists(result_filepath)):
		os.remove(result_filepath)
	
	with open(result_filepath, "a") as output_file:

		msgCount = 0
		writer = csv.writer(output_file, delimiter=";")

		header, header_len = csvHeaderFiller(get_max_param_size())
		writer.writerow(header)

		max_param_size = get_max_param_size()
	
		# on passe une premiere fois sur tous les fichiers pour en extraire les fichier qui concerne les categories de messages
		# ce sont des fichiers qui n ont pas de "_" dans leur nom
		# on en extrait les informations relatif au composant : numero, shortname, fullname
		compNrList = []
		getCompNrSplit(dir, compNrList)

		# syntax du os.walk meme si root et dirs ne sont pas utilises je les mets dans le for
		for (root, dirs, files) in os.walk(dir):
			for filename in files:
				if filename.endswith(".html") and "_" in filename:

					absolute_filepath = os.path.abspath(os.path.join(dir, filename))

					list_content, list_header, list_param, error_code = scrapper(absolute_filepath)

					if (len(list_content) >= 1):
						classValue = list_content[1].get_text().lower()
						classID = re.split(' -', classValue)
						# on ne traite que les messages qui ne sont pas de type info parmi les classes entre 1 et 12 exlu
						if 1 <= int(classID[0]) and int(classID[0]) < 12 and (classID[0] != 5 or classID[0] != 9 ):
							msgCount += 1
							csvFiller(list_param, list_content, error_code, writer, header_len, max_param_size, compNrList)

		print(f"Total of messages : [{msgCount}]")
	
# syntax pour dire :
# si ce fichier est passe a l interpreteur python et contient une methode "main"
# alors lance le main
if __name__ == "__main__":
  	main()

# RESULTAT
# total avec extraction des msg de type info --> 6168 msg
# total avec warning / default et classe de 1 a 12 --> 6475