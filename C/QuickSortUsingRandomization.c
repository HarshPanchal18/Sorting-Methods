#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

void RandomShuffle(int arr[])
{
    srand(time(NULL));
    int i, j, tmp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    int pivotindex = p + rand() % (r - p + 1); // generate pivot index
    int pivot, j;
    int i = p - 1;
    pivot = arr[pivotindex];
    swap(&arr[pivotindex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quicksort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partition(arr, p, q);
        quicksort(arr, p, j - 1);
        quicksort(arr, j + 1, q);
    }
}

int main(void)
{
    int arr[MAX];
    printf("Enter %d Elements:\n", MAX);
    for (int i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);

    RandomShuffle(arr);
    quicksort(arr, 0, MAX - 1);

    printf("\nSorted\n");
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
}