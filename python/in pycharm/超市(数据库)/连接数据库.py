import pymysql as sql

coon = sql.connect(host='localhost', port=3306, user='', password='', database='商品表', charset='utf8')
cur = coon.cursor()

cur.close()
coon.close()