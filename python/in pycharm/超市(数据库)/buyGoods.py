import pymysql as sql
# 告知客人商品信息
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
            a = input("没有对应的id,请重新输入.")
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
            return get_store[0][2]
# a-->id  get_store_number-->此商品库存量  last_number-->剩余的数量
def buyGoods():
    a = input("请输入你购买的商品id(n-->退出):")
    while a != '':
        if a == 'n':
            break
        else:
            get_store_number = showGoods(int(a))
            buy_num = input("请输入需要购买商品的数量:")
            buy_num = int(buy_num)
            if buy_num <= get_store_number:
                # ----------------------------------------------金额部分
                # 获取单价
                coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
                cur = coon.cursor()
                search_goods_sql = 'SELECT * FROM goods where goodsid = {};'.format(int(a))
                cur.execute(search_goods_sql)
                coon.commit()
                print(type(cur.fetchone()))
                print(cur.fetchall())
                cur.close()
                coon.close()
                break
                # 计算金额
                add = buy_num*get_goods_price
                cur.close()
                coon.close()
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
                break
            else:
                print("购买量{}大于库存量{},无法购买!".format(buy_num, get_store_number))
        a = input("请输入你购买的商品id(n-->退出):")
buyGoods()
print("end")
