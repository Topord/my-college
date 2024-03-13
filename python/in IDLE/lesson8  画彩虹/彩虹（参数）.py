import turtle as t
def rainbow(y,x):
    t.penup()
    t.goto(-250+2*x,0)
    t.pendown()
    if(y==1):#红
        t.color('red','red')
    if(y==2):#橙
        t.color('orange','orange')
    if(y==3):#黄
        t.color('yellow','yellow')
    if(y==4):#绿
        t.color('green','green')
    if(y==5):#蓝
        t.color('blue','blue')
    if(y==6):#靛
        t.color('indigo','indigo')
    if(y==7):#紫
        t.color('purple','purple')
    t.tracer(0)
    t.pensize(25)
    t.setheading(90)
    t.circle(2*x-190,180)
    t.update()
    
rainbow(1,10)
rainbow(2,20)
rainbow(3,30)
rainbow(4,40)
rainbow(5,50)
rainbow(6,60)
rainbow(7,70)

