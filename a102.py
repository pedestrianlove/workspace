class Table:
	hash_list = []
	def __init__ (self, mod):
		self.mod = mod
		for i in range (mod):
			self.hash_list.append ([])

	def insert (self, integer):
		self.hash_list[integer % self.mod].append (integer)
	
	def delete (self, integer):
		if integer in self.hash_list[integer % self.mod]:
			self.hash_list[integer % self.mod].remove (integer)
	
	def print (self):
		print ("===== s =====")
		for i in range (self.mod):
			print ("[{:03d}]:".format (i), end='')
			self.hash_list[i].sort ()
			for elem in self.hash_list[i]:
				print ("{:d} -> ".format (elem), end='')
			print ("NULL")	
		print ("===== e =====")
	
# driver code

## input
input_lists = input ("").strip ().split (" ")
test_cases = int (input_lists[0])
modulo = int (input_lists[1])

## process
HASH_TABLE = Table (modulo)
for i in range (test_cases):
	input_lists = input ("").strip ().split (" ")
	if input_lists[0] == '1':
		HASH_TABLE.insert (int (input_lists[1]))
	elif input_lists[0] == '2':
		HASH_TABLE.delete (int (input_lists[1]))
	elif input_lists[0] == '3':
		HASH_TABLE.print ()

