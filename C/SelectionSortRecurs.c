#include <stdio.h>

void Selection(int list[], int i, int j, int size, int flag)
{
    int temp;
    if (i < size - 1)
    {
        if (flag)
            j = i + 1;

        if (j < size)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            Selection(list, i, j + 1, size, 0);
        }
        Selection(list, i + 1, 0, size, 1);
    }
}

int main(void)
{
    printf("\nEnter the number of elements: ");
    int n;
    scanf("%d", &n);
    int list[n];

    printf("\nEnter %d Elements: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    Selection(list, 0, 0, n, 1);

    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
}
