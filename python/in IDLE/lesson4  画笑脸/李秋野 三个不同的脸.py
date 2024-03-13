import turtle as t
def face():
    t.speed(500)
    t.color('yellow','yellow')
    t.begin_fill()
    t.circle(100)
    t.end_fill()
    '''大圆'''
def mouth(z):
    if(z==0):
     t.setheading(90)
     t.penup()
     t.forward(50)
     t.pendown()
     t.setheading(0)
     t.pensize(5)
     t.pencolor('black')
     t.circle(50,60)
     t.circle(50,-120)
     t.circle(50,60)
    '''上扬'''
    if(z==1):
     t.setheading(90)
     t.penup()
     t.forward(50)
     t.pendown()
     t.setheading(180)
     t.pensize(5)
     t.pencolor('black')
     t.circle(50,60)
     t.circle(50,-120)
     t.circle(50,60)
    '''下撇'''
    if(z==3):
        t.setheading(0)
        t.pencolor('yellow')
        t.forward(20)
        t.pencolor('black')
        t.circle(20)
    
def eyes(x):
    t.setheading(90)
    t.pencolor('yellow')
    t.penup()
    t.forward(75)
    t.pendown()
    t.setheading(0)
    t.forward(75/x)
    t.color('white')
    t.begin_fill()
    t.circle(35/x)
    t.end_fill()
    '''右眼白'''
    t.color('black')
    t.begin_fill()
    t.circle(25/x)
    t.end_fill()
    '''右眼球'''
    t.setheading(180)
    t.penup()
    t.forward(65)
    t.pendown()
    t.color('white')
    t.setheading(0)
    t.begin_fill()
    t.circle(35/x)
    t.end_fill()
    '''左眼白'''
    t.color('black')
    t.begin_fill()
    t.circle(25/x)
    t.end_fill()
    '''左眼球'''
def smile(x,z):
    face()
    mouth(z)
    eyes(x)
'''打包笑脸'''

t.penup()
t.goto(-150,0)
t.pendown()
smile(2,1)
'''第一个'''
t.penup()
t.goto(150,0)
t.pendown()
smile(2,0)
'''第二个'''
t.penup()
t.goto(0,-200)
t.pendown()
smile(1,3)
'''第三个'''











