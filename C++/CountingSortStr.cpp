#include <iostream>

using namespace std;

void countSort(string arr)
{
    string output;
    int count[256];

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; arr[i]; i++)
        ++count[arr[i]];

    for (int i = 1; i < 256; i++)
        count[i] += count[i - 1];

    for (int i = 0; arr[i]; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; arr[i]; i++)
        arr[i] = output[i];

    cout << "\nSorted Array: " << arr << endl;
}

int main(void)
{
    string arr;
    cout << "\nEnter string arr: ";
    cin >> arr;
    countSort(arr);
}

/*
Enter string arr: 23451094026
Sorted Array: 00122344569
*/
