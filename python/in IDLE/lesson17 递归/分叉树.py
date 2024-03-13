import turtle as t
t.hideturtle()e
t.speed(0)
t.pensize(1)
t.pencolor('green')
t.penup()
t.goto(0,-300)
t.pendown()
t.seth(90)
 
def tree(n,x):#n表示距离，x表示次数
    if(x > 0):
        t.fd(n)
        t.left(30)
        tree(0.8*n, x-1)
        t.right(60)
        tree(0.8*n, x-1)
        t.left(30)
        t.backward(n) 
tree(150,5)
