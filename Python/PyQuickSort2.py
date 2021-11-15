def quicksort(arr, start, end):
    if end-start > 1:
        p = partition(arr, start, end)
        quicksort(arr, start, p)
        quicksort(arr, p+1, end)


def partition(arr, start, end):
    pivot = arr[start]
    i = start+1
    j = end-1

    while True:
        while(i <= j and arr[i] <= pivot):
            i = i+1
        while(i <= j and arr[j] > pivot):
            j = j-1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            arr[start], arr[j] = arr[j], arr[start]
            return j


arrlist = [41, 62, 20, 48, 96, 37, 55]
quicksort(arrlist, 0, len(arrlist))
print("Sorted List: ", end="")
print(arrlist)
