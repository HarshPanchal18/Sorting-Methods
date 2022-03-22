// Three Way Merge Sort
#include <stdio.h>

// Time Complexity: O(n*logn)
// Space Complexity: O(n)

// Merge the three sections in ascending order
void merge(int arr[], int beg, int midA, int midB, int end, int temp[])
{
    int i, j, k, l;
    i = beg;
    j = midA;
    k = midB;
    l = beg;

    // Find the smallest element among the three sections
    while ((i < midA) && (j < midB) && (k < end))
    {
        if (arr[i] < arr[j])
        {
            if (arr[i] < arr[k])
                temp[l++] = arr[i++];

            else
                temp[l++] = arr[k++];
        }
        else
        {
            if (arr[j] < arr[k])
                temp[l++] = arr[j++];

            else
                temp[l++] = arr[k++];
        }
    }

    /*
    Now any two arrays would have remaining values that are yet to be merged,
    We have to identify those two arrays and merge the elements.
    */

    while ((i < midA) && (j < midB))
    {
        if (arr[i] < arr[j])
            temp[l++] = arr[i++];
        else
            temp[l++] = arr[j++];
    }

    while ((j < midB) && (k < end))
    {
        if (arr[j] < arr[k])
            temp[l++] = arr[j++];
        else
            temp[l++] = arr[k++];
    }

    while ((i < midA) && (k < end))
    {
        if (arr[i] < arr[k])
            temp[l++] = arr[i++];

        else
            temp[l++] = arr[k++];
    }

    /*
      Now a single array would have remaining values that are yet to be merged,
      We have identify that array and copy its remaining elements.
    */

    while (i < midA)
        temp[l++] = arr[i++];

    while (j < midB)
        temp[l++] = arr[j++];

    while (k < end)
        temp[l++] = arr[k++];
}
