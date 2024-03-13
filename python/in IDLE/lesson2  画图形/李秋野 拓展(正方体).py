import turtle

a=100
b=300
c=200
d=5
turtle.speed(0)
'''正方体的棱长'''
turtle.penup()
turtle.goto(-a,a)
turtle.pendown()

turtle.right(90)
turtle.forward(b)
turtle.left(90)
turtle.forward(b)
turtle.left(90)
turtle.forward(b)
turtle.left(90)
turtle.forward(b)
turtle.right(135)
turtle.forward(c)
turtle.right(45)
turtle.forward(b)
turtle.right(135)
turtle.forward(c)
turtle.left(45)
turtle.forward(b)
turtle.left(135)
turtle.forward(c)
turtle.left(45)
turtle.forward(b)
'''画实体框架'''

turtle.left(90)
turtle.forward(b)
turtle.left(90)
for i in range(30):
    turtle.penup()
    turtle.forward(d)
    turtle.pendown()
    turtle.forward(d)
    
turtle.left(90)
for i in range(30):
    turtle.penup()
    turtle.forward(d)
    turtle.pendown()
    turtle.forward(d)
turtle.penup()
turtle.left(180)
turtle.forward(b)
turtle.pendown()

turtle.left(45)
for i in range(20):
    turtle.penup()
    turtle.forward(d)
    turtle.pendown()
    turtle.forward(d)
'''画虚体框架'''








