#include <stdio.h>
#include <stdlib.h>

/*
Shows the use of qsort function. It needs a function that returns
    +ve value if a should be after  b
    -ve value if a should be before b
    0 if a and b are equivalent
*/

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int arr[] = {10, 60, 80, 40, 25, 90};
    qsort(arr, 6, sizeof(*arr), compare);

    /*
    arr = Source of data
    6 = Number of elements to sort
    sizeof(*arr)= size of the source data
    compare = Top comment (Line 5)
    */

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%3d", arr[i]);
}