#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[] = {1, 2, 6, 3, 8, 5, 7, 9};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i += 2)
    {
        if (i != 0 && a[i] < a[i - 1])
            swap(&a[i], &a[i - 1]);
        if (i != (n - 1) && a[i] < a[i + 1])
            swap(&a[i], &a[i + 1]);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
//2 1 6 3 8 5 9 7
