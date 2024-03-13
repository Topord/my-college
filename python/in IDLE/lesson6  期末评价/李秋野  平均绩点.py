def eng(n1):#n--分数  
    n1=eval(n1)
    if(n1>90):
        n1=90
    g_eng=3*(n1/10-5)
    return g_eng

def math(n2):#n--分数  
    n2=eval(n2)
    if(n2>90):
        n2=90
    g_math=3.5*(n2/10-5)
    return g_math

def com(n3):#n--分数  
    n3=eval(n3)
    if(n3>90):
        n3=90
    g_com=2.5*(n3/10-5)
    return g_com 
def ave(g_eng,g_math,g_com):
    g_ave=(g_eng+g_math+g_com)/9
    print('所以你的成绩为{:.2f}'.format(g_ave))

a=input('请输入你各科的分数(按n退出，回车继续)：')
while(a!='n'):
    #英语成绩的输入
    n1=input('请输入你英语的分数：')
    g_eng=eng(n1)
    #数学成绩的输入
    n2=input('请输入你数学的分数：')
    g_math=math(n2)
    #计算机导论成绩的输入
    n3=input('请输入你计算机导论的分数：')
    g_com=com(n3)
    ave(g_eng,g_math,g_com)
    a=input('请输入你各科的分数(按n退出)：')
    

    
    
