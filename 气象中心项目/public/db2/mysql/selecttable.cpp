/*
 * 程序名：selecttable.cpp，此程序查询stu表中的数据
 * 作者：topord
 */

#include "_mysql.h"

struct stu
{
  long id;
  char name[31];
  double height;
  char date[21];
}instu;

int main()
{
  connection conn;

  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306", "utf9") != 0)
  {
    printf("conn.connecttodb() failed\n%s\n", conn.m_cda.message); return -1;
  }

  sqlstatement stmt(&conn);

  int imin = 0, imax = 0;

  stmt.prepare("\
  select id, name, height, date_format(date, '%%Y-%%m-%%d %%H:%%i:%%s') from stu\
  where id>=:1 and id<=:2");
  
  stmt.bindin(1, &imin);
  stmt.bindin(2, &imax);
  stmt.bindout(1, &instu.id);
  stmt.bindout(2, instu.name, 30);
  stmt.bindout(3, &instu.height);
  stmt.bindout(4, instu.date, 20);
  
  imin = 1110;
  imax = 1114;
  
  if (stmt.execute() != 0)
  {
    printf("stmt.execute() failed. \n%s\n%s\n", stmt.m_sql, stmt.m_cda.message); return -1;
  }

  while (true)
  {
    memset(&instu, 0, sizeof(struct stu));

    if (stmt.next() != 0) break;

    printf("id=%d, name=%s, height=%.02f, date=%s\n", instu.id, instu.name, instu.height, instu.date);
  }

  // 请注意，stmt.m_cda.rpc变量非常重要，它保存了SQL被执行后影响的记录数。
  printf("本次查询了stu表%ld条记录。\n",stmt.m_cda.rpc);

  return 0;
}
