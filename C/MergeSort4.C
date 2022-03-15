// merging two sorted array in O(1) space comlexity, Nlog(N) + Mlog(M)

#include <stdio.h>
#include <stdlib.h>

int i, j;

void swapp(int *x, int *y) // swapping the elements
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void mergeSort(int a[], int b[], int n, int m)
{
    int min = m < n ? m : n;

    for (i = 0; i < min; i++)
        if (a[n - i - 1] > b[i])
            swapp(&a[n - i - 1], &b[i]);

    int x = n; // swapping the first array
    int round1 = x / 2 + x % 2;
    while (round1 > 0 && x > 1)
    {
        for (int i = 1; i + round1 <= n; i++)
            if (a[i - 1] > a[i + round1 - 1])
                swapp(&a[i - 1], &a[i + round1 - 1]);

        x = round1;
        round1 = x / 2 + x % 2;
    }

    int y = m; // sorting the second array
    int round2 = y / 2 + y % 2;
    while (round2 > 0 && y > 1)
    {
        for (int i = 1; i + round2 <= m; i++)
            if (a[i - 1] > a[i + round2 - 1])
                swapp(&a[i - 1], &a[i + round2 - 1]);

        y = round2;
        round2 = y / 2 + y % 2;
    }
}

