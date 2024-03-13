import turtle as t
t.setup(900,600)
#打包国旗
def flag(a,b,d):
    t.hideturtle()
    t.speed(0)
    t.penup()
    t.goto(a,b)
    t.color('red')
    t.begin_fill()
    t.setheading(0)
    t.forward(750/d)
    t.right(90)
    t.forward(500/d)
    t.right(90)
    t.forward(750/d)
    t.right(90)
    t.forward(500/d)
    t.end_fill()#画国旗
    t.setheading(-90)
    t.penup()
    t.forward(100/d)
    t.pendown()
    t.setheading(0)
    t.penup()
    t.forward(40/d)
    t.pendown()
    
#打包大星
def big_star(c):
    t.color('yellow')
    t.begin_fill()
    for i in range(5):
        t.forward(100/c)
        t.right(144)
    t.end_fill()#画一颗大的星星

#打包复星
def fu_star(e):
    t.setheading(0)
    t.penup()
    t.forward(150/e)
    t.pendown()
    t.setheading(90)
    t.speed(0)
    t.pencolor('red')
    t.circle(75/e,60)
    t.color('yellow')
    t.begin_fill()
    t.setheading(-10)
    for i in range(5): 
        t.forward(45/e)
        t.right(144)
    t.end_fill()#第一颗
    t.setheading(-90)
    t.penup()
    t.circle(75/e,60)
    t.pendown()
    t.color('yellow')
    t.begin_fill()
    t.setheading(15)
    for i in range(5): 
        t.forward(45/e)
        t.right(144)
    t.end_fill()#第二颗
    t.setheading(-90)
    t.penup()
    t.circle(-75/e,50)
    t.pendown()
    t.color('yellow')
    t.begin_fill()
    t.setheading(0)
    for i in range(5): 
        t.forward(45/e)
        t.right(144)
    t.end_fill()#第三颗
    t.setheading(-100)
    t.penup()
    t.circle(-75/e,50)
    t.pendown()
    t.color('yellow')
    t.begin_fill()
    t.setheading(-25)
    for i in range(5): 
        t.forward(45/e)
        t.right(144)
    t.end_fill()#第四颗

#对整个国旗进行打包
def total_flag(a,b,d,c,e):#a,b为国旗的初始位置；c为大星的缩小比列 d为国旗的缩小比例 e为副星的缩小比例
    flag(a,b,d,)
    big_star(c)
    fu_star(e)

total_flag(-200,200,4,4,4)
total_flag(100,100,2,2,2)






