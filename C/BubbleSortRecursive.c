#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) // put < for descending order
            Swap(&a[i], &a[i + 1]);

    BubbleSort(a, n - 1);
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter %d elements: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    BubbleSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}