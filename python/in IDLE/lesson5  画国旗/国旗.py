import turtle as t
t.speed(0)
t.setup(900,600)
t.penup()
t.goto(-400,250)
t.color('red')
t.begin_fill()
t.setheading(0)
t.forward(750)
t.right(90)
t.forward(500)
t.right(90)
t.forward(750)
t.right(90)
t.forward(500)
t.end_fill()#画国旗

t.setheading(-90)
t.penup()
t.forward(100)
t.pendown()
t.setheading(0)
t.penup()
t.forward(40)
t.pendown()

t.color('yellow')
t.begin_fill()
for i in range(5):
    t.forward(100)
    t.right(144)
t.end_fill()#画一颗大的星星
#打包
def star(x,y):
    t.color('yellow')
    t.begin_fill()
    t.setheading(x)
    for i in range(5): 
        t.forward(y)
        t.right(144)
    t.end_fill()

t.setheading(0)
t.penup()
t.forward(150)
t.pendown()
t.setheading(90)

t.speed(0)
t.pencolor('red')
t.circle(75,60)
star(-10,45)#第一颗

t.setheading(-90)
t.penup()
t.circle(75,60)
t.pendown()
star(15,45)#第二颗

t.setheading(-90)
t.penup()
t.circle(-75,50)
t.pendown()
star(0,45)#第三颗

t.setheading(-100)
t.penup()
t.circle(-75,50)
t.pendown()
star(-25,45)#第四颗








