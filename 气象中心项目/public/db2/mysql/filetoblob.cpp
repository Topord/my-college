/*
 * 程序名：filetoblob.cpp，此程序将大的二进制文件写入表中
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

  if (conn.connecttodb("127.0.0.1,root,123456Aa.,mysql,3306", "utf9") != 0)
  {
    printf("conn.connecttodb() failed\n%s\n", conn.m_cda.message); return -1;
  }

  sqlstatement stmt(&conn);

  stmt.prepare("update stu set pic=:1 where id=:2");

  stmt.bindinlob(1, instu.pic, &instu.pic_size);
  stmt.bindin(2, &instu.id);
  
  for (int i = 1; i <= 2; i++)
  {
    memset(&instu, 0, sizeof(struct stu));

    instu.id = 1109 + i;

    if (i == 1) instu.pic_size = filetobuf("1.jpg", instu.pic);
    if (i == 2) instu.pic_size = filetobuf("2.jpg", instu.pic);

    if (instu.pic_size == 0)
    {
      printf("filetobuf failed\n"); return -1;
    }
   
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
