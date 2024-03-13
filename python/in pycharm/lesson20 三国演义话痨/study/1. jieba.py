import jieba
# jieba.cut可对字符串进行切割(需要转换为列表才能输出)，lcut直接转换为列表
test1 = list(jieba.cut("大家好，我是peter."))
test2 = jieba.lcut("大家好，我是peter.")
print(test1)
print(test2)
with open('论语.txt', 'r', encoding='utf-8') as file1:
    for line in file1:
        # line = line.strip()
        print(line)
print(ord(128153))