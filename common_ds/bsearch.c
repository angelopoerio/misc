#include <stdio.h>
/*
  Binary search: Angelo Poerio <angelo.poerio@gmail.com>
*/

/* iterative binary search */
int bsearch_it(int *list, int start, int end, int x) {
	int m;
	while(start <= end) {
		m = (start+end)/2;
		if(list[m] == x)
		{
			return m;
		}
	
		else if(list[m] < x) 
		{
			start = m + 1;
		}

		else {
			end = m - 1;
		}
	}
	return -1;
}

/* recursive binary search */
int bsearch(int *list, int start, int end, int x) {
	int middle = (start + end) / 2;
	int el = list[middle];

	if(start > end)
		return -1;

	if(el == x)
	{
		return middle; 
	}

	if(el > x) {
		return bsearch(list, start, middle - 1, x);
	}

	else {
		return bsearch(list, middle + 1, end, x);
	}
}

int main(int argc, char *argv[]) {
	int lst[] = {1,2,3,4,5,6,7,8,9,10};
	printf("bsearch_rec: %d\n",bsearch(lst, 0, 10, 9));
	printf("bsearch_it: %d\n",bsearch_it(lst,0,10,9));
}
