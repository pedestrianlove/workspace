# input
size = eval (input (""))
num_list = input ("").strip ().split (" ")

# sort
num_list.sort (key = lambda x:eval (x))

# distribute
num_tmp = [[], []]

## fix nonzero start problem
if ('0' in num_list):
	idx = num_list.rfind ('0')
	num_tmp[0].append (num_list[idx+1])
	num_tmp[1].append (num_list[idx+2])
	del num_list[idx+1]
	del num_list[idx+1]

## evenly distribute
for i in range (len (num_list)):
	num_tmp[i % 2].append (num_list[i])

## compute
num1 = eval (''.join (num_tmp[0]))
num2 = eval (''.join (num_tmp[1]))

## output
print (num1 + num2)


