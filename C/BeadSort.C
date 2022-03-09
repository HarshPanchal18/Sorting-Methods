#include <stdio.h>
#include <string.h>

#define BEAD(i, j) beads[i * max + j]

void BeadSort(int *a, int len)
{
    int max = a[0];
    for (int i = 1; i < len; i++) // find the max element
        if (a[i] > max)
            max = a[i];

    // allocating memory
    unsigned char beads[max * len];
    memset(beads, 0, sizeof(beads));

    // mark the beads
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < a[i]; j++)
            BEAD(i, j) = 1;
        printf("%d ", beads[i]);
    }

    int sum = 0;
    printf("\n");
    for (int j = 0; j < max; j++)
    {
        // count how many beads are on each post
        sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        // move beasd down
        for (int i = len - sum; i < len; i++)
            BEAD(i, j) = 1;
    }

    // put sorted values in array using beads
    for (int i = 0; i < len; i++)
        for (int j = 0; j < max && BEAD(i, j); j++)
            a[i] = j;
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

    BeadSort(a, n);

    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i] + 1);
}
