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


int main(void)
{
    int n, m;
    printf("\nEnter the number of elements first array: ");
    scanf("%d", &n);

    printf("\nEnter the number of elements second array: ");
    scanf("%d", &m);

    int capacity = 100;
    int used = 0;

    int *a = (int *)malloc(sizeof(int) * capacity);
    int *b = (int *)malloc(sizeof(int) * capacity);

    printf("\nEnter the elements of first array:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i - 1]);
        if (used == capacity)
        {
            capacity *= 2;
            a = (int *)realloc(a, capacity * sizeof(int));
        }
        a[used] = a[i - 1];
        used++;
    }

    printf("\nEnter the elements of second array:\n");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i - 1]);
        if (used == capacity)
        {
            capacity *= 2;
            b = (int *)realloc(b, capacity * sizeof(int));
        }
        b[used] = b[i - 1];
        used++;
    }

    mergeSort(a, b, n, m);
    print(a, b, n, m);
}

// algorithm for merging two sorted array in O(1) space complexity and in
// Nlog(N) + Mlog(M) time complexity
/*
Sample input/output
Enter size of first array:
6
Enter size of second array:
5
Enter array elements:
1 5 7 9 13 17
Enter array elements:
4 6 10 13 15
output
1 4 5 6 7 9 10 13 13 15 17
*/
