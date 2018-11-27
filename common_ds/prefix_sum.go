package main

// https://en.wikipedia.org/wiki/Prefix_sum

import "fmt"

func prefixSum(values []int) []int {
	var results []int;
	sum_so_far := 0
	for i := 0; i < len(values);i++ {
		sum_so_far += values[i]
		results=append(results,sum_so_far)
	}
	return results
}

func main() {
	or := []int{1,10,20,10}
	rs := prefixSum(or)
	fmt.Printf("%v\n", or)
	fmt.Printf("%v\n", rs)
}
