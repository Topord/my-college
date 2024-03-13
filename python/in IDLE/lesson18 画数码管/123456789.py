import turtle as t
stor=[[0,1,1,1,1,1,1],[0,1,0,0,0,0,1],[1,0,1,1,0,1,1],[1,1,1,0,0,1,1],\
     #      0              1                  2            3
     [1,1,0,0,1,0,1],[1,1,1,0,1,1,0],[1,1,1,1,1,1,0],[0,1,0,0,0,1,1],\
     #      4              5                  6            7
     [1,1,1,1,1,1,1],[1,1,1,0,1,1,1]]
     #     8                9           
t.pensize(5)
t.penup()
t.goto(-250,0)
t.pendown()
t.speed(0)
t.hideturtle()
def jd(bh):  #--------------------------------判断
    t.pendown() if bh==1 else t.penup()
def num(n):
    t.seth(0)
    for i in range(3):#                ---
        jd(stor[n][i])
        t.fd(20)
        t.right(90)
    for j in range(3,5):
        jd(stor[n][j])
        t.fd(20)
    t.right(90)
    for k in range(5,6):
        jd(stor[n][k])
        t.fd(20)
        t.right(90)
    jd(stor[n][6])
    t.fd(20)
    t.seth(0)
    t.penup()
    t.fd(30)
    t.pendown()
for i in range(10):
    num(i)
