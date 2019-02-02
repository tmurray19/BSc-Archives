#test.py

#!/usr/bin/python

import sys
import os 
import os.path
import getopt

def usage():
	print("Syntax: fc [OPTIONS] [PATH]")
	print("Options:")
	print("-h/--help: Prints out this help section")
	print("-f/--files: Prints name and number of files in the directory. Also prints total number of files")		
	print("-s/--sizes: prints name and size of files in the directory. Also prints tota file size")
	print("-q/--quiet: Only prints the total number of files (if -f is present) or total size (if -s is present). No per-file/directory info will be printed")	


def main(argv):
	try:
		opts, args = getopt.getopt(argv, "hq:fs", ["help", "files", "sizes", "quiet"])
	except getopt.GetoptError:	
		usage()
		sys.exit(2)

	for opt, arg in opts:	
		if opt in ("-h", "--help"):
			usage()
			sys.exit(2)

		elif opt in("-f", "--files"):
			totfiles=0
			for (dirpath, dirnames, filenames) in os.walk(argv[1]):
				print("Directory Name: {}".format(dirpath))
				print("Files in Directory: {}".format(len(filenames)))
				totfiles+=len(filenames)
			print("Total number of files={}".format(totfiles))

		elif opt in("-s", "--sizes"):
			totsize=0
			for (dirpath, dirnames, filenames) in os.walk(argv[1]):
				print("Directory name: {}".format(dirpath))
				for fname in filenames:
					print("File name: {}		File size: {} bytes".format(fname, os.path.getsize(os.path.join(dirpath, fname))))
					totsize+=os.path.getsize(os.path.join(dirpath, fname))
			print("Total Size={} bytes".format(totsize))

		elif opt in("-q", "--quiet"):
			if argv[1] in("-s","--sizes"):
				totsize=0
				for (dirpath, dirnames, filenames) in os.walk(argv[2]):
					print("Directory name: {}".format(dirpath))
					for fname in filenames:	
						totsize+=os.path.getsize(os.path.join(dirpath, fname))					
					print("Total Size={} bytes".format(totsize))

			elif argv[1] in("-f", "--files"):
				totfiles=0
				for (dirpath, dirnames, filenames) in os.walk(argv[2]):
					print("Directory Name: {}".format(dirpath))
					totfiles+=len(filenames)
				print("Total number of files={}".format(totfiles))

			else:
				usage()
				sys.exit(2)

if __name__=="__main__":
	main(sys.argv[1:])
