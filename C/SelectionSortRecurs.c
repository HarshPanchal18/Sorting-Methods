#include <stdio.h>
#define MAX 5
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
    int list[MAX], temp, i, j;

    printf("\nEnter %d Elements: \n", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &list[i]);

    Selection(list, 0, 0, MAX, 1);

    for (i = 0; i < MAX; i++)
        printf("%d ", list[i]);
}