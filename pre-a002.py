import sys

cities = []

for line in sys.stdin:
	index = line.strip().find (" ")
	city = line[index+1:].strip ().split (" ")
	cities.append (city)

print (cities)
