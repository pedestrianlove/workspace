# function area
def fact (n):
	summation = 1
	while (n >= 1):
		summation *= n
		n -= 1
	return summation

def singleSol (houses, friends):
	if (houses + friends) % 2 != 0:
		return 0
	elif friends == 1:
		if houses % 2 == 0:
			return 0
		else:
			return 1
	else:
		divisor = fact (friends - 1)
		dividend = ( houses + friends ) / 2
		summation = 1
		for i in range (friends -1):
			summation *= dividend - (i + 1)
		print ("Houses:", houses, "friends: ", friends, summation, divisor)
		return summation / divisor

def computeSol (houses):
	summation = 0
	for i in range (houses):
		summation += singleSol (houses, i+1)
	return summation


# driver code
test_data = eval (input (""))
for i in range (test_data):
	print (computeSol (eval (input ("").strip ())) )
