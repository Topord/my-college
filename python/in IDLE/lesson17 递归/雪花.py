import turtle as t
t.penup()
t.goto(-200,100)
t.pendown()
t.pencolor('red')
t.pensize(3)
def koch(lenth, n):
    if(n == 0):
        t.fd(lenth)
    else:
        for angle in [0, 60, -120, 60]:
            t.left(angle)
            koch(lenth/3, n-1)
koch(300,3)
t.right(120)
koch(300,3)
t.right(120)
koch(300,3)
t.right(120)
