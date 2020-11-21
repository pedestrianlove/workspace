class Book:
	def __init__ (self):
		line = input ("").strip ().split (" ")
		self.printing = eval (line[0])
		self.binding = eval (line[1])
	def total_time (self):
		return self.printing + self.binding
		
# driver code

## Variables
book_list = []

## Input
book_number = eval (input (""))
for i in range (book_number):
	book_list.append (Book ())

## Process
book_list.sort (key = lambda elem: (elem.binding*(-1), elem.printing))

current_time = 0
max_timestamp = 0
tmp_binding = 0
for book in book_list:
#print ("Current time:", current_time, "max_time:", max_timestamp)
	test_max = current_time + book.total_time ()
	if max_timestamp < test_max :
			max_timestamp = test_max
	current_time += book.printing

## Output
print (max_timestamp)

