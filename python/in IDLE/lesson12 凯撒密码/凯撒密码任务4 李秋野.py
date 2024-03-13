num = [3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3]
x = input("请输入需要转换的内容:")

leth = len(x)
while(x != ' '):
    for i in x: 
        if(64 < ord(i) < 91):                 #大写字母
            m = ord(i) + num[ord(i) - 65]
            if (m > 90):
                m = m - 26
            print(chr(m),end = ' ')
            
        elif(96 < ord(i) < 123):              #小写字母
            n = ord(i) + num[ord(i) - 97]
            if (n > 122):
                n = n - 26
            print(chr(n),end = '')
                
        elif(38 < ord(i) < 48):               #大小写之间的标点符号
            print(chr(ord(i)))
            
    print('\n')
    x = input("请输入需要转换的内容):")



