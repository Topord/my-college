import datetime as dt
import turtle as t
stor={'0':[0,1,1,1,1,1,1],'1':[0,1,0,0,0,0,1],'2':[1,0,1,1,0,1,1],\
       '3':[1,1,1,0,0,1,1],'4':[1,1,0,0,1,0,1],'5':[1,1,1,0,1,1,0],\
       '6':[1,1,1,1,1,1,0],'7':[0,1,0,0,0,1,1],'8':[1,1,1,1,1,1,1],\
       '9':[1,1,1,0,1,1,1]}
#2022-2-8
t.tracer(0)
t1=t.Pen()
t2=t.Pen()
t1.pensize(5)
t1.penup()
t1.goto(-250,0)
t1.pendown()
t1.speed(0)
t1.hideturtle()

def jd(bh):  #--------------------------------判断
    t1.pendown() if bh==1 else t1.penup()
def num(n):
    t.seth(0)
    n = str(n)
    for i in range(3):#                ---
        jd(stor[n][i])
        t1.fd(20)
        t1.right(90)
    for j in range(3,5):
        jd(stor[n][j])
        t1.fd(20)
    t1.right(90)
    for k in range(5,6):
        jd(stor[n][k])
        t1.fd(20)
        t1.right(90)
    jd(stor[n][6])
    t1.fd(20)
    t1.seth(0)
    t1.penup()
    t1.fd(30)
    t1.pendown()
def week(get):
    t1.penup()
    t1.goto(-100,-100)
    t1.pendown()
    if(get == 0): t1.write('星期一', font=("",30, "normal"))
    elif(get == 1): t1.write('星期二', font=("",30, "normal"))
    elif(get == 2): t1.write('星期三', font=("",30, "normal"))
    elif(get == 3): t1.write('星期四', font=("",30, "normal"))
    elif(get == 4): t1.write('星期五', font=("",30, "normal"))
    elif(get == 5): t1.write('星期六', font=("",30, "normal"))
    elif(get == 6): t1.write('星期日', font=("",30, "normal"))
tm = dt.datetime.today()
to = str(tm)[:-16]
print(to)
for i in range(10):
    if i == 4: continue
    elif i == 5: continue
    elif i == 7:
        t1.penup()
        t1.seth(-90)
        t1.fd(5)
        t1.pendown()
        t1.seth(0)
        t1.fd(20)
        t1.penup()
        t1.seth(90)
        t1.fd(5)
        t1.seth(0)
        t1.fd(10)
        t1.pendown()
        continue
    else:
        n = to[i]
        n = int(n)
        num(n)
    if i == 3:
        t1.penup()
        t1.seth(-90)
        t1.fd(5)
        t1.pendown()
        t1.seth(0)
        t1.fd(20)
        t1.penup()
        t1.seth(90)
        t1.fd(5)
        t1.seth(0)
        t1.fd(10)
        t1.pendown()
get = int(tm.weekday())
week(get)
t2.goto(-50,-200)
t2.pendown()
while 1:
    tm = dt.datetime.today()
    time=str(tm)[11:13]+'时'+str(tm)[14:16]+'分'+str(tm)[17:19]+'秒'
    t2.write(time,align="center",font=("",40))
    t2.clear()


    
