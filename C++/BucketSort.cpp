#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> *b = new vector<float>[n]; // create N empty buckets

    for (int i = 0; i < n; i++) // put array element in different bucket
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) // sort individual bucket
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];

    // delete[] b;
}

int main(void)
{
    int n;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    float arr[n];
    cout << "\nEnter " << n << " elements (<1 and >0):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr, n);

    cout << "\nSorted array:";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
}

/*
Enter the number of elements: 5
Enter 5 elements:
0.7 0.9 0.4 0.28 0.6
Sorted array: 0.28 0.4 0.6 0.7 0.9
*/