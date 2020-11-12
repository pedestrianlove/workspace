def looping (iterator):
	duplicate = iterator
	for i in range (len (iterator)):
		duplicate[i] = abs (iterator[i] - iterator[(i+1)%len (iterator)])
	return duplicate

test_cases = eval (input (""))
for i in range (test_cases):
	num = eval (input (""))
	line = input ("").strip ()
	if num == 4 or num == 8:
		print ("ZERO")
	else:
		ZERO = " ".join(['0' for i in range (num)])
		if (line == ZERO):
			print ("ZERO")
		else:
			iterator = [int (x) for x in line.split (" ")]
			seen = []
			seen.append (iterator)
			looping (iterator)
			FLAG = False
			while not ((iterator in seen) or iterator == ZERO):
				seen.append (iterator)
				looping (iterator)
			
			if iterator in seen:
				print ("LOOP")
			else:
				print ("ZERO")
