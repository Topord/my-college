import turtle as t
t.screensize(800,800)
t.hideturtle()
t.speed(0)
t.tracer(0)


'''BH列表表示卡牌中大图案的坐标,2对为一个'''
BH=[[-530,130],#卡片A
    [-230,100,-230,-100],#卡片2
    [80,120,80,-10,80,-170],#卡片3
    [280,130,280,-130,380,130,380,-130],#卡片4
    [530,150,630,150,530,-110,630,-110,580,20]]#卡片5


'''函数体'''
def frame(x,y):#-------------------------------画边框
    t.pencolor('black')
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.setheading(90)
    t.forward(200)
    t.setheading(180)
    t.forward(250)
    t.setheading(-90)
    t.forward(400)
    t.setheading(0)
    t.forward(250)
    t.setheading(90)
    t.forward(200)
def heart(a,i,j,l):#--------------画爱心的程序     a-->相对大小  i,j-->位置   l=1 正 l=-1 反
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.begin_fill()
    t.color('red')
    t.setheading(115)
    t.circle(l*a,l*200)
    t.forward(2*a*l)
    t.left(90*l)
    t.forward(2*a)
    t.circle(a,200)
    t.end_fill()
def black(q,w,e,k):#---------------------------------黑桃      q-->相对大小  w,e-->位置   k=1 正 k=-1 反
    if(k == 1):
        t.penup()
        t.goto(w,e)
        t.pendown()
        t.begin_fill()
        t.color('black')
        t.setheading(115)
        t.circle(-q,-200)
        t.forward(-2*q)
        t.left(-90)
        t.forward(2*q)
        t.circle(q,200)
        t.setheading(180)
        t.forward(q/5)
        t.setheading(-90)
        t.forward(q/5)
        t.setheading(90)
        t.circle(q,-60)
        t.setheading(0)
        t.forward(q)
        t.setheading(152)
        t.circle(-q,60)
        t.end_fill()
    else:
        t.penup()
        t.goto(w,e)
        t.pendown()
        t.begin_fill()
        t.color('black')
        t.setheading(115)
        t.circle(q,200)
        t.forward(2*q)
        t.left(90)
        t.forward(2*q)
        t.circle(q,200)
        t.setheading(0)
        t.forward(q/5)
        t.setheading(90)
        t.forward(q/5)
        t.setheading(90)
        t.circle(-q,60)
        t.setheading(180)
        t.forward(q)
        t.setheading(152)
        t.circle(q,-60)
        t.end_fill()
def plum(s,d,f,g):#--------------------------------------------------梅花  s-->相对大小  d,f-->位置   g=1 正 g=-1 反
    if(g == 1):
        t.penup()
        t.goto(d,f)
        t.pendown()
        t.color('black')
        t.begin_fill()
        t.setheading(90)
        t.circle(s,-60)
        t.setheading(0)
        t.forward(s)
        t.setheading(152)
        t.circle(-s,60)
        t.setheading(-60)
        t.circle(s,240)
        t.setheading(60)
        t.circle(s,240)
        t.setheading(180)
        t.circle(s,240)
        t.end_fill()
    else:
        t.penup()
        t.goto(d,f)
        t.pendown()
        t.color('black')
        t.begin_fill()
        t.setheading(90)
        t.circle(-s,60)
        t.setheading(180)
        t.forward(s)
        t.setheading(152)
        t.circle(s,-60)
        t.setheading(60)
        t.circle(-s,240)
        t.setheading(-60)
        t.circle(-s,240)
        t.setheading(180)
        t.circle(-s,240)
        t.end_fill()
def squ(z,v,b):#-------------------------------------------红方    s-->相对大小  v,b-->位置  
    t.penup()
    t.goto(v,b)
    t.pendown()
    t.color('red')
    t.begin_fill()
    t.setheading(-45)
    t.fd(z)
    t.setheading(-135)
    t.fd(z)
    t.setheading(135)
    t.fd(z)
    t.setheading(45)
    t.fd(z)
    t.end_fill()
def write(o,p,b):#-----------打印数字或字母的程序        (o,p)表示位置坐标;b--表示将要打印数字的参数
    t.penup()
    t.goto(o,p)
    t.pendown()
    if(b == 1):
        t.pencolor('red')
        t.write('A',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 2):
        t.pencolor('black')
        t.write('2',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 3):
        t.pencolor('black')
        t.write('3',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 4):
        t.pencolor('black')
        t.write('4',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 5):
        t.pencolor('red')
        t.write('5',move=False,align='center',font=('黑体',20,'normal'))



'''画图程序'''
#---------------------------------------------------------------------------------------------------------------红桃A
frame(-400,0)#边框开始的位置
heart(10,-630,160,1)#左上角的心
heart(20,-530,20,1)#中间的大心
heart(10,-430,-155,-1)#右下角的心
write(-630,170,1)
write(-430,-190,1)
#---------------------------------------------------------------------------------------------------------------黑桃2
frame(-100,0)#边框开始的位置
black(10,-330,130,1)#左上角的黑桃
black(10,-130,-130,-1)#右下角的黑桃
for n in range(0,4,2):
        i = BH[1][n]
        j = BH[1][n+1]
        black(20,i,j,1)
write(-330,170,2)
write(-130,-190,2)
#----------------------------------------------------------------------------------------------------------------梅花3
frame(200,0)#边框开始的位置
plum(6,-30,140,1)#左上角的梅花
plum(6,180,-130,-1)#右下角的梅花
for n in range(0,6,2):
        i = BH[2][n]
        j = BH[2][n+1]
        plum(15,i,j,1)
write(-30,170,3)
write(180,-190,3)
#----------------------------------------------------------------------------------------------------------------红桃4
frame(450,0)#边框开始的位置
heart(10,220,160,1)#左上角的心
heart(10,430,-150,-1)#右下角的心
for n in range(0,8,2):
        i = BH[3][n]
        j = BH[3][n+1]
        heart(20,i,j,1)
write(220,170,4)
write(430,-190,4)
#----------------------------------------------------------------------------------------------------------------红桃5
frame(700,0)#边框开始的位置
squ(15,470,160)#左上角的红方
squ(15,680,-140)#右下角的红方
for n in range(0,10,2):
        i = BH[4][n]
        j = BH[4][n+1]
        squ(50,i,j)
write(470,170,5)
write(680,-190,5)

t.update()


