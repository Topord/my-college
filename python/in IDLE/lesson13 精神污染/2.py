import turtle as t
import random as r
t.hideturtle()
t.speed(0)
t.screensize(800,800)

z = t.xcor()
y = t.ycor()

m = 1
while(m > 0):
    x = r.randint(10,50)#x表示移动的距离
    a = r.randint(0,360)#a表示每次转动的角度
    l = r.randint(1,10)#l表示每次画笔的宽度
    c1 = r.randint(1,6)#c1控制颜色
    c2 = r.randint(1,6)#c2控制背景颜色
    if(c1 == 1):
        t.pencolor('red')
    elif(c1 == 2):
        t.pencolor('orange')
    elif(c1 == 3):
        t.pencolor('green')
    elif(c1 == 4):
        t.pencolor('yellow')
    elif(c1 == 5):
        t.pencolor('blue')
    elif(c1 == 6):
        t.pencolor('purple')

    if(c2 == 1):
        t.bgcolor('red')
    elif(c2 == 2):
        t.bgcolor('orange')
    elif(c2 == 3):
        t.bgcolor('green')
    elif(c2 == 4):
        t.bgcolor('yellow')
    elif(c2 == 5):
        t.bgcolor('blue')
    elif(c2 == 6):
        t.bgcolor('purple')
    t.forward(x)
    t.setheading(a)
    t.pensize(l)
    if(z > 400  and y > 400):#超出第一象限
        t.goto(x,x)
    elif(z < -400 and y > 400):#超出第二象限
        t.goto(x,x)
    elif(z < -400 and y < -400):#第三项限
        t.goto(x,x)
    elif(z > 400 and y < -400):
        t.goto(x,x)
        
        
     



    
