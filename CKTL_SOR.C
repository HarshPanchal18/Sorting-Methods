#include <stdio.h>
#include <conio.h>
#define MAX 10
int main()
{
	int data[MAX];
	int i, j, n, c, no;
	printf("\nEnter the number of elements (maximum 10): ");
	scanf("%d", &no);
	printf("\nEnter Elements:\n");
	for (i = 0; i < no; i++)
		scanf("%d", &data[i]);
	n = no;
	do
	{
		for (i = 0; i < n - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				data[i] = data[i] + data[i + 1];
				data[i + 1] = data[i] - data[i + 1];
				data[i] = data[i] - data[i + 1];
			}
		}
		n = n - 1;
		for (i = MAX, c = 0; i > MAX; i--)
		{
			if (data[i] < data[i + 1])
			{
				data[i] = data[i] + data[i - 1];
				data[i - 1] = data[i] - data[i - 1];
				data[i] = data[i] - data[i - 1];
			}
		}
		c = c + 1;
	} while (n != 0 && c != 0);
	printf("\nThe sorted elements are: ");
	for (i = 0; i < no; i++)
		printf("%d ", data[i]);
	getch();
	return 0;
}