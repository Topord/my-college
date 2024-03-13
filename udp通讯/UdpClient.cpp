#include "UdpClient.h"

UdpClient::UdpClient()
{
  m_sockfd = -1;
  m_port = 0;
  memset(s_ip, 0, sizeof(s_ip));
  memset(&clientAddr, 0, sizeof(clientAddr));
}

UdpClient::~UdpClient()
{
  CloseConnection();
}

// 初始化1
bool UdpClient::InitClient(const char *ip, const int port)
{
  if (m_sockfd != -1) { close(m_sockfd); m_sockfd = -1; }
  strcpy(s_ip, ip);

  m_sockfd = socket(PF_INET, SOCK_DGRAM, 0);
  if(m_sockfd == -1)
  {
    printf("ConnectToServer() failed\n");
    return -1;
  }   
  clientAddr.sin_family = AF_INET;
  clientAddr.sin_port = htons(port);
  inet_pton(AF_INET, s_ip, &clientAddr.sin_addr.s_addr);

  return true;
}

bool UdpClient::Send(char* sendbuffer, const char *ip, const int port)
{
  if (InitClient(ip, port) == false) return false;

  if (m_sockfd == -1) return false;
  int len = strlen(sendbuffer) + 1;
  sendto(m_sockfd, sendbuffer, len, 0, (struct sockaddr *)&clientAddr, sizeof(clientAddr));

  return true;
}

bool UdpClient::Recv(char* recvbuffer, const unsigned int port)
{
  if (m_sockfd == -1) return false;
 
  socklen_t size = sizeof(clientAddr);

  recvfrom(m_sockfd, recvbuffer, 10241, 0, NULL, NULL);

  return true;
}

void UdpClient::CloseConnection()
{
  m_sockfd = -1;
  m_port = 0;
  memset(s_ip, 0, sizeof(s_ip));
  memset(&clientAddr, 0, sizeof(clientAddr));
}
