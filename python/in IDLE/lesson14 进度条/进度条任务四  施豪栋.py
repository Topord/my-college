ss=['L','o','a','d','i','n','g','.','.','.','']
import turtle as t
import random as r
t.bgcolor('cornflowerblue')
t.setup(800,300)
t.screensize(750,250)
t1=t.Pen()
t2=t.Pen()
t3=t.Pen()
t1.hideturtle()
t2.hideturtle()
t3.hideturtle()
t2.speed(0)
def zi():#数字
    if a<=100:
        t1.clear()
    t1.penup()
    t1.goto(-250+(a+1)*5,32)
    t1.pendown()
    t1.seth(90)
    t1.fd(15)
    t1.write('{}%'.format(a),align='center',font=('华文琥珀',34))    
def jd():#进度条
    r,g,b=1,a/100,a/100
    t2.penup()
    t2.color((r,g,b))
    t2.goto(-250+a*5,12)
    t2.seth(0)
    t2.pendown()
    t2.pensize(22)
    t2.goto(-250+a*5,12)
def tiao():#时间调整
    sj=r.randint(0,20)
    for i in range(sj):
        t2.penup()
        t2.goto(0,0)
        t2.circle(10)
def kuang(a,b):#进度条框
    t2.pensize(a)
    t2.color(b)
    t2.penup()
    t2.goto(-250,-5)
    t2.seth(180)
    t2.pendown()
    for j in range(2):
        t2.circle(-16.5,180)
        t2.fd(500)
def load():#loading
    t3.clear()
    global s
    global j
    t3.penup()
    t3.goto(0,-64)
    t3.pendown()
    s+=ss[j]
    j+=1
    if j>10:
        j-=11
        s=''
    if a<100:
        t3.write(s,align='center',font=('华文琥珀',30))
    else:
        t3.clear()
        t3.write('Load complete',align='center',font=('华文琥珀',30))
j=0
s=''
for a in range(101):
    zi()
    t.tracer(0)
    jd()
    kuang(3.5,'black')
    kuang(1,'lightgrey')
    load()
    t.tracer(1)
    tiao()
