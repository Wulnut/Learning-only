"""
def deco(func):
    def modify_text(str):
        return "<strong>" + func(str) + "</strong>"
    return modify_text

@deco
def textFunc(str):
    return str

print(textFunc("text"))
"""

"""
def num(func):
    def nums(a):
        return 4 + a
    return nums

@num
def add(b):
    print("here")
    b += 2
    return b

print(add(2))
"""

"""
def DECO(args):
    def deco(func):
        def call_func(x,y):
            print("%d %s %d = " % (x,args,y),end = ' ')
            return func(x,y)
        return call_func
    return deco

@DECO('&')
def andFunc(x,y):
    return x & y

@DECO('|')
def orFunc(x,y):
    return x | y

#_name_ = "_main_"

if __name__ == "__main__": #__main__ 下划线是双下划线
    print(andFunc(5,6))
    print(orFunc(5,6))
"""

"""
class car:
    def __init__(self,name):
        self.name = name
    
    def getName(self):
        return self.name

c1 = car("ok")

print("This is :",c1.getName())
"""

