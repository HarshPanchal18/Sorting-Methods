#include <stdio.h>

void CycleSort(int *a, int n)
{
    int temp, item, pos, k;

    for (int i = 0; i < n; i++)
    {
        item = a[i];
        pos = i;

        do
        {
            k = 0;
            for (int j = 0; j < n; j++)
                if (pos != j && a[j] < item)
                    k++;

            if (pos != k)
            {
                while (pos != k && item == a[k])
                    k++;
                temp = a[k];
                a[k] = item;
                item = temp;
                pos = k;
            }
        } while (pos != i);
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

    CycleSort(a, n);

    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}