class Idoneal:
	number = []
	def isIdoneal (self, num):
#print ("Testing idoneal at {:d}...".format (num))
		for I in range (1, num - 1):
			for J in range (1, I):
				if I*J >= num:
					continue
				for K in range (1, J):
					if num == I*J + J*K + K*I:
						print (I,J,K,"=",num)
						return False
		self.number.append (num)
		return True
	def __init__ (self, num):
		index = 1
		counter = 0
		while counter < num:
			if self.isIdoneal (index):
				counter += 1
			index += 1





# driver code

## input
num = eval (input (""))

## init instance
idoneal = Idoneal (num)
print (idoneal.number [num - 1])
