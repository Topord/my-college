ss=[[4,7,0,8,45],[-1,-5,-6,45,0],[2,6,12,65,0]]
for k in range(len(ss[0])-1):
    for i in range(len(ss[0])-1):
     for j in range(i+1,len(ss[0])):
        if(ss[0][i]>ss[0][j]):
             ss[0][j],ss[0][i]=ss[0][i],ss[0][j]
print(ss[0])
#--------------------数组1---------------------------------------------------
for k in range(len(ss[1])-1):
    for i in range(len(ss[1])-1):
     for j in range(i+1,len(ss[1])):
        if(ss[1][i]>ss[1][j]):
             ss[1][j],ss[1][i]=ss[1][i],ss[1][j]    
print(ss[1])
#--------------------数组2---------------------------------------------------
for k in range(len(ss[2])-1):
    for i in range(len(ss[2])-1):
     for j in range(i+1,len(ss[2])):
        if(ss[2][i]>ss[2][j]):
             ss[2][j],ss[2][i]=ss[2][i],ss[2][j]    
print(ss[2])
#--------------------数组3---------------------------------------------------
