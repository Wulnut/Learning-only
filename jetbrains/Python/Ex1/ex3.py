# 快速排序

list = list([8, 2, 1, 3, 5])

N = list.__len__()

print("排序前：", end = ' ')

for i in range(N):
    print(list[i], end = ' ')

print()

for i in range(N - 1):
    min = i

    for j in range(i + 1, N):
        if list[min] > list[j]: min = j

    list[i], list[min] = list[min], list[i] # 交换

print('排序之后：', end = ' ')

for i in range(N):
    print(list[i], end = ' ')