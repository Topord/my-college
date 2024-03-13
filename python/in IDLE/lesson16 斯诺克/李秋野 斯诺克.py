import turtle as t

other=[['black',0,325],['pink',0,20],['blue',0,-80],['orange',0,-200],['green',-80,-200],['yellow',80,-200],['white',0,-280]]
hole=[[-230,350],[230,350],[230,0],[230,-350],[-230,-350],[-230,0]]

t.screensize(500,900)
t.setup(500,900)
t.speed(0)
t.hideturtle()


def redball(x,y):#-----------------------------------红球
    t.pensize(1)
    t.color('red')
    t.penup()
    t.goto(-y*20+(x-1)*40,130+y*35)
    t.pendown()
    t.begin_fill()
    t.circle(20,360)
    t.end_fill()
    t.end_fill()
def otherball():#-----------------------------------------其他颜色的球
    for i in range(len(other)):
        t.color(other[i][0])
        t.penup()
        t.goto(other[i][1],other[i][2])
        t.pendown()
        t.begin_fill()
        t.circle(20)
        t.end_fill()
def desk():#-------------------------------------------桌子
    t.pensize(5)
    t.color('black','lightgreen')
    t.penup()
    t.goto(-200,350)
    t.pendown()
    t.begin_fill()
    t.seth(0)
    t.fd(460)
    t.seth(-90)
    t.fd(700)
    t.seth(180)
    t.fd(460)
    t.seth(90)
    t.fd(700)
    t.end_fill()
def h_line():
    t.pensize(1)
    t.pencolor('black')
    t.penup()
    t.goto(-200,-200)
    t.pendown()
    t.seth(0)
    t.fd(460)
def h_circle():
    t.pensize(1)
    t.pencolor('black')
    t.penup()
    t.seth(90)
    t.goto(-60,-200)
    t.pendown()
    t.circle(-80,-180)
desk()
h_line()
h_circle()
for i in range(5):    
    for j in range(1,i+2):
        redball(j,i)
otherball()
for i in range(6):
    t.penup()
    t.goto(hole[i][0],hole[i][1])
    t.pendown()
    t.color('grey')
    t.begin_fill()
    t.circle(30)
    t.end_fill()
  
