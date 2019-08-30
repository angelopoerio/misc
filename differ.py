'''`
	Quick and dirty script to check if two files are equal or not.
	Try to be smart enough (compare hash of the chunks of the files instead of the hash of the full file)
	Author : Angelo Poerio <angelo.poerio@gmail.com>
	Note: Ugly code! 
'''

import os
import sys
import hashlib

def differ(file_name1, file_name2, block_size=512): # block size default is 512 bytes
	# block_size > 0 always!
	
	if os.stat(file_name1).st_size != os.stat(file_name2).st_size:
		print "Files do not have the same size"
		return 1

	file_size = os.stat(file_name1).st_size # this would require better error handling (example: file does not exist)
	chunk_nums = file_size / block_size
	remaining_bytes = file_size % block_size
	
	with open(file_name1) as fn1:
		with open(file_name2) as fn2:
			for i in range(chunk_nums):
				current_chunk1 = fn1.read(block_size)
				current_chunk2 = fn2.read(block_size)
				if hashlib.sha1(current_chunk1).hexdigest() != hashlib.sha1(current_chunk2).hexdigest():
					print "Files are different at the block at the offset: {0}".format(fn1.tell() - block_size)
					return 1
			if remaining_bytes > 0:
				remaining_size = file_size - fn1.tell()
				remaining_chunk1 = fn1.read(remaining_size)
				remaining_chunk2 = fn2.read(remaining_size)
				if hashlib.sha1(remaining_chunk1).hexdigest() != hashlib.sha1(remaining_chunk2).hexdigest():
					print "Files are different at the block at the offset: {0}".format(fn1.tell() - block_size)
					return 1
	
	print "Files are equal"
	return 0
	

if __name__ == "__main__":
	if len(sys.argv)  < 3:
		print "specify a file1, file2 and a block size!"
		sys.exit(1)
	if int(sys.argv[3]) < 0:
		print "block size must be greater than 0 !"
		sys.exit(1)
	sys.exit(differ(sys.argv[1], sys.argv[2], int(sys.argv[3])))
