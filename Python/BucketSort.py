def insertion(b):
    for i in range(1, len(b)):
        up = b[i]
        j = i-1
        while j >= 0 and b[j] > up:
            b[j+1] = b[j]
            j -= 1
        b[j+1] = up
    return b


def bucketSort(x):
    arr = []
    slot = 10  # 10 means 10 slots, each slot's size is 0.1
    for i in range(slot):
        arr.append([])

    for j in x:  # put array element in different bucket
        index = int(slot*j)
        arr[index].append(j)

    for i in range(slot):  # sort individual bucket
        arr[i] = insertion(arr[i])

    k = 0
    for i in range(slot):  # concatenate the results
        for j in range(len(arr[i])):
            x[k] = arr[i][j]
            k += 1

    return x


x = [0.84, 0.68, 0.71, 0.28, 0.59]

print(bucketSort(x))
