import turtle as t
import random as r

pen_color=['red','orange','green','yellow','blue','purple']     #将笔的颜色保存在数组中
screen_color=['red','orange','green','yellow','blue','purple']  #将背景的颜色保存在数组中

t1=t.Pen()                 #引入画笔1
t2=t.Pen()                 #引入画笔2
t1.hideturtle()            #隐藏画笔1
t2.hideturtle()            #隐藏画笔2
t.screensize(800,800)      #设置画布大小
t.setup(800,800)           #设置窗口大小
t1.speed(50)               #调整画笔1速度
t2.speed(50)               #调整画笔2速度

m = 1
while(m > 0):              #m>0恒成立，故可以一直画
    
    d = r.randint(10,20)           #d表示移动的距离
    a = r.randint(180,181)           #a表示每次转动的角度
    l = r.randint(1,10)            #l表示每次画笔的宽度
    c1 = r.randint(0,5)            #c1控制画笔颜色
#--------------------------------------------------------------------------------------------------------------画笔1
    t1.pencolor(pen_color[c1])     #画笔1的颜色
    t1.pensize(l)                  #画笔1的粗细
    t1.forward(d)                  #画笔1前进的距离
    t1.setheading(a)               #画笔1转动的角度
    if((t1.xcor() > 400 or t1.xcor() < -400) and -310 < t1.ycor() < 310):#对画笔1的限制
        t1.goto(d,d)
        m = 1
    elif((t1.ycor() > 310 or t1.ycor() < -310) and -400 < t1.xcor() < 400):
        t1.goto(d,d)
        m = 1


#------------------------------------------------------------------------------------------------------------画笔2
    t2.pencolor(pen_color[c1])
    t2.pensize(l)
    t2.forward(2*m)
    t2.left(40)
    m = m + 0.3 #每次循环使m递增,让画笔2画螺旋
    
    if((t2.xcor() >400 or t2.xcor() < -400) and -310 < t2.ycor() < 310):#对画笔2的限制
        t2.goto(d,d)
        m = 1
    elif((t2.ycor() > 310 or t2.ycor() < -310) and -400 < t2.xcor() < 400):
        t2.goto(d,d)
        m = 1

#---------------------------------------------------------------------------------------------------------------背景 
    c3 = r.randint(1,3) #c3为背景出现的次数
    while(c3 > 0):
        c2 = r.randint(0,5)#背景随机选择
        t.bgcolor(screen_color[c2])
        c3 = c3 - 1                 #背景每变成一种颜色，就将这个颜色执行C3遍，从而达到随机背景随机时间
   

    
