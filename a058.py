import sys

for line in sys.stdin:
	data = line.rstrip ().split ('\n')
	if data == [0, 0]:
		break;
	# INPUT 
	x_arr = input ("").strip ().split ()
	y_arr = input ("").strip ().split ()
	
	# PROCESS
	x_set = set (x_arr)
	y_set = set (y_arr)
	common = len (x_set.intersection (y_set))
	
	# OUTPUT
	print (min (len (x_set), len (y_set)) - common)
