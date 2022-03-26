#include <stdio.h>

// It only works with 0, 1 and 2

void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sorting(int *a, int n)
{
    int low = 0;
    int high = n - 1, mid;

    while (mid <= high)
    {
        if (a[mid] == 0)
            swap(a, mid++, low++);
        else if (a[mid] == 1)
            mid++;
        else if (a[mid] == 2)
            swap(a, mid, high--);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sorting(arr, n);
    for (int j = 0; j < n; j++)
        printf("%d ", arr[j]);

    return 0;
}
