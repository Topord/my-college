#输入姓名
name=input('请输入学生姓名：')
while(name==''):
    name=input('输入格式不对，请再次输入：')
#语文成绩输入
a=input('请输入语文成绩(0-100)：')
q=0
while(a==''):
    a=input('输入格式不对，请输入(语文)成绩(0-100)：')
while(a!=''):
    for i in a:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             q+=1
    if(q==0):
        yuwen=eval(a)
        break
    else:
        a=input('请输入你的成绩(语文)(0-100):')
    q=0
#数学成绩输入
b=input('请输入数学成绩(0-100)：')
w=0
while(b==''):
    b=input('输入格式不对，请输入(数学)成绩(0-100)：')
while(b!=''):
    for i in b:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             w+=1
    if(w==0):
        shuxue=eval(b)
        break
    else:
        b=input('请输入你的成绩(数学)(0-100):')
    w=0
#英语成绩输入
c=input('请输入英语成绩(0-100)：')
t=0
while(c==''):
    c=input('输入格式不对，请输入(英语)成绩(0-100)：')
while(c!=''):
    for i in c:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             t+=1
    if(t==0):
        yingyu=eval(c)
        break
    else:
        c=input('请输入你的成绩(英语)(0-100):')
    t=0
#体育成绩输入
d=input('请输入体育成绩(0-100)：')
r=0
while(d==''):
    d=input('输入格式不对，请输入(体育)成绩(0-100)：')
while(d!=''):
    for i in d:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             r+=1
    if(r==0):
        tiyu=eval(d)
        break
    else: 
        d=input('请输入你的成绩(体育)(0-100):')
    r=0
#劳动成绩输入
e=input('请输入劳动成绩(0-100)：')
y=0
while(e==''):
    e=input('输入格式不对，请输入(劳动)成绩(0-100)：')
while(e!=''):
    for i in e:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             y+=1
    if(y==0):
        laodong=eval(e)
        break
    else:
        e=input('请输入你的成绩(劳动)(0-100):')
    y=0
#美术成绩输入
f=input('请输入美术成绩(0-100)：')
u=0
while(f==''):
    f=input('输入格式不对，请输入(美术)成绩(0-100)：')
while(f!=''):
    for i in f:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             u+=1
    if(u==0):
        meishu=eval(f)
        break
    else:
        f=input('请输入你的成绩(美术)(0-100):')
    u=0
#音乐成绩输入
g=input('请输入音乐成绩(0-100)：')
p=0
while(g==''):
    f=input('输入格式不对，请输入(音乐)成绩(0-100)：')
while(g!=''):
    for i in f:
         if(i!='1' and i!='2'and i!='3'and i!='4'and i!='5'and i!='6'and i!='7'and i!='8'and i!='9'and i!='0'):
             print('输入的值为',i,'不符合要求')
             p+=1
    if(p==0):
        yinyue=eval(g)
        break
    else:
        g=input('请输入你的成绩(音乐)(0-100):')
    p=0
#输出分数
print(name,'你的语文成绩为',yuwen,'数学成绩为',shuxue,'英语成绩为',yingyu,'体育成绩为',tiyu,'劳动成绩为',laodong,'美术成绩为',meishu,'音乐成绩为',yinyue)
#进行判断并生成评语（对语数外三科）
print('从基础科目上来看：')
#奖励（全在90及以上）-------------------------------------------------------------------------------------------------------------
if(yuwen>=90 and shuxue>=90 and yingyu>=90):
    print('你真是一个学习成绩好并且发展全面的孩子。')
    if(yuwen>shuxue):
        if(yuwen>yingyu):
            print('而且你在语文方面真的很有天赋，但在英语和数学方面还可以加把力。')
        else:
            print('而且你在英语方面真的很有天赋，但在数学和语文方面还可以学的更精一点。')
    if(yuwen==shuxue==yuwen==yingyu):
        print('你是一个在各个方面都有很大天赋的孩子，继续努力，别松懈！')
    elif(yuwen==shuxue):
        print('语文和数学一样优秀。')
    elif(shuxue==yingyu):
        print('数学和英语一样优秀。')
    elif(yuwen==yingyu):
        print('语文和英语一样优秀。')#分数高时对语数外三科的评语
if(90>yuwen>=60 and 90>shuxue>=60 and 90>yingyu>=60):#（三个全在60到90）-------------------------------------------------------------
    print('你的成绩很不错了，相信在以后你会有很大的提升。')
    if(shuxue>80):
        print('数学是你的强项呢，')
        if(yingyu>80):
            print('另外你的英语也是一个亮点。')
        elif(yingyu>80):
            print('另外你的语文也是一个亮点。')
    elif(yuwen>80):
        print('语文是你的强项呢，')
        if(yingyu>80):
            print('另外你的英语也是一个亮点。')
        elif(shuxue>80):
            print('另外你的数学也是一个亮点。')
    elif(yingyu>80):
         print('英语是你的强项呢。')
         if(yingyu>80):
            print('另外你的英语也是一个亮点。')
         elif(yuwen>80):
            print('另外你的语文也是一个亮点。')
#两个在>=90，另外一个在60--90------------------------------------------------------------------------------------------------------
if(yuwen>=90 and 90>shuxue>=60 and 90>yingyu>=60):
    print('如果加强除语文以外两科的学习的话你会更优秀。')
elif(shuxue>=90 and 90>yingyu>=60 and 90>yuwen>=60):
    print('如果加强除数学以外两科的学习的话你会更优秀。')
elif(yingyu>=90 and 90>shuxue>=60 and 90>yuwen>=60):
    print('如果加强除数学以外两科的学习的话你会更优秀。')
#有批评和表扬(一个>=90 一个在60--90 另一个不及格)------------------------------------------------------------------
if(yuwen>=90 and 90>shuxue>=60 and 90>yingyu>=60):
    print('语文成绩很优秀了，其他两科提升一下就更好了。')
elif(yuwen>=90 and 90>shuxue>=60 and yingyu<=60):
    print('你的语文成绩很好，数学也不错，但是英语不及格哈,望改正。')
elif(yuwen>=90 and shuxue<=60 and 90>yingyu>=60):
    print('你的语文成绩很好，英语也不错，但是数学不及格哈,望改正。')
if(shuxue>=90 and 90>yuwen>=60 and 90>yingyu>=60):#语文
    print('数学成绩很优秀了，其他两科提升一下就更好了。')
elif(shuxue>=90 and 90>yuwen>=60 and yingyu<=60):
    print('你的数学成绩很好，语文也不错，但是英语不及格哈,望改正。')
elif(shuxue>=90 and yuwen<=60 and 90>yingyu>=60):
    print('你的数学成绩很好，英语也不错，但是语文不及格哈,望改正。')
if(yingyu>=90 and 90>yuwen>=60 and 90>shuxue>=60):#数学
    print('英语成绩很优秀了，其他两科提升一下就更好了。')
elif(yingyu>=90 and 90>yuwen>=60 and shuxue<=60):
    print('你的英语成绩很好，语文也不错，但是数学不及格哈,望改正。')
elif(yingyu>=90 and yuwen<=60 and 90>shuxue>= 60):#英语
    print('你的英语成绩很好，数学也不错，但是语文不及格哈,望改正。')
#一个>=90,两个在60--90-------------------------------------------------------------------------------------------------------------
if(yuwen>=90 and 90>shuxue>60 and 90>yingyu>60):
    print('继续努力，争取全部上90分。')
elif(shuxue>=90 and 90>yuwen>60 and 90>yingyu>60):
    print('继续努力，争取全部上90分。')
elif(yingyu>=90 and 90>yuwen>60 and 90>shuxue>60):
    print('继续努力，争取全部上90分。')
#一个>=90，两个不及格--------------------------------------------------------------------------------------------------------------
if(yuwen>=90 and shuxue<60 and yingyu<60):
    print('你的数学成绩还不错，但其余两科都不及格，偏科严重,望改进。')
elif(yingyu>=90 and shuxue<60 and yuwen<60):
    print('你的英语成绩还不错，但其余两科都不及格，偏科严重，望改进。')
elif(yuwen>=90 and yingyu<60 and shuxue<60):
    print('你的语文成绩还不错，但其余两科都不及格，偏科严重，望改进。')
#两个在60--90 ，一个不及格---------------------------------------------------------------------------------------------------------
if(90>=shuxue>=60 and 90>=yingyu>=60 and yuwen<=60):
    print('你的数学和英语还可以提升，语文学好了那你就是优秀的学生了。')
elif(90>=60 and 90>=yuwen>=60 and shuxue<=60):
    print('你的语文和英语还可以提升，数学学好了那你就是优秀的学生了。')
elif(90>=shuxue>=60 and 90>=yuwen>=60 and yingyu<=60):
    print('你的语文和数学还可以提升，英语学好了那你就是优秀的学生了。')
#一个在60--90，两个不及格-----------------------------------------------------------------------------------------------------------
if(90>=yuwen>60 and shuxue<60 and yingyu<60):
    print('你偏科很严重，希望你能花更多的时间在不及格的两科上。')
elif(90>=shuxue>60 and yuwen<60 and yingyu<60):
    print('你偏科很严重，希望你能花更多的时间在不及格的两科上。')
elif(90>=yingyu>60 and yuwen<60 and shuxue<60):
    print('你偏科很严重，希望你能花更多的时间在不及格的两科上。')
#全部为60---------------------------------------------------------------------------------------------------------------------
if(yuwen==60 and shuxue==60 and yingyu==60):
    print('你真幸运，全部压线。但任需要很大的努力。')
#全部不及格--------------------------------------------------------------------------------------------------------------------------
if(yuwen<60 and shuxue<60 and yingyu<60):
    print('你的三个科目全部不及格，在学习上，你还有很长的路要走！')


#对于副科---------------------------------------------------------------------------------------------------------------------------
print('从副科上来看，')
if(tiyu>=90):
    print('你的身体健壮，')
elif(60>=tiyu>90):
    print('你的身体素质一般，还有很大的进步空间。')
elif(tiyu<60):
    print('你的身体有点羸弱，希望可以加强哈！')

if(laodong>=90):
    print('同时，你还是一个热爱劳动的孩子，')
elif(60>=laodong>90):
    print('但你的劳动力还可以有所提升哈！')
elif(laodong<60):
    print('劳动能力欠缺，必须要有所提升！')

if(meishu>=90):
    print('看不出来你还有很多艺术细胞呢！')
elif(60>=meishu>90):
    printf('美术能力还可以提升哈！')
elif(meishu>60):
    print('画画也是看天赋的，勤能补拙,')

if(yinyue>=90):
    print('你还是一个小艺术家呢！')
elif(90>yinyue>=60):
    print('或许多听听古典音乐能让你音乐成绩提升,')
elif(yinyue<60):
    print('音乐不好不是大问题，自己喜欢音乐就对了.')


