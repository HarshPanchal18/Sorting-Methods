#include <stdio.h>
#include <conio.h>

#define MAX 10

int main()
{
	int arr[MAX], i, j, k, n;
	printf("\nEnter the number of elements (Maximum: 10): ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter %d element : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\nUnsorted list is: ");
	for (i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	printf("\n");

	for (j = 1; j < n; j++)
	{
		k = arr[j];
		for (i = j - 1; i >= 0 && k < arr[i]; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[i + 1] = k;
	}

	printf("\nSorted list is: ");
	for (i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	printf("\nPress any key to Exit...");
	getch();
	return 0;
}
