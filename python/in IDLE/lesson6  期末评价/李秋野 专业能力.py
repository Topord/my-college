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
begin=input('按下回车键进入程序。')
while(begin==''):
    i=input('请为你的电脑基础评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
    j=input('请为你的编程能力评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')
    k=input('请为你的自学能力评分：\na-(优秀)\tb-(好)     \tc-(一般)\td-(较差)\te-(很差)\n')#--------------------------输入
    begin=input('按下除回车键以外的键退出程序。')

I=grade(i)
J=grade(j)
K=grade(k)#----------------------------赋值

ave=(I+J+K)/3#-------------------------计算
print('所以你的平均得分是',ave)
    
    
