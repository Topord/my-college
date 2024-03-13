import turtle as t
t.hideturtle()
t.speed(0)
t.screensize(800,800)
#-----------------------------------------------------------------------------------------数组用于储存红桃的坐标
store=[[0,320,0,-320],[0,300,0,0,0,-300],[-125,195,125,195,-125,-195,125,-195],[-125,195,125,195,0,0,-125,-195,125,-195],[-125,195,125,195,-125,0,125,0,-125,-195,125,-195],[-125,195,125,195,-125,0,0,0,125,0,-125,-195,125,-195],[125,300,125,150,-125,300,-125,150,-125,-150,-125,-300,125,-300,125,-150],[125,300,125,150,-125,300,-125,150,0,-20,-125,-150,-125,-300,125,-300,125,-150],[125,300,125,150,-125,300,-125,150,-130,0,130,0,-125,-150,-125,-300,125,-300,125,-150]]
type=eval(input('请选择你需要画出的红桃点数((A=1)到10):'))
frame()
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
def write(type):
    t.pencolor('red')
    t.penup()
    t.goto(-200,380)
    t.pendown()
    t.write(type,move=False,align='center',font=('黑体',50,'normal'))
        
    
    
