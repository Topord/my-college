print('当输入n或者按回车键时跳出该程序')
a=input('请输入你的成绩:') 
while(a!=''and a!='n'):
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
    

    
