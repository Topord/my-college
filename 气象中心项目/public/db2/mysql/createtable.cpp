/*
 * 程序名：createtable.cpp, 演示用开发框架操作mysql(建表)
 * 作者：topord
*/

#include "_mysql.h"

int main(int argc, char* argv[])
{
  connection conn;  // 

  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306", "utf8") != 0)
  {
    printf("connect database failed.\n%s\n", conn.m_cda.message);
    return -1;
  }

  sqlstatement stmt(&conn);  // 操作SQL语句的对象 

  // 准备创建表的SQL语句
  // 学生表stu, 学生编号id, 姓名name, 身高height, 生日date, 学生说明memo, 图片pic

  stmt.prepare("create table stu(id      bigint(10),\
                   name    varchar(30),\
                   height  decimal(8, 2),\
                   date    datetime,\
                   memo    longtext,\
                   pic     longblob,\
                   primary key(id))");    

  if (stmt.execute() != 0)
  {
    printf("stmt.execute() failed.\n%s\n%s\n", stmt.m_sql, stmt.m_cda.message); return -1;
  }

  printf("create table stu ok\n");

  return 0;
}

