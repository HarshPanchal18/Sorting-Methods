#include <iostream>

using namespace std;

/*
 Problem proposed by Edsger Dijkstra.
 The flag of the Netherlands consists of three colors: white, red, and blue.
 The task is to randomly arrange balls of white, red, and blue in such a way that balls of the same color are placed together.
 For DNF (Dutch National Flag), we sort an array of 0, 1, and 2's in linear time that does not consume any extra space.
 We have to keep in mind that this algorithm can be implemented only on an array that has three unique elements.
*/

void flagSorting(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++], arr[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

int main(void)
{
    int arr[] = {0, 1, 2, 0, 2, 0, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    flagSorting(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}
