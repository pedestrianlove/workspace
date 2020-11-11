# function area
def isPossible (position, stride, goal):
	if (stride*(stride+1) / 2) <= (goal - position):
		return True
	return False

def WALK (start, end):
	steps = 0
	stride = 1
	position = start
	while stride >= 1 and position < end:
		if isPossible (position + stride, stride + 1, end):
			position += stride
			stride += 1
			steps += 1
		elif isPossible (position + stride, stride, end):
			position += stride
			stride = stride
			steps += 1
		else:
			position += stride
			stride -= 1
			steps += 1	
	return steps

# driver code
test_case = eval (input (""))
for i in range (test_case):
	tmp = input ("")
	query = input ("").strip ().split (" ")
	print (WALK (int (query[0]), int (query[1])))
