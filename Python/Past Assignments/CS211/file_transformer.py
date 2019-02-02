#file_transformer.py

"""
given file that contains names of files, two names per line.
You need to write a program that writes the content of the first fiel to the second file, with the following stipulations:

	-All Characters, except for letters/spaces removed
	-All letters converted to lower case (.lower())

Program should execute as follows:

	Asks user for name of files
	Opens file 1 for read, reads line by line
	Open file 2 for write, adds info to file
	Closes files when finished 
"""
def main():
	fileoriginal=input("Please enter file name: ")
	try:
		f = open(fileoriginal, 'r')	
	except IOError:
		print("File does not exist")
		exit()
	for lines in f.read().splitlines():
		l=lines.split(' ')
		try:
			foo = open(l[0], 'r')
			bar = open(l[1], 'w+')
		except PermissionError:
			print("Sorry, you do not have the correct permissions for the file.")
			exit()
		except FileNotFoundError:
			print("Sorry, the file '{}' does not exist, so it cannot be read from.".format(l[0]))
			exit()
		for line in foo.read():
			if line.isalpha() or line==' ' or line=='\n':   
				bar.write(line.lower())
			else:
				continue
		foo.close()
		bar.close()
		print("The contents of the file '{}' has now been copied into the file '{}'.".format(l[0],l[1]))
	f.close()
main()
