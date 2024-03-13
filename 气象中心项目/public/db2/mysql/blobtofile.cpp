/*
 * 程序名：blobtofile.cpp，此程序将大的二进制文件从表中读出
 * 作者：topord
 */

#include "_mysql.h"

struct stu
{
  long id;
  char pic[100000];
  unsigned long pic_size;
}instu;

int main()
{
  connection conn;
  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306","utf8") != 0)
  {
    printf("conn.connecttodb() failed.\n"); return -1;
  }

  sqlstatement stmt(&conn);

  stmt.prepare("select pic, id from stu where id in (1110, 1111)");

  stmt.bindoutlob(1, instu.pic, 100000, &instu.pic_size);
  stmt.bindout(2, &instu.id);

  stmt.execute();

  char filename[31];

  while (true)
  {
    memset(&instu, 0, sizeof(instu));
    if (stmt.next()!=0) break;
    memset(filename, 0, sizeof(filename));

    printf("id = %d\n", instu.id);
    sprintf(filename, "%d_out.jpg", instu.id-1109);
    buftofile(filename, instu.pic, instu.pic_size);
  }

  // 请注意，stmt.m_cda.rpc变量非常重要，它保存了SQL被执行后影响的记录数。
  printf("本次查询了girls表%ld条记录。\n",stmt.m_cda.rpc);

  return 0;
}
