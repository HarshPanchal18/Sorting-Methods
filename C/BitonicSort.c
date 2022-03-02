#include <stdio.h>

// This algorithm only works on even numbers of elements.

void compare(int data[], int i, int j, int dir)
{
    /*The parameter dir indicates the sorting direction, ASCENDING
    or DESCENDING; if (a[i] > a[j]) agrees with the direction,
    then a[i] and a[j] are interchanged.*/
    if (dir == (data[i] > data[j]))
    {
        int t = data[i];
        data[i] = data[j];
        data[j] = t;
    }
}

void bitonicMerge(int data[], int low, int c, int dir)
{
    /*It recursively sorts a bitonic sequence in ascending order,
    if dir = 1, and in descending order otherwise (means dir=0).
    The sequence to be sorted starts at index position low,
    the parameter cnt is the number of elements to be sorted.*/
    if (c > 1)
    {
        int k = c / 2;
        for (int i = low; i <= low + k; i++)
            compare(data, i, i + k, dir);
        
        bitonicMerge(data, low, k, dir);
        bitonicMerge(data, low + k, k, dir);
    }
}

void bitonicSort(int data[], int low, int c, int dir)
{
    /* This function first produces a bitonic sequence by recursively
    sorting its two halves in opposite sorting orders, and then
    calls bitonicMerge to make them in the same order */
    if (c > 1)
    {
        int k = c / 2;
        bitonicSort(data, low, k, 1);
        bitonicSort(data, low + k, k, 0);
        bitonicMerge(data, low, c, dir);
    }
}

int main(void)
{
    int n;

    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    
    int data[n];
    printf("\nEnter %d Elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);

    bitonicSort(data, 0, n, 1); // 1 for Ascending, 0 for Descending

    printf("\nSorted\n");
    for (i = 0; i < n; i++)
        printf("%d\t", data[i]);
}
