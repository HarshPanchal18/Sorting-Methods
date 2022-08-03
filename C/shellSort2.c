#include <stdio.h>

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0; j -= gap)
                // if lesser index value is small
                // compared to bigger index
                // then continue
                if (arr[j + gap] >= arr[j])
                    break;
                // else
                // Swap values of bigger index with smaller one
                else
                {
                    int temp = arr[j];
                    arr[j] = arr[j + gap];
                    arr[j + gap] = temp;
                }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%3d", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter total number of elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    display(arr, n);
    shellSort(arr, n);
    display(arr, n);

    return 0;
}

/*
Enter total number of elements : 10
Enter elements : 36 432 43 44 57 63  94 3 5 6

    36 432    43    44    57     63     94      3      5       6
    3    5    6    36     43     44     57     63     94     432
*/

/*Complexity

Worst case time complexity is O(n2)
Best case time complexity is O(nlog(n)).
Space complexity is O(1).
*/
