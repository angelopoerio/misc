/*
	Minimum cost path in a matrix - recursive solution (simple but not efficient)
	Angelo Poerio - angelo.poerio@gmail.com
*/
#include <stdio.h>
#include <limits.h>

int min(int a,int b, int c) {
	int tmp = (a < b) ? a : b;
	return (tmp < c) ? tmp : c;
}

/* best solution needs dynamic programming! */
int mcp(int M[3][3],int m,int n) {
	if(m < 0 || n < 0)
		return INT_MAX;

	if(m == 0 && n == 0)
		return M[m][n];

	return M[m][n] + min(mcp(M,m,n-1),
			 mcp(M,m-1,n),
			 mcp(M,m-1,n-1));
}

int main(int argc,char *argv[]) {
	int v[3][3] = {
		{1,70,4},
		{3,789,9},
		{0,1,0}
	};
	printf("min: %d\n",mcp(v,3-1,3-1));
}
