#                 小超市（MYSQL）开发文档

## 一、程序效果

程序在执行时，可根据使用者输入相应的内容来执行不同的功能（进货、删除、修改、查找、购买打印小票、查看购买操作等）。在执行途中，使用者可以根据提示退出程序并在存放该程序的文件夹里面看见此次购买物品的记录（小票），也可以在navicat中的endfile表中看见超市中售出物品的数量以及时间。

## 二、整体结构

 ![整体结构.png](https://img1.imgtp.com/2022/03/18/Tk4mTwWT.png) 

## 三、数据库部分

先在navicat上建立了名为t1的链接，再在此链接中的表部分建立了名字为goods、storehouse、endfile的3个数据表.

### 	1.  goods表

#### 	1.1 创建语句

```mysql
-- 创建商品信息表（goods)
CREATE TABLE goods(
goodsid int PRIMARY KEY auto_increment,
goodsname VARCHAR(20) NOT NULL,
goodsprice int
);

```

#### 1.2 主要作用

​	此表主要用来记录并显示商品的ID、名字以及单价。

- ![1647600574133.png](https://img1.imgtp.com/2022/03/18/HZfaxVHc.png)

###   2. storehouse表

#### 2.1 创建语句

```mysql
#创建库存表
CREATE TABLE storehouse(
goodsid int PRIMARY KEY auto_increment,
goodsname VARCHAR(20) NOT NULL,
goodsnumber int
);

```

#### 	2.2 主要作用

此表用来当做商店的库存，会显示商品ID、商品名字、商品数量。

​											 ![1647600699108.png](https://img1.imgtp.com/2022/03/18/8LvIw9LE.png) 

###    3.  endfile表

#### 3.1 创建语句

```mysql
# 创建endfile表
CREATE TABLE endfile(
name VARCHAR(20) NOT NULL,
number int,
price int,
time VARCHAR(50)
);

```

#### 	3.2 主要作用

此表会记录使用者购买商品的信息。会显示所购商品名字、所购商品数量、所购价格、所购时间。

 											![1647600865915.png](https://img1.imgtp.com/2022/03/18/gcRB029R.png) 

###  4. 将python与数据库连接

#### 4.1 链接与断开

使用了python中的mysql模块，代码如下。

```python
import pymysql as sql
# 在调用数据库前------------------------------------------------------------------------------
coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
cur = coon.cursor()
# coon语句的意思为连接上我的mysql库中名为商品表的数据库，便于接下来的操作（goods、storehouse、endfile都是在此数据库中）
# cur语句的意思为打开光标
# 在调用完数据库中的数据后----------------------------------------------------------------------
cur.close()
coon.close()
# 需要将连接和光标关闭
```

#### 4.2 用python执行mysql语句

```python
# 例
import pymysql as sql
# 与数据库建立连接后 #
search_sql = 'SELECT * FROM goods ;' # 设置一个字符串变量等于你需要执行的mysql语句
cur.execute(search_sql) # 让数据库执行该语句
coon.commit() # 提交，注意在提交后才能看见结果
# 记得关闭连接和光标 #
```

#### 4.3 其他注意事项

1. 若使用navicat进行操作，需在操作后刷新表才能看见改动。
2. 注意mysql语句中的变量要与表头所规定的的变量一一对应。
3. 必须要连接成功后才能进行操作；
4. 创建表可以在navicat中进行。

### 5.  程序中使用到的MYSQL的操作语句

#### 5.1 插入信息

```mysql
insert into 表(列,列..) values(值,值..);
# 例
INSERT INTO goods(goodsid,goodsname,goodstype,place) VALUES 
(2, '山东红富士苹果（一级果）', '水果', '山东'),
(3, '康师傅桶装方便面（红烧牛肉面）','零食', '杭州'),
(4, '格力NS-8823变频空调', '电器',  '珠海'),
(5, '泰国山竹特级', '水果', '泰国');
```

#### 5.2 删除信息

```mysql
delete from 表 [where 条件]
# 例
DELETE FROM sale  where goodsid = 5;
```

#### 5.3 更新信息

```mysql
update 表 set 列 = 值,列 = 值... [where 条件]
# 例
UPDATE goods set place = '河南' where goodsid = 2;
```

#### 5.4 清除信息

```mysql
truncate table 表;
# 例
truncate table endfile;
```

#### 5.5 查询信息

```mysql
-- 查询部分列
SELECT * FROM goods;
```



## 四、python部分

### 1. 函数详解

#### 1.1  addGoods()

##### 1.1.1 主要作用

此函数用来向商品表、库存表添加一项新的物品。在使用时要求使用者输入新加入物品的ID、物品的名字、物品的单价、物品数量。

##### 1.1.2 代码部分

```python
a = input("请输入你需要进货商品id(n退出)")
while a != '':
    #----------------------------------------------------------------------------python与数据库的链接
    coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
    cur = coon.cursor()
    # --------------------------------------------------------------------退出
    if a == 'n':
        cur.close()
        coon.close()
        break
    # ---------------------------------------------------------------------------检查goods中是否已经存在该物品
    # ---------------------------------------获取所有物品的id
    search_sql = 'SELECT * FROM goods ;'
    cur.execute(search_sql)
    coon.commit()
    # ----------------------------------------------开始检查（用flag判断是否继续）
    flag = 1
    get = list(cur.fetchall())# 将元组变成列表方便截取需要的数据
    lenth = len(get)# 自适应，获取列表的长度
            for i in range(lenth):
                a = int(a)
                if a == get[i][0]:
                    flag = 0 # 若有重复的话就将17行附给flag的1变成0
                    print("编码重复，请重新输入.") # 提醒使用者
                    cur.close()
                    coon.close() # 关闭连接
                    break   # 返回到第一个while中并继续操作
            if flag == 1: # 若没有重复的ID
                goodsid = a # 商品的ID即为输入的a值
                goodsname = input("商品名字:")
                goodsprice = input("商品单价:")
                goodsnumber = input("商品数量:")

                goodsname = "'" + goodsname + "'"  # 对goodsname进行加工，以便于可写入navicat
                goods_sql = 'INSERT INTO goods(goodsid, goodsname, goodsprice) VALUES({},{},{});'.format(goodsid, goodsname, goodsprice) # 此语句向goods填入信息                                                                                               
 			   store_sql = 'INSERT INTO storehouse(goodsid, goodsname, goodsnumber) VALUES({},{},{});'.format(goodsid, goodsname, goodsnumber) # 此语句向storehouse填入信息                                                                                                                                                                                   
                cur.execute(goods_sql) # 执行
                cur.execute(store_sql) # 执行
                coon.commit() # 提交
                print("添加成功")
                cur.close()
                coon.close()
            a = input("请输入你需要进货商品id(n退出)") # 继续循环
```

注：addGoods()函数中的==检查重复部分==与其他函数不同

##### 1.1.3 addGoods()中检查重复部分

- ![addGoods.png](https://img1.imgtp.com/2022/03/18/o75DS16v.png)

##### 1.1.4 其他函数中的检查重复部分

flag = 1为没找到相等的ID，为0则为找到相等的ID。

#### 1.2 deleteGoods()

##### 1.2.1 主要作用

删除使用者输入ID对应的物品在goods表和storehouse中的记录。

##### 1.2.2 代码部分

```python
def deleteGoods():
    a = input("请选择你需要删除商品的条形码(n-->退出):")
    while a != '':
 # ----------------------------------------------------------------------------python与数据库的链接
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        if a == 'n':  # --------------------------------------------------------------------退出
            cur.close()
            coon.close() # 关闭连接
            break
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所有物品ID
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查
        flag = 1
         #将goods表中所有的信息转换成列表，获取每一个列表元素的第1个元素，即为物品ID
        get = list(cur.fetchall()) 
        lenth = len(get) # 可根据物品的种类增加列表长度
        for i in range(lenth):
            a = int(a)
            if a != get[i][0]:
                flag = 0
            else:
                flag = 1
                break
        # -------------------------------------------------------------根据检查的结果进行判断
        if flag == 0:
            print("没有该id对应的物品,请重新输入.")
        elif flag == 1:
            goods_sql = 'DELETE FROM goods where goodsid = {};'.format(int(a))
            store_sql = 'DELETE FROM storehouse where goodsid = {};'.format(int(a))
            
            cur.execute(goods_sql) # 在goods中删除
            cur.execute(store_sql) # 在storehouse中删除
            coon.commit()
            print("删除完成")
            cur.close()
            coon.close()

        a = input("请选择你需要删除商品的条形码(n-->退出):")
```

#### 1.3 modifyGoods()

##### 1.3.1 主要作用

让使用者输入需要更改的物品的ID，之后让使用者进行选择需要更改的内容（名字、单价、数量）、最后输入更改结果，并在goods表以及storehouse中刷新。

例1：需要更改ID为2的物品的名字。（耳机-->蓝牙耳机）

原来的样子：

storehouse表中

- ![1647651302174.png](https://img1.imgtp.com/2022/03/19/PtanDEjn.png)

 goods表中

- ![1647651373466.png](https://img1.imgtp.com/2022/03/19/li6ni5A6.png)

使用时python部分：

![1647651465769.png](https://img1.imgtp.com/2022/03/19/136Pymb6.png)     

再次查看goods表以及storehouse表。

​                                ![1647651544126.png](https://img1.imgtp.com/2022/03/19/EK9FOdsI.png) 

- ![1647651569599.png](https://img1.imgtp.com/2022/03/19/SYJqyFdw.png)

##### 1.3.2 代码部分

```python 
def modifyGoods():
    a = input("请输入你需要修改商品的id(n-->退出):")
    while a != '':
        # 连接数据库
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        # ---------------------------------------退出
        if a == 'n':
            cur.close()
            coon.close()
            break
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所有id
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查（同上）
        flag = 1
        get_exam = list(cur.fetchall())
        lenth = len(get_exam)
        for i in range(lenth):
            a = int(a)
            if a != get_exam[i][0]:
                flag = 0
            else:
                flag = 1
                break
        # ----------------------------------------------选择
        if flag == 0:
            cur.close()
            coon.close()
            print("没有此id对应的物品,请重新输入.")
        elif flag == 1:
            b = input("请选择你需要更改的内容(1-->name;2-->price;3-->number):")
            if b == '1': # 对商品的名字进行修改
                mod_name = input("请输入需要更改的名字:")
                # 在goods中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = "UPDATE goods set goodsname = '{}' where goodsid = {};".format(mod_name, int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                # 在storehouse中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = "UPDATE storehouse set goodsname = '{}' where goodsid ={};".format(mod_name, int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
            elif b == '2': # 对商品的单价进行修改
                mod_price = input("请输入需要更改的单价:")
                # 在goods中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = 'UPDATE goods set goodsprice = {} where goodsid = {};'.format(int(mod_price), int(a)) # 因为创建表时price为int,故需要进行类型转化
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
            elif b == '3': # 对商品数量进行修改，只需在storehouse表中修改
                mod_number = input("请输入新的库存数量:")
                # 在storehouse中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = 'UPDATE storehouse set goodsnumber = {} where goodsid ={};'.format(int(mod_number), int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
        a = input("请输入你需要修改商品的id(n-->退出):")
```



#### 1.4 searchGoods()

##### 1.4.1 主要作用

将使用者输入ID对应物品的信息通过“ID     名字   单价    库存量”的形式显示出来。

例：查询ID为2的物品的信息。

- ![1647650804226.png](https://img1.imgtp.com/2022/03/19/uQhl2tiS.png)

##### 1.4.2 代码部分

```python 
def searchGoods():
    a = input("请输入你需要查找的商品id(n-->退出):")
    while a != '':
        # 与数据库连接
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        # ---------------------------------------------------退出
        if a == 'n':
            cur.close()
            coon.close()
            break
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所有物品id
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查（检查方式同上）
        flag = 1
        get_exam = list(cur.fetchall())
        lenth = len(get_exam)
        for i in range(lenth):
            a = int(a)
            if a != get_exam[i][0]:
                flag = 0
            else:
                flag = 1
                break
        if flag == 0:
            print("没有对应的id,请重新输入.")
            cur.close()
            coon.close()
        elif flag == 1:
            # ------------------------在goods中查找
            search_goods_sql = 'SELECT * FROM goods where goodsid = {};'.format(int(a))
            cur.execute(search_goods_sql)
            coon.commit()
            get_goods = list(cur.fetchall())
            # 对get_goods进行处理
            get_goods_name = get_goods[0][1]   # 获取该物品的名字
            get_goods_price = get_goods[0][2]   # 获取该物品的单价
            cur.close()
            coon.close()
            # ------------------------在storehouse中查找
            coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
            cur = coon.cursor()
            search_store_sql = 'SELECT * FROM storehouse where goodsid = {};'.format(int(a))
            cur.execute(search_store_sql)
            coon.commit()
            get_store = list(cur.fetchall())
            get_store_number = get_store[0][2]   # 获取该物品的库存量
            cur.close()
            coon.close()
            # 将查询到的数据打印出来
            p1 = "goodsid" + "        " + "goodsname" + "        " + "goodsprice" + "        " + "goodsnumber"
            p2 = "{}              {}              {}元             {}件".format(a, get_goods_name, get_goods_price, get_store_number)   # 商品ID即为上文中输入的a
            print(p1)
            print(p2)                # 将信息打印
        a = input("请输入你需要查找的商品id(n-->退出):")
```

#### 1.5  showGoods()

##### 1.5.1 主要作用

该函数并不是独立存在，而是嵌套在buyGoods()函数中，在使用者输入需要购买物品的ID时，它会先进行对此ID的检查重复功能，若重复，则提醒重新输入；若重复，则会先显示商品的信息（“ID     名字   单价    库存量”）。显示完成后，它也会返回此商品的ID以及库存量。

例：购买ID为7的商品前：

- ![1647652300234.png](https://img1.imgtp.com/2022/03/19/eLoWzDWE.png)

##### 1.5.2 代码部分（类似于searchGoods()）

```python
def showGoods(a): #传入的a为buyGoods()函数中输入的商品ID
    while a != '':
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所有物品id
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查
        flag = 1
        get_exam = list(cur.fetchall())
        lenth = len(get_exam)
        for i in range(lenth):
            a = int(a)
            if a != get_exam[i][0]:
                flag = 0
            else:
                flag = 1
                break
        if flag == 0:
            a = input("没有对应的id,请重新输入:")
            cur.close()
            coon.close()
            continue
        elif flag == 1:
            # ------------------------在goods中查找
            search_goods_sql = 'SELECT * FROM goods where goodsid = {};'.format(int(a))
            cur.execute(search_goods_sql)
            coon.commit()
            get_goods = list(cur.fetchall())
            # 对get_goods进行处理
            get_goods_name = get_goods[0][1]
            get_goods_price = get_goods[0][2]
            cur.close()
            coon.close()
            # ------------------------在storehouse中查找
            coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
            cur = coon.cursor()
            search_store_sql = 'SELECT * FROM storehouse where goodsid = {};'.format(int(a))
            cur.execute(search_store_sql)
            coon.commit()
            get_store = list(cur.fetchall())
            get_store_number = get_store[0][2]
            cur.close()
            coon.close()
            # 将查询到的数据打印出来
            p1 = "goodsid" + "        " + "goodsname" + "        " + "goodsprice" + "        " + "goodsnumber"
            p2 = "{}              {}              {}元              {}件".format(a, get_goods_name, get_goods_price,
                                                                               get_store_number)
            print(p1)
            print(p2)
            return get_store[0][2], a # 返回商品库存量以及ID
```

#### 1.6 buyGoods()

##### 1.6.1 主要作用

1. 显示使用者此次购物的总金额；
2. 在endfile表中写入购物记录；
3. 更新ID对应的物品在storehouse表中的库存量；
4. 在小票.txt文档中写入此次购物对应的信息；
5. 若购买量大于库存量，则会提示使用者。

例：购买ID为3的物品4件

 ![1647653428128.png](https://img1.imgtp.com/2022/03/19/6kFt4Ng5.png) 

endfile表中

- ![1647653477476.png](https://img1.imgtp.com/2022/03/19/uL0CibAj.png)

原来的storehouse表

​                                        ![1647653511582.png](https://img1.imgtp.com/2022/03/19/XTVqmDmM.png) 

现在的storehouse表

​                                        ![1647653557279.png](https://img1.imgtp.com/2022/03/19/mXqZWxn0.png) 

小票中

 ![1647653597540.png](https://img1.imgtp.com/2022/03/19/FIGLwYAJ.png) 

当购买量大于库存量时

- ![1647653780063.png](https://img1.imgtp.com/2022/03/19/0fOAcezs.png)

##### 1.6.2 代码部分

```python
def buyGoods():
    a = input("请输入你购买的商品id(n-->退出):")
    while a != '':
        if a == 'n':
            break
        else:
            get_store_number, a = showGoods(int(a))  # 接收showGoods()的返回值
            buy_num = input("请输入需要购买商品的数量:")
            buy_num = int(buy_num)
            if buy_num <= get_store_number:
                # ----------------------------------------------金额部分
                # 获取单价
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表',charset='utf8')
                cur = coon.cursor()
                search_goods_sql = 'SELECT * FROM goods where goodsid = {};'.format(int(a))
                cur.execute(search_goods_sql)
                coon.commit()
                cur.close()
                coon.close()
                get_goods = cur.fetchall()
                # 对get_goods进行处理
                get_goods_name = get_goods[0][1]
                get_goods_price = get_goods[0][2]
                # 计算金额
                add = buy_num*get_goods_price
                print("此次购买花费{}元".format(add))
                # -----------------------------------------------更新库存
                last_number = get_store_number - buy_num
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                up_store_sql = "UPDATE storehouse set goodsnumber = '{}' where goodsid = {};".format(last_number, int(a))
                cur.execute(up_store_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("购买完成")
                # ------------------------------------------------写入endfile
                tm = dt.datetime.today()
                to = str(tm)[0:-7] # 只显示年月日、时分秒
                get_goods_name = "'" + get_goods_name + "'"  # get_goods_name，以便于可写入navicat
                
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()

                get_goods_name = "{}".format(get_goods_name)
                to = "'{}'".format(to) # to为当前购买的时间
                add_sql = "INSERT INTO endfile(name, number, price, time) VALUES({},{},{},{});".format(get_goods_name, buy_num, add, to)
                cur.execute(add_sql)
                coon.commit()
                cur.close()
                coon.close()
                # -------------------------------------------------写入小票
                fo = open('小票.txt', 'a', encoding='utf-8') # 在程序的开头已打开小票的文档
                # 第一行已经写入了具体格式，所以要用'a'
                get_goods_name = get_goods_name.strip("'") # 将获得的名字两边的'删除
                c1 = "{}                  {}                  {}".format(get_goods_name, buy_num, add)
                fo.write(str(c1))
                fo.writelines("\n") # 写完后将光标移动到下一行，便于下次书写
                fo.close()
                break
            else:
                print("购买量{}大于库存量{},无法购买!".format(buy_num, get_store_number)) # 提醒购物者库存量小于所购买量
        a = input("请输入你购买的商品id(n-->退出):")
```

注：buyGoods()中的检查重复的功能已在showGoods()中实现。

#### 1.7 update_endfile()

##### 1.7.1 主要作用

将endfile表进行刷新

运行前：

- ![1647654339446.png](https://img1.imgtp.com/2022/03/19/miMRbNOG.png)

运行后：

​                                   ![1647654380487.png](https://img1.imgtp.com/2022/03/19/Zf4T38VA.png) 

##### 1.7.2 代码部分

```python 
def update_endfile():
    coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
    cur = coon.cursor()
    update_sql = "truncate table endfile;" # 对endfile表进行全部刷新
    cur.execute(update_sql)
    cur.close()
    coon.close()
    print("刷新成功")
```

#### 1.8 recepit()

##### 1.8.1 主要作用

当退出时，给小票进行结尾。

运行前：

- ![1647654608992.png](https://img1.imgtp.com/2022/03/19/ShcrpuMC.png)

运行后：

![1647654645662](../AppData/Roaming/Typora/typora-user-images/1647654645662.png)

##### 1.8.2 代码部分

```python
def recepit():
    # 在endfile表中获取购买物品的金额
    end = 0
    coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
    cur = coon.cursor()
    find_sql = "SELECT * FROM endfile;"
    cur.execute(find_sql)
    coon.commit()
    cur.close()
    coon.close()
    # 计算总金额
    get = list(cur.fetchall())
    lenth = len(get)
    for i in range(lenth):
        end += get[i][2]
    # 打印小票结尾
    fo = open('小票.txt', 'a', encoding='utf-8')
    c2 = "该次购物总共花费{}元,谢谢惠顾!".format(end)
    fo.write(str(c2))
    fo.close()
```

### 2. 其余部分

#### 2.1 引入的库

```python 
import pymysql as sql  # 与数据库有关
import datetime as dt  # 与世界有关
```

#### 2.2 程序部分

##### 2.2.1 程序一开始就打印小票结构

```python
fo = open('小票.txt', 'w', encoding='utf-8')
co = "goodsname            buy_num            price"
fo.write(str(co))
fo.writelines("\n") # 将光标换到下一行下次便于书写
fo.close()
```

因为写入模式是"w",故每次进入程序后都会刷新小票。

##### 2.2.2 整体判断部分

```python 
jd = input("请输入接下来的操作【a】-->进货;【b】-->删除;【c】-->修改;【d】-->查找;【e】-->购买;【f】-->刷新记录;【p】-->退出")
```

##### 2.2.3 程序整体

```python 
add = 0

fo = open('小票.txt', 'w', encoding='utf-8')
co = "goodsname            buy_num            price"
fo.write(str(co))
fo.writelines("\n")
fo.close()

jd = input("请输入接下来的操作【a】-->进货;【b】-->删除;【c】-->修改;【d】-->查找;【e】-->购买;【f】-->刷新记录;【p】-->退出")
while jd != '':
    if jd == 'a':
        addGoods()
    elif jd == 'b':
        deleteGoods()
    elif jd == 'c':
        modifyGoods()
    elif jd == 'd':
        searchGoods()
    elif jd == 'e':
        buyGoods()
    elif jd == "f":
        update_endfile()
    elif jd == 'p':
        # 通过Navicat获取总金额并写入小票结尾
        recepit()
        break
    jd = input("请选择接下来的操作【a】-->进货;【b】-->删除;【c】-->修改;【d】-->查找;【e】-->购买;【f】-->刷新记录;【p】-->退出")
    
print("end")
```

