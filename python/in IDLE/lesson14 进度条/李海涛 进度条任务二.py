import turtle as t
import random as r

t1=t.Pen()
t2=t.Pen()
a=0

def delay_forawrd():
    t2.speed(0)
    t2.forward(7.5)
    
t.setup(1000,300)
t.screensize(950,250,'black')
t1.hideturtle()
t2.hideturtle()

t1.color('white')
t2.color('white')

t2.speed(0)
t2.penup()
t2.goto(-350,-50)
t2.pendown()
t2.setheading(180)
for i in range(2):
    t2.circle(-25,180)
    t2.forward(750)

t1.penup()
t1.goto(-15,20)
t1.pendown()
t2.penup()
t2.goto(-350,-25)
t2.pendown()


while 1:
    t2.setheading(0)
    t2.pensize(35)
    delay_forawrd()
    
    t1.clear()
    t1.write('{}%'.format(a), font=("",30, "normal"))
    a+=1
    if a==100:
        break
    

t1.clear()
t1.write('{}%'.format(100), font=("",30, "normal"))
    
    


