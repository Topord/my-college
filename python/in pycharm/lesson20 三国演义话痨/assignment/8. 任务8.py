# -*- coding:utf-8 -*-
import jieba
import re
# dic = {}
# file = open('三国演义（原）.txt', 'r', encoding='utf-8')
# s = file.readlines()
# s = str(s)
# para = re.sub('([。！？\?])([^”’])', r"\1\n\2", s)
# para = para.replace('"', '=')
# para = para.replace('n', '')
# para = para.replace('\\', '')
# para = para.replace('\'', '')
# para = para.replace(',', '')
# para = para.replace('。', 'p')
# # print(para)
# for word in jieba.lcut(para.strip(), cut_all = True):
#     # # 对2字词进行筛选
#     if len(word) == 3:
#         dic[word] = dic.get(word, 0) + 1
#     if word == "关羽曰" or word == "美髯曰" or word == "武圣曰" or word == "壮缪曰" or word == "云长曰":
#         word = "关羽曰"
#         dic[word] = dic.get(word, 0) + 1
#     if word == "张飞曰" or word == "益德曰" or word == "飞曰" or word == "翼德曰":
#         word = "张飞曰"
#         dic[word] = dic.get(word, 0) + 1
#     if word == "孙权曰" or word == "权曰":
#         word = "孙权曰"
#         dic[word] = dic.get(word, 0) + 1
#     if word == "玄德曰" or word == "德曰" or word == "备曰" or word == "刘备曰":
#         word = "刘备曰"
#         dic[word] = dic.get(word, 0) + 1
#     if word == "诸葛曰" or word == "孔明曰" or word == "诸葛亮曰" or word == "卧龙曰":
#         word = "诸葛曰"
#         dic[word] = dic.get(word, 0) + 1
#     if word == "司马曰":
#         word = "司马曰"
#         dic[word] = dic.get(word, 0) + 1
# file.close()
#
# a = re.findall("=.*p", para)
# print(len(a))
# print(a)
# dic = list(dic.items())
# dic.sort(key=lambda x: x[1], reverse=True)       # 对dic列表中的元组第一个元素进行降序排列
# print(len(dic))
# # 显示使用量排名前10的词语
# for i in range(len(dic)):
#     if len(dic[i][0]) == 3:
#         if '曰' in dic[i][0]:
#             print("{}: {}".format(dic[i][0], dic[i][1]))
# def s1():
#     dic = {}
#     file = open('三国演义（原）.txt', 'r', encoding='utf-8')
#     for word in jieba.lcut(para.strip(), cut_all=True):
#         # # 对2字词进行筛选
#         if len(word) == 3:
#             dic[word] = dic.get(word, 0) + 1
#         if word == "关羽曰" or word == "美髯曰" or word == "武圣曰" or word == "壮缪曰" or word == "云长曰":
#             word = "关羽曰"
#             dic[word] = dic.get(word, 0) + 1
#         if word == "张飞曰" or word == "益德曰" or word == "飞曰" or word == "翼德曰":
#             word = "张飞曰"
#             dic[word] = dic.get(word, 0) + 1
#         if word == "孙权曰" or word == "权曰":
#             word = "孙权曰"
#             dic[word] = dic.get(word, 0) + 1
#         if word == "玄德曰" or word == "德曰" or word == "备曰" or word == "刘备曰":
#             word = "刘备曰"
#             dic[word] = dic.get(word, 0) + 1
#         if word == "诸葛曰" or word == "孔明曰" or word == "诸葛亮曰" or word == "卧龙曰":
#             word = "诸葛曰"
#             dic[word] = dic.get(word, 0) + 1
#         if word == "司马曰":
#             word = "司马曰"
#             dic[word] = dic.get(word, 0) + 1
#     file.close()
def s2():
    b[] = [0]
    jd = 0
    file = open('三国演义（原）.txt', 'r', encoding='utf-8')
    s = file.readlines()
    s = str(s)
    para = re.sub('([。！？\?])([^”’])', r"\1\n\2", s)
    para = para.replace('"', '=')
    para = para.replace('n', '')
    para = para.replace('\\', '')
    para = para.replace('\'', '')
    para = para.replace(',', '')
    para = para.replace('。', 'p')
    a = re.findall("=.*p", para)
    for i in range(9584, 2):
        print(a[i])
        b[i] = a[i]
    for word in b:
        if word == "羽" or  word == "武圣" or word == "壮缪" or word == "云长":
                word = "关羽曰"
                dic[word] = dic.get(word, 0) + 1
        if word == "飞" or word == "益德" or word == "翼德":
            word = "张飞曰"
            dic[word] = dic.get(word, 0) + 1
        if word == "孙权" or word == "权":
            word = "孙权曰"
            dic[word] = dic.get(word, 0) + 1
        if word == "玄德" or word == "德" or word == "备" or word == "刘备":
            word = "刘备曰"
            dic[word] = dic.get(word, 0) + 1
        if word == "诸葛" or word == "孔明" or word == "亮" or word == "卧龙":
            word = "诸葛曰"
            dic[word] = dic.get(word, 0) + 1
        if word == "司马曰":
            word = "司马曰"
            dic[word] = dic.get(word, 0) + 1
s2()