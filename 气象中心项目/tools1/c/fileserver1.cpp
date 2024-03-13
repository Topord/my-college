/*
 * 程序名：server.cpp，采用tcp协议，实现文件上传的客户端
 * 作者：topord
*/
#include "_public.h"

// 程序运行的参数结构体
struct st_arg
{
  int clienttype;          // 客户端类型，1-上传 2-下载
  char ip[31];             // 服务端的ip地址
  int port;                // 服务端的端口
  int ptype;               // 文件上传成功后文件的处理方式 1-删除 2-备份
  char clientpath[301];    // 本地文件的存放根目录
  char clientpathbak[301]; // 文件上传成功后，本地文件备份的根目录,仅ptype=2时有效
  bool andchild;           // 是否上传clientpath目录下各级子目录的文件, true-上传 false-不上传
  char matchname[301];     // 待上传文件名的匹配规则，如*.XML,*.CSV
  char srvpath[301];       // 服务器文件存放的根目录
  int timetvl;             // 扫描本地目录文件的时间间隔
  int timeout;             // 进程心跳的时间
  char pname[51];          // 进程名，用“tcpputfiles_后缀”的方式
};

char strrecvbuffer[1024];  // 接收报文的buffer
char strsendbuffer[1024];  // 发送报文的buffer
struct st_arg starg;       // 程序运行的参数结构体
CLogFile logfile;          // 服务程序的运行日志。
CTcpServer TcpServer;      // 创建服务端对象。

bool _xmltoarg(char* strxmlbuffer);                         // 解析xml参数 
bool srv000(const char* strrecvbuffer, char *strsendbuffer); // 心跳
bool ClientLogin();  // 登录业务处理函数。
void RecvFilesMain();    // 上传文件的主函数
void FathEXIT(int sig);  // 父进程退出函数。
void ChldEXIT(int sig);  // 子进程退出函数。


int main(int argc,char *argv[])
{
  if (argc!=4)
  {
    printf("Using:./fileserver port logfile timeout\nExample:/project/tools2/bin/fileserver 5005 /log/idc/fileserver.log 35\n\n"); return -1;
  }

  // 关闭全部的信号和输入输出。
  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  CloseIOAndSignal(); signal(SIGINT,FathEXIT); signal(SIGTERM,FathEXIT);

  if (logfile.Open(argv[2], "w") == false) { printf("logfile.Open(%s) failed.\n",argv[2]); return -1; }

  // 服务端初始化。
  if (TcpServer.InitServer(atoi(argv[1]))==false)
  {
    logfile.Write("TcpServer.InitServer(%s) failed.\n",argv[1]); return -1;
  }

  while (true)
  {
    // 等待客户端的连接请求。
    if (TcpServer.Accept()==false)
    {
      logfile.Write("TcpServer.Accept() failed.\n"); FathEXIT(-1);
    }

    logfile.Write("客户端（%s）已连接。\n",TcpServer.GetIP());

    // 处理客户端的登录报文     
    if (ClientLogin() == false)
    {
      logfile.Write("ClientLogin() failed\n");
      ChldEXIT(-1);
    }
    
    // 如果clienttype==1，调用上传文件的主函数
    if (starg.ptype == 1) RecvFilesMain(); 
    // 如果clienttype==2，调用下载文件的主函数
    if (starg.ptype == 2)

    ChldEXIT(0);
  }
}

// 上传文件的主函数
void RecvFilesMain()
{
  while (true)
  {
    memset(strsendbuffer, 0, sizeof(strsendbuffer));
    memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
  
    // 接收客户端的报文
    if (TcpServer.Read(strrecvbuffer, starg.timetvl+10) == false)
    {
      logfile.Write("RecvFilesMain() TcpServer.Read() failed\n");
      return;
    }
    logfile.Write("RecvFilesMain() strrecvbuffer = %s\n", strrecvbuffer);
    
    // 处理心跳报文
    if (strcmp(strrecvbuffer, "<active>ok</active>") == 0)
    {
      strcpy(strsendbuffer, "ok");
      if (TcpServer.Write(strsendbuffer) == false) return;
    }  
  } 
}



// 登录
bool ClientLogin()
{
  memset(strsendbuffer, 0, sizeof(strsendbuffer));
  memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
 
  if (TcpServer.Read(strrecvbuffer, 20) == false)
  {
    logfile.Write("TcpServer.Read() failed\n"); return false;
  }
  logfile.Write("xml = %s\n", strrecvbuffer);

  // 解析传过来的xml语句
  if (_xmltoarg(strrecvbuffer) == false)
  {
    logfile.Write("Tcpserver解析xml failed\n"); return false;
  }  
    
  if ((starg.ptype != 1)&&(starg.ptype != 2))
    strcpy(strsendbuffer, "failed");
  else
    strcpy(strsendbuffer, "ok");

  if (TcpServer.Write(strsendbuffer) == false)
  {
    logfile.Write("Tcpserver.Write() failed\n"); return false;
  }
  
  logfile.Write("%s login %s.\n", TcpServer.GetIP(), strsendbuffer);

  return true;
} 

// 解析xml参数
bool _xmltoarg(char* strxmlbuffer)
{
  memset(&starg, 0, sizeof(starg)); 
 
  GetXMLBuffer(strxmlbuffer,"ip",starg.ip);
  if (strlen(starg.ip)==0) { logfile.Write("ip is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"port",&starg.port);
  if ( starg.port==0) { logfile.Write("port is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"ptype",&starg.ptype);
  if ((starg.ptype!=1)&&(starg.ptype!=2)) { logfile.Write("ptype not in (1,2).\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"clientpath",starg.clientpath);
  if (strlen(starg.clientpath)==0) { logfile.Write("clientpath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"clientpathbak",starg.clientpathbak);
  if ((starg.ptype==2)&&(strlen(starg.clientpathbak)==0)) { logfile.Write("clientpathbak is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"andchild",&starg.andchild);

  GetXMLBuffer(strxmlbuffer,"matchname",starg.matchname);
  if (strlen(starg.matchname)==0) { logfile.Write("matchname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"srvpath",starg.srvpath);
  if (strlen(starg.srvpath)==0) { logfile.Write("srvpath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"timetvl",&starg.timetvl);
  if (starg.timetvl==0) { logfile.Write("timetvl is null.\n"); return false; }

  // 扫描本地目录文件的时间间隔，单位：秒。starg.timetvl没有必要超过30秒。
  if (starg.timetvl>30) starg.timetvl=30;

  // 进程心跳的超时时间，一定要大于starg.timetvl，没有必要小于50秒。
  GetXMLBuffer(strxmlbuffer,"timeout",&starg.timeout);
  if (starg.timeout==0) { logfile.Write("timeout is null.\n"); return false; }
  if (starg.timeout<50) starg.timeout=50;

  GetXMLBuffer(strxmlbuffer,"pname",starg.pname,50);
  if (strlen(starg.pname)==0) { logfile.Write("pname is null.\n"); return false; }

  return true;
}

// 父进程退出函数。
void FathEXIT(int sig)  
{
  // 以下代码是为了防止信号处理函数在执行的过程中被信号中断。
  signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);

  logfile.Write("父进程退出，sig=%d。\n",sig);

  TcpServer.CloseListen();    // 关闭监听的socket。

  kill(0,15);     // 通知全部的子进程退出。

  exit(0);
}

// 子进程退出函数。
void ChldEXIT(int sig)  
{
  // 以下代码是为了防止信号处理函数在执行的过程中被信号中断。
  signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);

  logfile.Write("子进程退出，sig=%d。\n",sig);

  TcpServer.CloseClient();    // 关闭客户端的socket。

  exit(0);
}
