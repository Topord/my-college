# 新知识点1：模块化程序设计（编程进阶）
# 新知识点2：带返回值函数（复杂的返回值）
# 任务：从两份政府工作报告（2018，2019）中找到词频前10名的共有词与特有词
import jieba

def getWords(fn):
    fi = open(fn, 'r', encoding='utf-8')
    ls = jieba.lcut(fi.read())
    d = {}
    for l in ls:
        if len(l) >= 2:
            d[l] = d.get(l, 0) + 1
    lt = list(d.items())
    lt.sort(key=lambda x: x[1], reverse=True)
    return lt


def showWords(li, year, num=10):
    print('{}:'.format(year), end='')
    for i in range(num):
        k, v = li[i]
        if i < num - 1:
            print('{}:{}'.format(k, v), end=',')
        else:
            print('{}:{}'.format(k, v))



def extraWords(li, num=10):
    ls = []
    for i in range(num):
        k, v = li[i]
        ls.append(k)
    return ls


def compareWords(ls1, ls2):
    comm = []
    lt1 = []
    lt2 = []
    for i in ls1:
        if i in ls2:
            comm.append(i)
        else:
            lt1.append(i)

    for i in ls2:
        if i not in ls1:
            lt2.append(i)
    return comm, lt1, lt2


def showDiffWords(comm, y1, y2, lt1, lt2):
    print('共有词语:', end='')
    print(','.join(comm))
    print('{}特有:'.format(y1), end='')
    print(','.join(lt1))
    print('{}特有:'.format(y2), end='')
    print(','.join(lt2))


def main():
    ls2019 = getWords('政府工作报告2019.txt')
    print(ls2019)
    ls2018 = getWords('政府工作报告2018.txt')
    nls2019 = extraWords(ls2019)
    nls2018 = extraWords(ls2018)
    comm, x2019, x2018 = compareWords(nls2019, nls2018)
    showDiffWords(comm, 2019, 2018, x2019, x2018)


main()
