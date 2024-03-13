# -*- coding:utf-8 -*-
# 题目：已有文件data4.txt，请将文件内同学的成绩进行统计，并将统计结果写入out4.txt中
# 要求：1）三门课都在85以上或总分在260以上为优秀
# 2）三门课都在60以上或总分在180以上为合格，其余为不合格

add = 0
L = list(open('data4.txt'))   # 将文档中的信息存放在一个列表中 一行信息即为一个元素
del L[0]  # 删除列表的第一个元素
print(L)
with open('final.txt', 'w') as f4:
    for s in L:  # 输出的s为字符串,内容为L列表的元素
        x = s.split()  # 在经过切片后又转换为列表
        for i in range(1, len(x)):
            x[i] = int(x[i])
        add = x[1] + x[2] + x[3]
        if x[1] >= 85 and x[2] >= 85 and x[3] >= 85 and add >= 260:
            key = '优秀'
        elif x[1] >= 60 and x[2] >= 60 and x[3] >= 60 and add >= 180:
            key = '合格'
        else:
            key = '不合格'
        f4.write('%s\t%s\n' % (x[0], key))
        print('%s\t%s' % (x[0], key))

