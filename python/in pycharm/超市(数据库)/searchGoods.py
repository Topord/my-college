import pymysql as sql
# -----------------------------------------------------------------------------------------------------python与数据库的链接
coon = sql.connect(host='localhost', port=3306, user='root', password='723916', database='商品表', charset='utf8')
cur = coon.cursor()

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
            p2 = "{}             {}             {}元              {}件".format(a, get_goods_name, get_goods_price, get_store_number)
            print(p1)
            print(p2)
        a = input("请输入你需要查找的商品id(n-->退出):")
searchGoods()
print("end")