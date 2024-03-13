# -*- coding:utf-8 -*-
# 新知识点：学习分析文本与确定简单文本处理算法
# 任务：将现行的《论语》读本进行处理与提纯
# 1）由文件 论语.txt去掉注释部分得到论语-原文.txt；
# 2）去掉文件 论语-原文.txt引用标号部分得到文件论语-提纯原文.txt
import jieba
a = 0
n = 0
file2 = open("论语2(含括号).txt", "w")
with open('论语.txt', 'r', encoding='utf-8') as file1:
    for line in file1:
        l1 = line.strip()
        # 用a的值来选择是否写入注释
        if l1.count("【原文】") != 0:
            # 即存在--> a = 1;
            a = 1
        if l1.count("【注释】") != 0:
            # 即存在--> a = 0
            a = 0
        if a == 1 and l1.count("【注释】") == 0 and l1.count("【原文】") == 0 and len(l1) > 0:
            file2.write("{}\n".format(l1))
file2.close()

file2 = open("论语2(含括号).txt", "r")
with open("论语3(无括号).txt", "w", encoding='utf-8') as file3:
    for line in file2:
        for k in range(12):
            line = line.replace('('+str(k)+')', '')
        file3.write(line)
file2.close()