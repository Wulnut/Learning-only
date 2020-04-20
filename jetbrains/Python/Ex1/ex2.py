import numpy as np

m = 2
n = 3

# 创建二维数组
test = np.zeros((m, n), dtype = np.int)

print(test)

print()

temp = 1

for i in range(2):
    for j in range(3):
        test[i][j] = temp
        temp += 1

print(test)