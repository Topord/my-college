import pymysql as sql
import datetime as dt
# 进货
def addGoods():
    a = input("请输入你需要进货商品id(n退出)")
    while a != '':
        # ----------------------------------------------------------------------------python与数据库的链接
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        # --------------------------------------------------------------------退出
        if a == 'n':
            cur.close()
            coon.close()
            break
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所以条形码
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查
        flag = 1
        get = list(cur.fetchall())
        lenth = len(get)
        for i in range(lenth):
            a = int(a)
            if a == get[i][0]:
                flag = 0
                print("编码重复，请重新输入.")
                cur.close()
                coon.close()
                break
        if flag == 1:
            goodsid = a
            goodsname = input("商品名字:")
            goodsprice = input("商品单价:")
            goodsnumber = input("商品数量:")

            goodsname = "'" + goodsname + "'"  # 对goodsname进行加工，以便于可写入navicat

            goods_sql = 'INSERT INTO goods(goodsid, goodsname, goodsprice) VALUES({},{},{});'.format(goodsid, goodsname,
                                                                                                     goodsprice)

            store_sql = 'INSERT INTO storehouse(goodsid, goodsname, goodsnumber) VALUES({},{},{});'.format(goodsid,
                                                                                                           goodsname,
                                                                                                           goodsnumber)

            cur.execute(goods_sql)
            cur.execute(store_sql)
            coon.commit()
            print("添加成功")
            cur.close()
            coon.close()

        a = input("请输入你需要进货商品id(n退出)")
# 删除
def deleteGoods():
    a = input("请选择你需要删除商品的条形码(n-->退出):")
    while a != '':
        # ----------------------------------------------------------------------------python与数据库的链接
        coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
        cur = coon.cursor()
        if a == 'n':  # --------------------------------------------------------------------退出
            cur.close()
            coon.close()
            break
        # ---------------------------------------------------------------------------检测是否有重复
        # ---------------------------------------获取所以条形码
        search_sql = 'SELECT * FROM goods ;'
        cur.execute(search_sql)
        coon.commit()
        # ----------------------------------------------检查
        flag = 1
        get = list(cur.fetchall())
        lenth = len(get)
        for i in range(lenth):
            a = int(a)
            if a != get[i][0]:
                flag = 0
            else:
                flag = 1
                break
        # ----------------------------------------------------------------------------------------根据检查的结果进行判断
        if flag == 0:
            print("没有该id对应的物品,请重新输入.")
        elif flag == 1:
            goods_sql = 'DELETE FROM goods where goodsid = {};'.format(int(a))
            store_sql = 'DELETE FROM storehouse where goodsid = {};'.format(int(a))

            cur.execute(goods_sql)
            cur.execute(store_sql)
            coon.commit()
            print("删除完成")
            cur.close()
            coon.close()

        a = input("请选择你需要删除商品的条形码(n-->退出):")
# 修改
def modifyGoods():
    a = input("请输入你需要修改商品的id(n-->退出):")
    while a != '':
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
        # ----------------------------------------------选择
        if flag == 0:
            cur.close()
            coon.close()
            print("没有此id对应的物品,请重新输入.")
        elif flag == 1:
            b = input("请选择你需要更改的内容(1-->name;2-->price;3-->number):")
            if b == '1':
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
                mod_sql = "UPDATE storehouse set goodsname = '{}' where goodsid = {};".format(mod_name, int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
            elif b == '2':
                mod_price = input("请输入需要更改的单价:")
                # 在goods中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = 'UPDATE goods set goodsprice = {} where goodsid = {};'.format(int(mod_price), int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
            elif b == '3':
                mod_number = input("请输入新的库存数量:")
                # 在storehouse中更新
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                mod_sql = 'UPDATE storehouse set goodsnumber = {} where goodsid = {};'.format(int(mod_number), int(a))
                cur.execute(mod_sql)
                coon.commit()
                cur.close()
                coon.close()
                print("修改成功")
        a = input("请输入你需要修改商品的id(n-->退出):")
# 查找
def searchGoods():
    a = input("请输入你需要查找的商品id(n-->退出):")
    while a != '':
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
            p2 = "{}              {}              {}元             {}件".format(a, get_goods_name, get_goods_price, get_store_number)
            print(p1)
            print(p2)
        a = input("请输入你需要查找的商品id(n-->退出):")
# 显示
def showGoods(a):
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
            coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表',
                               charset='utf8')
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
            return get_store[0][2], a
# 购买 + 日报
def buyGoods():
    a = input("请输入你购买的商品id(n-->退出):")
    while a != '':
        if a == 'n':
            break
        else:
            get_store_number, a = showGoods(int(a))
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
                to = str(tm)[0:-7]
                get_goods_name = "'" + get_goods_name + "'"  # get_goods_name，以便于可写入navicat
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()

                get_goods_name = "{}".format(get_goods_name)
                to = "'{}'".format(to)
                add_sql = "INSERT INTO endfile(name, number, price, time) VALUES({},{},{},{});".format(get_goods_name, buy_num,
                                                                                                                  add, to)
                cur.execute(add_sql)
                coon.commit()
                cur.close()
                coon.close()
                # -------------------------------------------------写入小票
                fo = open('小票.txt', 'a', encoding='utf-8')
                get_goods_name = get_goods_name.strip("'")
                c1 = "{}                  {}                  {}".format(get_goods_name, buy_num, add)
                fo.write(str(c1))
                fo.writelines("\n")
                fo.close()
                break
            else:
                print("购买量{}大于库存量{},无法购买!".format(buy_num, get_store_number))
        a = input("请输入你购买的商品id(n-->退出):")
# 刷新日报
def update_endfile():
    coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
    cur = coon.cursor()
    update_sql = "truncate table endfile;"
    cur.execute(update_sql)
    cur.close()
    coon.close()
    print("刷新成功")
# 打印小票
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
# 解决日报的问题(√)
# 完成小票的操作(√)
# 开始写文档(√)
