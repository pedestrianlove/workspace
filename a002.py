import sys

# data preprocessing
CITIES = [['A', '10'], ['N', '22'], ['B', '11'], ['O', '35'], ['C', '12'], ['P', '23'], ['D', '13'], ['Q', '24'], ['E', '14'], ['R', '25'], ['F', '15'], ['S', '26'], ['G', '16'], ['T', '27'], ['H', '17'], ['U', '28'], ['I', '34'], ['V', '29'], ['J', '18'], ['W', '32'], ['K', '19'], ['X', '30'], ['L', '20'], ['Y', '31'], ['M', '21'], ['Z', '33']]

Reordered = [[], [], [], [], [], [], [], [], [], []]

for city in CITIES:
	value = int (city[1][0]) * 1 + int (city[1][1]) * 9
	Reordered[value%10].append (city[0])

for each in Reordered:
	each.sort ()


# input data
for line in sys.stdin:
	line = line.strip ()
	summation = 0
	for i in range (8):
		summation += int (line[i]) * (8 - i)
	summation = summation % 10

	check_sum = 10 - int (line[-1])

	print ("".join(Reordered[(10 + (check_sum - summation)) % 10]))

