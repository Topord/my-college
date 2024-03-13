s=[3,2,-1,0,-9,-90,-100]
for i in range(len(s)-1):
     for j in range(i+1,len(s)-1):
        if(s[i]>s[j]):
             s[j],s[i]=s[i],s[j]
print(s)

  
