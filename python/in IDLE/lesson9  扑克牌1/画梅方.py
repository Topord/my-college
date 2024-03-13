import turtle as t
t.hideturtle()
def squ(g,i,j):
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.color('red')
    t.begin_fill()
    t.setheading(-45)
    t.fd(g)
    t.setheading(-135)
    t.fd(g)
    t.setheading(135)
    t.fd(g)
    t.setheading(45)
    t.fd(g)
    t.end_fill()

