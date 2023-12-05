#include <stdio.h>
#include <conio.h>
#define MAX 20

int main(void)
{
	int arr[MAX], i, j, k, temp, n, x;
	printf("Enter the total number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\nUnsorted(Given) array: ");
	for (i = 0; i < n; i++)
		printf("%d  ", arr[i]);
	printf("\n");

	for (i = 0; i < n - 1; i++)
	{
		x = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				x++;
			}
		}
		if (x == 0)
			break;

		printf("\nAfter pass %d elements: ", i + 1);
		for (k = 0; k < n; k++)
			printf("%d ", arr[k]);
		printf("\n");
	}

	printf("\nSorted list is: \n");
	for (i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	getch();
}
