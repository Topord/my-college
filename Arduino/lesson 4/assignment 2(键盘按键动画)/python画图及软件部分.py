import turtle as t
import serial
from time import sleep

#--------------------------------------------------------------------------------------------------------------------画图部分
#初始化画布大小、背景颜色、画笔颜色
t.screensize(800,800)
t.setup(800,800)
#引入3个画笔
t1 = t.Pen()             #t1用来画键盘
t2 = t.Pen()             #t2用来写字
t3 = t.Pen()             #t3用来表示按下和松开的状态
t1.hideturtle()
t2.hideturtle()
t3.hideturtle()
t1.pencolor('black')
t2.pencolor('black')
t3.pencolor('black')
t1.pensize(5)
t3.pensize(5)
t1.speed(0)
t3.speed(0)
#画键盘--------------------------------------------------------------------------------------------------main()
def button(x, y):             #按钮
    t1.penup()
    t1.goto(x, y)
    t1.pendown()
    t1.setheading(0)
    t1.fd(75)
    t1.right(90)
    t1.fd(150)
    t1.right(90)
    t1.fd(150)
    t1.right(90)
    t1.fd(150)
    t1.right(90)
    t1.fd(75)
def mark(i,j):
    t3.color('black','red')
    t3.penup()
    t3.goto(i, j)
    t3.pendown()
    t3.begin_fill()
    t3.setheading(0)
    t3.fd(75)
    t3.right(90)
    t3.fd(150)
    t3.right(90)
    t3.fd(150)
    t3.right(90)
    t3.fd(150)
    t3.right(90)
    t3.fd(75)
    t3.end_fill()
    

def main():                   #键盘 
    button(-285,360)        #1
    button(-95,360)         #2
    button(95,360)          #3
    button(285,360)         #A
    button(-285,190)        #4
    button(-95,190)         #5
    button(95,190)          #6
    button(285,190)         #B
    button(-285,0)          #7
    button(-95,0)           #8
    button(95,0)            #9
    button(285,0)           #C
    button(-285,-190)       #*
    button(-95,-190)        #0
    button(95,-190)         ##
    button(285,-190)        #D
#写字母以及字符-------------------------------------------------------------------------------------all_write()
def write(num,m,n):            #写数字
    t2.penup()
    t2.goto(m,n)
    t2.pendown()
    t2.write(num, font=("黑体",100, "normal"))
def number_write():
    write(1,-310,220)          #1
    write(2,-120,220)          #2
    write(3,70,220)            #3
    write(4,-310,40)           #4
    write(5,-120,40)           #5
    write(6,70,40)             #6
    write(7,-310,-150)         #7
    write(8,-120,-150)         #8
    write(9,70,-150)           #9
    write(0,-120,-340)         #0
def letter_write():
    t2.penup()
    t2.goto(260,220)
    t2.pendown()
    t2.write('A',font=("黑体",100, "normal") )
    t2.penup()
    t2.goto(260,40)
    t2.pendown()
    t2.write('B',font=("黑体",100, "normal") )
    t2.penup()
    t2.goto(260,-150)
    t2.pendown()
    t2.write('C',font=("黑体",100, "normal") )
    t2.penup()
    t2.goto(260,-340)
    t2.pendown()
    t2.write('D',font=("黑体",100, "normal") )
    t2.penup()
    t2.goto(-310,-340)
    t2.pendown()
    t2.write('*',font=("黑体",100, "normal") )
    t2.penup()
    t2.goto(70,-340)
    t2.pendown()
    t2.write('#',font=("黑体",100, "normal") )
def all_write():
    number_write()
    letter_write()

t.tracer(0)
main()
all_write()
t.update()
t.tracer(1)

#----------------------------------------------------------------------------------------------------------与arduino进行互动的部分
def judge(sth):
    if(sth == 1):
        t.tracer(0)
        mark(-285,360)
        write(1,-310,220)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 2):
        t.tracer(0)
        mark(-95,360)
        write(2,-120,220)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 3):
        t.tracer(0)
        mark(95,360)
        write(3,70,220)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 4):
        t.tracer(0)
        mark(-285,190)
        write(4,-310,40)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 5):
        t.tracer(0)
        mark(-95,190)
        write(5,-120,40)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 6):
        t.tracer(0)
        mark(95,190)
        write(6,70,40)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 7):
        t.tracer(0)
        mark(-285,0)
        write(7,-310,-150)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 8):
        t.tracer(0)
        mark(-95,0)
        write(8,-120,-150)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 9):
        t.tracer(0)
        mark(95,0)
        write(9,70,-150)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 0):
        t.tracer(0)
        mark(-95,-190)
        write(0,-120,-340)
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 11):#-----------------------------A
        t.tracer(0)
        mark(285,360)
        t2.penup()
        t2.goto(260,220)
        t2.pendown()
        t2.write('A',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 12):#------------------------------B
        t.tracer(0)
        mark(285,190)
        t2.penup()
        t2.goto(260,40)
        t2.pendown()
        t2.write('B',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 13):#------------------------------C
        t.tracer(0)
        mark(285,0)
        t2.penup()
        t2.goto(260,-150)
        t2.pendown()
        t2.write('C',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 14):#------------------------------D
        t.tracer(0)
        mark(285,-190)
        t2.penup()
        t2.goto(260,-340)
        t2.pendown()
        t2.write('D',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 15):#------------------------------*
        t.tracer(0)
        mark(-285,-190)
        t2.penup()
        t2.goto(-310,-340)
        t2.pendown()
        t2.write('*',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()
    elif(sth == 16):#------------------------------#
        t.tracer(0)
        mark(95,-190)
        t2.penup()
        t2.goto(70,-340)
        t2.pendown()
        t2.write('#',font=("黑体",100, "normal") )
        t.update()
        t.tracer(1)
        sleep(0.5)
        t3.clear()


        
serialPort = "COM3"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(serialPort, baudRate, timeout=1)
while 1:
    sth = ser.readline().decode('utf-8')
    if(sth == ''):
        nothing = 1
    else:
        sth = int(sth)
        if(sth == 11): print('A')
        elif(sth == 12): print('B')
        elif(sth == 13): print('C')
        elif(sth == 14): print('D')
        elif(sth == 15): print('*')
        elif(sth == 16): print('#')
        elif(sth!=11 and sth!=13 and sth!=14 and sth!=15 and sth!=16):  print(sth)
    judge(sth)


    
