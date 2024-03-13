/*
 * 功能：此程序主要用来对输入的xml语句进行存储
 * 作者：topord
 */

#include "_public.h"
#include "_ftp.h"

struct st_arg
{
  char host[31];           // 远程服务端的IP和端口。
  int  mode;               // 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。
  char username[31];       // 远程服务端ftp的用户名。
  char password[31];       // 远程服务端ftp的密码。
  char remotepath[301];    // 远程服务端存放文件的目录。
  char localpath[301];     // 本地文件存放的目录。
  char matchname[101];     // 待下载文件匹配的规则。 
} starg;

CLogFile logfile;

Cftp ftp;

// 程序退出和信号2、15的处理函数
void EXIT(int sig);

// 帮助函数
void _help();

// 解析xml的函数
bool _xmltoarg(char* strxmlbuffer);

int main(int argc, char* argv[])
{
  if (argc != 3) { _help(); return -1;}

  // 处理程序的退出信号
  // CloseIOAndSignal();
  signal(SIGINT, EXIT); signal(SIGTERM,EXIT);

  // 打开日志文件
  if (logfile.Open(argv[1]) == false) 
  {
    printf("logfile,open() failed\n"); 
    return -1;
  }
  // 解析xml, 得到程序运行参数
  if (_xmltoarg(argv[2]) == false)
  {
    logfile.Write("获取xml信息失败\n");
    return -1;
  }

  return 0;
}

bool _xmltoarg(char* strxmlbuffer)
{
  memset(&starg, 0, sizeof(struct st_arg));

  GetXMLBuffer(strxmlbuffer, "host", starg.host, 30);   // 远程服务端的IP和端口。
  if (strlen(starg.host) == 0)
  {
    logfile.Write("host is null\n"); return -1;
  }

  GetXMLBuffer(strxmlbuffer,"mode",&starg.mode);   // 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。
  if (starg.mode!=2)  starg.mode=1;
 
  GetXMLBuffer(strxmlbuffer, "username", starg.username, 30);   // 远程服务端ftp的用户名。
  if (strlen(starg.username) == 0)
  {
    logfile.Write("username is null\n"); return -1;
  } 

  GetXMLBuffer(strxmlbuffer, "password", starg.password, 30);   // 远程服务端ftp的密码
  if (strlen(starg.password) == 0)
  {
    logfile.Write("password is null\n"); return -1;
  }
 
  GetXMLBuffer(strxmlbuffer, "remotepath", starg.remotepath, 300);   // 远程服务端存放文件的目录
  if (strlen(starg.remotepath) == 0)
  {
    logfile.Write("remotepath is null\n"); return -1;
  }

  GetXMLBuffer(strxmlbuffer, "localpath", starg.localpath, 300);   // 本地文件存放的目录。
  if (strlen(starg.localpath) == 0)
  {
    logfile.Write("localpath is null\n"); return -1;
  }
  
  GetXMLBuffer(strxmlbuffer, "matchname", starg.matchname, 100);   // 待下载文件匹配的规则。
  if (strlen(starg.matchname) == 0)
  {
    logfile.Write("matchname is null\n"); return -1;
  }
}
void EXIT(int sig)
{
  printf("程序退出，sig = %d\n\n", sig);
  exit(0);
}

void _help()
{
  printf("\n");
  printf("Using:/project/tools2/bin/ftpgetfiles logfilename xmlbuffer\n\n");

  printf("Sample:/project/tools2/bin/procctl 30 /project/tools2/bin/ftpgetfiles /log/idc/ftpgetfiles_surfdata.log \"<host>172.20.119.29:21</host><mode>1</mode><username>root</username><password>#@!#!dqadsq!@#321</password><localpath>/idcdata/surfdata</localpath><remotepath>/tmp/idc/surfdata</remotepath><matchname>SURF_ZH*.XML,SURF_ZH*.CSV</matchname>\"\n\n\n");

  printf("本程序是通用的功能模块，用于把远程ftp服务端的文件下载到本地目录。\n");
  printf("logfilename是本程序运行的日志文件。\n");
  printf("xmlbuffer为文件下载的参数，如下：\n");
  printf("<host>127.0.0.1:21</host> 远程服务端的IP和端口。\n");
  printf("<mode>1</mode> 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。\n");
  printf("<username>wucz</username> 远程服务端ftp的用户名。\n");
  printf("<password>wuczpwd</password> 远程服务端ftp的密码。\n");
  printf("<localpath>/idcdata/surfdata</localpath> 本地文件存放的目录。\n");
  printf("<remotepath>/tmp/idc/surfdata</remotepath> 远程服务端存放文件的目录。\n");
  printf("<matchname>SURF_ZH*.XML,SURF_ZH*.CSV</matchname> 待下载文件匹配的规则。"\
         "不匹配的文件不会被下载，本字段尽可能设置精确，不建议用*匹配全部的文件。\n");
}
