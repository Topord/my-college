import turtle
a=5
n=1
turtle.pensize(1)
turtle.speed(500)
turtle.penup()
turtle.goto(-150,-150)
turtle.pendown()

turtle.right(45)
for i in range(90):     
    turtle.forward(a)
    turtle.left(n)

turtle.left(70)
turtle.forward(400)

turtle.left(123)
turtle.forward(430)

turtle.left(165)
for i in range(44):
    turtle.penup()
    turtle.forward(a)
    turtle.right(n)
    turtle.pendown()
    turtle.forward(a)
    turtle.right(n)
    
    
