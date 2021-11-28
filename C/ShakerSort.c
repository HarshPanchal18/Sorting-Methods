#include <stdio.h>
#define MAX 5
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ShakerSort(int a[], int n)
{
    for (int p = 1; p <= n / 2; p++)
    {
        for (int i = p - 1; i < n - p; i++)
            if (a[i] > a[i + 1])
                swap(&a[i], &a[i + 1]);

        for (int i = n - p - 1; i >= p; i--)
            if (a[i] <= a[i - 1])
                swap(&a[i], &a[i - 1]);
    }
}

int main(void)
{
    int arr[MAX];
    printf("\nEnter %d elements: \n", MAX);
    for (int i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);

    ShakerSort(arr, MAX);

    printf("\nSorted\n");
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
}