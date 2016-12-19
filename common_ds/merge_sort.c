/*
	Merge sort in C - Angelo Poerio <angelo.poerio@gmail.com>
*/
#include <stdlib.h>
#include <stdio.h>
 
void merge(int myarray[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 

    for(i = 0; i < n1; i++)
        L[i] =  myarray[l + i];
    for(j = 0; j < n2; j++)
        R[j] =  myarray[m + 1 + j];
 

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
             myarray[k] = L[i];
            i++;
        }
        else
        {
             myarray[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
         myarray[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
         myarray[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int  myarray[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSort( myarray, l, m);
        mergeSort( myarray, m+1, r);
        merge( myarray, l, m, r);
    }
}
 
 
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int  values[] = {343, 4, 123, 21, 6, 8};
 
    printf("Not ordered array is \n");
    printArray(values, 6);
 
    mergeSort( values, 0, 6);
 
    printf("\nSorted array is \n");
    printArray( values, 6);
    return 0;
}
