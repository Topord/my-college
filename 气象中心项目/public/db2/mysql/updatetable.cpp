/*
 * 程序名：updatetable.cpp，此程序修改stu表中的数据，修改5次
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

  stmt.prepare("\
          update stu set name=:1, height=:2, date=str_to_date(:3, '%%Y-%%m-%%d %%H:%%i:%%s') where id=:4");

  stmt.bindin(1, instu.name, 30);
  stmt.bindin(2, &instu.height);
  stmt.bindin(3, instu.date, 20);
  stmt.bindin(4, &instu.id);

  for (int i = 1; i <= 5; i++)
  {
    memset(&instu, 0, sizeof(struct stu));
   
    instu.id = 1109 + i;
    sprintf(instu.name, "%dchange", i);
    instu.height = 123.33 + i;
    sprintf(instu.date, "2012-12-0%d 11:11:0%d", i, i);
    if (stmt.execute() != 0)
    {
      printf("stmt.execute() failed.\n%s\n%s\n", stmt.m_sql, stmt.m_cda.message); return -1;
    }
    printf("成功修改一条数据.\n");
  }

  conn.commit();

  printf("修改表操作成功!\n");

  return 0;
}
