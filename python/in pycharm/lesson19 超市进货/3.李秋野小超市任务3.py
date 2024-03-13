# 显示出商品库存量排名及数量（盘存）
fo = open('商品数量库.txt', 'r', encoding='utf-8')
txt = fo.read()
# -----------------------------------------------------------------------------------------------读取文件
# 商品1
num1 = txt[14:15]
com1 = "大学物理练习册: " + num1 + "本"
num1 = eval(num1)
print(com1)
# 商品2
num2 = txt[30:31]
com2 = "英语听力: " + num2 + "本"
num2 = eval(num2)
print(com2)
# 商品3
num3 = txt[46:47]
com3 = "笔记本: " + num3 + "本"
num3 = eval(num3)
print(com3)
fo.close()
# -------------------------------------------------------------------------------------------将信息放置字典
d = {'9787568002677': ['大学物理练习册', num1], '9787544654166': ['英语听力', num2], '6936281408225': ['笔记本', num3]}
print(d)
lt = list(d.items())
print(lt)
lt.sort(key=lambda x: x[1][1], reverse=False) # 对其中的物品进行降序排列
print(lt)
# sort() 函数用于对原列表进行排序，如果指定参数，则使用比较函数指定的比较函数。
# list.sort( key=None, reverse=False)
# key -- 主要是用来进行比较的元素，只有一个参数，具体的函数的参数就是取自于可迭代对象中，指定可迭代对象中的一个元素来进行排序。
# reverse -- 排序规则，reverse = True 降序， reverse = False 升序（默认）
