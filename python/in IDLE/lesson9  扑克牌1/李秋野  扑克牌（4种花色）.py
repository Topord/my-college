#--------------------------------------------------------------------------------------------------------------需要用到的函数
def frame():
    t.pencolor('black')
    t.penup()
    t.goto(250,0)
    t.pendown()
    t.setheading(90)
    t.forward(400)
    t.setheading(180)
    t.forward(500)
    t.setheading(-90)
    t.forward(800)
    t.setheading(0)
    t.forward(500)
    t.setheading(90)
    t.forward(400)
def heart1(a,i,j):#---正的爱心     a-->大小  i,j-->位置
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.begin_fill()
    t.color('red')
    t.setheading(115)
    t.circle(a,200)
    t.forward(2*a)
    t.left(90)
    t.forward(2*a)
    t.circle(a,200)
    t.end_fill()
def heart2(r,m,n):#---反的爱心     b-->大小  m,n-->位置
    t.penup()
    t.goto(m,n)
    t.pendown()
    t.begin_fill()
    t.color('red')
    t.setheading(115)
    t.circle(-r,-200)
    t.forward(-2*r)
    t.left(-90)
    t.forward(2*r)
    t.circle(r,200)
    t.end_fill()
def black1(a,i,j):#------------------------------------------------------------------------正的黑桃
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.begin_fill()
    t.color('black')
    t.setheading(115)
    t.circle(-a,-200)#全反
    t.forward(-2*a)#全反
    t.left(-90)#全反
    t.forward(2*a)
    t.circle(a,200)
    t.setheading(180)#0
    t.forward(a/5)
    t.setheading(-90)#全反
    t.forward(a/5)
    t.setheading(90)
    t.circle(a,-60)#全反
    t.setheading(0)#180
    t.forward(a)
    t.setheading(152)
    t.circle(-a,60)
    t.end_fill()
def black2(r,m,n):#-------------------------------------------------------------------------------反黑桃
    t.penup()
    t.goto(m,n)
    t.pendown()
    t.begin_fill()
    t.color('black')
    t.setheading(115)
    t.circle(r,200)
    t.forward(2*r)
    t.left(90)
    t.forward(2*r)
    t.circle(r,200)
    t.setheading(0)
    t.forward(r/5)
    t.setheading(90)
    t.forward(r/5)
    t.setheading(90)
    t.circle(-r,60)
    t.setheading(180)
    t.forward(r)
    t.setheading(152)
    t.circle(r,-60)
    t.end_fill()
def plum1(b,i,j):#--------------------------------------------------正的梅花
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.color('black')
    t.begin_fill()
    t.setheading(90)
    t.circle(b,-60)
    t.setheading(0)
    t.forward(b)
    t.setheading(152)
    t.circle(-b,60)
    t.setheading(-60)
    t.circle(b,240)
    t.setheading(60)
    t.circle(b,240)
    t.setheading(180)
    t.circle(b,240)
    t.end_fill()
def plum2(r,m,n):#-----------------------------------------------------反的梅花
    t.penup()
    t.goto(m,n)
    t.pendown()
    t.color('black')
    t.begin_fill()
    t.setheading(90)
    t.circle(-r,60)
    t.setheading(180)
    t.forward(r)
    t.setheading(152)
    t.circle(r,-60)
    t.setheading(60)
    t.circle(-r,240)
    t.setheading(-60)
    t.circle(-r,240)
    t.setheading(180)
    t.circle(-r,240)
    t.end_fill()
def squ(g,i,j):#-----------------------------------------------------红方
    t.penup()
    t.goto(i,j)
    t.pendown()
    t.color('red')
    t.begin_fill()
    t.setheading(-45)
    t.fd(g)
    t.setheading(-135)
    t.fd(g)
    t.setheading(135)
    t.fd(g)
    t.setheading(45)
    t.fd(g)
    t.end_fill()

def write(type):
    t.pencolor('red')
    t.penup()
    t.goto(-200,380)
    t.pendown()
    t.write(type,move=False,align='center',font=('黑体',50,'normal'))
#---------------------------------------------------------------------------------------------------------------程序
#-----------------------------------------------------------------------------------------数组用于储存红桃的坐标
store=[[0,320,0,-320],[0,300,0,0,0,-300],[-125,195,125,195,-125,-195,125,-195],[-125,195,125,195,0,0,-125,-195,125,-195],[-125,195,125,195,-125,0,125,0,-125,-195,125,-195],[-125,195,125,195,-125,0,0,0,125,0,-125,-195,125,-195],[125,300,125,150,-125,300,-125,150,-125,-150,-125,-300,125,-300,125,-150],[125,300,125,150,-125,300,-125,150,0,-20,-125,-150,-125,-300,125,-300,125,-150],[125,300,125,150,-125,300,-125,150,-130,0,130,0,-125,-150,-125,-300,125,-300,125,-150]]
import turtle as t
color=input('请选择你需要画出的花色（红桃--HT 黑桃--BT  梅花--BF 红方--HS）:')#-----选择花色
type=eval(input('请选择你需要画出的红桃点数((A=1)到10):'))
t.hideturtle()
t.speed(0)
t.screensize(800,800)
frame()
#----------------------------------------------------------------------------------------------------------------------红桃
if(color == 'HT'):
    heart1(10,-200,330)
    heart2(10,200,-330)
    if(type == 1):
        t.pencolor('red')
        heart1(30,0,0)
        t.penup()
        t.goto(-200,340)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(200,-340)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
    else:
        t.pencolor('red')
        t.penup()
        t.goto(-200,340)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(200,-400)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        m = type
        for n in range(0,2*type,2):#---------------------------------------------------用循环读取坐标
            i = store[m-2][n]
            j = store[m-2][n+1]
            heart1(30,i,j)
#----------------------------------------------------------------------------------------------------------------------红方
elif(color == 'HS'):
    squ(25,-200,330)
    squ(25,200,-300)
    if(type == 1):
        t.pencolor('red')
        squ(55,0,0)
        t.penup()
        t.goto(-200,340)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(200,-400)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
    else:
        t.pencolor('red')
        t.penup()
        t.goto(-220,340)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(220,-400)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        m = type
        for n in range(0,2*type,2):
            i = store[m-2][n]
            j = store[m-2][n+1]
            squ(55,i,j)
#----------------------------------------------------------------------------------------------------------------梅花
elif(color == 'BF'):
    plum1(10,-200,320)
    plum2(10,200,-310)
    if(type == 1):
        t.pencolor('black')
        plum1(30,0,0)
        t.penup()
        t.goto(-220,340)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(220,-400)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
    else:
        t.pencolor('black')
        t.penup()
        t.goto(-230,340)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(220,-400)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        m = type
        for n in range(0,2*type,2):#---------------------------------------------------用循环读取坐标
            i = store[m-2][n]
            j = store[m-2][n+1]
            plum1(30,i,j)
#----------------------------------------------------------------------------------------------------------------------黑桃
elif(color == 'BT'):
    black1(10,-200,330)
    black2(10,200,-310)
    if(type == 1):
        t.pencolor('black')
        black1(30,0,0)
        t.penup()
        t.goto(-200,340)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(200,-400)
        t.pendown()
        t.write('A',move=False,align='center',font=('黑体',50,'normal'))
    else:
        t.pencolor('black')
        t.penup()
        t.goto(-200,340)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        t.penup()
        t.goto(200,-400)
        t.pendown()
        t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        m = type
        for n in range(0,2*type,2):#---------------------------------------------------用循环读取坐标
            i = store[m-2][n]
            j = store[m-2][n+1]
            black1(30,i,j)
    
    
            





'''#----------------------------------------------------------------------------------------------------------------------
heart1(10,-200,330)
heart2(10,200,-330)#-------------------------------------------------------------------------框架和小红心
if(type == 1):#--------------------------------------A是特例
    t.pencolor('red')
    heart1(30,0,0)
    t.penup()
    t.goto(-200,340)
    t.pendown()
    t.write('A',move=False,align='center',font=('黑体',50,'normal'))
    t.penup()
    t.goto(200,-340)
    t.pendown()
    t.write('A',move=False,align='center',font=('黑体',50,'normal'))
else:
    t.pencolor('red')
    t.penup()
    t.goto(-200,340)
    t.pendown()
    t.write(type,move=False,align='center',font=('黑体',50,'normal'))
    t.penup()
    t.goto(200,-400)
    t.pendown()
    t.write(type,move=False,align='center',font=('黑体',50,'normal'))
    m = type
    for n in range(0,2*type,2):#---------------------------------------------------用循环读取坐标
        i = store[m-2][n]
        j = store[m-2][n+1]
        heart1(30,i,j)
'''       
        
    
    
