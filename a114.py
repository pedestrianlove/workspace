class Point:
	def __init__ (self, x, y):
		self.x = x
		self.y = y

def coordArea (A, B):
	return (B.x - A.x) * (B.y - A.y)

def isInGraph (A1, B1, B2):
	if B1.x <= A1.x <= B2.x and B1.y <= A1.y <= B2.y:
		return True
	return False

def parseCoord (A1, A2, B1, B2):
	A_area = coordArea (A1, A2)
	B_area = coordArea (B1, B2)
	
	# find overlapped area
	overlapped = 0
	if isInGraph (A1, B1, B2):
		if isInGraph (A2, B1, B2):
			overlapped = coordArea (A1, A2)
		else:
			overlapped = coordArea (A1, B2)
	elif isInGraph (A2, B1, B2):
		overlapped = coordArea (B1, A2)

	print (overlapped, end=' ')
	print (A_area + B_area - 2 * overlapped, end=' ')
	print (10000 - A_area - B_area + overlapped)



# driver code
test_cases = eval (input (""))

for i in range (test_cases):
	print ("Night {:d}: ".format (i + 1), end='')
	man1 = input ("").strip ().split (" ")
	man2 = input ("").strip ().split (" ")
	man1_1 = Point (int (man1[0]), int (man1[1]))
	man1_2 = Point (int (man1[2]), int (man1[3]))
	man2_1 = Point (int (man2[0]), int (man2[1]))
	man2_2 = Point (int (man2[2]), int (man2[3]))
	parseCoord (man1_1, man1_2, man2_1, man2_2)
