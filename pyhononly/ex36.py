"""
n = int(input("请输入一个整数: "))

flag = str(n) + " 是偶数!"

if n % 2 != 0:
    flag = str(n) + " 是偶数!"

print(flag)
"""

"""
a = 5
b = 6

print("a = %d, b = %d" % (a,b))

if a > b:
    max = a
else: 
    max = b

print(max)
"""

"""
score = int(input("请输入成绩:"))

if score >= 90:
    print("成绩等级:优秀！")
elif score >= 80:
    print("成绩等级：良好！")
elif score >= 60:
    print("成绩等级：不合格！")
"""

"""
score = int(input("Please enter:"))

flag = "ok" if score >= 60 else "no"

print("score: ",flag)
"""

"""
a = 3; b = 2; c = 4

if a > b:
    if a > c:
        print("最大的数是：", a)
    else:
        print("最大的数是：", c)
else:
    if b > c:
        print("最大的数是: ", b)
    else:
        print("最大的数是: ", c)
"""

"""
n = 100
sum = 0
i = 1

while i <= n:
    sum = sum + i
    i += 1

print("1到%d之和为: %d." % (n,sum))
"""

"""
mu1 = 1; i = 1; sum = 0

while i <= 10:
    mu1 = mu1 * i
    sum = sum + mu1
    i = i + 1
else:
    print("循环结束!")

print("sum =", sum)
"""

"""
total = 0; ave = 0; count = 0

score = int(input("请输入学生英语成绩: "))
print("输入'-1'结束输入\n")

while score != -1:
    total = total + score
    count = count + 1
    score = int(input("请输入学生英语成绩: "))

ave = total / count
print("录入学生英语成绩%d份,学生英语总成绩%d，平均成绩%4.2f." % (count, total, ave))
"""

"""
for letter in 'python':
    print(letter, end=' ')

print() #起到换行作用

chemists = ['道尔顿','门捷列夫','拉瓦锡','诺贝尔']

print("化学家:",end=' ')

for hxj in chemists:
    print(hxj, end=' ')
"""

"""
universities = ['哈弗大学','斯坦福大学','剑桥大学','麻省理工学院','加州大学','普林斯顿大学','牛津大学','哥伦比亚大学','加州理工学院','芝加哥大学']

print("2017《Times》世界大学排名前三的大学是：")

for i in range(3):
    print(str(i+1) + ".", universities[i])
"""

"""
for i in range(1,6):
    for j in range(i):
        print("*", end=' ')
    print() #该print是属于  第一层循环
"""