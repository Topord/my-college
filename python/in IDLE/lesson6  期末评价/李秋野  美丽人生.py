#绩点
def eng(n1):#n--英语分数  
    n1=eval(n1)
    if(n1>90):
        n1=90
    g_eng=3*(n1/10-5)
    return g_eng

def math(n2):#n--数学分数  
    n2=eval(n2)
    if(n2>90):
        n2=90
    g_math=3.5*(n2/10-5)
    return g_math

def com(n3):#n--计算机导论分数  
    n3=eval(n3)
    if(n3>90):
        n3=90
    g_com=2.5*(n3/10-5)
    return g_com
    
def point():    
    a=input('输入任意英文字母进入平均绩点计算成绩，回车退出:')
    while(a!=''):
        #英语成绩的输入
        n1=input('请输入你英语的分数(0--100)：')
        g_eng=eng(n1)
        #数学成绩的输入
        n2=input('请输入你数学的分数(0--100)：')
        g_math=math(n2)
        #计算机导论成绩的输入
        n3=input('请输入你计算机导论的分数(0--100)：')
        g_com=com(n3)
        #平均绩点
        g_ave=(g_eng+g_math+g_com)/3
        a=input('按下除回车键退出程序。')
        return g_ave
#专业能力
def abl():
    def grade(x):
        if(x=='a'):
            return 100
        elif(x=='b'):
            return 80
        elif(x=='c'):
            return 60
        elif(x=='d'):
            return 40
        elif(x=='e'):
            return 20
    begin=input('输入任意英文字母进入专业能力评价程序，回车退出:')
    while(begin!=''):
        i=input('请为你的电脑基础评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
        j=input('请为你的编程能力评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
        k=input('请为你的自学能力评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')#--------------------------输入
        begin=input('按下除回车键退出程序。')

    I=grade(i)
    J=grade(j)
    K=grade(k)#----------------------------赋值

    ave2=(I+J+K)/3#-------------------------计算
    print('所以你的平均得分是{:.2f}'.format(ave2))
    return ave2

#成长性
def led():
    def grow(x):
        if(x=='a'):
            return 100
        elif(x=='b'):
            return 80
        elif(x=='c'):
            return 60
        elif(x=='d'):
            return 40
        elif(x=='e'):
            return 20
    begin=input('输入任意英文字母进入成长性评价程序(退出请按回车键):')
    while(begin!=''):
        q=input('请为你的人际关系评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
        w=input('请为你的自我反省评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
        e=input('请为你的学习力评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')#--------------------------输入
        begin=input('按下回车键键退出程序。')

    Q=grow(q)
    W=grow(w)
    E=grow(e)#----------------------------赋值

    x=0
    grade=0
    if(Q==40):
        x+=10
    elif(Q==20):
        x+=20
    if(W==40):
        x+=10
    elif(W==20):
        x+=20
    if(E==40):
        x+=10
    elif(E==20):
        x+=20

    grade=(Q+W+E)/3-x
    print('你的成长性得分为:{:.2f}'.format(grade))
    return grade
#调用函数--------------------------------------------------------------------------------------------------------------
g_ave=point()#表示引用point()函数并将point()中的返回值赋值给g_ave
ave2=abl()
grade=led()
P=(g_ave+ave2+grade)/3
print('所以你的综合评价成绩为{:.2f}'.format(P))

    
    
