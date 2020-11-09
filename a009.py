# import
import sys

# function area
def guessTest (key, guess):
	B = 0;
	for char in guess:
		if char in key:
			B+= 1
	return B

def preciseTest (key, guess):
	A = 0;
	for i in range (len (guess)):
		if (guess[i] == key[i]):
			A += 1
	return A


# driver code
key = raw_input ()
for line in sys.stdin:
	B = guessTest (key, line)
	A = preciseTest (key, line)
	B = B - A
	print ("{:d}A{:d}B".format (A, B))


