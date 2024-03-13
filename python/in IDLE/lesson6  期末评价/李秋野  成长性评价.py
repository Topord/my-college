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
begin=input('按下任意进入程序(退出请按回车键):')
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

    
    
    
