#include "UdpServer.h"

UdpServer Server;
char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];

void _help();
void reply(char* recv, char* ip, const unsigned int port);
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
  }
  
  return 0;
}

void _talktoclient(UdpServer& Server, const unsigned int port)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));

  char c_ip[24];

  // 接收
  if(Server.Recv(recvbuffer, port) == false)
  {
    printf("Server.Recv() failed\n"); return;
  }

  // 获取IP
  strcpy(c_ip, Server.GetIP());

  printf("已接收(from %s)\n", c_ip);
  printf("message: %s\n", recvbuffer);
  
  // 获取时间
  LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);
  
  // 向Client回复
  reply(recvbuffer, c_ip, port);
  printf("send %s to %s\n.", sendbuffer, c_ip);
  // 获取时间
  LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);

  Server.CloseConnection();
}

void reply(char* recv, char* ip, const unsigned int port)
{
  if (strcmp(recvbuffer, "Hello, this is test") == 0)
  {
    strcpy(sendbuffer, "test ok");
  }
  else if(strcmp(recvbuffer, "show time") == 0)
  {
    memset(strtime, 0, sizeof(strtime));
    LocalTime(strtime);
    strcpy(sendbuffer, strtime);
  }
  else
  {
    strcpy(sendbuffer, "I have received");
  }

  if(Server.Send(sendbuffer, ip, port) == false)
  {
    printf("Server.Send(%s) failed\n", sendbuffer);
  }
}

void _help()
{
  printf("Using:./MyUdpServer port\nExample:./MyUdpServer 5005\n\n");
}
