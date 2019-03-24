// https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
// recursive solution - better complexity with DP (reuse subproblems solutions)
// author: Angelo Poerio

package main

import "fmt"
import "strconv"
import "os"


func initializeMap() map[string]string {
	char_map := make(map[string]string)
	for i := 0; i < 26;i++ {
		char_map[strconv.Itoa(i + 1)] = string(i + 65)
	}
	return char_map 
}

func numWays(digits string, mapping map[string]string) int {
	str_len := len(digits)

	if  str_len == 0 || str_len == 1 {
		return 1
	}
	
	_, ok := mapping[digits]
	total := 0

	if ok {
		total += 1
	}	

	total += numWays(digits[1:str_len], mapping)

	if (str_len > 2) {
		prx := digits[0:2]
		rmn := digits[2:str_len]
		_, ok := mapping[prx]
		if ok {
			total += numWays(rmn, mapping)
		}
	}
	return total	

}

func main() {
	if len(os.Args) < 2 {
		os.Exit(1)
	}

	mapping := initializeMap()
	for args_cnt := 1;args_cnt < len(os.Args);args_cnt++ {
		current_str := os.Args[args_cnt]
		ret := numWays(current_str, mapping)
		fmt.Printf("String: %s, Num Ways: %d\n", current_str, ret)
	}
	os.Exit(0)
}
