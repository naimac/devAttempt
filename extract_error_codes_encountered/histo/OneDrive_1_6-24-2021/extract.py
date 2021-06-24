import re
regex = re.compile(b"\/\d+_\d+\.html")

with open("messages.chm", 'rb') as file:
	data = file.read()
	result = [_[1:-5] for _ in regex.findall(data)]
with open("messages.csv", "w") as output_file:
	for data in result:
		output_file.write(f"{data.decode()}\n")




