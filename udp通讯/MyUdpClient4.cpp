/*
 * 功能：实现UDP通讯一对多的客户端
 * 作者：Li
 *
 */
#include "UdpClient.h"

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
    Client.CloseConnection();
  }
  

  return 0;
}

void _talktoserver(UdpClient& Client, const char *ip, const int port)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));

  printf("请输入发送的消息: ");

  cin >> sendbuffer;
  
  if (Client.Send(sendbuffer, ip, port) == false)
  {
    printf("Client.Send() failed\n"); return;
  }
  LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);
}

void _help()
{
  printf("Using:./MyUdpClient ip port\nExample:./MyUdpClient 127.0.0.1 5005\n\n");
}
