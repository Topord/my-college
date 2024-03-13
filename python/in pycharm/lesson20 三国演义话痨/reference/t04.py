# 题目：已有文件data4.txt，请将文件内同学的成绩进行统计，并将统计结果写入out4.txt中
# 要求：1）三门课都在85以上或总分在260以上为优秀
# 2）三门课都在60以上或总分在180以上为合格，其余为不合格

sum = 0
L = list(open('data4.txt'))
f = open('out4.txt', 'w')
del L[0]

for s in L:
    x = s.split()         # split()字符串切片，默认以空格分切    strip() 去空格
    for i in range(1,len(x)):
        x[i] = int(x[i])
    sum = x[1]+x[2]+x[3]
    if x[1] >= 85 and x[2] >= 85 and x[3] >= 85 and sum >= 260:
        key = '优秀'
    elif x[1] >= 60 and x[2] >= 60 and x[3] >= 60 and sum >= 180:
        key = '合格'
    else:
        key = '不合格'
    f.write('%s\t%s\n' % (x[0], key))
    print('%s\t%s' % (x[0], key))
f.close()

