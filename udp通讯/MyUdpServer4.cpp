/*
 * 功能：实现UDP通讯一对多的客户端
 * 作者：Li
 *
 */
#include "UdpServer.h"

UdpServer Server;
char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];
int pid = -1;

void _help();
void _talktoclient(UdpServer& Server, const unsigned int port);   // 实现对话

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    _help(); return -1;
  }
  
  while (1)
  {
    _talktoclient(Server, atoi(argv[1]));
    Server.CloseConnection();
  }
  
  return 0;
}

void _talktoclient(UdpServer& Server, const unsigned int port)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));

  // 接收
  if(Server.Recv(recvbuffer, port) == false)
  {
    printf("!11\n");
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
