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

score = int(input("Please enter:"))

flag = "ok" if score >= 60 else "no"

print("score: ",flag)
