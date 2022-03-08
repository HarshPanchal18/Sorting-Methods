#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void CountSort(int a[], int n)
{
    int output[n + 1];
    int max = getMax(a, n);
    int count[max + 1];

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("\nEnter %d elements\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nGiven array\n");
    printArr(a, n);

    CountSort(a, n);

    printf("\nSorted array:\n");
    printArr(a, n);
}
