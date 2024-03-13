# 输入相应条码，该物品数量会+1，并在输入n后在创建的商品数量库中以 条码+数量的形式打印出来
num1 = 0
num2 = 0
num3 = 0
d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}

#对商品进行数量进行增加
a = input("")
while a != '':
    if a == '9787568002677':
        num1 = num1 + 1
    elif a == '9787544654166' :
        num2 = num2 + 1
    elif a == '6936281408225':
        num3 = num3 + 1
    if a == 'n':
        d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}
        # 写入商品1
        fo = open('商品数量库.txt', 'w', encoding='utf-8')
        print(d) # test
        fo.seek(0)
        tm1 = str(d)[2:15]  # 条码
        num1 = str(d)[30:31]  # 数量
        com1 = tm1 + " " + num1
        fo.write(str(com1))
        # 写入商品2
        fo.writelines('\n')
        # fo.seek(28)
        tm2 = str(d)[35:48]  # 条码
        num2 = str(d)[60:61]  # 数量
        com2 = tm2 + " " + num2
        fo.write(str(com2))
        # 写入商品3
        fo.writelines('\n')
        tm3 = str(d)[65:78]
        num3 = str(d)[89:90]
        com3 = tm3 + " " + num3
        fo.write(str(com3))
        # 关闭
        fo.close()
        break
    a = input("")
print('end')
