#include <iostream>
#include <algorithm>

#define fors(x, n, m) for (int x = n; x < m; x++)

using namespace std;

void sortPairs(int arr[], char ch[], int n)
{
    pair<int, char> sortingArr[n];

    // for (int i = 0; i < n; i++)
    fors(i, 0, n)
        sortingArr[i] = {arr[i], ch[i]};

    sort(sortingArr, sortingArr + n);

    // for (int i = 0; i < n; i++)
    fors(i, 0, n)
            cout
        << sortingArr[i].second << " ";
}

void sortPairs(char ch[], int arr[], int n)
{
    pair<int, char> sortingArr[n];

    // for (int i = 0; i < n; i++)
    fors(i, 0, n)
        sortingArr[i] = {arr[i], ch[i]};

    sort(sortingArr, sortingArr + n);

    // for (int i = 0; i < n; i++)
    fors(i, 0, n)
            cout
        << sortingArr[i].first << " ";
}

int main(void)
{
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int ar[] = {2, 3, 8, 1, 5};

    sortPairs(ar, arr, 5);

    cout << endl;

    sortPairs(arr, ar, 5);
}

/*
d a b e c 
1 2 3 5 8 
*/
