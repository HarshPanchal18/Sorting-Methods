def quicksort(A, low, high):
    if low < high:
        parti = lomutoPartition(A, low, high)
        quicksort(A, low, parti-1)
        quicksort(A, parti+1, high)


def lomutoPartition(A, low, high):
    pivot = A[high]
    i = low-1

    for j in range(low, high):

        if pivot >= A[j]:
            i += 1
            A[i], A[j] = A[j], A[i]

    A[i+1], A[high] = A[high], A[i+1]
    return i+1


if __name__ == "__main__":
    A = [4, 2, 7, 3, 1, 9, 6, 0, 8]
    low, high = 0, len(A)-1
    print("BEFORE SORTING:", A)
    quicksort(A, low, high)
    print("AFTER SORTING:", A)
