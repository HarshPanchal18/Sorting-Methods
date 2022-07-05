# Python program for implementation of MergeSort
# Merge Sort is a Divide and Conquer algorithm.
# It divides input array in two halves, calls itself for the two halves
# and then merges the two sorted halves.
# The merge() function is used for merging two halves.

def mergeSort(arr):
    if(len(arr) > 1):
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        mergeSort(L)
        mergeSort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while(i < len(L)):  # Checking if any element was left
            arr[k] = L[i]
            i += 1
            k += 1

        while(j < len(R)):  # Checking if any element was left
            arr[k] = R[j]
            j += 1
            k += 1

# Code to print the list


def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()


arr = [1, 12, 11, 2, 13, 5, 6, 7, 3]
print("Given array is: ", end="\n")
printList(arr)

mergeSort(arr)

print("Sorted array is: ", end="\n")
printList(arr)

'''
Given array is: 
1 12 11 2 13 5 6 7 3 
Sorted array is:     
1 2 3 5 6 7 11 12 13
'''
