import turtle as t
t1=t.Pen()                 #引入画笔1  大圆/小圆/百分号
t2=t.Pen()                 #引入画笔2  写字
t3=t.Pen()                 #引入画笔3  进度条
t1.hideturtle()            
t2.hideturtle()
t3.hideturtle()
t.setup(800,800)
t.screensize(800,800,'black')

def b_circle():
    t1.pensize(10)
    t1.pencolor('white')
    t1.penup()
    t1.goto(0,300)
    t1.pendown()
    t1.speed(0)
    t1.pensize(1)
    t1.circle(-300,-360)
def s_circle():
    t1.pensize(10)
    t1.pencolor('white')
    t1.penup()
    t1.goto(0,240)
    t1.pendown()
    t1.speed(0)
    t1.pensize(1)
    t1.circle(-240,-360)
    
def percent():
    t1.pencolor('white')
    t1.penup()
    t1.goto(70,320)
    t1.pendown()
    t1.write('%',align='center',font=('黑体',20,'normal'))

def write(m):#写字
    t2.speed(1)
    t2.pencolor('white')
    t2.penup()
    t2.goto(30,320)
    t2.pendown()
    t2.write(m,'%',align='right',font=('黑体',20,'normal'))
def red():
    t3.speed(1)
    t3.pencolor('red')
    t3.pensize(50)
    t3.circle(-270,3.6)

b_circle()
s_circle()
percent()
t3.penup()
t3.goto(0,270)
t3.pendown()
x = 1
while(x >= 0):
    m = x
    write(m)
    red()
    x = x + 1
    t2.clear()
    if(x > 100):
        t2.write('100',align='center',font=('黑体',20,'normal'))
        break
    

