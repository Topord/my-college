import turtle as t
t1=t.Pen()                 #引入画笔1
t2=t.Pen()                 #引入画笔2
t3=t.Pen()
t1.hideturtle()            
t2.hideturtle()
t3.hideturtle()
t.setup(900,300)
t.screensize(900,300,'black')

def squ():#进度条的正方形
    t1.speed(0)
    t1.color('black','white')
    t1.begin_fill()
    t1.fd(10)
    t1.right(90)
    t1.fd(20)
    t1.right(90)
    t1.fd(10)
    t1.right(90)
    t1.fd(20)
    t1.end_fill()
def write(m):#写字
    t2.speed(1)
    t2.color('white')
    t2.write(m,align='center',font=('黑体',20,'normal'))
def percent():
    t3.color('white')
    t3.write('%',align='center',font=('黑体',20,'normal'))
x = 0
t1.penup()
t1.goto(-250,0)
t1.pendown()
t2.penup()
t2.goto(0,50)
t2.pendown()
t3.penup()
t3.goto(40,50)
t3.pendown()
while(x >= 0):
    percent()
    m = x
    write(m)
    squ()
    t1.setheading(0)
    t1.penup()
    t1.fd(20)
    t1.pendown()
    x = x + 4
    t2.clear()
    t2.penup()
    t2.goto(0,50)
    t2.pendown()
    if(x > 100):
        t2.write('100',align='center',font=('黑体',20,'normal'))
        break
    
