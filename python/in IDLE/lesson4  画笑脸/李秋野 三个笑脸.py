import turtle as t
def face():
    t.speed(500)
    t.penup()
    t.pendown()
    t.color('yellow','yellow')
    t.begin_fill()
    t.circle(100)
    t.end_fill()
    '''大圆'''
def mouth():
    t.setheading(90)
    t.penup()
    t.forward(50)
    t.pendown()
    t.setheading(0)
    t.pensize(5)
    t.pencolor('black')
    t.circle(50,60)
    t.circle(50,-120)
    '''嘴'''
def eyes():
    t.circle(50,60)
    t.setheading(90)
    t.pencolor('yellow')
    t.penup()
    t.forward(75)
    t.pendown()
    t.setheading(0)
    t.forward(37.5)
    t.color('white')
    t.begin_fill()
    t.circle(17.5)
    t.end_fill()
    '''右眼白'''
    t.color('black')
    t.begin_fill()
    t.circle(12.5)
    t.end_fill()
    '''右眼球'''
    t.setheading(180)
    t.penup()
    t.forward(65)
    t.pendown()
    t.color('white')
    t.setheading(0)
    t.begin_fill()
    t.circle(17.5)
    t.end_fill()
    '''左眼白'''
    t.color('black')
    t.begin_fill()
    t.circle(12.5)
    t.end_fill()
    '''左眼球'''
def smile():
    face()
    mouth()
    eyes()
'''打包笑脸'''

t.penup()
t.goto(-150,0)
t.pendown()
smile()
'''第一个'''
t.penup()
t.goto(150,0)
t.pendown()
smile()
'''第二个'''
t.penup()
t.goto(0,-200)
t.pendown()
smile()
'''第三个'''











