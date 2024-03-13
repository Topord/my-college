num1 = 0
num2 = 0
num3 = 0
mon1 = 30
mon2 = 23
mon3 = 10
d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}
jd = input("a-进货;  b-删除;  c-修改;  d-查找;  e->购买;  n-退出(若购买则打印小票)")
while jd != '':
    d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}
    # -------------------------------------------------------------------------------------------------进货
    if jd == 'a':
        a = input("请输入你需要进货商品的条形码(n退出)")
        while a != '':
            if a == '9787568002677':
                num1 = num1 + 1
            elif a == '9787544654166':
                num2 = num2 + 1
            elif a == '6936281408225':
                num3 = num3 + 1
            if a == 'n':
                d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2],'6936281408225': ['笔记本', num3]}
                # 写入商品1
                fo = open('商品数量库.txt', 'w', encoding='utf-8')
                print(d)  # test
                fo.seek(0)
                tm1 = str(d)[2:15]  # 条码
                com1 = tm1 + " " + str(num1)
                fo.write(str(com1))
                # 写入商品2
                fo.writelines('\n')
                # fo.seek(28)
                tm2 = str(d)[35:48]  # 条码
                com2 = tm2 + " " + str(num2)
                fo.write(str(com2))
                # 写入商品3
                fo.writelines('\n')
                tm3 = str(d)[65:78]
                com3 = tm3 + " " + str(num3)
                fo.write(str(com3))
                # 关闭
                fo.close()
                break
            a = input("请输入你需要进货商品的条形码(n退出)")
    # --------------------------------------------------------------------------------------------------删除
    elif jd == 'b':
        a = input("请输入你需要修改商品的条形码(n退出)")
        while a != '':
            if a == '9787568002677':
                num1 = num1 - 1
            elif a == '9787544654166':
                num2 = num2 - 1
            elif a == '6936281408225':
                num3 = num3 - 1
            if a == 'n':
                d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2],
                     '6936281408225': ['笔记本', num3]}
                # 写入商品1
                fo = open('商品数量库.txt', 'w', encoding='utf-8')
                print(d)  # test
                fo.seek(0)
                tm1 = str(d)[2:15]  # 条码
                com1 = tm1 + " " + str(num1)
                fo.write(str(com1))
                # 写入商品2
                fo.writelines('\n')
                # fo.seek(28)
                tm2 = str(d)[35:48]  # 条码
                com2 = tm2 + " " + str(num2)
                fo.write(str(com2))
                # 写入商品3
                fo.writelines('\n')
                tm3 = str(d)[65:78]
                com3 = tm3 + " " + str(num3)
                fo.write(str(com3))
                # 关闭
                fo.close()
                break
            a = input("请输入你需要修改商品的条形码(n退出)")
    # -----------------------------------------------------------------------------------------------------修改
    elif jd == 'c':
        a = input('请输入你需要修改商品的条形码(n退出)')
        while a != '':
            if a == '9787568002677':
                b = input("请选择修改的内容: q->数量; w->单价")
                if b == 'q':
                    c = input('输入修改的数量:')
                    num1 = eval(c)
                elif b == 'w':
                    c = input('请输入修改的单价')
                    mon1 = eval(c)
            elif a == '9787544654166':
                b = input("请选择修改的内容: q->数量; w->单价")
                if b == 'q':
                    c = input('输入修改的数量:')
                    num2 = eval(c)
                elif b == 'w':
                    c = input('请输入修改的单价')
                    mon2 = eval(c)
            elif a == '6936281408225':
                b = input("请选择修改的内容: q->数量; w->单价")
                if b == 'q':
                    c = input('输入修改的数量:')
                    num3 = eval(c)
                elif b == 'w':
                    c = input('请输入修改的单价')
                    mon3 = eval(c)
            if a == 'n':
                d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2],
                     '6936281408225': ['笔记本', num3]}
                fo = open('商品数量库.txt', 'w', encoding='utf-8')
                fo.seek(0)
                tem1 = num1
                tem2 = num2
                tem3 = num3
                tm1 = str(d)[2:15]  # 条码
                com1 = tm1 + " " + str(num1)
                fo.write(str(com1))
                # 写入商品2
                fo.writelines('\n')
                # fo.seek(28)
                tm2 = str(d)[35:48]  # 条码
                com2 = tm2 + " " + str(num2)
                fo.write(str(com2))
                # 写入商品3
                fo.writelines('\n')
                tm3 = str(d)[65:78]
                com3 = tm3 + " " + str(num3)
                fo.write(str(com3))
                # 关闭
                fo.close()
                print(d)
                break
            a = input('请输入你需要修改商品的条形码(n退出)')
    # --------------------------------------------------------------------------------------------------查询
    # d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}
    elif jd == 'd':
        a = input("请输入你需要查找物品的条形码(n退出)")
        while a != '':
            tem1 = num1
            tem2 = num2
            tem3 = num3
            # ------------------------------------------------------------------------------------------读取数据
            if a == '9787568002677':
                ll = '物理练习册  ' + str(tem1) + '本    ' + '单价:  ' + str(mon1) + '元'
                print(ll)
                a = input("请输入你需要查找物品的条形码(n退出)")
                continue
            elif a == '9787544654166':
                ll = '英语听力    ' + str(tem2) + '本   ' + '单价:  ' + str(mon2) + '元'
                print(ll)
                a = input("请输入你需要查找物品的条形码(n退出)")
                continue
            elif a == '6936281408225':
                ll = '笔记本       ' + str(tem3) + '本    ' + '单价:  ' + str(mon3) + '元'
                print(ll)
                a = input("请输入你需要查找物品的条形码(n退出)")
                continue
            if a == 'n':
                print('查询结束')
                break

    # ------------------------------------------------------------------------------------------------------------购买
    elif jd == 'e':
        in1 = 0
        in2 = 0
        in3 = 0
        add = 0
        key = input('请输入你想购买商品的条码(n退出)')
        while key != '':
            if key == '9787568002677':
                add += mon1
                in1 += 1
                if in1 > num1:
                    in1 -= 1
                    print('大学物理练习册已经售罄')
                    key = input('请输入你想购买商品的条码(n退出)')
                    continue
            elif key == '9787544654166':
                add += mon2
                in2 += 1
                if in2 > num2:
                    in2 -= 1
                    print('英语听力已经售罄')
                    key = input('请输入你想购买商品的条码(n退出)')
                    continue
            elif key == '6936281408225':
                add += mon3
                in3 += 1
                if in3 > num3:
                    in3 -= 1
                    print('笔记本已经售罄')
                    key = input('请输入你想购买商品的条码(n退出)')
                    continue
            if key == 'n':
                last1 = num1 - in1
                last2 = num2 - in2
                last3 = num3 - in3
                price = in1 * 30 + in2 * 23 + in3 * 10
                price = str(price)
                # ------------------------------------------------------------------------------------------------------显示剩下的商品数量(备份)
                fo = open('商品剩余数量库.txt', 'w', encoding='utf-8')
                d = {'9787568002677': ['大学物理练习册', last1], '9787544654166': ['英语听力', last2],
                     '6936281408225': ['笔记本', last3]}
                fo.seek(0)
                tm1 = str(d)[2:15]  # 条码
                com1 = '大学物理练习册 ' + tm1 + " " + str(last1) + "本   " + "单价: " + str(mon1)
                fo.write(str(com1))
                # 写入商品2
                fo.writelines('\n')
                tm2 = str(d)[35:48]  # 条码
                com2 = '英语听力 ' + tm2 + " " + str(last2) + "本   " + "单价: " + str(mon2)
                fo.write(str(com2))
                # 写入商品3
                fo.writelines('\n')
                tm3 = str(d)[65:78]
                com3 = '笔记本 ' + tm3 + " " + str(last3) + "本   " + "单价: " + str(mon3)
                fo.write(str(com3))
                fo.close()
                # --------------------------------------------------------------------------------------------------打印小票
                fo = open('小票.txt', 'w', encoding='utf-8')
                end1 = '购买商品           数量            价格'
                end2 = '大学物理练习册       ' + str(in1) + '              ' + str(in1 * mon1)
                end3 = '英语听力            ' + str(in2) + '              ' + str(in2 * mon2)
                end4 = '笔记本              ' + str(in3) + '              ' + str(in3 * mon3)
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
            key = input('请输入你想购买商品的条码(n退出)')
    elif jd == 'n':
        break
    jd = input("a-进货;  b-删除;  c-修改;  d-查找;  e->购买;  n-退出(若购买则打印小票)")
print('end')