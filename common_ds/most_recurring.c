/*
	Print most recurrent number in an array of integers - Angelo Poerio <angelo.poerio@gmail.com> 
*/

#include <stdio.h>
#include <stdlib.h>

int max(int *arr, int len) {
	int max=arr[0],c;
	for(c=0;c<len;c++) {
		if(arr[c] > max)
		{
			max = arr[c];
		}
	}
	return max;
} 

int most_recurring(int *arr, int len) {
	int max_val = max(arr,len);
	int *recurring = calloc(max_val + 1, sizeof(int)); /* too lazy to check :) */
	int i = 0, most_recurrent;

	for(i = 0;i < len;i++) {
		recurring[arr[i]] += 1;
	}

	most_recurrent = 0;

	for(i = 0;i <= max_val;i++) 
	{
		if(recurring[i] > recurring[most_recurrent]) {
			most_recurrent = i;
		} 
	}

	free(recurring);
	return most_recurrent;
}

int main(int argc,char *argv[]) {
	int vals[] = {1,1,1,6,8,9,9,9,9,9,9,9,9,99,8,8,8,7,4,3,2,8,8,8,8,8,8,8,8,8,8};
	printf("%d\n",most_recurring(vals, sizeof(vals)/sizeof(vals[0]))); /* print 8 */
}
