#include <stdio.h>

/*
 * Gnome sort algorithm is not the best one but it is widely used.
 * The algorithm iteratively checks the order of pairs in the array.
 * If they are on right order it moves to the next successive pair, otherwise it swaps elements.
 * This operation is repeated until no more swaps are made thus
 * indicating the values to be in ascending order.
 */

int main(void)
{
    int i, no;
    printf("\nEnter the number of elements(MAXIMUM %d): ", MAX);
    scanf("%d", &no);
    int a[no];
    
    printf("\nEnter %d elements: \n", no);
    for (i = 0; i < no; i++)
        scanf("%d", &a[i]);

    i = 0;
    while (i < no)
    {
        if (i == 0 || a[i - 1] <= a[i])
            i++;
        else
        {
            int temp = a[i - 1];
            a[i - 1] = a[i];
            a[i] = temp;
            i--;
        }
    }

    printf("\nSorted list:\n");
    for (i = 0; i < no; i++)
        printf("%d\t", a[i]);
}
