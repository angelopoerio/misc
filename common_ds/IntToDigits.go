package main

/* Split an integer into its digits 
   Author: Angelo Poerio <angelo.poerio@gmail.com>

   MacBook-Pro-4:~ an.poerio$ ./IntToString kjkjkjk 546 $RANDOM
  kjkjkjk not a valid integer number
  546 -> [5 4 6] 
  16078 -> [1 6 0 7 8] 

*/

import "fmt"
import "os"
import "strconv"

func reverse(numbers []int) []int {
	for i, j := 0, len(numbers)-1; i < j; i, j = i+1, j-1 {
		numbers[i], numbers[j] = numbers[j], numbers[i]
	}
	return numbers
}


func IntToDigits(number int) []int {
	var digits []int
	for ;number >= 1; {
		digit := number % 10
		digits=append(digits, digit)
		number /= 10
	}
	return reverse(digits)
}

func main() {
	argsCnt := len(os.Args)
	
	if argsCnt < 2 {
		fmt.Printf("Usage: %s num_1 num_2 ... num_n\n",os.Args[0])
		os.Exit(1)
	}

	for i := 1; i < argsCnt;i++ {
		currentNum,err:=strconv.Atoi(os.Args[i])
		if err != nil {
			fmt.Printf("%s not a valid integer number\n", os.Args[i])
		} else if currentNum < 0 {
			fmt.Printf("%d is negative, not accepted\n",currentNum)
		} else {
			digits:=IntToDigits(currentNum)
			fmt.Printf("%d -> %v \n", currentNum, digits)
		}
	}

	os.Exit(0)
}
