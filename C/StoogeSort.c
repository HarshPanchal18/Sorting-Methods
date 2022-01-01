#include <stdio.h>
#define MAX 5

void StoogeSort(int a[], int i, int j)
{
    int temp, k;
    if (a[i] > a[j])
        temp = a[i], a[i] = a[j], a[j] = temp;

    if ((i + 1) >= j)
        return;

    k = (int)((j - i + 1) / 3);
    StoogeSort(a, i, j - k);
    StoogeSort(a, i + k, j);
    StoogeSort(a, i, j - k);
}

int main(void)
{
    int a[MAX], i;

    printf("\nEnter %d values:\n", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &a[i]);

    StoogeSort(a, 0, MAX - 1);

    printf("\nSorted values:");
    for (i = 0; i < MAX; i++)
        printf("\t%d", a[i]);
}