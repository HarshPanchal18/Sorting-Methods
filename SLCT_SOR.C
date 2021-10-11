// Selection Sort
#include <stdio.h>
#include <conio.h>

void swap(int *a, int *b);

void selectionSort(int arr[], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int arr[10], i, size;
	//clrscr();
	printf("\nHow many numbers you want to sort??: ");
	scanf("%d", &size);
	printf("\nEnter %d numbers: \n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	selectionSort(arr, size);
	printf("\nSorted array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	getch();
	return 0;
}
