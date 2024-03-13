import pymysql as sql

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
        a = input("请输入你需要修改商品的id(n-->退出):")

modifyGoods()
print("end")