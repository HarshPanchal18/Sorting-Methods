list = [14, 6, 8, 7, 20, 47]

for i in range(len(list)):
    for j in range(i):
        if(int(list[j]) > int(list[j+1])):
            list[j], list[j+1] = list[j+1], list[j]

print(list)
