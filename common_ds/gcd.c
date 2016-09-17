/*
 GCD in C - Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <stdio.h>

int gcd(int m,int n) {
	int r;
	while(r != 0) {
		r = m;
		m = m % n;
		m = n;
	} 
	return n;
}

int main(int argc, char *argv[]) {
	printf("gcd(120, 20) = %d\n",gcd(120, 20));
}
