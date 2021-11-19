#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int isSorted(int *a, int n)
{
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
            return 0;
    }
    return 1;
}

void shuffle(int *a, int n)
{
    int i, t, temp;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        temp = rand() % n;
        a[i] = a[temp];
        a[temp] = t;
    }
}

void BogoSort(int *a, int n)
{
    while (!isSorted(a, n))
        shuffle(a, n);
}

int main(void)
{
    int no[MAX];
    int i;
    printf("\nEnter the elements:\n");
    for (i = 0; i < MAX; i++)
        scanf("%d", &no[i]);
    BogoSort(no, MAX);
    printf("\nSorted list:\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", no[i]);
}