//selection sort

#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min])
			min = j;

		if(min != i)
			swap(&arr[min], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{   
    int n,i;
    printf("\nEnter number of elements of an array:\n");
    scanf("%d",&n);
    int  arr[n];
    printf("\nEnter elements: \n");
    for (i=0; i<n; i++)
    scanf("%d", &arr[i]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
