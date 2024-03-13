/*
 * 功能：实现Server和client一对一通讯
 * 作者：Li
 */
#include "UdpServer.h"

char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];

void _help();
bool _initconnection(UdpServer& Server); // 初始化对话
void _talktoclient(UdpServer& Server);   // 实现对话

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    _help(); return -1;
  }

  UdpServer Server;
  if (Server.InitServer(atoi(argv[1])) == false)
  {
    printf("Server.InitServer() failed\n"); return -1;
  }
  
  if(_initconnection(Server) == false) return -1;

  printf("服务端运行中, 正在等待消息...\n");
  while (1)
  {
    _talktoclient(Server);
  }
  Server.CloseListen();

  return 0;
}

void _talktoclient(UdpServer& Server)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));
  
  // 接收
  if(Server.Recv(recvbuffer) == false)
  {
    printf("Server.Recv() failed\n"); return;
  }
  // 获取IP
  printf("from "); Server.GetIP();
  printf("server recv: %s\n", recvbuffer);
  
  // 获取时间
  LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);
  
}

bool _initconnection(UdpServer& Server)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));

  if (Server.Recv(recvbuffer) == false)
  {
    printf("Server.Recv() failed\n"); return false;
  }
  
  strcpy(sendbuffer, "connection ok");
  if (Server.Send(sendbuffer) == false)
  {
    printf("Server.Send() failed\n"); return false;
  }
  printf("---------------------------------\n\n");
  
  return true;
}

void _help()
{
  printf("Using:./MyUdpServer port\nExample:./MyUdpServer 5005\n\n");
}
