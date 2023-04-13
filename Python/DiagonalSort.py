def sortDiagonal(a, M, N):
    # Loop to find the ith minimum
    # element from the major diagonally
    for i in range(M):
        sm = a[i][i]
        pos = i

        # Loop to find the minimum
        # element from the unsorted matrix
        for j in range(i+1, N):
            if sm >= a[j][j]:
                sm = a[j][j]
                pos = j

        # Swap to put the minimum
        # element at the beginning of
        # the major diagonal of matrix
        a[i][i], a[pos][pos] = a[pos][pos], a[i][i]

    # Loop to print the matrix
    for i in range(M):
        for j in range(N):
            print(a[i][j], end=" ")
        print()


'''
It loops through the major diagonal of the matrix, from the top left to the bottom right (line 6-8).
For each element on the major diagonal, it finds the minimum element from the remaining unsorted elements in the diagonal (lines 10-14).
If a smaller element is found, it swaps the current element with the minimum element to put the minimum element at the beginning of the major diagonal (line 15).
Finally, the function prints the sorted matrix, with the major diagonal elements sorted in ascending order (lines 18-21).
'''

a = [[4, 2, 5], [3, 1, 5], [9, 8, 4]]
sortDiagonal(a, 3, 3)

#b = [[7, 2, 3], [3, 1, 6], [9, 8, 4]]
#sortDiagonal(b, 3, 3)

'''
[[4, 2, 5], [3, 1, 6], [9, 8, 7]]
1 2 5
3 4 6
9 8 7

[[4, 2, 5], [3, 1, 5], [9, 8, 4]]
1 2 5
3 4 5
9 8 4
'''
