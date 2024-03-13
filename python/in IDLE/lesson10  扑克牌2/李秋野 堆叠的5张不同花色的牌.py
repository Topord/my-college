import turtle as t
t.screensize(800,800)
t.hideturtle()
t.speed(0)
'''函数体'''
def frame(x,y,z):#----------画边框的程序（长：宽=500:400）
    #(x,y)表示边框最右边那条线的终点，z是否为1表示是否画出最右边的边框
    t.pencolor('black')
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.setheading(90)
    t.penup()
    t.forward(200)
    t.pendown()
    t.setheading(180)
    t.forward(250)
    t.circle(30,90)#画圆角边框
    t.setheading(-90)
    t.forward(400)
    t.circle(30,90)
    t.setheading(0)
    t.forward(250)
    if(z == 1):#如果z=1,则最后一张牌的边框完整的，否则像其他的一样呈遮掩状态
        t.circle(30,90)
        t.setheading(90)
        t.forward(400)
        t.circle(30,90)
def heart(a,i,j,l):#--------------画爱心的程序     a-->相对大小  i,j-->位置   l=1 正
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
def plum(s,d,f):#--------------------------------------------------梅花  s-->相对大小  d,f-->位置  
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
def write(o,p,b):#-----------打印数字或字母的程序        (o,p)表示位置坐标;b--表示将要打印数字的参数
    t.pencolor('red')
    t.penup()
    t.goto(o,p)
    t.pendown()
    if(b == 1):
        t.color('black')
        t.write('A',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 2):
        t.color('black')
        t.write('2',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 3):#--------------------------------------------------------------小王
        t.color('black')
        t.write('J',move=False,align='center',font=('宋体',20,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(20)
        t.write('O',move=False,align='center',font=('宋体',15,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(20)
        t.write('K',move=False,align='center',font=('宋体',15,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(20)
        t.write('E',move=False,align='center',font=('宋体',15,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(20)
        t.write('R',move=False,align='center',font=('宋体',15,'normal'))
    elif(b == 4):
        t.write('4',move=False,align='center',font=('宋体',15,'normal'))
    elif(b == 5):
        t.write('5',move=False,align='center',font=('宋体',15,'normal'))
    elif(b == 6):#--------------------------------------------------------------大王
        t.color('red')
        t.write('J',move=False,align='center',font=('黑体',25,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(25)
        t.write('O',move=False,align='center',font=('黑体',25,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(25)
        t.write('K',move=False,align='center',font=('黑体',25,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(25)
        t.write('E',move=False,align='center',font=('黑体',25,'normal'))
        t.penup()
        t.setheading(-90)
        t.forward(25)
        t.write('R',move=False,align='center',font=('黑体',25,'normal'))

'''画图程序'''
#----------------------------------------------------------------------------------------------------------------红桃5
frame(-400,0,0)#边框开始的位置，此后依次向右平移50个单位长度
heart(10,-650,160,1)#左上角的爱心
write(-650,170,5)#左上角的数字
#----------------------------------------------------------------------------------------------------------------红方4
frame(-350,0,0)
squ(25,-600,165)#左上角的方块
write(-600,170,4)#左上角的数字
#----------------------------------------------------------------------------------------------------------------小王
frame(-300,0,0)
write(-550,170,3)#左上角的字母
#----------------------------------------------------------------------------------------------------------------梅花2
frame(-250,0,0)
plum(10,-500,130)#左上角的梅花
write(-500,170,2)#左上角的数字
#----------------------------------------------------------------------------------------------------------------大王
frame(-200,0,0)
write(-450,170,6)#左上角的字母
#----------------------------------------------------------------------------------------------------------------黑桃A
frame(-150,0,1)
black(10,-400,130,1)#左上角的黑桃
black(30,-280,-50,1)#最左边那张牌中间大的黑桃
black(10,-160,-190,-1)#右下角的黑桃
write(-400,170,1)#左上角的字母
write(-160,-260,1)#右下角的字母





