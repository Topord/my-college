import turtle as t
ball = [-50,0]
#------------------------------------5个红球
t.color('red','red')
t.penup()
t.goto(-50,0)
t.pendown()
t.hideturtle()
t.speed(0)
for i in range(1,6):
    t.begin_fill()
    t.circle(20,360)
    t.end_fill()
    t.penup()
    t.setheading(0)
    t.fd(40)
    t.pendown()
    
