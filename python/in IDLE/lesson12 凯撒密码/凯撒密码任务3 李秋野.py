x = input("请输入需要转换的内容:")
n = len(x)
while(x != ''):
    for i in  x:
        if(67 < ord(i) < 94):        #大写
            print(chr(ord(i) - 3), end = '')
        elif(ord(i) == 44):
            print(',',end = '')
        elif(ord(i) > 96):           #小写
            print(chr(ord(i) + 23),end = '')
        n = n - 1
    print('n')
        while(n == 0):
            break
    x = input("请输入需要转换的内容(回车跳出):")
