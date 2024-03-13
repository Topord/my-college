# 新知识点1：中文jieba分词库
# 任务：从文件data1.txt中统计二字词的词频，并显示前10名
import jieba
dk = {}
with open('data1.txt','r',encoding='utf-8') as f:
    sl = f.readlines() # 读取所有
for s in sl:
    k=jieba.lcut(s, cut_all = True)             #精确模式，有冗余  （分词）
    for wo in k:
        if len(wo)==2:
           dk[wo] = dk.get(wo,0) + 1            #无此项则添加新项并填0值，有此项则加1

dp = list(dk.items())
dp.sort(key= lambda x:x[1], reverse = True)       #降序
#print(dp)

for i in range(10):
   print("{}:{}".format(dp[i][0],dp[i][1]))

