import turtle
a=10
turtle.pensize(1)
turtle.speed(123)

for i in range(50):
    turtle.penup()
    turtle.goto(a,0)
    turtle.pendown()
    turtle.goto(0,a)
    turtle.goto(-a,0)
    turtle.goto(0,-a)
    turtle.goto(a,0)
    a=a+5
    
    
   
