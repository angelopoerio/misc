#include <stdio.h>
/*
  Binary search: Angelo Poerio <angelo.poerio@gmail.com>
*/

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
	printf("%d\n",bsearch(lst, 0, 10, 9));
}
