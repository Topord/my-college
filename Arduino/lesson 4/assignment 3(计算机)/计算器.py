import turtle as t
import serial
from time import sleep
#-------------------------------------------------------------------------------------------与arduino进行连接
serialPort = "COM3"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(serialPort, baudRate, timeout=0.5)
#--------------------------------------------------------------------------------------------初始化画布和画笔
#初始化画布大小、背景颜色、画笔颜色
t.screensize(800,800)
t.setup(800,800)
#引入3个画笔
t1 = t.Pen()             #t1用来写最开始的数字
t1.hideturtle()
t1.pencolor('black')
t1.pensize(1)
t1.speed(0)
t1.penup()
t1.goto(-200,0)
t1.pendown()
t2 = t.Pen()             #t1用来写最开始的数字
t2.hideturtle()
t2.pencolor('black')
t2.pensize(1)
t2.speed(0)
t2.penup()
t2.goto(-200,0)
t2.pendown()
c=''
fin=0
#-------------------------------------------------------------------------------------------计算数字时需要的函数
while True:
    t.tracer(0)
    a = ser.readline().decode('utf-8')
    if(a==''): no = 1
    elif(a!=''):
        if(a=='11'):
            a='+'
        elif(a=='12'):
            a='-'
        elif(a=='13'):
            a='*'
        elif(a=='14'):
            a='/'
        if(a=='16'):
            t1.clear()
            fin = eval(c)
            print(eval(c))
            t2.write(fin,font=("黑体",75, "normal") )
            c=''
            a=''
            fin=0
            a = ser.readline().decode('utf-8')
        if(a=='15'):
            t2.clear()
            a=''   
        c = c + a
        print(c)
        t1.write(c,font=("黑体",75, "normal") )    
t.update()
    

        


    
