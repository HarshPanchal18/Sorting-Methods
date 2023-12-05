#include <stdio.h>
#define MAX 5

int array[] = {7, 85, 41, 6, 3, 7, 1};
int n = sizeof(array) / sizeof(array[0]);

void swap(int *a, int *b)
{
    *a = (*a + *b) - (*b = *a);
}

void StoogeSort(int a[], int i, int j, int flag)
{
    //int temp, k;
    if (!flag)
    {
        if (a[i] > a[j])
            swap(&a[i], &a[j]);
    }
    else if (a[i] < a[j])
        swap(&a[i], &a[j]);

    if ((i + 1) >= j)
        return;

    int k = (int)((j - i + 1) / 3);
    StoogeSort(a, i, j - k, flag);
    StoogeSort(a, i + k, j, flag);
    StoogeSort(a, i, j - k, flag);
}

int main(void)
{
    int a[MAX], i;

    /*printf("\nEnter %d values:\n", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &a[i]);*/

    StoogeSort(array, 0, n - 1, 0);

    printf("\nSorted values:");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);

    StoogeSort(array, 0, n - 1, 1);

    printf("\nSorted values:");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);
}