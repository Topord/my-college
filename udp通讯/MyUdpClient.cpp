#include "UdpClient.h"
#include <stdio.h>

UdpClient Client;
char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];

void _help();
void _talktoserver(UdpClient& Client, const char *ip, const int port);    // 实现对话

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    _help(); return -1;
  }

  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));

  while (1)
  {
    _talktoserver(Client, argv[1], atoi(argv[2]));
  }
  

  return 0;
}

void _talktoserver(UdpClient& Client, const char *ip, const int port)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));

  printf("请输入发送的消息: ");

  gets(sendbuffer);

  if (Client.Send(sendbuffer, ip, port) == false)
  {
    printf("Client.Send() failed\n"); return;
  }
  printf("\n");

  // 接收server
  if (Client.Recv(recvbuffer, port) == false)
  {
    printf("Client.Recv() failed\n"); return;
  }
  printf("接收到: %s\n", recvbuffer);

  printf("---------------------------------from %s\n\n", Client.s_ip);

  Client.CloseConnection();
}

void _help()
{
  printf("Using:./MyUdpClient ip port\nExample:./MyUdpClient 127.0.0.1 5005\n\n");
  printf("Input: Hello, this is test   Reply: test ok\n");
  printf("Input: show time             Reply: strtime\n");
  printf("Input: others                Reply: I have received\n");
}
