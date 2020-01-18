"""
def IsEvenFunc(n):
    return n % 2 == 0

a = list(filter(IsEvenFunc,[1,2,3,4,5]))

print("a: ",a)
"""

"""
a = list(zip(["泰山","黄山","庐山","华山"],["山东","安徽","江西","陕西"])) #打包
print("a: ",a)

z = zip([1,2,3],[4,5,6]) #打包
a = list(zip(*z)) #解包

print("a: ",a)
"""

"""
weeks = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday','saturday']
a = list(enumerate(weeks))
print("a: ",a)
"""

"""
def cube(x):
    return x ** 3

a = list(map(cube,[1,2,3,4,5,6])) #计算列表中的各个元素的立方和

print("a: ",a)

def add(x, y):
    return x + y

a = list(map(add,[1,2,3,4,5],[1,2,3,4,5])) #两个列表中相同位置的元素相加

print("a: ",a)

a,b = map(int, input("请输入两个数(用空格隔开):").split())

print("a = %d, b = %d."%(a,b))
"""



