class People:

    def __init__(self, n, a):
        self._name = n
        self._age = a

    def speak(self):
        print("我是 %s, 今年%d岁." % (self._name, self._age))


class Student(People):

    def __init__(self, n, a, g):

        People.__init__(self, n, a)
        self._grade = g

    def speak(self):
        print("我是%s, 今年%d岁, 读%d年级." % (self._name, self._age, self._grade))


if __name__ == '__main__':
    s = Student('he', 10, 4)
    s.speak()
    super(Student, s).speak() ## 调用父类的方法
