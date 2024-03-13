# 模拟顾客买单，对数据文件中的数量进行操作，并打印销售小票
# 大学物理练习册: 30元  英语听力: 23元  笔记本: 10元
# -----------------------------------------------------------------------------------------------读取文件
fo = open('商品数量库.txt', 'r', encoding='utf-8')
txt = fo.read()
# 商品1
num1 = txt[14:15]
com1 = "大学物理练习册: " + num1 + "本"
print(com1)
num1 = eval(num1)
# 商品2
num2 = txt[30:31]
com2 = "英语听力: " + num2 + "本"
print(com2)
num2 = eval(num2)
fo.close()
# 商品3
num3 = txt[46:47]
com3 = "笔记本: " + num3 + "本"
print(com3)
num3 = eval(num3)
fo.close()
# -------------------------------------------------------------------------------------------------------购买
mon1 = 30
mon2 = 23
mon3 = 10
in1 = 0
in2 = 0
in3 = 0
add = 0
key = input("请输入你想购买商品的条码")
while key != '':
    if key == '9787568002677':
        add += mon1
        in1 += 1
        if in1 > num1:
            in1 -= 1
            print('大学物理练习册已经售罄')
            key = input('')
            continue
    elif key == '9787544654166':
        add += mon2
        in2 += 1
        if in2 > num2:
            in2 -= 1
            print('英语听力已经售罄')
            key = input('')
            continue
    elif key == '6936281408225':
        add += mon3
        in3 += 1
        if in3 > num3:
            in3 -= 1
            print('笔记本已经售罄')
            key = input('')
            continue
    if key == 'n':
        last1 = num1 - in1
        last2 = num2 - in2
        last3 = num3 - in3
        price = in1*30 + in2*23 + in3*10
        price = str(price)
        # ------------------------------------------------------------------------------------------------------显示剩下的商品数量
        fo = open('商品剩余数量库.txt', 'w', encoding='utf-8')
        d = {'9787568002677': ['大学物理练习册', last1], '9787544654166': ['英语听力', last2], '6936281408225': ['笔记本', last3]}
        fo.seek(0)
        tm1 = str(d)[2:15]  # 条码
        num1 = str(d)[30:31]  # 数量
        com1 = '大学物理练习册 ' + tm1 + " " + num1 + "本"
        fo.write(str(com1))
        # 写入商品2
        fo.writelines('\n')
        tm2 = str(d)[35:48]  # 条码
        num2 = str(d)[60:61]  # 数量
        com2 = '英语听力 ' + tm2 + " " + num2 + "本"
        fo.write(str(com2))
        # 写入商品3
        fo.writelines('\n')
        tm3 = str(d)[65:78]
        num3 = str(d)[89:90]
        com3 = '笔记本 ' + tm3 + " " + num3 + "本"
        fo.write(str(com3))
        fo.close()
        # --------------------------------------------------------------------------------------------------打印小票
        fo = open('小票.txt', 'w', encoding='utf-8')
        end1 = '购买商品           数量            价格'
        end2 = '大学物理练习册       ' + str(in1) + '              ' + str(in1*30)
        end3 = '英语听力            ' + str(in2) + '              ' + str(in2*23)
        end4 = '笔记本              ' + str(in3) + '              ' + str(in3*10)
        end5 = '您一共花费' + price + '元'
        fo.write(str(end1))
        fo.writelines('\n')
        fo.write(str(end2))
        fo.writelines('\n')
        fo.write(str(end3))
        fo.writelines('\n')
        fo.write(str(end4))
        fo.writelines('\n')
        fo.write(str(end5))
        fo.close()
        break
    key = input('')
print('end')