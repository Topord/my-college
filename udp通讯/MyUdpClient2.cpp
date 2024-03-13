/*
 * 功能：实现Server和client一对一通讯
 * 作者：Li
 */
#include "UdpClient.h"

char recvbuffer[10241];
char sendbuffer[10241];
char strtime[32];

void _help();
bool _initconnection(UdpClient& Client);  // 初始化对话
void _talktoserver(UdpClient& Client);    // 实现对话

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    _help(); return -1;
  }

  UdpClient Client;
  if (Client.ConnectToServer(argv[1], atoi(argv[2])) == false)
  {
    printf("Client.ConnectToServer() failed\n"); return -1;
  }

  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));

  if(_initconnection(Client) == false) return -1;
  
  while (1)
  {
    _talktoserver(Client);
  }
  Client.CloseConnection();

  return 0;
}

void _talktoserver(UdpClient& Client)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));
  memset(strtime, 0, sizeof(strtime));

  printf("请输入发送的消息: ");

  cin >> sendbuffer;
  
  if (Client.Send(sendbuffer) == false)
  {
    printf("Client.Send() failed\n"); return;
  }LocalTime(strtime);
  printf("---------------------------------%s\n\n", strtime);
}

bool _initconnection(UdpClient& Client)
{
  memset(recvbuffer, 0, sizeof(recvbuffer));
  memset(sendbuffer, 0, sizeof(sendbuffer));

  strcpy(sendbuffer, "Hello,this is client");
  if (Client.Send(sendbuffer) == false)
  {
    printf("Client.Send() failed\n"); return false;
  }
  if (Client.Recv(recvbuffer) == false)
  {
    printf("Client.Recv() failed\n"); return false;
  }
  printf("---------------------------------\n\n");

  return true;
}

void _help()
{
  printf("Using:./MyUdpClient ip port\nExample:./MyUdpClient 127.0.0.1 5005\n\n");
}
