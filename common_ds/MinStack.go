/*
	Stack datastructure backed by a LinkedList
	It supports min() in O(1)
	Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

package main

import "fmt"

type Node struct {
	value int
	min int
	next *Node
}

type Stack struct {
	item *Node
}

func (stack *Stack) push(val int) {
	var min_value int
	if stack.item == nil  {
		min_value = val
	} else {
		if stack.item.min > val {
			min_value = val
		} else {
			min_value = stack.item.min
		}
	}
	
	new_node := &Node{value: val, min: min_value}
	new_node.next = stack.item
	stack.item = new_node 
}

func (stack *Stack) pop() (int) {
	if stack.item == nil {
		panic("Empty stack")
	}

	head := stack.item	
	stack.item = head.next
	return head.value	
}

func (stack *Stack) min() (int) {
	if stack.item == nil {
		panic("Empty stack")
	}

	return stack.item.min
}

func main() {
	stack := Stack{}
	stack.push(90)
	stack.push(9)
	stack.push(19)	
	stack.push(8)
	fmt.Printf("Min value: %v\n", stack.min())
	stack.pop()	
	fmt.Printf("Min value after popping: %v\n", stack.min())
	// pop values until it panics with "Empty stack"
	for {
		fmt.Printf("Popped value: %v\n",stack.pop())
	}
}
