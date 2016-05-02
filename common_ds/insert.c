// insertion sort in C

#include <stdio.h>

void insert_sort(int nums[], int N) {
	int i,j,tmp;

	for(i = 0;i < N;i++) {
		j = i;
		while(j > 0 && nums[j-1] > nums[j]) {
			tmp = nums[j];
			nums[j] = nums[j-1];
			nums[j-1] = tmp;
			j = j - 1;
		}
	}
}

void printArray(int nums[], int N) {
	int i;
	for(i = 0;i < N;i++) {
		printf("%d ",nums[i]);
	}
	
	printf("\n");
}

int main(int argc,char *argv[]) {
	int nums[] = {56,3,9,45};
	printArray(nums, 4);
	insert_sort(nums,4);
	printArray(nums, 4);
}


