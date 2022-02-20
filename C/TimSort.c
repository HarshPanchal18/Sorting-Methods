#include <stdio.h>
#include <stdlib.h>

const int RUN = 32;

// This function sorts array from left index to
// to right index which is of size atmost RUN

int min(int x, int y)
{
    return (x < y ? x : y);
}
// sorts array from left index to to right index which is of size atmost RUN
void InsertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void Merge(int arr[], int l, int m, int r)
{
    // original array is broken in two parts, left & right
    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    // we merge two array in larger sub-array after comparing
    while (i < len1 && j < len2)
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];

    // copy remaining elements
    while (i < len1)
        arr[k++] = left[i++];

    while (j < len2)
        arr[k++] = right[j++];
}

void TimSort(int arr[], int n)
{
    // sort the individual subarrats of size RUN
    for (int i = 0; i < n; i += RUN)
        InsertionSort(arr, i, min((i + 31), (n - 1)));

    // start merging from size RUN. It will merge to form size 64, then 128, 256 and so on...
    for (int size = RUN; size < n; size = 2 * size)
    {
        // pick starting point of left sub array.
        // We're going to merge arr[left..left+size-1] and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size

        for (int left = 0; left < n; left += 2 * size)
        {
            /* find ending point of left sub array,
               mid+1 is starting point of right sub array*/

            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            // merge sub array arr[left...mid] & arr[mid+1....right]
            Merge(arr, left, mid, right);
        }
    }
}

void PrintArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    system("cls");
    int n;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    system("cls");

    printf("\nGiven Array:\n");
    PrintArr(arr, n);

    TimSort(arr, n);

    printf("\nSorted list:\n");
    PrintArr(arr, n);
}