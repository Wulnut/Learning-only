#python 绘图
import matplotlib.pyplot as plt
import numpy as np
import math

"""
n = 512 #数据个数

x = np.random.normal(0, 1, n) #均值为0，方差为1的随机数
y = np.random.normal(0, 1, n)  #均值为0，方差为1的随机数

color = np.arctan2(y, x) #计算颜色值

plt.scatter(x, y, s = 75, c = color, alpha = 0.6) #绘制散点图

plt.xlim((-2.0,2.0))
plt.ylim((-2.0,2.0))

plt.show()
"""

def main():
    x = np.linspace(1, 200, 50)

    y1 = [a ** 3 * math.log(a, 2) for a in x]

    plt.plot(x ,y1, linewidth = 2, color = '#007500', label = 'x^4*log2(x)')

    #plt.plot([1,1], [y1[0], y1[1]], "r--", linewidth = 2) #在坐标1处描红

    y2 = [a ** 4 for a in x]
    plt.plot(x, y2, linewidth = 2, color = '#9F35FF', label = 'x^4')


    plt.legend(loc='lower right')
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()