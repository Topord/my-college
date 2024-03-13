s=[3,2,-1,0,-7,-90,-999]
for i in range(len(s)-1):
    if(s[0]>s[i+1]):
        s[0],s[i+1]=s[i+1],s[0]
print(s)
