/*
 *  程序名：demo1.cpp，此程序演示采用开发框架的CTcpServer类实现socket通讯多进程的服务端。
 * 1）在多进程的服务程序中，如果杀掉一个子进程，和这个子进程通讯的客户端会断开，但是，不会影响其它的子进程和客户端，也不会影响父进程。
 * 2）如果杀掉父进程，不会影响正在通讯中的子进程，但是，新的客户端无法建立连接。
 * 3）如果用killall+程序名，可以杀掉父进程和全部的子进程。
 * 
 * 多进程网络服务端程序退出的三种情况：
 * 1）如果是子进程收到退出信号，该子进程断开与客户端连接的socket，然后退出。
 * 2）如果是父进程收到退出信号，父进程先关闭监听的socket，然后向全部的子进程发出退出信号。
 * 3）如果父子进程都收到退出信号，本质上与第2种情况相同。
 */

#include "../_public.h" 
#include <signal.h>

CLogFile logfile;
CTcpServer TcpServer;

void FathEXIT(int sign);    // 父进程退出函数
void ChldEXIT(int sign);    // 子进程退出函数


int main(int argc,char *argv[])
{
  if (argc!=3)
  {
    printf("Using:./demo11 port logfilepath \nExample:./demo11 5005 /log/tcptest/demo11.log\n\n"); return -1;
  }

  
  if (logfile.Open(argv[2], "w") == false)
  {
    printf("logfile.Open(%s) failed\n", argv[2]); return 0;
  }

  // bool InitServer(const unsigned int port,const int backlog=5);
  if (TcpServer.InitServer(atoi(argv[1])) == false)
  {
    printf("TcpServer.InitServer(%s) failed\n", argv[1]); return -1;
  }
  
  // 关闭全部的信号和输入输出。
  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  CloseIOAndSignal(); signal(SIGINT,FathEXIT); signal(SIGTERM,FathEXIT);


  while (true)
  {
 
   if (TcpServer.Accept() == false) 
   { 
     printf("TcpServer.Accept() failed\n"); return 0;
   }
   // 忽略信号，避免产生僵尸进程
   signal(SIGCHLD, SIG_IGN);

   // 测试
   // printf("listen_fd = %d, connect_fd = %d\n", TcpServer.m_listenfd, TcpServer.m_connfd);
   
   if (fork()>0)
   {
     TcpServer.CloseClient();
     continue;
   }
   
   // 子进程重新设置退出信号。
   signal(SIGINT,ChldEXIT); signal(SIGTERM,ChldEXIT);

   // 测试
   TcpServer.CloseListen();
   // printf("listen_fd = %d, connect_fd = %d\n", TcpServer.m_listenfd, TcpServer.m_connfd);

   printf("成功连接上%s\n", TcpServer.GetIP());  
   logfile.Write("成功连接上客户端%s\n", TcpServer.GetIP());   

   char buffer[1024];

   while (1)
   {
      int ibuflen = 0;
      memset(buffer,0,sizeof(buffer));
      // bool Read(char *buffer,const int itimeout=0);
      if (TcpServer.Read(buffer) == false) // 接收客户端的请求报文。
      {
         printf("TcpRead failed\n"); break;   
      }
      logfile.Write("接收: %s\n", buffer);
      printf("接收：%s\n",buffer);
  
      memset(buffer, 0, sizeof(buffer));
      SPRINTF(buffer, sizeof(buffer), "ok");
      if (TcpServer.Write(buffer) == false)
      {
        printf("TcpServer write failed\n"); break;
      }
      printf("给%s发送%s\n\n", TcpServer.GetIP(), buffer);
      logfile.Write("给%s发送%s\n\n", TcpServer.GetIP(), buffer);
   }
   exit(0);
  } 
  return 0;
}

void FathEXIT(int sign)
{
   // 以下代码是为了防止信号处理函数在执行的过程中被信号中断。
  signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);

  logfile.Write("父进程退出, sig = %d", sign);
  TcpServer.CloseListen();
  kill(0, 15);
  exit(0);
}

void ChldEXIT(int sign)
{
  // 以下代码是为了防止信号处理函数在执行的过程中被信号中断。
  signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);

  logfile.Write("子进程退出, sig = %d", sign);
  TcpServer.CloseClient();
  exit(0);
}

