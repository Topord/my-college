#include "_cmpublic.h"

class UdpClient
{
public:
  int  m_sockfd;    // 客户端的socket.
  int  m_port;      // 接收消息的端口
  char s_ip[21];    // 服务端的ip地址。
  struct sockaddr_in clientAddr;

  // 构造函数
  UdpClient();

  // 析构
  ~UdpClient();

  // 初始化
  bool InitClient(const char *ip, const int port);

  // 接收
  bool Recv(char* recvbuffer, const unsigned int port);

  // 发送
  bool Send(char* sendbuffer, const char *ip, const int port);

  // 断开连接
  void CloseConnection();
};
