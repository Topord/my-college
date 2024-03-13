import jieba
dic = {}
with open('asidata1.txt', 'r', encoding='utf-8') as file:
    s = file.readlines()
# for a in s:
#     print(a.strip())
for z in s.strip():
    print(z)
