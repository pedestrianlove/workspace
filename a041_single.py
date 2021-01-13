data = []

# database for memoization
min_memory = {}
max_memory = {}

# function
def query (start, end):
	global max_memory
	global min_memory

	if start == end:
		return (0, data[start], data[start])
	elif (start, end) in max_memory:
		max_mem = max_memory[start, end]
		min_mem = min_memory[start, end]
		return (max_memory[start, end] - min_memory[start, end], max_mem, min_mem)
	elif end == start + 1:
		max_val = max (data[start], data[end])
		max_memory[start, end] = max_val
		min_val = min (data[start], data[end])
		min_memory[start, end] = min_val
		return (max_val - min_val, max_val, min_val)

	# divide
	mid = int ((start + end) / 2)
	prev, prev_max, prev_min = query (start, mid)
	nex, nex_max, nex_min = query (mid + 1, end)
	max_memory[start, mid] = prev_max
	max_memory[mid + 1, end] = nex_max
	min_memory[start, mid] = prev_min
	min_memory[mid + 1, end] = nex_min
	
	MAX = max (prev_max, nex_max)
	MIN = min (prev_min, nex_min)
	#max_memory[start, end] = MAX
	#min_memory[start, end] = MIN

	# return
	return (MAX - MIN, MAX, MIN)


# input length
input_data = input ("").strip ().split ()
data_length = eval (input_data[0])
query_length = eval (input_data[1])

# input data
for i in range (data_length):
	data.append (eval (input ("")))

# accept query
for j in range (query_length):
	queries = input ("").strip ().split ()
	start = int (queries[0]) - 1
	end = int (queries[1]) - 1
	print (query(start, end)[0])
