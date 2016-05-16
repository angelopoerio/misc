/* Max-Heap in C
   Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

struct Heap {
	int size;
	int *values;
};

typedef struct Heap Heap;

Heap *heap_init(void) {
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	heap->size = 0;
	return heap;
}

int parent(int i) {
	return (i-1)/2;
}

int  right(int i) {
	return 2*i + 2;
}

int left(int i) {
	return 2*i + 1;
}


Heap *insert(Heap *heap, int value) {
	heap->values = (int *)realloc(heap->values,(heap->size + 1) * sizeof(int));
	int zero_index = heap->size;
	heap->values[zero_index]  = value;

	int parent_i = parent(zero_index);

	if(parent_i < 0)
		return heap;

	int parent_value = heap->values[parent_i];

	while(parent_i >= 0 && heap->values[parent_i] < heap->values[zero_index]) {
		int tmp = heap->values[parent_i];
		heap->values[parent_i] = heap->values[zero_index];
		heap->values[zero_index] = tmp;
		zero_index = parent_i;
		parent_i = parent(zero_index);
	}
  	heap->size += 1;
	return heap;
}

void print_heap(Heap *heap) {
	int i;
	for(i = 0;i < heap->size;i++) {
		printf("[%d] ", heap->values[i]);
	}
	printf("\n");
}

int get_max(Heap *heap) {
	return heap->values[0];
}

int main(int argc, char *argv) {
	Heap *heap = heap_init();
	heap = insert(heap, 37);
	heap = insert(heap, 206);
	heap = insert(heap, 2);
	heap = insert(heap, 56);
	heap = insert(heap, 22);
	print_heap(heap);
	printf("MAX VALUE: %d\n", get_max(heap));
}
