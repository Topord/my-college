/*
 * 程序名：tcpputfiles，采用tcp协议，实现文件上客户端
 * 作者：topord
*/
#include "_public.h"

// 程序运行的参数结构体
struct st_arg
{
  int clienttype;          // 客户端类型，1-上传 2-下载
  char ip[31];             // 服务端的ip地址
  int port;                // 服务端的端口
  char clientpath[301];    // 本地文件的存放根目录
  bool andchild;           // 是否上传clientpath目录下各级子目录的文件, true-上传 false-不上传
  char matchname[301];     // 待上传文件名的匹配规则，如*.XML,*.CSV
  char srvpath[301];       // 服务器文件存放的根目录
  int timetvl;             // 扫描本地目录文件的时间间隔
  int timeout;             // 进程心跳的时间
  char pname[51];          // 进程名，用“tcpputfiles_后缀”的方式
};

char strrecvbuffer[1024];
char strsendbuffer[1024];

struct st_arg starg;
CLogFile logfile;
CTcpClient TcpClient;
CPActive PActive;

void _help();                       // 帮助文档
bool _xmltoarg(char* strxmlbuffer); // 解析xml参数到starg结构体中
bool ActiveTest();                  // 心跳机制
bool Login(const char* argv);       // 登录业务。
bool _tcpgetfiles();                // 文件下载的主函数，执行一次下载文件的操作
void EXIT(int sig);                 // 退出函数
void Ackmessage(const char* strrecvbuffer);   // 删除或转存本地的文件
bool RecvFile(const int sockfd, const char* filename, const char* mtime, const int filesize); // 接收上传的内容

int main(int argc,char *argv[])
{
  if (argc != 3)
  {
    _help();  EXIT(-1);
  }
 
  if (logfile.Open(argv[1], "w") == false)
  {
    printf("日志文件打开失败\n"); EXIT(-1);
  }

  if (_xmltoarg(argv[2]) == false)
  {
    logfile.Write("xml参数解析失败\n"); EXIT(-1);
  }

  PActive.AddPInfo(starg.timeout, starg.pname);    // 把进程的心跳信息写入共享内存

  // 向服务端发起连接请求。
  if (TcpClient.ConnectToServer(starg.ip, starg.port) == false)
  {
    logfile.Write("TcpClient.ConnectToServer(%s, %d) failed.\n", starg.ip, starg.port); EXIT(-1);
  }

  
  // 登录业务
  if (Login(argv[2]) == false) { logfile.Write("Login() failed.\n"); EXIT(-1); }
 
  while (true)
  {
    if (_tcpgetfiles() == false)
    {
      logfile.Write("_tcpgetfiles() failed\n"); EXIT(-1);
    }

    sleep(starg.timetvl);
     
    if (ActiveTest() == false) break;
    
    PActive.UptATime();   
  }

  EXIT(0);
}

// 执行一次上传文件的操作
bool _tcpgetfiles()
{
  while (true)
  {
    memset(strsendbuffer, 0, sizeof(strsendbuffer));
    memset(strrecvbuffer, 0, sizeof(strrecvbuffer));
  
    PActive.UptATime();

    // 接收客户端的报文
    if (TcpClient.Read(strrecvbuffer, starg.timetvl+10) == false)
    {
      logfile.Write("RecvFilesMain() TcpServer.Read() failed\n");
      return false;
    }
    // logfile.Write("RecvFilesMain() strrecvbuffer = %s\n", strrecvbuffer);
    
    // strsendbuffer = <filename>/tmp/tcp/surfdata2/SURF_ZH_20230405120717_22795.csv</filename>
    // <mtime>1970-01-01 07:59:59<mtime><size>46776</size>

    // 处理上传文件的请求报文
    if (strncmp(strrecvbuffer, "<filename>", 10) == 0)
    {
      char clientfilename[301]; memset(clientfilename, 0, sizeof(clientfilename));
      char serverfilename[301]; memset(serverfilename, 0, sizeof(serverfilename));

      char mtime[21]; memset(mtime, 0, sizeof(mtime));
      int filesize = 0;     
      // 解析上传文件请求报文的xml
      GetXMLBuffer(strrecvbuffer, "filename", serverfilename, 300);
      GetXMLBuffer(strrecvbuffer, "mtime", mtime, 19);
      GetXMLBuffer(strrecvbuffer, "size", &filesize);

      // 客户端和服务端文件的目录是不一样的，以下代码生成服务端的文件路径
      // 就是把文件名中的clientpath替换成srvpath
      strcpy(clientfilename, serverfilename);

      // <clientpath>/tmp/tcp/surfdata1</clientpath><srvpath>/tmp/tcp/surfdata2</srvpath>

      UpdateStr(clientfilename, starg.srvpath, starg.clientpath, false);

      // 接收上传文件的内容
      logfile.Write("recv %s(%d) ...", serverfilename, filesize);
      if (RecvFile(TcpClient.m_connfd, clientfilename, mtime, filesize) == true)
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
      logfile.Write("strsendbuffer = %s\n", strsendbuffer);
      if (TcpClient.Write(strsendbuffer) == false) 
      {
        logfile.Write("RecvFileMain() TcpServer.Write() failed\n");
        return false;
      }      
    }
  } 
  return true;
}

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
  printf("本地的filename = %s\n", filename);
  // 把临时文件RENAME为正式的文件
  if (RENAME(tmpfilename, filename) == false) return false;  
 
  return true;
}
// 删除或转存本地文件
void Ackmessage(const char* strrecvbuffer)
{
  char filename[301];
  char result[31];

  memset(filename, 0, sizeof(filename));
  memset(result, 0, sizeof(result));

  GetXMLBuffer(strrecvbuffer, "filename", filename);
  GetXMLBuffer(strrecvbuffer, "result", result);
  // 如果服务端接收文件不成功， 直接返回
  if (strcmp(result, "ok") != 0) return;
  
  
}


// 上传文件给对端
bool SendFile(const int sockfd, const char* filename, const int filesize)
{
  int onread = 0;       // 每次调用fread时打算读取的字节数
  int bytes = 0;        // 调用一次fread从文件中读取的字节数
  char buffer[1000];    // 存放读取数据的buffer
  int totalbytes = 0;       // 从文件中已读取的字节总数
  FILE* fp = NULL;

  // 以"rb"的模式打开文件
  fp = fopen(filename, "rb");
  if (fp == false)
  {
    logfile.Write("SendFile() file open(%s) failed\n", filename);
    return false;
  }

  while (true)
  {
    memset(buffer, 0 ,sizeof(buffer));

    // 计算本次应该读取的字节数，如果剩余的数据超过1000字节，就读取1000字节
    if (filesize - totalbytes > 1000) onread = 1000;
    else onread = filesize - totalbytes;

    // 从文件中读取数据
    bytes = fread(buffer, 1, onread, fp);
    
    // 把读取的数据发送给对端
    if (bytes > 0)
    {
      if (Writen(sockfd, buffer, bytes) == false)
      {
        printf("error\n");
        fclose(fp); return false;
      }
    }

    // 计算已读取的字节总数，如果文件已读完，跳出循环
    totalbytes += bytes;
    if (totalbytes == filesize) break;
  }  
  fclose(fp);

  return true;
}

// 心跳
bool ActiveTest()
{
  memset(strsendbuffer, 0, sizeof(strsendbuffer));
  memset(strrecvbuffer, 0, sizeof(strrecvbuffer));

  SPRINTF(strsendbuffer, sizeof(strsendbuffer), "<active>ok</active>");
  logfile.Write("发送: %s\n", strsendbuffer);
  if (TcpClient.Write(strsendbuffer) == false) return false;

  if (TcpClient.Read(strrecvbuffer) == false) return false;
  logfile.Write("接收: %s\n", strrecvbuffer);

  return true;
}

// 登录业务。 
bool Login(const char* argv)    
{
  memset(strsendbuffer, 0, sizeof(strsendbuffer));
  memset(strrecvbuffer, 0, sizeof(strrecvbuffer));

  
  SPRINTF(strsendbuffer, sizeof(strsendbuffer), "%s<clienttype>2</clienttype>", argv);

  logfile.Write("发送：%s\n", strsendbuffer);

  if (TcpClient.Write(strsendbuffer)==false) return false; // 向服务端发送请求报文。

  if (TcpClient.Read(strrecvbuffer, 20)==false) return false; // 接收服务端的回应报文。

  logfile.Write("接收：%s\n", strrecvbuffer);

  logfile.Write("登录(%s: %d)成功。\n", starg.ip, starg.port); 

  return true;
}

// 退出
void EXIT(int sig)
{
  logfile.Write("程序退出, sig = %d\n", sig);
 
  exit(0);
}
// 解析参数
bool _xmltoarg(char* strxmlbuffer)
{
  memset(&starg,0,sizeof(struct st_arg));

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


// 帮助文档
void _help()
{
  printf("\n");
  printf("Using:/project/tools2/bin/tcpgetfiles xmlbuffer logfilename\n\n");

  printf("Sample:/project/tools2/bin/procctl 20 /project/tools2/bin/tcpgetfiles /log/idc/tcpgetfiles_surfdata.log \"<clienttype>2</clienttype><ip>192.168.80.129</ip><port>5005</port><clientpath>/tmp/tcp/surfdata1</clientpath><andchild>true</andchild><matchname>*.XML,*.CSV</matchname><srvpath>/tmp/tcp/surfdata2</srvpath><timetvl>10</timetvl><timeout>50</timeout><pname>tcpputfiles_surfdata</pname>\"\n");
  printf("       /project/tools2/bin/procctl 20 /project/tools2/bin/tcpgetfiles /log/idc/tcpgetfiles_surfdata.log \"<clienttype>2</clienttype><ip>192.168.80.129</ip><port>5005</port><clientpath>/tmp/tcp/surfdata1</clientpath><andchild>true</andchild><matchname>*.XML,*.CSV</matchname><srvpath>/tmp/tcp/surfdata2</srvpath><timetvl>10</timetvl><timeout>50</timeout><pname>tcpputfiles_surfdata</pname>\"\n\n\n");

  printf("本程序是数据中心的公共功能模块，采用tcp协议把文件上传给服务端。\n");
  printf("logfilename   本程序运行的日志文件。\n");
  printf("xmlbuffer     本程序运行的参数，如下：\n");
  printf("ip            服务端的IP地址。\n");
  printf("port          服务端的端口。\n");
  printf("clientpath    本地文件存放的根目录。\n");
  printf("andchild      是否上传clientpath目录下各级子目录的文件，true-是；false-否，缺省为false。\n");
  printf("matchname     待上传文件名的匹配规则，如\"*.TXT,*.XML\"\n");
  printf("srvpath       服务端文件存放的根目录。\n");
  printf("timetvl       扫描本地目录文件的时间间隔，单位：秒，取值在1-30之间。\n");
  printf("timeout       本程序的超时时间，单位：秒，视文件大小和网络带宽而定，建议设置50以上。\n");
  printf("pname         进程名，尽可能采用易懂的、与其它进程不同的名称，方便故障排查。\n\n");
}
