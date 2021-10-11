#include <stdio.h>
#include <conio.h>
int main()
{
	int arr1[20], arr2[20], arr3[20];
	int i, j, k;
	int max1, max2;

	printf("Enter the number of elements in list1: ");
	scanf("%d", &max1);
	printf("\nGive the element in sorted order only: \n");
	for (i = 0; i < max1; i++)
	{
		printf("\n Enter element %d : ", i + 1);
		scanf("%d", &arr1[i]);
	}
	printf("\nEnter the number of elements in list2: ");
	scanf("%d", &max2);
	printf("\nGive the element in sorted order only: \n");
	for (i = 0; i < max2; i++)
	{
		printf("\nEnter element %d : ", i + 1);
		scanf("%d", &arr2[i]);
	}
	i = 0;
	j = 0;
	k = 0;

	while ((i < max1) && (j < max2))
	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	while (i < max1)
		arr3[k++] = arr1[i++];

	while (j < max2)
		arr3[k++] = arr2[j++];

	printf("\nList1: ");
	for (i = 0; i < max1; i++)
		printf("%5d ", arr1[i]);

	printf("\nList2: ");
	for (i = 0; i < max2; i++)
		printf("%5d ", arr2[i]);

	printf("\nMerged list: ");
	for (i = 0; i < (max1 + max2); i++)
		printf("%d ", arr3[i]);

	printf("\nPress any key to exit...");
	getch();
	return 0;
}