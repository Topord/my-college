s=[3,2,-1,0,-9,90]
for j in range(len(s)-1):
    for i in range(j,len(s)-1):
            if(s[j]>s[i+1]):
                 s[j],s[i+1]=s[i+1],s[j]
print(s)
