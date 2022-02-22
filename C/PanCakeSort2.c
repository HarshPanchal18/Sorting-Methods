#include <stdio.h>
#include <stdlib.h>

// get the index of ceiling of data in arr[low...high]
int ceilSearch(int arr[], int low, int high, int data)
{
    if (data <= arr[low]) // If data is less than first element then return first element
        return data;

    if (data > arr[high]) // If data is greater than last element
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == data)
        return mid;

    /*
    If data is greater than arr[mid], then arr[mid+1] is ceiling of data
    Or ceiling lies to the arr[mid+1...high]
    */

    if (arr[mid] < data)
    {
        if (mid + 1 <= high && data <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, data);
    }

    if (mid - 1 >= low && data >= arr[mid - 1])
        return mid;
    else
        return ceilSearch(arr, low, mid - 1, data);
}

void flip(int arr[], int i)
{
    int start = 0, temp;

    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;

        start++;
        i--;
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) // start from the second element and do the sorting one by one
    {
        int j = ceilSearch(arr, 0, i - 1, arr[i]); // find the smallest element in arr[0...i-1] which is >= arr[i]

        if (j != -1) // if there is no element > arr[i]
        {            // put arr[i] before arr[j]
            flip(arr, j - 1);
            flip(arr, i - 1);
            flip(arr, i);
            flip(arr, j);
        }
    }
}

int main(void)
{
    int arr[] = {10, 5, 6, 4, 17, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}