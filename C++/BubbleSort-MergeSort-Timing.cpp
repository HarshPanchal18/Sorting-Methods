#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int main(void)
{
    int n;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    int a[100000];
    // create a reverse sorted array for the worst case
    for (int i = 0; i < n; i++)
        a[i] = n - i;

    time_t start = clock();
    bubbleSort(a, n);
    time_t end = clock();

    cout << "\nBubble Sort Time: " << end - start << endl;

    // create a reverse sorted array for the worst case
    for (int i = 0; i < n; i++)
        a[i] = n - i;

    start = clock();
    sort(a, a + n);
    end = clock();

    cout << "\nMerge Sort Time: " << end - start << endl;
}

/*
Enter the number of elements: 10000
Bubble Sort Time: 386
Merge Sort Time: 1
*/
