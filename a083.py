import itertools

def parse (num_arr):
	return num_arr[0] * 10000 + num_arr[1] * 1000 + num_arr[2] * 100 + num_arr[3] * 10 + num_arr[4] * 1

def output (target):
	num_list = [eval (char) for char in '0123456789']
	all_num_list = list (itertools.permutations (num_list))
	counter = 0
	for num in all_num_list:
		if (num[0] < num[5]) or (num[4] != (num[9] * target % 10)):
			continue
		num1 = parse (num[:5])
		num2 = parse (num[5:])
		if (num2 * target == num1):
			print ('{:05d}'.format (num1) + ' / ', end='')
			print ('{:05d}'.format (num2) + ' = ', end='')
			print (target)
			counter += 1
	if counter == 0:
		print ("No solution for N.")
	
	


# driver code
output (27)

