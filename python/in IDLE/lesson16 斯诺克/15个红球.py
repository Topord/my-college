import turtle as t
ball=[["red",-80,200]]
t.speed(0)
t.hideturtle()
def pos(x):
    t.penup()
    t.goto(ball[0][1]+20*(6-x),ball[0][2]-35*(6-x))
    t.setheading(0)
    t.color(ball[0][0])
    t.pendown()
pos(6)
for i in range(5,0,-1):
    for j in range(i):
        t.begin_fill()
        t.circle(20)
        t.end_fill()
        t.penup()
        t.fd(40)
        t.pendown()
    pos(i)
        



    

        
    
