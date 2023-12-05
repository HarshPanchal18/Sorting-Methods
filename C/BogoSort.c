#include <stdio.h>
#include <stdlib.h>

/*
 *      Bogosort (also known as permutation sort, stupid sort, slowsort,
 *      shotgun sort, random sort, monkey sort, bobosort or shuffle sort) is a highly inefficient
 *      sorting algorithm based on the generate and test paradigm. Two versions of this algorithm
 *      exist: a deterministic version that enumerates all permutations until it hits a sorted one,
 *      and a randomized version that randomly permutes its input.
 *      Randomized version is implemented here.
 *
 *      ### Algorithm
 *      Shuffle the array untill array is sorted.
 */

int isSorted(int *a, int n)
{
    while (--n >= 1)         // Loop through all of the elements
        if (a[n] < a[n - 1]) // and compare them to each other until it finds one that's less than another element.
            return 0;
    return 1;
}

void shuffle(int *a, int n)
{
    for (int i = 0; i < n; i++)
    { // Shuffle the values using random number of element.
        int t = a[i];
        int temp = rand() % n;
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
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);

    int no[n];
    printf("\nEnter %d elements:\n",n);
    for (int i = 0; i < n; i++)
        scanf("%d", &no[i]);

    BogoSort(no, n);

    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", no[i]);
}
