/*
The Pigeonhole sort is a sorting technique that is used when the range of keys is relatively small.
An array of pigeonholes (buckets, chunks of RAM) is reserved for each possible key value.
The records from the unsorted list are scanned and copied into their respective pigeonholes based on their key values.
Then, the contents of the pigeonholes are copied in sequence to the final destination.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the size of array:\n");
    int n;
    scanf("%d", &n);
    int pigeon[n];

    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &pigeon[i]);

    int max = pigeon[0];
    int min = pigeon[0];

    for (int i = 0; i < n; ++i)
    {
        if (min > pigeon[i])
            min = pigeon[i];

        if (max < pigeon[i])
            max = pigeon[i];
    }

    int range = max + 1;
    int hole[range + 1];

    for (int i = 0; i < range + 1; ++i)
        hole[i] = 0;

    for (int i = 0; i < n; ++i)
        hole[pigeon[i]]++;

    printf("\n");
    for (int i = 0; i < range + 1; ++i)
    {
        while (hole[i] > 0)
        {
            printf("%d ", i);
            hole[i]--;
        }
    }

    printf("\nMaximum: %d\nMinimum: %d\n", max, min); //optional
}
