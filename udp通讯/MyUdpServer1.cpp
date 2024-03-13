/*
 * 功能：此程序实现了最简单的UDP server
 * 作者：Li
 *
 */

#include "UdpServer.h"

void _help();

char recvbuffer[1025];
char sendbuffer[1025];

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
  

  while (1)
  {
    memset(recvbuffer, 0, sizeof(recvbuffer));
    memset(sendbuffer, 0, sizeof(sendbuffer));
    if (Server.Recv(recvbuffer) == false)
    {
      printf("Server.Recv() failed\n"); return -1;
    }
    strcpy(sendbuffer, "hi");
    if (Server.Send(sendbuffer) == false)
    {
        printf("Server.Send() failed\n"); return -1;
    }
  }
  Server.CloseListen();

  return 0;
}

void _help()
{
  printf("Using:./MyUdpServer port\nExample:./MyUdpServer 5005\n\n");
}
