/*
 * 程序名：demo08.cpp，此程序用封装CTcpServer实现通讯
 * 作者：topord
*/
#include "../_public.h" 

int main(int argc,char *argv[])
{
  if (argc!=2)
  {
    printf("Using:./demo08 port\nExample:./demo08 5005\n\n"); return -1;
  }

  CTcpServer TcpServer;
  
  // bool InitServer(const unsigned int port,const int backlog=5);
  if (TcpServer.InitServer(atoi(argv[1])) == false)
  {
    printf("TcpServer.InitServer(%s) failed\n", argv[1]); return -1;
  }
 
  if (TcpServer.Accept() == false) 
  {
    printf("TcpServer.Accept() failed\n"); return -1;
  } 

  printf("成功连接上%s\n", TcpServer.GetIP());  

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
    printf("接收：%s\n",buffer);
  
    memset(buffer, 0, sizeof(buffer));
    SPRINTF(buffer, sizeof(buffer), "ok");
    if (TcpServer.Write(buffer) == false)
    {
      printf("TcpServer write failed\n"); break;
    }
    printf("给%s发送%s\n\n", TcpServer.GetIP(), buffer);
  }
 
}
