/*
 * 程序名：demo07.cpp，此程序用于使用CTcpClient类实现数据传输
 * 作者：topord
*/
#include "../_public.h"

int main(int argc, char* argv[])
{
  if (argc!=3)
  {
    printf("Using:./demo07 ip port\nExample:./demo07 127.0.0.1 5005\n\n"); return -1;
  }

  CTcpClient TcpClient;

  char buffer[1024];
  // bool ConnectToServer(const char *ip,const int port);
  if (TcpClient.ConnectToServer(argv[1], atoi(argv[2])) == false)
  {
    printf("TcpClient(%s, %d) failed\n", argv[1], argv[2]); return -1;
  }

  // 第3步：与服务端通讯，连续发送1000个报文。
  for (int ii=0;ii<10;ii++)
  {
    memset(buffer,0,sizeof(buffer));
    // int SNPRINTF(char *dest,const size_t destlen,size_t n,const char *fmt,...);
    SPRINTF(buffer, sizeof(buffer), "这是第%d条信息, 编号为%03d", ii+1, ii+1);
    // bool Write(const char *buffer,const int ibuflen=0);
    if (TcpClient.Write(buffer) == false) break; // 向服务端发送请求报文。
    printf("发送: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    if (TcpClient.Read(buffer) == false) break;
    printf("接收到：%s\n\n",buffer);
    sleep(2);
  }
  

  return 0; 
}

