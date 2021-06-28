import csv, re, os
import more_itertools as mit
from typing import Iterable

dir = "./html_sample"

with open('documentation/filter_sample.csv', newline='') as csvfile:
	irrelevant = csv.DictReader(csvfile)
	it = mit.seekable(irrelevant)
	isRelevant = 1

	for (root, dirs, files) in os.walk(dir): # parcours dossiers
		for filename in files: # parcours fichiers
			if filename.endswith(".html") and "_" in filename: # compNr_msgNr
				filename_split = re.split('_', filename) # on recupere le compNr

				it.seek(0)
				isRelevant = 1
				for row in it:
					if filename_split[0] == row['compNr']:
						if not row['msgNr']:
							isRelevant = 0
						elif filename_split[1] != row['msgNr']: 
							isRelevant = 1
						
				if isRelevant == 1:
					print(filename)
				# if (isRelevant):
				# 	print(f"{filename}")
