/*
 * Bubble Sort Algorithm is the sorting algorithm in which each element is compared to its adjacent element
 * and if first elememt is greater than second element ,then the swapping occurs.
 * The swapping occurs till the array is sorted.
 */

#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool optimizedBubble(int arr[], int size)
{
    bool sort = true;
    for (int index = 0; index < size; index++)
    {
        for (int j = 0; j < size - 1 - index; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sort = false;
            }

        if (sort)
            break;
    }
}

int main()
{
    int size;
    printf("Enter the size of an array : \n");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements of an array :\n");
    for (int index = 0; index < size; index++)
        scanf("%d", &arr[index]);

    optimizedBubble(arr, size);

    printf("The sorted array is :\n");
    for (int index = 0; index < size; index++)
        printf("%d ", arr[index]);

    return 0;
}

/*
 Enter the size of an array: 5
 Enter the elements of an array :
 7 9 8 2 4
 The sorted array is :
 2 4 7 8 9
*/
