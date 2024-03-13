#include "UdpServer.h"

// 构造函数
UdpServer::UdpServer()
{
  m_listenfd = -1;
  m_socklen = 0;
}

// 析构函数
UdpServer::~UdpServer()
{
  CloseConnection();
}

// 初始化1
bool UdpServer::InitServer(const unsigned int port)
{
  if (m_listenfd > 0) 
  {
    m_listenfd = -1;
  }

  m_listenfd = socket(PF_INET, SOCK_DGRAM, 0);

  if (m_listenfd <= 0) return false;

  serverAddr.sin_family = AF_INET;  
  serverAddr.sin_addr.s_addr = INADDR_ANY;          
  serverAddr.sin_port = htons(port);

  if (bind(m_listenfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
  {
    CloseConnection(); 
    return false;
  }

  return true;
}

// 接收
bool UdpServer::Recv(char* recvbuffer, const unsigned int port)
{
  if (InitServer(port) == false) return false;

  if (m_listenfd == -1) return false;

  socklen_t size = sizeof(clientAddr);
  
  recvfrom(m_listenfd, recvbuffer, 10241, 0, (struct sockaddr *) &clientAddr, &size);

  return true;
}

// 发送
bool UdpServer::Send(char* sendbuffer, const char* ip, const int port)
{
  if (m_listenfd == -1) return false;
  int len = strlen(sendbuffer) + 1;

  sendto(m_listenfd, sendbuffer, len, 0, (struct sockaddr *) &clientAddr, sizeof(clientAddr));

  return true;
}

char* UdpServer::GetIP()
{
  memset(c_ip, 0, sizeof(c_ip));

  inet_ntop(AF_INET, &clientAddr.sin_addr.s_addr, c_ip, sizeof(c_ip));
  return c_ip;
}

// 关闭连接
void UdpServer::CloseConnection()
{
  
  close(m_listenfd); 

  memset(&this->clientAddr, 0, sizeof(struct sockaddr_in));
  memset(&this->serverAddr, 0, sizeof(struct sockaddr_in));
  memset(c_ip, 0, sizeof(c_ip));

  m_listenfd=-1;
  
}

// 获取当前时间
void timetostr(const time_t ltime,char *stime)
{
  if (stime==0) return;

  strcpy(stime,"");

  struct tm sttm = *localtime ( &ltime ); 

  sttm.tm_year=sttm.tm_year+1900;
  sttm.tm_mon++;

  snprintf(stime,20,"%04u-%02u-%02u %02u:%02u:%02u",sttm.tm_year,
                    sttm.tm_mon,sttm.tm_mday,sttm.tm_hour,
                    sttm.tm_min,sttm.tm_sec);
}

void LocalTime(char *stime)
{
  if (stime==0) return;

  time_t  timer;

  time( &timer ); timer=timer;

  timetostr(timer,stime);
}
