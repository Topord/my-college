# pymysql

### python与mysql的链接

```python
coon = sql.connect(host='localhost', port=3306, user='', password='', database='商品进出货', charset='utf8')
cs1 = coon.cursor()


cs1.close()
coon.close()
```

### python运行sql语句

使用语句

```python
sql_select2 = 'select 编号 from 商品数据 '
cs1.execute(sql_select2)
```

### python向mysql写入数据

```python
coon = sql.connect(host='localhost', port=3306, user='root', password='1Q2W3E4R??', database='商品进出货',
                   charset='utf8')
cs1 = coon.cursor()

sql_insert = 'insert into 商品数据(商品编号, 商品名称, 进价, 售价, 库存) values(1,"2",3,4,5)'
#sql_insert = 'delete from 商品数据 where 商品编号=1'
cs1.execute(sql_insert)

coon.commit()
cs1.close()
coon.close()
```

### python读取mysql数据的方法

##### 直接获取

```python
coon = sql.connect(host='localhost', port=3306, user='root', password='1Q2W3E4R??', database='商品进出货',charset='utf8')
cs1 = coon.cursor()

sql_select = 'select * from 商品数据 where 编号=1'
a=cs1.execute(sql_insert)
print(a)#输出受影响行数，并不输出真正的信息。

coon.commit()
cs1.close()
coon.close()
```

##### 输出元组

```python
coon = sql.connect(host='localhost', port=3306, user='root', password='1Q2W3E4R??', database='商品进出货',charset='utf8')
cs1 = coon.cursor()

sql_select = 'select * from 商品数据 where 编号=1'
cs1.execute(sql_insert)
#正确应该读取光标
print(cursor.fetchone())
print(cursor.fetchone())#光标在数据里顺次移动

print(cursor.fetchmany(n))

print(cursor.fetchall())

coon.commit()
cs1.close()
coon.close()
```

##### 输出列表

```python
coon = sql.connect(host='localhost', port=3306, user='root', password='1Q2W3E4R??', database='商品进出货',charset='utf8')
cs1=coon.cursor(pymysql.cursors.DictCursor)

sql_select = 'select * from 商品数据'
cs1.execute(sql_insert)

print(cursor.fetchall())

coon.commit()
cs1.close()
coon.close()
```

### 对于光标位置的处理

```python
cs1.scroll(n,mode='absolute')#相对绝对位置移动

cs1.scroll(n,mode='relative')#相对绝对位置移动
```

