package main

import "fmt"

// Resursive edit Distance - Improve with dynamic programming
// Author: Angelo Poerio <angelo.poerio@gmail.com>

func binaryMin(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func ternaryMin(a int, b int, c int) int {
	return binaryMin(binaryMin(a, b), c)
}

func editDistance(s1 string, s2 string, l1 int, l2 int) int {
	if l1 == 0 {
		return l2
	}

	if l2 == 0 {
		return l1
	}

	if s1[l1-1] == s2[l2-1] {
		return editDistance(s1, s2, l1-1, l2-1)
	}

	return 1 + ternaryMin(editDistance(s1, s2, l1-1, l2),
		editDistance(s1, s2, l1, l2-1),
		editDistance(s1, s2, l1-1, l2-1))
}

func main() {
	fmt.Println(editDistance("aaa", "bbb", 3, 3))         // print 3
	fmt.Println(editDistance("ship", "sheep", 4, 5))      // print 2
	fmt.Println(editDistance("sunday", "saturday", 6, 8)) // print 3
}
