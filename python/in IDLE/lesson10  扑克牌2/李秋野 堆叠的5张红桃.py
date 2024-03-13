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
#----------------------------------------------------------------------------------------------------------------红桃5
frame(-400,0,0)#边框开始的位置，此后依次向右平移50个单位长度
heart(10,-650,160,1)#左上角的爱心
write(-650,170,5)#左上角的数字
#----------------------------------------------------------------------------------------------------------------红桃4
frame(-350,0,0)
heart(10,-600,160,1)#左上角的爱心
write(-600,170,4)#左上角的数字
#----------------------------------------------------------------------------------------------------------------红桃3
frame(-300,0,0)
heart(10,-550,160,1)#左上角的爱心
write(-550,170,3)#左上角的数字
#----------------------------------------------------------------------------------------------------------------红桃2
frame(-250,0,0)
heart(10,-500,160,1)#左上角的爱心
write(-500,170,2)#左上角的数字
#----------------------------------------------------------------------------------------------------------------红桃A
frame(-200,0,1)
heart(10,-450,160,1)#左上角的爱心
heart(30,-310,30,1)#最左边那张牌中间大的红心
heart(10,-210,-220,-1)#右下角的爱心
write(-450,170,1)#左上角的字母
write(-210,-260,1)#右下角的字母





