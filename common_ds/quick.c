// quicksort in C

#include <stdio.h>

void printArray(int *array, int len) {
	int i;
	for(i = 0;i < len;i++) {
		printf("[%d]", array[i]);
	}
	
	printf("\n");
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *array, int low, int high) {
	int i = low,j = high;
	int pivot = array[low];

	do {
		while(array[i] < pivot)
			i++;
		while(array[j] > pivot)
			j--;
		swap(&array[j], &array[i]);
	}while(i < j);

	return i;
}

void quicksort(int *array, int low, int high) {
	int pivot;
	if(low < high) {
		pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

int main(int argc, char *argv[]) {
	int vals[] = {55334,64,3222222,87,19339};
	printArray(vals, 5);
	quicksort(vals,0,5);
	printArray(vals, 5);
}

