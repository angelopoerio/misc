package main

import "fmt"

func isSorted(array []int, asc bool) bool {
	for i := 0; i < len(array)-1; i++ {
		if asc {
			if array[i] > array[i+1] {
				return false
			}
		} else {
			if array[i] < array[i+1] {
				return false
			}
		}
	}
	return true
}

func main() {
	arr := []int{1, 4, 5}
	is_asc_sorted := isSorted(arr, true)
	is_desc_sorted := isSorted(arr, false)
	fmt.Printf("Array: %v, Asc sorted: %t, Disc sorted: %t\n", arr, is_asc_sorted, is_desc_sorted)
}
