// Kind of better version of Bubble Sort
// While Bubble sort is comparing adjacent value, CombSort is using gap >1

#include <stdio.h>

int a[10];
int n;

int max(int x, int y) { return x > y ? x : y; }

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int FindNextGap(int x)
{
    x = (x * 10) / 13;
    return max(1, x);
}

void CombSort(int a[], int l, int r)
{
    // init gap
    int gap = n;

    int swapped = 1; // initialize swapped as true to make sure that loop runs

    // keep running until gap=1 or none elements were swapped
    while (gap != 1 || swapped)
    {
        gap = FindNextGap(gap); // find next gap

        swapped = 0;

        for (int i = l; i <= r - gap; i++) // Compare all elements with current gap
        {
            if (a[i] > a[i + gap])
            {
                swap(&a[i], &a[i + gap]);
                swapped = 1;
            }
        }
    }
}

int main(void)
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    CombSort(a, 0, n);

    printf("\nSorted list:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}