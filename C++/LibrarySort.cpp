#include <algorithm>
#include <iostream>

void librarySort(int *index, int n)
{
    int libSize, indexPos;
    int *gaps, *library[2];

    bool targetLib, *numbered;

    for (int i = 0; i < 2; i++)
        library[i] = new int[n];

    gaps = new int[n + 1];
    numbered = new bool[n + 1];

    libSize = 1;
    indexPos = 1;
    targetLib = 0;
    library[targetLib][0] = index[0];

    while (indexPos < n)
    {
        int insert = std::distance(library[targetLib],
                                   std::lower_bound(library[targetLib], library[targetLib] + libSize, index[indexPos]));

        // if there is no gap to insert a new node
        if (numbered[insert] == true)
        {
            int provSize = 0, nextTargetLib = !targetLib;

            // update library and close gap
            for (int i = 0; i <= n; i++)
            {
                if (numbered[i] == true)
                {
                    library[nextTargetLib][provSize] = gaps[i];
                    provSize++;
                    numbered[i] = false;
                }

                if (i <= libSize)
                {
                    library[nextTargetLib][provSize] = library[targetLib][i];
                    provSize++;
                }
            }
            targetLib = nextTargetLib;
            libSize = provSize - 1;
        }
        else
        {
            numbered[insert] = true;
            gaps[insert] = index[indexPos];
            indexPos++;
        }
    }

    int indexPosForOutput = 0;
    for (int i = 0; indexPosForOutput < n; i++)
    {
        if (numbered[i] == true)
        {
            // std::cout << gaps[i] << std::endl;
            index[indexPosForOutput] = gaps[i];
            indexPosForOutput++;
        }

        if (i < libSize)
        {
            // std::cout << library[target_lib][i] << std::endl;
            index[indexPosForOutput] = library[targetLib][i];
            indexPosForOutput++;
        }
    }
}

int main(void)
{
    int arr[] = {5, 9, 2, 3, 7, 0, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    librarySort(arr, n);

    std::cout << "\nSorted : ";

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}
