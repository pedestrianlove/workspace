import itertools


def parse (num_arr):
	if num_arr[0] == '0':
		return eval (''.join (num_arr[1:]))
	else:
		return eval (''.join (num_arr))


def output (target):
	num_list = [char for char in '0123456789']
	all_num_list = list (itertools.permutations (num_list))
	counter = 0
	for num in all_num_list:
		if (num[0] < num[5]):
			continue
		num1 = parse (num[:5])
		num2 = parse (num[5:])
		if (num2 * target == num1):
			print (''.join (num[:5]) + ' / ', end='')
			print (''.join (num[5:]) + ' = ', end='')
			print (target)
			counter += 1
	if counter == 0:
		print ("No solution for N.")
	
	


# driver code
output (27)

