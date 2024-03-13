import turtle
a=4

for i in range(12):
    turtle.penup()
    turtle.color('green')
    turtle.goto(a,a)
    turtle.pendown()
    turtle.goto(-a,a)
    turtle.goto(-a,-a)
    turtle.goto(a,-a)
    turtle.goto(a,a)
    a=a+8


    

    



    
