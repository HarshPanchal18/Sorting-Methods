#include <stdio.h>
#define MAX 10

int arr[MAX];
void merge(int low, int mid, int high)
{
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    while ((i <= mid) && (j <= high))
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void merge_sort(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main(void)
{
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nUnsorted list:\n");
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);

    merge_sort(0, n - 1);

    printf("\nUnsorted List:\n");
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}
