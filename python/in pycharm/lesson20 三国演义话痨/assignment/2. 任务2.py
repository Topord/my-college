# 新知识点1：模块化程序设计（编程进阶）
# 新知识点2：带返回值函数（复杂的返回值）
# 任务：从两份政府工作报告（2018，2019）中找到词频前10名的共有词与特有词
import jieba

# 找到字数大于等于2的词语并储存在dic字典中，再进行降序排列
def getWords(file_name):
    dic = {}
    with open(file_name, 'r', encoding='utf-8') as file:
        # 读取所有文本信息(包括转义字符)并将其放在一个名为s的列表中
        s = file.readlines()
    for a in s:
        for word in jieba.lcut(a.strip(), cut_all=True):
            if len(word) >= 2:
                dic[word] = dic.get(word, 0) + 1
    dic = list(dic.items())
    dic.sort(key=lambda x: x[1], reverse=True)
    return dic

# 输出dic列表中词频前10的词,并放入fin列表中
def extraWords(dic, num=10):
    fin = []
    for i in range(num):
        word = dic[i][0]
        fin.append(word)
    return fin

def compareWords(list1, list2):
    # comm-->共有词; lt1-->list1特有词; lt2-->list2特有词
    comm = []
    lt1 = []
    lt2 = []

    for i in list1:
        if i in list2:
            comm.append(i)
        else:
            lt1.append(i)

    for i in list2:
        if i not in list1:
            lt2.append(i)

    return comm, lt1, lt2


def showDiffWords(comm, y1, y2, lt1, lt2):
    print('共有词语:', end='')
    print(','.join(comm))
    print('{}特有:'.format(y1), end='')
    print(','.join(lt1))
    print('{}特有:'.format(y2), end='')
    print(','.join(lt2))


f2019 = getWords('政府工作报告2019.txt')
f2018 = getWords('政府工作报告2018.txt')
s2019 = extraWords(f2019)
s2018 = extraWords(f2018)
comm, t2019, t2018 = compareWords(s2019, s2018)
showDiffWords(comm, "2019报告", "2018报告", t2019, t2018)
