import re
from typing import Text

import requests
from bs4 import BeautifulSoup

regex_code_error = re.compile(b"[0-9]+_[0-9]+")
regex_title = re.compile(b"([A-Z]+[a-z]+):")

# with open("50_111.html", 'rb') as file:
# 	data = file.read()
# 	result_1 = regex_code_error.findall(data)
# 	result_2 = regex_title.findall(data)
# 	for data in result:
# 		print(data)

		# os.walk
		# os.readir

with open("50_111.html") as fp:
	soup = BeautifulSoup(fp, "lxml")
	print(soup.title.string)
	list_pStandard = soup.find_all(class_='pStandard')
	pStd_len = len(list_pStandard)
	list_pUeberschrift3= soup.find_all(class_='pUeberschrift3')
	p3_len = len(list_pUeberschrift3)

	for i in range(pStd_len):
		if (list_pUeberschrift3[i].get_text() != "Parameter:"):
			print(list_pUeberschrift3[i].get_text())
		else:
			print(list_pUeberschrift3[i].get_text())
			list_pTabelle = soup.find_all(class_='pTabelle_Standard')
			for param in list_pTabelle:
				print(param.get_text())
		print(list_pStandard[i].get_text())

	# print(soup.find_all(class_='pStandard')[0].get_text())
	
"""
with open("messages.csv", "w") as output_file:
	for data in result:
		output_file.write(f"{data.decode()}\n"
"""
