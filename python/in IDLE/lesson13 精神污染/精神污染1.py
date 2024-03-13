import turtle as t
import random as r

t.speed(0)
m = 1
while(m > 0):
    x = r.randint(10,30)#x表示移动的距离
    a = r.randint(0,360)#a表示每次转动的角度
    l = r.randint(1,10)#l表示每次画笔的宽度
    c = r.randint(1,6)#c控制颜色

    if(c == 1):
        t.pencolor('red')
    elif(c == 2):
        t.pencolor('orange')
    elif(c == 3):
        t.pencolor('green')
    elif(c == 4):
        t.pencolor('yellow')
    elif(c == 5):
        t.pencolor('blue')
    elif(c == 6):
        t.pencolor('purple')
    t.forward(x)
    t.setheading(a)
    t.pensize(l)




    
