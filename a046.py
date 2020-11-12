class sudoku:
	row = []
	column = []
	block = []
	def __init__ (self):
		for i in range (9):
			self.row.append ([])
			self.column.append ([])
			self.block.append ([])
	def insert_data (self, row, num_string):
		for i in range (len (num_string)):
			elem = int (num_string[i])
			self.row[row].append (elem)
			self.column[i].append (elem)
			self.block[int (row / 3) * 3 + int (i/3)].append (elem)
	def check_row (self):
		flag = True
		for row in range (9):
			seen = []
			for i in range (9):
				if self.row[row][i] != 0 and self.row[row][i] in seen:
					print ("row{:d} #{:d}".format (row+1, self.row[row][i]))
					flag = False
					break
				else:
					seen.append (self.row[row][i])	
		return flag
	def check_column (self):
		flag = True
		for col in range (9):
			seen = []
			for i in range (9):
				if self.column[col][i] != 0 and self.column[col][i] in seen:
					print ("column{:d} #{:d}".format (col+1, self.column[col][i]))
					flag = False
					break
				else:
					seen.append (self.column[col][i])
		return flag
	def check_block (self):
		flag = True
		for bloc in range (9):
			seen = []
			for i in range (9):
				if self.block[bloc][i] != 0 and self.block[bloc][i] in seen:
					print ("block{:d} #{:d}".format (bloc+1, self.block[bloc][i]))
					flag = False
					break
				else:
					seen.append (self.block[bloc][i])	
		return flag

			
# driver code
## init instance
SUDOKU = sudoku ()

## input
for i in range (9):
	line = input ("").strip ()
	SUDOKU.insert_data (i, line)

## process && output
flag1 = SUDOKU.check_row ()
flag2 = SUDOKU.check_column ()
flag3 = SUDOKU.check_block ()
if flag1 and flag2 and flag3:	
	print ("true")

