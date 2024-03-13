# -*- coding:utf-8 -*-

# 新知识点：学习获取网页的源代码（google浏览器ctrl+u），并作简单分析
# 任务：从www.icourse163.org/university/view/all.htm网站上提取大学列表，并统计大学与学院数量
# 提取时，学会分析并处理文本，去掉相似内容

f = open("univ.txt","w")
with open('data5.txt', 'r', encoding='utf-8') as file:
    for line in file:
        if "alt" in line:
            # line不为列表,当使用完split函数后才变为列表的,元素个数以网页代码中的“,"隔开,为['xxxx','xxxx']的形式
            # ['<img class="" id="" src="%E5%A4%A7%E5%AD%A6%E5%88%97%E8%A1%A8_\
            # %E4%B8%AD%E5%9B%BD%E5%A4%A7%E5%AD%A6MOOC(%E6%85%95%E8%AF%BE)_files/\
            # 370D4ADD98FE6993DE1970DB0060ACCA.png" ',\
            # 'alt="北京大学" width="164" height="60">']
            end = line.split("alt=")[-1].split('"')[1]
            f.write("{}\n".format(end))
f.close()


n = 0
m = 0
f = open("univ.txt", "r")
lines = f.readlines()
f.close()
for line in lines:
    line = line.replace("\n", "")
    if '大学生' in line:  # 筛除大学生
        continue
    elif '学院' in line and '大学' in line:
        m += 1
        n += 1
        print('{}'.format(line))
    elif '学院' in line:
        m += 1
    elif '大学' in line:
        n += 1
print("包含大学的名称数量是{}".format(n))  # 输出大学计数
print("包含学院的名称数量是{}".format(m))  # 输出学院计数
