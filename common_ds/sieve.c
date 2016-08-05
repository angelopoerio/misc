/*
	Sieve of Erathostene - Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNums(char *arr, int N) {
	int i = 2;
	printf("Prime numbers 2-%d: ", N);
	for(;i<=N;i++)
		if(arr[i])
			printf("[%d] ", i);
		if(i % 10 == 0)
			printf("\n");
	printf("\n");	
}

void sieve(int N) {
	char nums[N+1];
	int i,m;
	memset(nums, 1 , N+1);

	for(i = 2;i <= N;i++) {
		if(nums[i])
		{
			for(m = 2; m*i <= N;m++) {
				nums[m*i] = 0;
			}
		}
	}

	printNums(nums, N);
}

int main(int argc, char *argv[]) {
	int i,n;
	if(argc < 2) {
		printf("Usage: %s [num_1] [num_2] ... [num_n]\n", argv[0]);
		return 1;
	}

	for(i = 1;i < argc;i++)
	{
		n = atoi(argv[i]);
		if(n <= 2) {	
			printf("Skipping ... %d\n",n);
			continue;
		}	
		sieve(atoi(argv[i]));
	}
}
