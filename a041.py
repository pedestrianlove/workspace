data = []

# database for memoization
min_memory = {}
max_memory = {}

# function
def query_max (start, end):
	global max_memory

	if start == end:
		return data[start]
	elif end == start + 1:
		max_val = max (data[start], data[end])
		max_memory[start, end] = max_val
		return max_val
	elif (start, end) in max_memory:
		return max_memory[start, end]

	# divide
	mid = int ((start + end) / 2)
	prev = query_max (start, mid)
	max_memory[start, mid] = prev
	nex = query_max (mid + 1, end)
	max_memory[mid + 1, end] = nex

	# return
	return max (prev, nex)

def query_min (start, end):
	global min_memory

	if start == end:
		return data[start]
	elif end == start + 1:
		min_val = min (data[start], data[end])
		min_memory[start, end] = min_val
		return min_val
	elif (start, end) in min_memory:
		return min_memory[start, end]

	# divide
	mid = int ((start + end) / 2)
	prev = query_min (start, mid)
	min_memory[start, mid] = prev
	nex = query_min (mid + 1, end)
	min_memory[mid + 1, end] = nex

	# return
	return min (prev, nex)




# input length
input_data = input ("").strip ().split ()
data_length = eval (input_data[0])
query_length = eval (input_data[1])

# input data
for i in range (data_length):
	data.append (eval (input ("")))

# accept query
for j in range (query_length):
	query = input ("").strip ().split ()
	start = int (query[0]) - 1
	end = int (query[1]) - 1
	print (query_max (start, end) - query_min (start, end))
