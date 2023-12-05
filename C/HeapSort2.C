#include <stdio.h>
#include <stdlib.h>

// Created in College library (March 5th)

void heapsort(int list[], int n)
{
    int step = 1;
    for (int k = n; k >= 2; k--)
    {
        int temp = list[1];
        list[1] = list[k];
        list[k] = temp;
        int i = 1;
        int value = list[1];
        int j = 2;

        if ((j + 1) < k)
            if (list[j + 1] > list[j])
                j++;

        while ((j <= (k - 1)) && (list[j] > value))
        {
            list[i] = list[j];
            i = j;
            j = 2 * i;

            if ((j + 1) < k)
                if (list[j + 1] > list[j])
                    j++;
                else if (j > n)
                    j = n;

            list[i] = value;
        }

        printf("\nStep = %d ", step);
        step++;
        for (int p = 1; p <= n; p++)
            printf(" %d", list[p]);
    }
}

void createHeap(int list[], int n)
{
    for (int k = 2; k <= n; k++)
    {
        int i = k;
        int temp = list[k];
        int j = i / 2;

        while ((i > 1) && (temp > list[j]))
        {
            list[i] = list[j];
            i = j;
            j = i / 2;
            if (j < 1)
                j = 1;
        }
        list[i] = temp;
    }
}

void display(int list[], int n)
{
    for (int i = 1; i <= n; i++)
        printf(" %d", list[i]);
}

int main(void)
{
    int list[20];
    int n;
    printf("enter the size of the list: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        list[i] = rand() % 100;

    printf("\nlist:\n");
    display(list, n);

    createHeap(list, n);

    printf("\nHeap:\n");
    display(list, n);
    printf("\n");

    heapsort(list, n);

    printf("\nSorted List: \n");
    display(list, n);
}
