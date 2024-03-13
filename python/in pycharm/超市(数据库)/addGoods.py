import pymysql as sql

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
            if a == get_exam[i][0]:
                flag = 0
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
addGoods()
print("end")