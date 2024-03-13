ss=[[4,7,0,8,45],[-1,-5,-6,45,0],[2,6,12,65,0,90]]
for k in range(len(ss[0])-1):
  for j in range(len(ss[0])-1):
     for i in range(j,len(ss[0])-1):
          if(ss[0][j]>ss[0][i+1]):
               ss[0][j],ss[0][i+1]=ss[0][i+1],ss[0][j]
         
print(ss[0])
for k in range(len(ss[1])-1):
  for j in range(len(ss[1])-1):
     for i in range(j,len(ss[1])-1):
          if(ss[1][j]>ss[1][i+1]):
               ss[1][j],ss[1][i+1]=ss[1][i+1],ss[1][j] 
print(ss[1])
for k in range(len(ss[2])-1):
  for j in range(len(ss[2])-1):
     for i in range(j,len(ss[2])-1):
          if(ss[2][j]>ss[2][i+1]):
               ss[2][j],ss[2][i+1]=ss[2][i+1],ss[2][j] 
print(ss[2])
