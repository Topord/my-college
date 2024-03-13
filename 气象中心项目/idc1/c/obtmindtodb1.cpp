/*
 * 程序名：obtmindtodb.cpp，此程序把全国站点分钟观测数据入库到T_ZHOBTMIND表中，支持.xml和.csv格式
 * 作者：topord
 */

#include "_public.h"
#include "_mysql.h"

CLogFile logfile;                          // 日志类
connection conn;
CPActive PActive;

bool _obtmindtodb(const char* pathname, const char* connstr, const char* charset);
void EXIT(int sig);

int main(int argc, char* argv[])
{
  // 帮助文档。
  if (argc != 5)
  {
    printf("\n");
    printf("Using:./obtmindtodb pathname connstr charset logfile\n");

    printf("Example:/project/tools2/bin/procctl 10 /project/idc2/bin/obtmindtodb /idcdata/surfdata \"127.0.0.1,root,123456Aa.,mysql,3306\" utf8 /log/idc/obtmindtodb.log\n\n");

    printf("本程序用于把全国站点分钟观测数据保存到数据库的T_ZHOBTMIND表中，数据只插入，不更新。\n");
    printf("pathname 全国站点分钟观测数据文件存放的目录。\n");
    printf("connstr  数据库连接参数：ip,username,password,dbname,port\n");
    printf("charset  数据库的字符集。\n");
    printf("logfile  本程序运行的日志文件名。\n");
    printf("程序每10秒运行一次，由procctl调度。\n\n\n");

    return -1;
  }
  
  // 处理程序退出的信号
  // 关闭全部的信号和输入输出。
  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程。
  // 但请不要用 "kill -9 +进程号" 强行终止。
  // CloseIOAndSignal(); signal(SIGINT,EXIT); signal(SIGTERM,EXIT);

  // 打开日志文件
  if (logfile.Open(argv[4], "w") == false)
  {
    printf("logfile.Open(%s) failed\n", argv[4]); return -1;
  }
  PActive.AddPInfo(5000,"obtmindtodb");   // 进程的心跳，10秒足够。
 
  // 处理业务主函数
  _obtmindtodb(argv[1], argv[2], argv[3]);

  return 0;
}

// 业务处理主函数
bool _obtmindtodb(const char* pathname, const char* connstr, const char* charset)
{
  // 打开目录
  CDir Dir;
  if (Dir.OpenDir(pathname, "*.xml") == false)
  {
    logfile.Write("Dir.OpenDir(%s) failed\n", pathname);
    return false;
  }
  while (true)
  {
    // 读取目录，得到一个数据文件名
    if (Dir.ReadDir() == false) break;
    logfile.Write("filename = %s\n", Dir.m_FullFileName);
    // 打开文件

//    while (true)
//    {
      // 处理文件中的每一行
//    }

    // 删除文件、提交事务
  }




  return true;
}

void EXIT(int sig)
{
  logfile.Write("程序退出，sig=%d\n\n",sig);

  conn.disconnect();

  exit(0);
}



/*
 // 连接数据库
  if (conn.connecttodb(argv[2], argv[3]) != 0)
  {
    logfile.Write("conn.connecttodb(%s) failed\n", argv[2], conn.m_cda.message); return -1;
  }
  logfile.Write("conn.connecttodb(%s) ok\n", argv[2]);


  conn.commit();
*/