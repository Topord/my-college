x = input("请输入需要转换的内容:")
n = len(x)
while(x != ''):
    for i in  x:
        if(64 < ord(i) < 69):
            print(chr(ord(i) + 3), end = '')
        elif(ord(i) > 97):
            print(chr(ord(i) - 23))
        n = n - 1
        
        while(n == 0):
            break
    x = input("请输入需要转换的内容:")

