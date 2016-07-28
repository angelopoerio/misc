/*
	A simple test program to compute fibonacci series - Angelo Poerio <angelo.poerio@gmail.com>
	Useful metrics:
	/usr/bin/time -v ./fibo -i 20
	/usr/bin/time -v ./fibo -r 20 
*/
#include <string.h>
#include <stdio.h>

int rec_fibo(int n) {
	if(n == 1 || n == 2) 
		return 1;
	return rec_fibo(n-1) + rec_fibo(n-2);
}

int it_fibo(int n) {
	int first = 1, second = 1, i, tmp;
	for(i = 3; i<=n;i++) 
	{
		tmp = first;
		first = second;
		second = second + tmp;
	}
	return n <= 2 ? 1 : second;
}

void usage(char **argv) {
	printf("Usage: %s [-i/-r] i-th\n", argv[0]);
}

int main(int argc,char *argv[]) {
	int rt, n;
	int (*to_call)(int n);
	if(argc != 3) {
		usage(argv);
		return 1;
	}

	if(strcmp(argv[1],"-i") == 0) {
		to_call = &it_fibo;
	}
	else if(strcmp(argv[1], "-r") == 0) {
		to_call = &rec_fibo;
	}
	else {
		usage(argv);
		return 1;
	}

	n = atoi(argv[2]);

	if(n < 2)
	{
		usage(argv);
		return 1;
	}

	printf("%d-th element is %d\n",n,to_call(n));
	return 0;
}
