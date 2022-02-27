#include <stdio.h>
#include <math.h>

void SlowSort(int *arr, int i, int j)
{
    if (i >= j)
        return;

    int temp;
    int m = floor((i + j) / 2);

    SlowSort(arr, i, m);
    SlowSort(arr, m + 1, j);

    if (arr[j] < arr[m])
    {
        temp = arr[j];
        arr[j] = arr[m];
        arr[m] = temp;
    }

    SlowSort(arr, i, j - 1);
}

void PrintArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nUnSorted list: \n");
    PrintArr(arr, n);

    SlowSort(arr, 0, n - 1);

    printf("\nSorted list: \n");
    PrintArr(arr, n);
}