import re
import csv
from bs4 import BeautifulSoup

		# os.walk
		# os.readir

with open("50_111.html") as fp:
	soup = BeautifulSoup(fp, "lxml")
	print(soup.title.string)
	
	list_pStandard = soup.find_all(class_='pStandard')
	pStd_len = len(list_pStandard)

	list_pUeberschrift3= soup.find_all(class_='pUeberschrift3')
	p3_len = len(list_pUeberschrift3)

	list_pTabelle = soup.find_all(class_='pTabelle_Standard')
	pTabelle_len = len(list_pTabelle)

with open("msg_scrap.csv", "w") as output_file:

	output_file.write(soup.find_all(class_='pCreationDate')[0].get_text() + '\n')
	output_file.write(soup.title.string + ';')

	for i in range(pStd_len):

		if (list_pUeberschrift3[i].get_text() != "Parameter:"):
			# print(list_pUeberschrift3[i].get_text())
			output_file.write(list_pUeberschrift3[i].get_text() + '\n')
		else:
			# print(list_pUeberschrift3[i].get_text())
			output_file.write(list_pUeberschrift3[i].get_text() + '\n')

			for param in list_pTabelle:
				# print(param.get_text())
				output_file.write(param.get_text() + ';')
		# print(list_pStandard[i].get_text())
		output_file.write(list_pStandard[i].get_text() + ';')

	# print(soup.find_all(class_='pStandard')[0].get_text())
	
"""
with open("messages.csv", "w") as output_file:
	for data in result:
		output_file.write(f"{data.decode()}\n"
"""
