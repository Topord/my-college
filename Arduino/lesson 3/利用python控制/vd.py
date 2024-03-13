import serial
import turtle as t


t.pencolor('black')
t.hideturtle()
serialPort = "COM3"  # 串口
baudRate = 9600  # 波特率
ser = serial.Serial(serialPort, baudRate, timeout=1)
t.penup()
t.goto(-150,0)
t.pendown()

while 1:
    num = ser.readline().decode('utf-8')
    t.tracer(0)
    t.clear()
    t.write(num, font=("",30, "normal"))
    t.update()
    #t.write('电压为{}V'.format(num), font=("",30, "normal"))








