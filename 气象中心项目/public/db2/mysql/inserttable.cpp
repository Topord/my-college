/*
 * 程序名: inserttable.cpp, 向表中插入5条数据
 * 作者: topord
 */

#include "_mysql.h"

struct student
{
  long id;
  char name[31];
  double height;
  char date[21];
}instu;

int main()
{
  connection conn;

  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306", "utf8") != 0)
  {
    printf("connect database failed.\n%s\n",conn.m_cda.message); return -1;
  }

  sqlstatement stmt(&conn);

  // 数据库插入eg: insert into employee(id,workno,name,gender,age,idcard,entrydate)
  // values(1,'1','Itcast','男',10,'123456789012345678','2000-01-01');

  stmt.prepare("insert into stu(id, name, height, date) values(:1, :2, :3, str_to_date(:4, '%%Y-%%m-%%d %%H:%%i:%%s'))");

  stmt.bindin(1, &instu.id);
  stmt.bindin(2, instu.name, 30);
  stmt.bindin(3, &instu.height);
  stmt.bindin(4, instu.date, 20);
  
  for (int i = 0; i < 5; i++)
  {
    memset(&instu, 0, sizeof(instu));

    instu.id = 1110+i;
    sprintf(instu.name, "studentokk%d", i+1);
    instu.height = 171.32+i;
    sprintf(instu.date, "2002-08-2%d 12:55:5%d", i, i);
    
    // 执行SQL语句，一定要判断返回值，0-成功，其它-失败。
    // 失败代码在stmt.m_cda.rc中，失败描述在stmt.m_cda.message中。
    if (stmt.execute()!=0)
    {
      printf("stmt.execute() failed.\n%s\n%s\n",stmt.m_sql,stmt.m_cda.message); return -1;
    }

    printf("成功插入了%ld条记录。\n",stmt.m_cda.rpc); // stmt.m_cda.rpc是本次执行SQL影响的记录数。
  }

  printf("insert table stu ok.\n");

  conn.commit();

  return 0;
}
