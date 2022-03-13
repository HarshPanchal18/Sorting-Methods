#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row, col;
    printf("\nEnter the number of the ROW: ");
    scanf("%d", &row);
    printf("\nEnter the number of the COLUMN: ");
    scanf("%d", &col);

    int arr[row][col];
    int min, k, w, z = 0, q = 0;

    /*
    k = iteration for row iterator i
    w = for storing the previous value of column iterator j;
    z = used as a temporary variable for storing k
    q = used as temporary variable for storing column iterator j
    */

    printf("\nEnter Matrix data:\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            int temp = i;
            q = j;
            min = arr[i][j];
            w = j;

            for (int k = i; k < row; k++)
            {
                for (; w < col; w++)
                    if (arr[k][w] < min)
                    {
                        min = arr[k][w];
                        z = k;
                        q = w;
                    }
                w = 0;
            }

            if (arr[z][q] < arr[i][j])
            {
                temp = arr[i][j];
                arr[i][j] = arr[z][q];
                arr[z][q] = temp;
            }
        }

    printf("\nSorted Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
