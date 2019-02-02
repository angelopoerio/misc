import heapq
import sys

# print k-th element in an array

def k_smallest_sort(numbers, k):
	sorted_numbers=sorted(numbers, reverse=False)
	return numbers[k]

def k_smallest_heap(numbers, k):
	heapq.heapify(numbers)
	for i in range(0,k-2):
		heapq.heappop(numbers)
	return heapq.heappop(numbers)

if __name__ == "__main__":
	lst = [67,9,50,15]
	print k_smallest_sort(lst,3)
	print k_smallest_heap(lst,3)
	#for i in range(len(lst)):
	#	print "{}-i elem: {}".format(i, k_smallest(lst, i))
