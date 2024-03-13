#include "_cmpublic.h"

class UdpServer
{
private:
  int m_socklen;                    // 结构体struct sockaddr_in的大小。
  char c_ip[21];                    // Client的地址
  struct sockaddr_in clientAddr;    // 客户端的地址信息。
  struct sockaddr_in serverAddr;    // 服务端的地址信息
public:
  int  m_listenfd;                  // 服务端用于监听的socket。

  // 构造函数
  UdpServer();

  // 析构
  ~UdpServer();

  // 初始化
  bool InitServer(const unsigned int port);

  // 接收
  bool Recv(char* recvbuffer, const unsigned int port);

  // 发送
  bool Send(char* sendbuffer, const char* ip, const int port);

  // 获取通话IP
  char* GetIP();

  // 关闭连接
  void CloseConnection();
};

// 获取当前时间的函数
void LocalTime(char *stime);
void timetostr(const time_t ltime,char *stime);