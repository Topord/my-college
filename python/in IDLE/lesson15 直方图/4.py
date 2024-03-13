import turtle as t
arry = [[67,6],[37,5],[78,6],[233,13],[100,9],[20,40],[40,9]]
X_len = 500
Y_len = 300
x0 = -200
y0 = -100
t.speed(0)
#------------------------------------------------------------------
t.hideturtle()
t.penup()
t.goto(x0, y0)
t.pendown()
t.setheading(0)
t.fd(X_len)
t.setheading(180)
t.fd(X_len)
t.setheading(90)
t.fd(Y_len)
t.setheading(-90)
t.fd(Y_len)
t.setheading(0)
t.fd(50)
for i in range(0, len(arry)):
    for j in range(0,1):
        length = arry[i][j]
        size = arry[i][j + 1]
        t.color('red','red')
        t.setheading(90)
        t.begin_fill()
        t.fd(length)
        t.setheading(0)
        t.fd(size)
        t.setheading(-90)
        t.fd(length)
        t.end_fill()
        t.penup()
        t.setheading(0)
        t.fd(50)
    
