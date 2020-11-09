import sys


# function area
def sentenceParse (word_list):
	counter = 0;
	for word in word_list:
		if len (word) >= (counter + 1):
			print (word[counter], end='')
			counter += 1

# driver code
test_size = eval (input (""))
tmp = input ("")
for case in range (test_size):
	print ("Case #{:d}:".format (case + 1))
	for line in sys.stdin:
		if line == "\n":
			break
		line = line.strip ()
		word_list = line.split (" ")
		sentenceParse (word_list)
		print ()
	print ("\n")
