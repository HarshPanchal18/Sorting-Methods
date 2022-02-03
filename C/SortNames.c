#include <string.h>
#include <stdio.h>

void Sort(char q[][20], int n)
{
    int i, j, p;
    char t[20], l[20];
    for (i = 0; i < n - 1; i++)
    {
        strcpy(l, q[i]), p = i;
        for (j = i + 1; j < n; j++)
            if (strcmpi(l, q[j]) > 0) // put  <  for descending order
                strcpy(l, q[j]), p = j;
        strcpy(t, q[i]);
        strcpy(q[i], q[p]);
        strcpy(q[p], t);
    }
}
int main(void)
{
    printf("\n\n_______________________________________________________________________\n");
    printf("     Arranging Array of Names in Descending order using selection sort\n");
    printf("_________________________________________________________________________");

    int n;
    printf("\n\n\n\n\nEnter the size of array =\t");
    scanf("%d", &n);
    char a[n][20];

    printf("\nEnter all the values of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", &a[i]);

    Sort(a, n);
    printf("\n Sorted Array :-\n");
    for (int i = 0; i < n; i++)
        printf("\t%s\n", a[i]);
}
