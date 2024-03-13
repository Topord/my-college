/*
 * 功能：此程序实现了最简单的UDP通讯
 * 作者：Li
 *
 */

#include "UdpClient.h"

void _help();

char recvbuffer[1025];
char sendbuffer[1025];


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

  while (1)
  {
    memset(recvbuffer, 0, sizeof(recvbuffer));
    memset(sendbuffer, 0, sizeof(sendbuffer));
    strcpy(sendbuffer, "hello");
    if (Client.Send(sendbuffer) == false)
   {
        printf("Client.Send() failed\n"); return -1;
    }
    if (Client.Recv(recvbuffer) == false)
    {
        printf("Client.Recv() failed\n"); return -1;
    }
    sleep(1);
  }
  Client.CloseConnection();

  return 0;
}

void _help()
{
  printf("Using:./MyUdpClient ip port\nExample:./MyUdpClient 127.0.0.1 5005\n\n");
}
