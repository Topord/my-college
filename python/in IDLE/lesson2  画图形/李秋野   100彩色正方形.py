import turtle
a=4
turtle.speed(123)


for i in range(0,25):
    turtle.penup()
    turtle.pencolor('red')
    turtle.goto(a,a)
    turtle.pendown()
    turtle.goto(-a,a)
    turtle.goto(-a,-a)
    turtle.goto(a,-a)
    turtle.goto(a,a)
    a=a+2

    turtle.penup()
    turtle.pencolor('yellow')
    turtle.goto(a,a)
    turtle.pendown()
    turtle.goto(-a,a)
    turtle.goto(-a,-a)
    turtle.goto(a,-a)
    turtle.goto(a,a)
    a=a+2

    turtle.penup()
    turtle.pencolor('green')
    turtle.goto(a,a)
    turtle.pendown()
    turtle.goto(-a,a)
    turtle.goto(-a,-a)
    turtle.goto(a,-a)
    turtle.goto(a,a)
    a=a+2
    
    turtle.penup()
    turtle.pencolor('blue')
    turtle.goto(a,a)
    turtle.pendown()
    turtle.goto(-a,a)
    turtle.goto(-a,-a)
    turtle.goto(a,-a)
    turtle.goto(a,a)
    a=a+2


    
