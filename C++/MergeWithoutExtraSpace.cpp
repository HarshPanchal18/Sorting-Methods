#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    // Starting from last index of first array and first index of second arary
    int i = n - 1;
    int j = 0;

    // iterating till the small array is traversed [Note that AND operator is used]
    while (i >= 0 && j < m)
        if (arr1[i] > arr2[j])
            swap(arr1[i--], arr2[j++]);
        else
            break;

    // Sorting both the arrays as the order in which element occured would have changed
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    // n -> Size of first Array
    // m -> Size of Second Array
    int n, m, i;
    cin >> n >> m;
    int arr1[n], arr2[m];

    for (i = 0; i < n; i++)
        cin >> arr1[i];
    for (i = 0; i < m; i++)
        cin >> arr2[i];

    merge(arr1, arr2, n, m);

    for (i = 0; i < n; i++)
        cout << arr1[i] << " ";
    for (i = 0; i < m; i++)
        cout << arr2[i] << " ";

    cout << "\n";
    return 0;
}
/*
4 5
1 3 5 7
0 2 6 8 9
0 1 2 3 5 6 7 8 9

we start from end of first array and start of second array
i.e i points to index 3 of first array and j points to index 0 of second array

i=3
j=0

since 7>0 (arr1[n-1]>arr2[0]), we swap both of them, now array becomes

arr1[] = [1 3 5 0]
arr2[] = [7 2 6 8 9]

i=2
j=1

since 5>2

arr1[] = [1 3 2 0]
arr2[] = [7 5 6 8 9]

i=1
j=2
3 is not greater than 6, for-loop breaks and we come out of the loop

*/
