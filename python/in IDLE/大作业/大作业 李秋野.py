import datetime as dt
import math
import turtle as t

#-----------------------------------------------------------------------------------------------------------------------------计算天数
months = [0,31,59,90,120,151,181,212,243,273,304,334]
#--------------------------------------------------------------------------------------获取当天的时间（精准到日）
today = dt.datetime.today()

today_year = str(today)[:-22]#-----------------------当今年份
today_month = str(today)[6:-19]#---------------------当今月份
today_day = str(today)[8:-15]#-----------------------当今日期

today_year = int(today_year)#------------------------转为int,便于计算
today_month  = int(today_month)#---------------------转为int,便于计算
today_day  = int(today_day)#-------------------------转为int,便于计算
print(today)
#---------------------------------------------------------------------------------------获取用户的出生年月日
year_differ_day = 0
use_year = input("请输入你出生的年份：")
use_month = input("请输入你出生的月份：")
use_day = input("请输入你出生的日期：")

use_year = int(use_year)#----------------------------转为int,便于计算
use_month = int(use_month)#--------------------------转为int,便于计算
use_day = int(use_day)#------------------------------转为int,便于计算

def now_day(today_month,today_day):#用来计算这个月你存活的天数
    if 0 <= today_month <= 12:
        add = months[today_month - 1]
    else:
        print ('输入错误')
    add += today_day
    return add

def before_day(use_month,use_day):#用来计算你从出生到第一年的存活天数
    if 0 <= use_month <= 12:
        add = months[use_month - 1]
    else:
        print ('输入错误')
    add += use_day
    if (use_month % 400 == 0) or ((use_month % 4 == 0) and (use_month % 100 != 0)):
        add = 366 - add
    else:
        add = 365 - add
    return add

def year_day(use_year,today_year):#用来计算你中间年份的存活天数
    global year_differ_day
    while(use_year < today_year - 1):
        if (use_year % 400 == 0) or ((use_year % 4 == 0) and (use_year % 100 != 0)):
            year_differ_day += 366
            use_year += 1
        else:
            year_differ_day += 365
            use_year += 1
    return year_differ_day

def all_day(sum1,sum2,differ_day):#计算你从出生到现在存活的天数
    all_day = sum1 + sum2 + differ_day
    print('您已存活{}天'.format(all_day))
    return all_day

sum1 = now_day(today_month,today_day) 
sum2 = before_day(use_month,use_day)
year_differ_day = year_day(use_year,today_year)
all_day = all_day(sum1,sum2,year_differ_day)

#此时  all_day表示用户从出生到目前出生的天数

#----------------------------------------------------------------------------------------------------------------------------画图
t.screensize(800,800)
t.setup(800,800)
t.tracer(0)
t1 = t.Pen()#t1-draw
t2 = t.Pen()#t2-write
t1.hideturtle()
t1.speed(0)

t2.hideturtle()
t2.speed(0)

def sin(move):#用来画正弦函数
    i=-218
    t1.penup()
    t1.goto(-318,299.2-move)
    t1.pendown()
    while(i<=-4):
        i = i + 0.1
        y = -60*math.sin(0.06*i+0.5)
        t1.goto(i-100,y+300-move)
def x_arrow(move):#X轴的箭头
    t1.pensize(3)
    t1.penup()
    t1.goto(-90,299.2-move)
    t1.pendown()
    t1.seth(160)
    t1.fd(10)
    t1.seth(-20)
    t1.fd(10)
    t1.seth(-160)
    t1.fd(10)
    t1.pensize(1)
def y_arrow(move):#Y轴的箭头
    t1.pensize(3)
    t1.penup()
    t1.goto(-213,382.2-move)
    t1.pendown()
    t1.seth(-70)
    t1.fd(10)
    t1.seth(110)
    t1.fd(10)
    t1.seth(-110)
    t1.fd(10)
    t1.pensize(1)
def axis(move):#二维平面坐标系
    t1.penup()
    t1.goto(-318,299.2-move)
    t1.pendown()
    t1.seth(0)
    t1.fd(228)
    t1.seth(180)
    t1.fd(124)
    t1.seth(90)
    t1.fd(80)
    t1.seth(-90)
    t1.fd(160)
def all_axis():#三个完整的二维平面坐标系
    x_arrow(0)
    y_arrow(0)
    x_arrow(250)
    y_arrow(250)
    x_arrow(500)
    y_arrow(500)
    axis(0)
    axis(250)
    axis(500)
sin(0)
sin(250)
sin(500)
all_axis()
#--------------------------------------------------------------------------------------------------------------------------------算周期
#体力
py_T = all_day//23    #处于第几个周期
py_day = all_day%23   #处于第几个周期的第几天
#情绪
em_T = all_day//28
em_day = all_day%28
#智力
in_T = all_day//33
in_day = all_day%33
#----------------------------------------------------------------------------------------------------------------------------------结合
def information(x,y,sign):#写是什么波形图
    t1.penup()
    t1.goto(x,y)
    t1.pendown()
    t1.pencolor('black')
    t1.write('{}周期波形图'.format(sign), font=('华文行楷',15,'normal'))
def write_T(move,num):#在波形图上写出是第几个周期
    t1.penup()
    t1.goto(-265,299.2-move)
    t1.pendown()
    t1.pencolor('blue')
    t1.dot(6)
    t1.pencolor('black')
    t1.penup()
    t1.goto(-320,310-move)
    t1.pendown()
    t1.write('{}周期'.format(num), font=("",10, "normal"))
def py_write_date(DAY1,move):#在波形图上表明当前日期的位置              DAY1表达当前在周期内的第几天
    x1 = -265 + DAY1*4.95
    t1.penup()
    t1.goto(x1,299.2-move)
    t1.pencolor('red')
    t1.dot(6)
    t1.pencolor('black')
    t1.pendown()
    t1.penup()
    t1.pencolor('red')
    t1.goto(x1-30,270.2-move)
    t1.pendown()
    t1.write('{}月{}日'.format(today_month,today_day))
    return x1
def em_write_date(DAY1,move):#在波形图上表明当前日期的位置              DAY1表达当前在周期内的第几天
    x1 = -270 + DAY1*4.07
    t1.penup()
    t1.goto(x1,299.2-move)
    t1.pencolor('red')
    t1.dot(6)
    t1.pencolor('black')
    t1.pendown()
    t1.penup()
    t1.pencolor('red')
    t1.goto(x1-30,270.2-move)
    t1.pendown()
    t1.write('{}月{}日'.format(today_month,today_day))
    return x1
def in_write_date(DAY1,move):#在波形图上表明当前日期的位置              DAY1表达当前在周期内的第几天
    x1 = -265 + DAY1*3.45
    t1.penup()
    t1.goto(x1,299.2-move)
    t1.pencolor('red')
    t1.dot(6)
    t1.pencolor('black')
    t1.pendown()
    t1.penup()
    t1.pencolor('red')
    t1.goto(x1-30,270.2-move)
    t1.pendown()
    t1.write('{}月{}日'.format(today_month,today_day))
    return x1
def dotline(x1,move,jd):#画虚线，用虚线之间的区域表达前后10天的情况    
    t1.penup()
    t1.goto(x1,299.2-move)
    t1.pendown()
    t1.pensize(2)
    if(jd == 0):
        t1.pencolor('darkred')
    elif(jd == 1):
        t1.pencolor('blue')
    for i in range(14):
        t1.seth(90)
        t1.penup()
        t1.forward(3)
        t1.pendown()
        t1.forward(2)
    t1.penup()
    t1.goto(x1,299.2-move)
    t1.pendown()
    for i in range(14):
        t1.seth(-90)
        t1.penup()
        t1.forward(3)
        t1.pendown()
        t1.forward(2)
    t1.pensize(1)
#体力周期图
information(-370,360,'体力')
write_T(0,py_T)
py_write_date(py_day,0)
x = py_write_date(py_day,0)
dotline(x,0,1)
dotline(x-10*4.95,0,0)
dotline(x+10*4.95,0,0)
#情绪周期图
information(-370,130,'情绪')
write_T(250,em_T)
em_write_date(em_day,250)
x = em_write_date(em_day,250)
dotline(x,250,1)
dotline(x-10*4.07,250,0)
dotline(x+10*4.07,250,0)
#智力周期波形图
information(-370,-120,'智力')
write_T(500,in_T)
in_write_date(in_day,500)
x = in_write_date(in_day,500)
dotline(x,500,1)
dotline(x-10*3.45,500,0)
dotline(x+10*3.45,500,0)
#------------------------------------------------------------------------------------------------------------------------写字部分
def writecontent(move,content1,content2,content3):#content1-什么周期    content2-第几个   content3-第几天
    t2.penup()
    t2.goto(-360,220-move)
    t2.pendown()
    t2.pencolor('steelblue')
    t2.write('您正处于{}节律中的第{}个周期的第{}天'.format(content1,content2,content3), font=("华文行楷",13, "normal"))
    t2.pencolor('black')
def writedetail(types,day,move):#准确描述当前日期处于周期的位置并对前后10天进行说明
    t2.penup()                  #types-什么周期  day-当天日期在周期中的第几天
    t2.goto(-50,360-move)
    t2.pendown()
    if types == '体力':
        if day == 0 or day == 23:
            cir = 11.5
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif 0 < day < 6:
            cir = 6 - day
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif day == 6:
            t2.write('您正处于{}节律中的巅峰期，珍惜机会哦'.format(types), font=("方正姚体",13, "normal"))
        elif 6 < day < 18:
            cir = 23 - day
            t2.write('您正处于{}节律中的过渡区，刚从顶峰下来,可能在'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}方面会感觉到不适应。调整好状态，{}天就可以进入下'.format(types,cir), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,300-move)
            t2.pendown()
            t2.write('一个周期啦!', font=("方正姚体",13, "normal"))
        elif day == 18:
            t2.write('您正处于{}节律中的低谷，加油，怎么走都是向上！'.format(types), font=("方正姚体",13, "normal"))
        elif 18 <day < 23:
            cir = 23 - day + 5
            t2.write('您正处于{}节律中的过渡区，刚从低谷出来。调整好状态，'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}此后{}天内都是上升趋势!'.format(types,cir), font=("方正姚体",13, "normal"))
    elif types == '情绪':
        if day == 0 or day == 28:
            cir = 7
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif 0 < day < 6:
            cir = 7 - day
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif day == 7:
            t2.write('您正处于{}节律中的巅峰期，珍惜机会哦'.format(types), font=("方正姚体",13, "normal"))
        elif 7 < day < 21:
            cir = 28 - day
            t2.write('您正处于{}节律中的过渡区，刚从顶峰下来，可能在'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}方面会感觉到不适应。调整好状态,{}天就可以进入下'.format(types,cir), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,300-move)
            t2.pendown()
            t2.write('一个周期啦！', font=("方正姚体",13, "normal"))
        elif day == 21:
            t2.write('您正处于{}节律中的低谷，加油，怎么走都是向上！'.format(types), font=("方正姚体",13, "normal"))
        elif 21 <day < 28:
            cir = 28 - day + 7
            t2.write('您正处于{}节律中的过渡区，刚从低谷出来。调整好状态，'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}此后{}天内都是上升趋势！'.format(types,cir), font=("方正姚体",13, "normal"))
    elif types == '智力':
        if day == 0 or day == 33:
            cir = 8
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif 0 < day < 8:
            cir = 8 - day
            t2.write('您正处于{}节律周期的开始，会在{}天内到达顶峰'.format(types,cir), font=("方正姚体",13, "normal"))
        elif day == 8:
            t2.write('您正处于{}节律中的巅峰期，珍惜机会哦'.format(types), font=("方正姚体",13, "normal"))
        elif 8 < day < 25:
            cir = 33 - day
            t2.write('您正处于{}节律中的过渡区，刚从顶峰下来，可能在'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}方面会感觉到不适应。调整好状态，{}天就可以进入下'.format(types,cir), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,300-move)
            t2.pendown()
            t2.write('一个周期啦！', font=("方正姚体",13, "normal"))
        elif day == 25:
            t2.write('您正处于{}节律中的低谷，加油，怎么走都是向上'.format(types), font=("方正姚体",13, "normal"))
        elif 25 <day < 33:
            cir = 33 - day + 8
            t2.write('您正处于{}节律中的过渡区，刚从低谷出来。调整好状态，'.format(types), font=("方正姚体",13, "normal"))
            t2.penup()
            t2.goto(-80,330-move)
            t2.pendown()
            t2.write('{}此后{}天内都是上升趋势！'.format(types,cir), font=("方正姚体",13, "normal"))
def des_dotline(move):#对虚线的解释
    t2.penup()
    t2.goto(-80,250-move)
    t2.pendown()
    t2.pencolor('tomato')
    t2.write('(红色虚线内的图像是对前后10天节律变化描述)', font=("方正姚体",13, "normal"))
    t2.pencolor('black')
def decorate(x,y,color):#将3个分区隔离开
    t1.pencolor(color)
    t1.penup()
    t1.goto(x,y)
    t1.pendown()
    t1.seth(0)
    for i in range(50):
        t1.fd(8)
        t1.penup()
        t1.fd(8)
        t1.pendown()
#体力周期描述
writecontent(30,'体力',py_T,py_day)
writedetail('体力',py_day,0)
des_dotline(0)
#情绪周期描述
writecontent(280,'情绪',em_T,em_day)
writedetail('情绪',em_day,250)
des_dotline(250)
#智力周期描述
writecontent(530,'智力',in_T,in_day)
writedetail('智力',in_day,500)
des_dotline(500)
decorate(-400,165,'blue')
decorate(-400,-85,'blue')
decorate(-400,-335,'blue')
t.tracer(1)
