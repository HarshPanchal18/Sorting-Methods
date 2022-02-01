#include <stdio.h>
#include <stdbool.h>

void ShakerSort(int a[], int n)
{
    bool swapped = false;

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }

        for (int j = n - 2 - i; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) // If elements are already sorted.
            break;
    }
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter %d elements: \n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    ShakerSort(a, n);

    printf("\nSprted Elements: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}