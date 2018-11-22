package main

import "fmt"

// remove duplicates from an array -> original order not kept! (need a linkedhashmap a la java)
func removeDuplicates(values []int) []int {
	duplicates := make(map[int]bool)
	var finalValues []int

	for i := 0;i < len(values);i++ {
		currValue := values[i]
		if _, contained := duplicates[currValue]; !contained {
			duplicates[currValue] = true
			finalValues = append(finalValues, currValue)
		}
	}

	return finalValues
}

func main() {
	out := removeDuplicates([]int{1,3,3,7})
	fmt.Printf("%v\n", out)
}

