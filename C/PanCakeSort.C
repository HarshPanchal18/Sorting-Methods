#include <stdio.h>
#include <stdlib.h>

void Flip(int *, int, int);

int PanCakeSort(int *list, unsigned int length)
{
    if (length < 2)
        return 0;
    int i, a, max_pos, moves = 0;
    for (i = length; i > 1; i--)
    {
        max_pos = 0;
        for (a = 0; a < i; a++)
        {
            if (list[a] > list[max_pos])
                max_pos = a;
        }
        if (max_pos == i - 1)
            continue;
        if (max_pos)
        {
            moves++;
            Flip(list, length, max_pos + 1);
        }
        Flip(list, length, i);
    }
    return moves;
}

void Flip(int *list, int length, int number)
{
    int swap;
    int i = 0;
    for (i = 0; i < --number; i++)
    {
        swap = list[i];
        list[i] = list[number];
        list[number] = swap;
    }
}

int main(void)
{
    int list[15];
    int i, n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);

    printf("\nBefore Sorting: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", list[i]);

    int moves = PanCakeSort(list, n);

    printf("\nAfter Sorting: \n");
    for (i = 0; i < n; i++)
        printf("%d\t", list[i]);

    printf("\nWith a total of %d moves", moves);
}
