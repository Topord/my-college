/*
 * 程序名：server.cpp，采用tcp协议，实现文件上传和下载的客户端,无参考 
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
CPActive PActive;          // 进程的心跳

bool _xmltoarg(char* strxmlbuffer);                           // 解析xml参数 
bool ClientLogin();                                           // 登录业务处理函数。
void RecvFilesMain();                                         // 上传文件的主函数
bool RecvFile(const int sockfd, const char* filename, const char* mtime, const int filesize); // 接收上传的内容
void SendFileMain();
bool SendFile(int sockfd, const char* filename, int size); // 发送文件内容
void FathEXIT(int sig);                                       // 父进程退出函数。
void ChldEXIT(int sig);                                       // 子进程退出函数。

int main(int argc,char *argv[])
{
  if (argc != 4)
  {
    printf("Using:./myfileserver port logfile timeout\nExample:/project/tools2/bin/myfileserver 5005 /log/idc/myfileserver.log 35\n\n"); return -1;
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
    if (starg.clienttype == 1) RecvFilesMain(); 
    // 如果clienttype==2，调用下载文件的主函数
    if (starg.clienttype == 2) SendFileMain();

    ChldEXIT(0);
  }
}

// 上传文件的主函数
void SendFileMain()
{
  CDir Dir;

  int delayed = 0;
  int buflen = 0;

  if (Dir.OpenDir(starg.srvpath, starg.matchname, 10000, starg.andchild) == false)
  {
    logfile.Write("SendFileMain() failed\n"); return;
  }
  while (true)
  {
    memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
    memset(strsendbuffer, 0, sizeof(strsendbuffer));

    //遍历目录中的每个文件，即调用ReadDir()获取一个文件名
    if (Dir.ReadDir() == false)
    {
      logfile.Write("SendFileMain() Dir.Read() failed\n");
      return;
    } 
    // 把文件名、修改时间、文件大小组成报文，发送给对端
    SNPRINTF(strsendbuffer, sizeof(strsendbuffer), 1000, "<filename>%s</filename><mtime>%s<mtime><size>%d</size>", Dir.m_FullFileName, Dir.m_ModifyTime, Dir.m_FileSize);
    logfile.Write("strsendbuffer = %s\n", strsendbuffer);

    if (TcpServer.Write(strsendbuffer) == false)
    {
      logfile.Write("SendFileMain() TcpSercer.Write() failed\n");
      return;
    }
    logfile.Write("send %s(%d) ...", Dir.m_FileName, Dir.m_FileSize);
    if (SendFile(TcpServer.m_connfd, Dir.m_FullFileName, Dir.m_FileSize) == true)
    {
      logfile.WriteEx("ok\n");
    }
    else
    {
      logfile.WriteEx("failed\n"); return;
    }
    // 2023-4-6
    if (TcpServer.Read(strrecvbuffer) == false)
    {
      logfile.Write("SendFileMain() TcpRead() failed\n");
      return;
    }
  }
}

bool SendFile(int sockfd, const char* filename, int size)
{
  int onread = 0;
  int bytes = 0;
  char buffer[1000];
  int totalbytes = 0;
  FILE* fp = NULL;

  // 以"rb"的方式打开文件
  fp = fopen(filename, "rb");
  if (fp == false)
  {
    logfile.Write("SendFile() fopen(%s) failed\n", filename); 
    return false;
  }

  while (true)
  {
    memset(buffer, 0, sizeof(buffer));

    if (size - totalbytes > 1000) onread = 1000;
    else onread = size - totalbytes;

    // 从文件中读取数据
    bytes = fread(buffer, 1, onread, fp);

    // 把读取的数据发送给对端
    if (bytes > 0)
    {
      if (Writen(sockfd, buffer, bytes) == false)
      {
        printf("erroe/n");
        fclose(fp);
        return false;
      }
    }

    totalbytes += bytes;
    if (totalbytes == size) break;
  }
  fclose(fp);

  return true;
}

// 接收文件的主函数
void RecvFilesMain()
{
  PActive.AddPInfo(starg.timeout, starg.pname);  

  while (true)
  {
    memset(strsendbuffer, 0, sizeof(strsendbuffer));
    memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
  
    PActive.UptATime();

    // 接收客户端的报文
    if (TcpServer.Read(strrecvbuffer, starg.timetvl+10) == false)
    {
      logfile.Write("RecvFilesMain() TcpServer.Read() failed\n");
      return;
    }
    // logfile.Write("RecvFilesMain() strrecvbuffer = %s\n", strrecvbuffer);
    
    // 处理心跳报文
    if (strcmp(strrecvbuffer, "<active>ok</active>") == 0)
    {
      strcpy(strsendbuffer, "ok");
      // logfile.Write("strsendbuffer = %s\n", strsendbuffer);
      if (TcpServer.Write(strsendbuffer) == false)
      {
        logfile.Write("RecvFileMain() TcpServer.Write() failed\n");
        return;
      }
    }
    // 处理上传文件的请求报文
    if (strncmp(strrecvbuffer, "<filename>", 10) == 0)
    {
      char clientfilename[301]; memset(clientfilename, 0, sizeof(clientfilename));
      char mtime[21]; memset(mtime, 0, sizeof(mtime));
      int filesize = 0;     
      // 解析上传文件请求报文的xml
      GetXMLBuffer(strrecvbuffer, "filename", clientfilename, 300);
      GetXMLBuffer(strrecvbuffer, "mtime", mtime, 19);
      GetXMLBuffer(strrecvbuffer, "size", &filesize);

      // 客户端和服务端文件的目录是不一样的，以下代码生成服务端的文件路径
      // 救赎把文件名中的clientpath替换成srvpath
      char serverfilename[301]; memset(serverfilename, 0, sizeof(serverfilename));
      strcpy(serverfilename, clientfilename);
      UpdateStr(serverfilename, starg.clientpath, starg.srvpath, false);

      // 接收上传文件的内容
      logfile.Write("recv %s(%d) ...", serverfilename, filesize);
      if (RecvFile(TcpServer.m_connfd, serverfilename, mtime, filesize) == true)
      {
        logfile.WriteEx("ok\n");
        SNPRINTF(strsendbuffer, sizeof(strsendbuffer), 1000, "<filename>%s</filename><result>ok</result>", clientfilename);
      }
      else
      {
        logfile.WriteEx("failed\n");
        SNPRINTF(strsendbuffer, sizeof(strsendbuffer), 1000, "<filename>%s<filename><result>failed</result>", clientfilename);
      }   
      // 把接收结果返回给对端
      // logfile.Write("strsendbuffer = %s\n", strsendbuffer);
      if (TcpServer.Write(strsendbuffer) == false) 
      {
        logfile.Write("RecvFileMain() TcpServer.Write() failed\n");
        return;
      }      
    }
  } 
}

// 接收上传的内容
bool RecvFile(const int sockfd, const char* filename, const char* mtime, const int filesize)
{
  int onread = 0;
  int totalbytes = 0;
  char buffer[1000];
  char tmpfilename[301];
  FILE* fp = NULL;

  // 生成临时文件名
  SNPRINTF(tmpfilename, sizeof(tmpfilename), 300, "%s.tmp", filename);   

  // 创建临时文件
  fp = FOPEN(tmpfilename, "wb");
  if (fp == NULL) return false;

  while (true)
  { 
    memset(buffer, 0, sizeof(buffer));

    // 计算本次应该接收的字节数
    if (filesize - totalbytes > 1000) onread = 1000;
    else onread = filesize - totalbytes; 
     
    // 接收文件内容
    if (Readn(sockfd, buffer, onread) == false)
    {
      fclose(fp); return false;
    }

    // 把接受到的内容写入文件
    fwrite(buffer, 1, onread, fp);

    // 计算已接收文件的总字节数, 如果文件接收完，跳出循环
    totalbytes = totalbytes+onread;
  
    if (totalbytes == filesize) break;

  }
  // 关闭临时文件
  fclose(fp);
  
  // 重置文件时间  
  UTime(tmpfilename, mtime);

  // 把临时文件RENAME为正式的文件
  if (RENAME(tmpfilename, filename) == false) return false;  

  return true;
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
  // logfile.Write("xml = %s\n", strrecvbuffer);

  // 解析传过来的xml语句
  if (_xmltoarg(strrecvbuffer) == false)
  {
    logfile.Write("Tcpserver解析xml failed\n"); return false;
  }  
    
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

  GetXMLBuffer(strxmlbuffer,"clientpath",starg.clientpath);
  if (strlen(starg.clientpath)==0) { logfile.Write("clientpath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"andchild",&starg.andchild);

  GetXMLBuffer(strxmlbuffer,"matchname",starg.matchname);
  if (strlen(starg.matchname)==0) { logfile.Write("matchname is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"srvpath",starg.srvpath);
  if (strlen(starg.srvpath)==0) { logfile.Write("srvpath is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"timetvl",&starg.timetvl);
  if (starg.timetvl==0) { logfile.Write("timetvl is null.\n"); return false; }

  GetXMLBuffer(strxmlbuffer,"clienttype", &starg.clienttype);
  if (starg.clienttype == 0) {logfile.Write("clienttype = 0\n"); return false;}

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
