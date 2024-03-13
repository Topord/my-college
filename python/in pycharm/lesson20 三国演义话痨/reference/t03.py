# 新知识点：学习分析文本与确定简单文本处理算法
# 任务：将现行的《论语》读本进行处理与提纯 1）由文件 论语.txt去掉注释部分得到论语-原文.txt；
# 2）去掉文件 论语-原文.txt引用标号部分得到文件  论语-提纯原文.txt
fi = open("论语.txt", "r", encoding='utf-8')
fo = open("论语-原文.txt", "w")
a = 0
for line in fi:
    line = line.strip()                           # strip()去掉首尾空格
    if line.count("【原文】") != 0:               # count()统计字符串出现的次数
        a = 1
    if line.count("【注释】") != 0:
        a = 0
    if a == 1 and line.count("【注释】") == 0 and line.count("【原文】") == 0 and len(line) > 0:
        fo.write("{}\n".format(line))
fi.close()
fo.close()


fi = open("论语-原文.txt", "r")
fo = open("论语-提纯原文.txt", "w")
for line in fi:
    for k in range(100):                        # 可以打开给定文件看一下最大值
        line=line.replace('('+str(k)+')', '')    # 字符串替换：用后者替换前者
    fo.write(line)
fi.close()
fo.close()


