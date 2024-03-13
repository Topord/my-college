import turtle as t
t.screensize(1000,800,'black')
t.setup(1000,800)

t1=t.Pen()           #打印数字
t2=t.Pen()           #打印红色方框
t3=t.Pen()           #蓝色进度条

t1.hideturtle()
t2.hideturtle()
t3.hideturtle()

t1.speed(0)
t1.pencolor('white')
t2.pensize(10)
t2.pencolor('red')

num_1=[[-420,190],[-400,220],[-385,250],[-350,280],[-350,240],[-350,200],[-350,150],[-350,100],[-350,50],[-350,0],[-350,-50],\
      #     1           3           5       7           9           11       13           15       17       19        21       
       [-350,-100],[-350,-150],[-450,-200],[-400,-200],[-350,-200],[-300,-200],[-250,-200]]            #一共18个数 
      #     23         25          27          29          31         33             35

num_0=[[-150,220],[-100,200],[-50,160],[0,100],[0,40],[00,-20],[-50,-80],[-100,-120],[-150,-140],\
      #   37       39       41        43        45       47         49       51       53
       [-200,-120],[-250,-80],[-300,-20],[-300,40],[-300,100],[-250,150],[-200,200]]      
    #      55          57         59         61        63         65        67
#-------------------------------------------------------------------------------------------------------------------
def squ():                               #红色方框
    t2.speed(10)
    t2.setheading(0)
    t2.penup()
    t2.goto(-480,380)
    t2.pendown()
    t2.fd(950)
    t2.right(90)
    t2.fd(750)
    t2.right(90)
    t2.fd(950)
    t2.right(90)
    t2.fd(750)
    
def bot():                                #蓝色进度条                         
    t3.pensize(30)
    t3.pencolor('blue')
    t3.setheading(0)
    t3.fd(17.2)
#--------------------------------------------------------------------------------------------------------------------
def write_1():                           #左边的1
    n = 1
    while(n < 37):
        for i in range(len(num_1)):               #len(num_1)=16     range(16)-->0-15
            for j in range(1):
                squ()#
                x = num_1[i][j] 
                y = num_1[i][j+1]
                t1.penup()
                t1.goto(x,y)#
                t1.pendown()
                t1.write('{}%'.format(n), font=("黑体",15, "normal"))
                bot()#
                t2.clear()
                n = n + 2
                   
def write_0mid():                        #中间的0
    n = 37
    while(n < 67):
        for i in range(len(num_0)):              
            for j in range(1):
                squ()#
                x = num_0[i][j] 
                y = num_0[i][j+1]
                t1.penup()
                t1.goto(x,y)#
                t1.pendown()
                t1.write('{}%'.format(n), font=("黑体",15, "normal"))
                bot()#
                t2.clear()
                n = n + 2
                
def write_0left():                      #左边的0
    n = 69
    while(n < 99):
        for i in range(len(num_0)):               #len(num_1)=16     range(16)-->0-15
            for j in range(1):
                squ()#
                x = num_0[i][j] + 350
                y = num_0[i][j+1]
                t1.penup()
                t1.goto(x,y)#
                t1.pendown()
                t1.write('{}%'.format(n), font=("黑体",15, "normal"))
                bot()#
                t2.clear()
                n = n + 2

#让画方框的t3去左上角
t3.penup()
t3.goto(-440,-300)
t3.pendown()
t.tracer(0)
write_1()
write_0mid()
write_0left()
t.update()

