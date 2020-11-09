# import
import sys


# function area
def factorSum (n):
	summation = 0
	if n % 2 == 0:
		ranger = n / 2
	else:
		ranger = int (n / 3)
	for i in range (ranger):
		if n % (i + 1) == 0:
			summation += (i + 1)
	return summation




# driver code
for line in sys.stdin:
	n = eval (line)
	if (n == 0) :
		break
	else :
		SUM = factorSum (n)
		if (n == SUM):
			print ("={:d}".format (n))
		elif  (n == factorSum (SUM)):
			print ("{:d}".format (SUM))
		else:
			print ("0")
