package main;
import "fmt";

/*
	Detect a cycle in a linked list in Golang
	Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

type Node struct {
	value int
	next *Node
}

func checkLoop(list *Node) bool {
	slow := list
	fast := list
	for slow != nil && fast != nil && fast.next != nil {
		slow = slow.next
		fast = fast.next.next
		if slow == fast {
			return true
		}
	}
	return false
}

// utility function to print a list
func printList(list *Node) {
	n := list
	for n != nil {
		fmt.Println(n.value)
		n = n.next
	}
}

func main() {
	list := &Node{value: 10, next:nil}
	head := list
	list_2 := &Node{value: 11, next: nil}
	list.next = list_2
	list_3 := &Node{value: 12, next:nil}
	list_2.next = list_3
	list_3.next = head
	// printList(list) infinite loop :)
	fmt.Println(fmt.Sprintf("Containing a cycle: %t", checkLoop(list)))
        list_3.next = nil
	fmt.Println(fmt.Sprintf("Not containing a cycle: %t", checkLoop(list)))
}
