package main
import "fmt"

/*
	Priotity Queue in golang
	Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

type PriorityQueue struct {
	size   int
	idx    int
	values []int
}

func getPriorityQueue(size int) *PriorityQueue {
	return &PriorityQueue{idx: 0, size: size, values: make([]int, size)}
}

func parent(i int) (int) {
	return (i - 1) / 2
}

func (p *PriorityQueue) Swap(i int, j int) {
	p.values[i], p.values[j] = p.values[j], p.values[i]
}

func (p *PriorityQueue) BubbleUp(i int) {
	parent_idx := parent(i)
	if parent_idx < 0 {
		return
	}
	if p.values[i] > p.values[parent_idx] {
		p.Swap(i, parent_idx)
		p.BubbleUp(parent_idx)
	}
}

func (p *PriorityQueue) Insert(value int) {
	if p.idx > p.size {
		panic("queue is empty!")
	}
	p.values[p.idx] = value
	p.BubbleUp(p.idx)
	p.idx = p.idx + 1
}

func (p *PriorityQueue) printMax() {
	fmt.Printf("MAX IS %d\n", p.values[0])
}

func main() {
	p := getPriorityQueue(10)
	p.Insert(8)
	p.Insert(3)
	p.Insert(17)
	p.Insert(5)
	p.Insert(0)
	p.printMax()
}
