/*
	counter game - Hackerrank  
	solution by Angelo Poerio <angelo.poerio@gmail.com>
*/

#include <stdio.h>

int max_power_2(unsigned int N) {
	unsigned int n = 1 << 31;
	while((N & n) == 0) {
		n >>= 1;
	}

	return n;
}


char game(int N) {
	char turn = 'R';
	while(N!=1) {
		turn = (turn == 'L') ? 'R' : 'L';
 		if(N % 2 != 0){
			N -= max_power_2(N);
		}
		else {
			N -= (N/2);
		}
	} 
	return turn;
}

// L = Louise, R = Richard. Pass N as argument
int main(int argc,char *argv[]) {
	int i;
	for(i = 1; i < argc;i++) 
		printf("%c\n",game(atoi(argv[i])));
}
