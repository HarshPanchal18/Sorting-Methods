#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cockTailSort(int a[], int n)
{
    int swapped = 1;
    int start = 0, end = n - 1;

    while (swapped)
    {
        swapped = 0;

        for (int i = start; i < end; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped) // if array is already sorted
            break;

        // otherwise reset the flag so that it can be used in next stage.
        swapped = 0;
        --end;

        for (int i = end - 1; i >= start; i--)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
        start++;
    }
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    cockTailSort(a, n);

    printf("\nSorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
