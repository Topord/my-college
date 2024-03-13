import pymysql as sql

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
        get_exam = list(cur.fetchall())
        lenth = len(get_exam)
        for i in range(lenth):
            a = int(a)
            if a != get_exam[i][0]:
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
deleteGoods()
print("end")