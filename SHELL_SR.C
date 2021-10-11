#include <stdio.h>
#include <conio.h>
#define MAX 20
int main()
{
	int arr[MAX], i, j, k, n, incr;
	//clrscr();
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	//clrscr();
	printf("\nUnsorted list is: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\nEnter maximum increment (odd)");
	scanf("%d", &incr);

	while (incr >= 1)
	{
		for (j = incr; j < n; j++)
		{
			k = arr[j];
			for (i = j - incr; i >= 0 && k < arr[i]; i = i - incr)
			{
				arr[i + incr] = arr[i];
			}
			arr[i + incr] = k;
		}
		printf("\nIncrement = %d\n", incr);
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
		incr = incr - 2;
	}
	printf("\nSorted list is : ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	getch();
	return 0;
}