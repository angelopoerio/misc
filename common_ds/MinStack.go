/*
	Stack datastructure backed by a LinkedList
	It supports min() in O(1)
	Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

package main

import "fmt"

type Node struct {
	value int
	next *Node
}

type Stack struct {
	minValue int
	item *Node
}

func (stack *Stack) push(val int) {
	new_node := &Node{value: val}

	if stack.item == nil {
		stack.minValue = val
	}

	if stack.item != nil && val < stack.minValue {
		stack.minValue = val
	}

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

	return stack.minValue
}

func main() {
	fmt.Println("test");
	stack := Stack{}
	stack.push(90)
	stack.push(8)
	stack.push(9)
	stack.push(19)
	fmt.Printf("Min value: %v\n", stack.min())
	// pop values until it panics with "Empty stack"
	for {
		fmt.Printf("Popped value: %v\n",stack.pop())
	}
}
