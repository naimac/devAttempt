import re, csv, os
from bs4 import BeautifulSoup

		# os.walk
		# os.readir

def scrapper(file_fullpath):
	# with open("50_268.html") as fp:
	# print(file_fullpath)
	with open(file_fullpath, 'r') as fp:
		soup = BeautifulSoup(fp, "lxml")

		error_code = soup.title.string
		list_content = soup.find_all(class_='pStandard')
		list_header= soup.find_all(class_='pUeberschrift3')
		list_param = soup.find_all(class_='pTabelle_Standard')

		# param_count = len(soup.find_all('tr'))

		return list_content, list_header, list_param, error_code 

def csvHeaderFiller(max_param_size):

	header = []
	
	header.append('msg_id')
	header.append('msg_object')
	header.append('Message Class')
	header.append('Reason')
	header.append('Effect')
	header.append('Solution')

	# for i in range(len(list_header)):
	# 	if (list_header[i].get_text() != "Parameter:"):
	# 		header.append(list_header[i].get_text()[0:-1])
	
	for i in range(max_param_size):
		header.append("Paramter_" + str(i + 1))

	return header

def csvParamFiller(list_param, header_len):

	row = []

	param_len = len(list_param)

	for i in range(header_len + 1):
		row.append('')

	for i in range(param_len - 1):
		if (i % 2 == 0):
			row.append(list_param[i].get_text() + list_param[i+1].get_text())
	return row

def csvFiller(list_param, list_content, error_code, writer, max_column_size):

	#pas max_column_size mais le nombre de headers
	row = csvParamFiller(list_param, max_column_size)

	j = 0
	row[j] = error_code

	for i in range(len(list_content)):
		j = i + 1
		row[j] = list_content[i].get_text()

	print(row)

	writer.writerow(row)

def get_max_column_size():
	max_column_size = 0
	for (root, dirs, files) in os.walk("./html"):
		for filename in files:
			if filename.endswith(".html"):
				absolute_filepath = os.path.abspath(os.path.join("./html", filename))

				list_content, list_header, list_param, error_code = scrapper(absolute_filepath)

				current_max_column_size = len(list_header) + len(list_param)
				max_column_size = current_max_column_size if (current_max_column_size > max_column_size) else max_column_size
	return max_column_size

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
	
	# max_column_size = get_max_column_size()
	# print(f"max_column [{max_column_size}]")

	with open("msg_scrap.csv", "a") as output_file:
		writer = csv.writer(output_file, delimiter=";")

		writer.writerow(csvHeaderFiller(get_max_param_size()))

		for (root, dirs, files) in os.walk("./html"):
			for filename in files:
				if filename.endswith(".html"):

					absolute_filepath = os.path.abspath(os.path.join("./html", filename))

					list_content, list_header, list_param, error_code = scrapper(absolute_filepath)
					csvFiller(list_param, list_content, error_code, writer, get_max_column_size())
	
if __name__ == "__main__":
  	main()
			# print(os.path.abspath(os.path.join("./html", filename)))
#  csvFiller("./html")
