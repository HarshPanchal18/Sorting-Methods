#include <stdio.h>

#define MAX 10
int main(void)
{
    int i, temp, no;
    int a[MAX];
    printf("\nEnter the number of elements(MAXIMUM %d): ", MAX);
    scanf("%d", &no);

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
            temp = a[i - 1];
            a[i - 1] = a[i];
            a[i] = temp;
            i--;
        }
    }

    printf("\nSorted list:\n");
    for (i = 0; i < no; i++)
        printf("%d\t", a[i]);
}
