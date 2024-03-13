# 新知识点：学习获取网页的源代码（google浏览器ctrl+u），并作简单分析
# 任务：从www.icourse163.org/university/view/all.htm网站上提取大学列表，并统计大学与学院数量
# 提取时，学会分析并处理文本，去掉相似内容

fi = open("data5.txt","r",encoding="utf-8")
f = open("univ.txt","w")
for line in fi:
    if "alt" in line:
        ex=line.split("alt=")[-1].split('"')
        print(ex)
        f.write("{}\n".format(ex[1]))
f.close()
fi.close()

n = 0    
m = 0    
f = open("univ.txt", "r")  
lines = f.readlines()      
f.close()   
for line in lines:      
    line = line.replace("\n","")   
    if '大学生' in line:           
        continue
    elif '学院' in line and '大学' in line:  
        if line[-2:] == '学院':
            m += 1
        elif line[-2:] == '大学':            
            n += 1
        print('{}'.format(line))
    elif '学院' in line:           
        print('{}'.format(line))                                      
        m += 1                     
    elif '大学' in line:           
        print('{}'.format(line))   
        n += 1
print("包含大学的名称数量是{}".format(n))  # 输出大学计数
print("包含学院的名称数量是{}".format(m))  # 输出学院计数
