import sys
def house (current, total):
	if total == 1 or total == 0:
		return 1
	methods = 0
	for next_current in range (1, current + 1, 2):
		if total >= next_current:
			methods += house (next_current, total - next_current)
	return methods


# driver code
test_cases = input ("")
for line in sys.stdin:
	num = eval (line)
	print (house (num, num))
