import sys

def routing (n, prev):
	# prev 1 implies limited, ow unlimited
	if n == 0:
		return 1

	# vertical
	vertical = routing (n - 1, 2)

	# horizontal
	if prev == 1:
		horizontal = routing (n - 1, prev)
	else:
		horizontal = 2 * routing (n - 1, 1)
	
	
	return vertical + horizontal

for line in sys.stdin:
	n = eval (line)
	print (routing (n, -1))

