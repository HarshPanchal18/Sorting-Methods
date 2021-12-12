#include <stdio.h>

#define MAX 5

void compare(int data[], int i, int j, int dir)
{
    int t;
    if (dir == (data[i] >= data[j]))
    {
        t = data[i];
        data[i] = data[j];
        data[j] = t;
    }
}

void bitonicMerge(int data[], int low, int c, int dir)
{
    int k, i;
    if (c > 1)
    {
        k = c / 2;
        for (i = low; i <= low + k; i++)
            compare(data, i, i + k, dir);
        bitonicMerge(data, low, k, dir);
        bitonicMerge(data, low + k, k, dir);
    }
}

void bitonicSort(int data[], int low, int c, int dir)
{
    int k;
    if (c > 1)
    {
        k = c / 2;
        bitonicSort(data, low, k, 1);
        bitonicSort(data, low + k, k, 0);
        bitonicMerge(data, low, c, dir);
    }
}

int main(void)
{
    int i;
    int data[MAX];

    printf("\nEnter %d Elements:\n", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &data[i]);

    bitonicSort(data, 0, MAX, 1); // 1 for Ascending, 0 for Descending

    printf("\nSorted\n");
    for (i = 0; i < MAX; i++)
        printf("%d\t", data[i]);
}