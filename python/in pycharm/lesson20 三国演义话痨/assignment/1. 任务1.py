# 新知识点1：中文jieba分词库
# 任务：从文件data1.txt中统计二字词的词频，并显示前10名
import jieba
dic = {}
with open('asidata1.txt', 'r', encoding='utf-8') as file:
    # 读取所有文本信息(包括转义字符)并将其放在一个名为s的列表中
    s = file.readlines()
for a in s:
    # 如果用word对jieba.cut(s.strip())（去除空格后并且按照中文意思切片后的语句）进行遍历，则只会出现“xx大学”，而不是“大学
    # 必须加上cut_all = True进行精确切片
    for word in jieba.lcut(a.strip(), cut_all = True):
        # 对2字词进行筛选
        print(word)
        if len(word) == 2:
            # 如果dic字典中有word的话，就对该word对应的值加1；反之，则会在字典中生成"word": value的键值对。
            dic[word] = dic.get(word, 0) + 1
# Python 字典(Dictionary) items() 函数以列表返回可遍历的(键, 值) 元组数组
dic = list(dic.items())
dic.sort(key= lambda x:x[1], reverse = True)       # 对dic列表中的元组第一个元素进行降序排列
# 显示使用量排名前10的词语
for i in range(10):
    print("{}: {}".format(dic[i][0], dic[i][1]))
