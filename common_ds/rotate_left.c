/*
	Rotate an array left by N position
	Author: Angelo Poerio <angelo.poerio@gmail.com>
	compile as: cc rotate_left.c -o rotate_left
*/
#include <stdio.h>

void rotateLeftByOne(int *arr, int len) {
	int first,i;
	
	if(len == 0)
		return;

	first = arr[0];

	for(i = 1;i < len;i++) {
		arr[i-1] = arr[i];
	}

	arr[len-1] = first;
}

void rotateLeftByN(int *arr,int len, int N) {
	int i;
	for(i = 0; i < N;i++) {
		rotateLeftByOne(arr,len);
	}
} 

void printArray(int *arr,int len) {
	int i;
	for(i = 0;i < len;i++) {
		printf("[%d] ",arr[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int values[] = {4,7,3,19,1}; /* example array */
	int i;
	printf("Original array:\n");
	printArray(values,5);	
	for(i = 1; i<=5;i++) {
		printf("Rotated left by %d positions\n", i);
		rotateLeftByN(values,5,1);
		printArray(values, 5);
	}
}
