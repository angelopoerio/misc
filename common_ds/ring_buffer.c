/*
	Implementation of a ring buffer - Author: Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

struct RingBuffer {
	int size, head_in, tail_in;
	int *data;
};

typedef struct RingBuffer RingBuffer;

RingBuffer *initialize(int size) {
	RingBuffer *ring = (RingBuffer *)malloc(sizeof(RingBuffer)); /* too lazy to check if malloc succeded :) */
	ring->head_in = 0;
	ring->tail_in = 0;
	ring->size = size;
	ring->data = (int *)malloc(size*sizeof(int));
	return ring;
}

void deinitialize(RingBuffer *ring) {
	free(ring->data);
	free(ring);
}

RingBuffer *push(RingBuffer *ring, int el) {
	ring->data[ring->head_in] = el;
	ring->head_in++;
	if(ring->head_in == ring->size) /* 0 index ring buffer */
		ring->head_in = 0;
	return ring;
}

RingBuffer *pop(int *el, RingBuffer *ring) {
	*el = ring->data[ring->tail_in];
	ring->tail_in++;
	if(ring->tail_in == ring->size)	/* 0 index ring buffer */
		ring->tail_in = 0;
	return ring;
}

int main(int argc, char *argv[]) {
	int SIZE = 10,c,el;
	RingBuffer *ring = initialize(SIZE);
	printf("---- initial values ----\n");
	for(c = 0;c < SIZE;c++) {
		ring = push(ring, 10); /* fill with 10 */
	}

	ring = push(ring, 15); /* overwrite ring[0] with 15 */
	ring = pop(&el, ring);
	printf("%d\n",el);
	deinitialize(ring);
}
