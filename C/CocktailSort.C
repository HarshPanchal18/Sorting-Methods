#include <stdio.h>
#include <conio.h>

void Swap(int *a, int *b)
{
	/*int temp = *a;
	 *a = *b;
	 *b = temp;*/
	*a = (*a + *b) - (*b = *a);
}

int main(void)
{
	int c, no;
	printf("\nEnter the number of elements: ");
	scanf("%d", &no);
	int data[no];

	printf("\nEnter %d Elements:\n", no);
	for (int i = 0; i < no; i++)
		scanf("%d", &data[i]);

	int n = no;

	do
	{
		for (int i = 0; i < n - 1; i++) // Go forward
		{
			if (data[i] > data[i + 1])
			{
				Swap(&data[i], &data[i + 1]);
			}
		}
		n--;

		for (int i = no, c = 0; i > no; i--) // Go backward
		{
			if (data[i] < data[i + 1])
			{
				Swap(&data[i], &data[i + 1]);
			}
		}
		c++;

	} while (n != 0 && c != 0);

	printf("\nThe sorted elements are: ");
	for (int i = 0; i < no; i++)
		printf("%d ", data[i]);
}
