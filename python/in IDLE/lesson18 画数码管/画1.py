import turtle as t
num_1=[0,1,1,1,1,1,1,'0'],[0,1,0,0,0,0,1,'1']
t.pensize(5)


def num(x,y,k):
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.seth(0)
    for i in range(2):
        if k == num_1[i][7]:
            for j in range(4):
                t.pendown() if num_1[i][j] else t.penup()
                t.fd(50)
                t.penup()
                t.fd(10)
                t.right(90)
            t.seth(90)
            for j in range(4,7):
                t.pendown() if num_1[i][j] else t.penup()
                t.fd(50)
                t.penup()
                t.fd(10)
                t.right(90)

num(0,0,'1')
