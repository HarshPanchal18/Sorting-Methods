def seleectionSort(arr):
    for i in range(0, len(arr)-1):
        smallest = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[smallest]:
                smallest = j
        arr[i], arr[smallest] = arr[smallest], arr[i]


alist = input("Enter the numbers: ").split()
# 50 870 20 67 34
# (Space between numbers)
alist = [int(x) for x in alist]
seleectionSort(alist)
print("Sorted List ", end="")
print(alist)
