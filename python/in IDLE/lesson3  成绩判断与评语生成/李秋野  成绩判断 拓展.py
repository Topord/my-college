print('当输入n或者按回车键时跳出该程序')
a=input('请输入你的成绩:')
c=0
while(a!=''and a!='n'):
    for i in a:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             c+=1
             
    if(c==0):
        b=eval(a)
        if(b==100):
            print('满分')
        elif(b>=90):
            print('优秀')
        elif(b>=80):
            print('良好')
        elif(b>=70):
            print('中等')
        elif(b>=60):
            print('及格')
        else:
            print('不及格')
        a=input('请输入你的成绩:')
    else:
        a=input('请输入你的成绩:')
    c=0

    

    
