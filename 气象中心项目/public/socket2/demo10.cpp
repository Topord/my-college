/*
 * 程序名：demo10.cpp，此程序用封装CTcpServer实现通讯,实现有个一个server接收多个client的内容, 并向/log/tcptest中写入日志文件
 * 作者：topord
*/
#include "../_public.h" 
#include <signal.h>

CLogFile logfile;

int main(int argc,char *argv[])
{
  if (argc!=3)
  {
    printf("Using:./demo10 port logfilepath \nExample:./demo10 5005 /log/tcptest/demo10.log\n\n"); return -1;
  }

  CTcpServer TcpServer;
  
  if (logfile.Open(argv[2], "w") == false)
  {
    printf("logfile.Open(%s) failed\n", argv[2]); return 0;
  }

  // bool InitServer(const unsigned int port,const int backlog=5);
  if (TcpServer.InitServer(atoi(argv[1])) == false)
  {
    printf("TcpServer.InitServer(%s) failed\n", argv[1]); return -1;
  }
  
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
