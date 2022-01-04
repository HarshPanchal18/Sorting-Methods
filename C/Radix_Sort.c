#include <stdio.h>

#define MAX 10

//#define SHOWPASS

void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
}

int RadixSort(int *a, int n)
{
    int b[MAX], i, m = 0, exp = 1;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    while (m / exp > 0)
    {
        int box[10] = {0};
        for (i = 0; i < n; i++)
            box[a[i] / exp % 10]++;
        for (i = 1; i < 10; i++)
            box[i] += box[i - 1];
        for (i = n - 1; i >= 0; i--)
            b[--box[a[i] / exp % 10]] = a[i];
        for (i = 0; i < n; i++)
            a[i] = b[i];
        exp *= 10;
        /*#ifdef SHOWPASS
        printf("\n\nPASS: ");
        print(a, n);
        #endif*/
    }
}

int main(void)
{
    int arr[MAX], i, num;

    printf("\nEnter the number of elements: ");
    scanf("%d", &num);

    printf("\nEnter %d elements: \n", num);
    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("\nUnsorted:");
    print(&arr[0], num);

    RadixSort(&arr[0], num);

    printf("\n\nSorted:\t");
    print(&arr[0], num);
}