#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void oddeven_sort(int *x,int n)
{
	int sort = 0, i;
	while (!sort)
	{
		sort = 1;
		for (i = 1; i < n - 1; i += 2)
		{
			if (x[i] > x[i + 1])
			{
				swap(&x[i], &x[i + 1]);
				sort = 0;
			}
		}
		for (i = 0; i < n - 1; i += 2)
		{
			if (x[i] > x[i + 1])
			{
				swap(&x[i], &x[i + 1]);
				sort = 0;
			}
		}
	}
}

int main(void)
{
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	int a[n];
	printf("Enter %d elements: \n", MAX);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Sorted elements are:\n");
	oddeven_sort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
