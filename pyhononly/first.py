#turtle海龟库
import turtle
turtle.setup(650, 350, 200, 200)
#turtle.setup(width, height, startx, starty)
#电脑屏幕的左上角为坐标系的（0，0）
turtle.penup()
turtle.fd(-250)
#fd 正前方进行
#kb 反方行前进
#circle（r, angle）弧度方向
turtle.pendown()
turtle.pensize(25)
turtle.pencolor("purple")
turtle.seth(-40)
#seth方向旋转角度
for i in range(4):
    turtle.circle(40, 80)
    turtle.circle(-40, 80)
turtle.circle(40, 80/2)
turtle.fd(40)
turtle.circle(16, 100)
turtle.fd(40*2/3)
turtle.done()
