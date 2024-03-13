/*
 * 程序名：deletetable.cpp，此程序删除stu表中的数据
 * 作者：topord
 */

#include "_mysql.h"

int main()
{
  connection conn;

  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306", "utf9") != 0)
  {
    printf("conn.connecttodb() failed\n%s\n", conn.m_cda.message); return -1;
  }

  sqlstatement stmt(&conn);

  int imin = 0, imax = 0;

  stmt.prepare("delete from stu where id>=:1 and id<=:2");
  
  stmt.bindin(1, &imin);
  stmt.bindin(2, &imax);
  
  imin = 1112;
  imax = 1114;
  
  if (stmt.execute() != 0)
  {
    printf("stmt.execute() failed. \n%s\n%s\n", stmt.m_sql, stmt.m_cda.message); return -1;
  }

  // 请注意，stmt.m_cda.rpc变量非常重要，它保存了SQL被执行后影响的记录数。
  printf("本次删除了stu表%ld条记录。\n",stmt.m_cda.rpc);

  conn.commit();

  return 0;
}
