import csv, os, re
# from sre_constants import error
from bs4 import BeautifulSoup

def scrapper(file_fullpath):

	with open(file_fullpath, 'r') as fp:
		soup = BeautifulSoup(fp, "lxml")

		error_code = soup.find(class_='pUeberschrift1').get_text()
		list_content = soup.find_all(class_='pStandard')
		list_header= soup.find_all(class_='pUeberschrift3')
		list_param = soup.find_all(class_='pTabelle_Standard')

		# param_count = len(soup.find_all('tr'))

		return list_content, list_header, list_param, error_code

def csvHeaderFiller(max_param_size):

	header = []
	
	header.append('objShortName')
	header.append('objFullName')
	header.append('msg_id')
	header.append('compNR')
	header.append('msgNR')
	header.append('msg_object')
	header.append('Message Class')
	header.append('Reason')
	header.append('Effect')
	header.append('Solution')

	# for i in range(len(list_header)):
	# 	if (list_header[i].get_text() != "Parameter:"):
	# 		header.append(list_header[i].get_text()[0:-1])
	
	for i in range(max_param_size):
		header.append("Parameter_" + str(i + 1))

	header_count = len(header)

	return header, header_count

def getCompNrSplit(dir, compNR_split):

	for (root, dirs, files) in os.walk(dir):
		for filename in files:
			if (filename.endswith(".html") and ("_" not in filename)):
				absolute_filepath = os.path.abspath(os.path.join(dir, filename))
				with open(absolute_filepath, 'r') as fp:
					soup = BeautifulSoup(fp, "lxml")
					msgId = soup.find(class_='pUeberschrift1').get_text()
					split = re.split(' - | \/ ', msgId)
					compNR_split.append(split)

def csvCompNrFiller(row, error_code, compNRList):

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

def csvFiller(list_param, list_content, error_code, writer, header_count, max_param_count, compNrList):

	row = []

	csvCompNrFiller(row, error_code, compNrList) # append row with 3 first column

	msgIdSplit = re.split('_', error_code)
	row.append(msgIdSplit[0])
	row.append(msgIdSplit[1])

	for i in range(len(list_content)): #en plus de la liste de content il y a les colonnes short/fullName
		row.append(list_content[i].get_text())
	
	for i in range(max_param_count):
		if (i < len(list_param) and i % 2 != 0):
			row.append(list_param[i].get_text())

	writer.writerow(row)

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

		compNrList = []
		
		getCompNrSplit(dir, compNrList)

		for (root, dirs, files) in os.walk(dir):
			for filename in files:
				if filename.endswith(".html") and "_" in filename:

					absolute_filepath = os.path.abspath(os.path.join(dir, filename))

					list_content, list_header, list_param, error_code = scrapper(absolute_filepath)

					if (len(list_content) >= 1):
						classValue = list_content[1].get_text().lower()
						classID = re.split(' -', classValue)
						if (
							classID[0] != "5" or 
							classID[0] != "9" or
							classID[0] != "12" or
							(
							classID[0] == "1" or
							classID[0] == "2" or
							classID[0] == "3" or
							classID[0] == "4" or
							classID[0] == "6" or
							classID[0] == "7" or
							classID[0] == "8" or
							classID[0] == "10" or
							classID[0] == "11"
							)
							):
								msgCount += 1
								csvFiller(list_param, list_content, error_code, writer, header_len, max_param_size, compNrList)
		print(f"msg count [{msgCount}]")
	
if __name__ == "__main__":
  	main()
# total-info --> 6168 msg
# total-info-(not warning nor error) --> 6565