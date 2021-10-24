#include <stdio.h>
#include <conio.h>
#define MAX 5
void oddeven_sort(int *);
void swap(int *x, int *y);
int main(void)
{
	int a[MAX], i;
	printf("Enter %d elements: \n", MAX);
	for (i = 0; i < MAX; i++)
		scanf("%d", &a[i]);

	printf("Sorted elements are:\n");
	oddeven_sort(a);

	for (i = 0; i < MAX; i++)
		printf("%d\t", a[i]);
	getch();
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void oddeven_sort(int *x)
{
	int sort = 0, i;
	while (!sort)
	{
		sort = 1;
		for (i = 1; i < MAX; i += 2)
		{
			if (x[i] > x[i + 1])
			{
				swap(&x[i], &x[i + 1]);
				sort = 0;
			}
		}
		for (i = 0; i < MAX - 1; i += 2)
		{
			if (x[i] > x[i + 1])
			{
				swap(&x[i], &x[i + 1]);
				sort = 0;
			}
		}
	}
}