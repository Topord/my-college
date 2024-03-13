import turtle as t
t.screensize(800,800)
t.hideturtle()
t.speed(0)
'''BH列表表示卡牌中(大红心)的坐标,2对为一个'''
BH=[[-530,130],#卡片A
    [-230,100,-230,-100],#卡片2
    [80,150,80,20,80,-140],#卡片3
    [280,130,280,-130,380,130,380,-130],#卡片4
    [530,130,630,130,530,-130,630,-130,20,580]]#卡片5
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
def write(o,p,b):#-----------打印数字或字母的程序        (o,p)表示位置坐标;b--表示将要打印数字的参数
    t.pencolor('red')
    t.penup()
    t.goto(o,p)
    t.pendown()
    if(b == 1):
        t.write('A',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 2):
        t.write('2',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 3):
        t.write('3',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 4):
        t.write('4',move=False,align='center',font=('黑体',20,'normal'))
    elif(b == 5):
        t.write('5',move=False,align='center',font=('黑体',20,'normal'))

'''画图程序'''
#---------------------------------------------------------------------------------------------------------------红桃A
frame(-400,0)#边框开始的位置
heart(10,-630,160,1)
heart(20,-530,20,1)
heart(10,-430,-155,-1)
write(-630,170,1)
write(-430,-190,1)
#----------------------------------------------------------------------------------------------------------------红桃2
frame(-100,0)#边框开始的位置
heart(10,-330,160,1)
heart(10,-130,-160,-1)
for n in range(0,4,2):
        i = BH[1][n]
        j = BH[1][n+1]
        heart(20,i,j,1)
write(-330,170,2)
write(-130,-190,2)
#----------------------------------------------------------------------------------------------------------------红桃3
frame(200,0)#边框开始的位置
heart(10,-30,160,1)
heart(10,180,-160,-1)
for n in range(0,6,2):
        i = BH[2][n]
        j = BH[2][n+1]
        heart(20,i,j,1)
write(-30,170,3)
write(180,-190,3)
#----------------------------------------------------------------------------------------------------------------红桃4
frame(450,0)
heart(10,220,160,1)
heart(10,430,-150,-1)
for n in range(0,8,2):
        i = BH[3][n]
        j = BH[3][n+1]
        heart(20,i,j,1)
write(220,170,4)
write(430,-190,4)
#----------------------------------------------------------------------------------------------------------------红桃5
frame(700,0)#边框开始的位置
heart(10,470,160,1)
heart(10,680,-150,-1)
for n in range(0,10,2):
        i = BH[4][n]
        j = BH[4][n+1]
        heart(20,i,j,1)
write(470,170,5)
write(680,-190,5)




