import sys

'''
	Print all pairs of numers in an array that sum to a given number
	Author: Angelo Poerio <angelo.poerio@gmail.com>
'''

def print_pairs(arr, x): # better than naive O(n^2) solution
	nums = {}
	for n in arr:
		if n in nums:
			print n, nums[n]
		else:
			nums[x - n] = n

def check_list(lst):
	try:
		arr = eval(lst)
		_ = [int(x) for x in arr]
	except (SyntaxError, TypeError, ValueError):
		print 'not a valid list of numbers!'
		sys.exit(1)
	return arr

if len(sys.argv) < 3:
	print 'Usage: array_of_nums X'
	print 'Example: python sum_2 "[1,3,67,90]" 70'
	sys.exit(1)

arr = check_list(sys.argv[1:][0])

try:
	print_pairs(arr, int(sys.argv[1:][1]))
except ValueError:
	print 'not a valid sum!'
	sys.exit(1)

sys.exit(0)





 
