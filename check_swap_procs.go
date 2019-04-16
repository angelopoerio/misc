package main

// Get The most swapping out process of the system
// Re-written in Golang to be faster

import (
	"fmt"
	"github.com/mitchellh/go-ps"
	"io/ioutil"
	"regexp"
	"strconv"
)

func getSwap(pid int) []string {
	b, err := ioutil.ReadFile(fmt.Sprintf("/proc/%d/status", pid))
	if err != nil {
		panic(err)
	}
	re := regexp.MustCompile("VmSwap:\\s+(?P<swap>\\d+)")
	match := re.FindStringSubmatch(string(b))
	return match
}

func main() {
	p, err := ps.Processes()
	biggest_so_far := -1
	biggest_pid := -1

	if err != nil {
		panic("Could not get processes list!")
	}

	for _, p1 := range p {
		pid := p1.Pid()
		swp := getSwap(pid)
		if len(swp) > 1 {
			current_swp, _ := strconv.Atoi(swp[1])
			if current_swp > biggest_so_far {
				biggest_so_far = current_swp
				biggest_pid = pid
			}
		}
	}
	if biggest_so_far != 0 {
		fmt.Printf("PID: %d - SWAP USED: %dKb\n", biggest_pid, biggest_so_far)
	} else {
		fmt.Printf("NO SWAPPING PROCESSES\n")
	}
}