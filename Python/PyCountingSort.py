def CountingSort(a1, max):
    m = max+1
    count = [0]*m

    for a in a1:
        count[a] += 1
    i = 0
    for a in range(m):
        for c in range(count[a]):
            a1[i] = a
            i += 1
    return a1


list = [1, 5, 8, 2, 4, 8, 7, 11, 15, 20, 9]
print(CountingSort(list, max(list)))
