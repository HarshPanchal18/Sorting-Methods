def prepare(numbers, low, high):
    pivot = numbers[high]
    item = low - 1

    for i in range(low, high):
        if numbers[i] <= pivot:
            item = item + 1
            (numbers[item], numbers[i]) = (numbers[i], numbers[item])
    (numbers[item + 1], numbers[high]) = (numbers[high], numbers[item + 1])
    return item + 1


def quick_sort(numbers, low, high):
    if low < high:
        pivot = prepare(numbers, low, high)
        quick_sort(numbers, low, pivot - 1)
        quick_sort(numbers, pivot + 1, high)


arr = [8, 4, 59, 74, 64, 20, 1, 3]

quick_sort(arr, 0, len(arr) - 1)

print(arr)
