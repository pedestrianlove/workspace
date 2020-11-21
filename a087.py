def output (arr):
	if arr == ['1', '2', '4']:
		return
	print ("{", end='')
	print (",".join (arr), end='')
	print ("}")

def dictionary (arr, current, target):
	output (arr)
	for i in range (current + 1, target + 1):
		arr.append (str (i))
		dictionary (arr, i, target)
		del arr[len (arr) - 1]


# driver code
num = eval (input (""))
dictionary ([], 0, num)
