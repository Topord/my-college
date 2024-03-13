#include "UdpServer.h"

UdpServer Server;
char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];

void _help();
void _talktoclient(UdpServer& Server);   // 实现对话

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    _help(); return -1;
  }

  if (Server.InitServer(atoi(argv[1])) == false)
  {
    printf("Server.InitServer() failed\n"); return -1;
  }
 
  while (1)
  {
    // 初始化连接
    if(Server.ConnectToClient() == false) return -1;

    // 父进程返回到循环首部。
    // if (fork() > 0) continue;

    while (1)
    {
      _talktoclient(Server);
    }
    Server.CloseConnection();
  }

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
  printf("已接收(from "); Server.GetIP(); printf(")\n");
  printf("message: %s\n", recvbuffer);
  
  // 获取时间
  LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);
  
}

void _help()
{
  printf("Using:./MyUdpServer port\nExample:./MyUdpServer 5005\n\n");
}
