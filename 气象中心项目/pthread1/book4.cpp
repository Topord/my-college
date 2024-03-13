// 本程序演示原子性
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <atomic>
#include <iostream>

std::atomic<int> var;

void* thmain1(void* arg); // 线程主函数
void* thmain2(void* arg); // 线程主函数


int main(int argc, char* argv[])
{
  pthread_t thid1 = 0;  // 线程id typedef unsigned long pthread_t
  pthread_t thid2 = 0;  // 线程id typedef unsigned long pthread_t

  // 创建线程
  if (pthread_create(&thid1, NULL, thmain1, NULL) != 0)
  {
    printf("pthread_create() failed\n");
  }
  
  if (pthread_create(&thid2, NULL, thmain2, NULL) != 0)
  {
    printf("pthread_create() failed\n");
  }
  
  // 等待子线程退出
  printf("join...\n");
  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);
  printf("join ok.\n");

  std::cout << "var = " << var << std::endl;
  return 0;
}

void* thmain1(void* arg)
{
  for (int i = 0; i < 10000; i++)
  {
    var++;
  }
}


void* thmain2(void* arg)
{
  for (int i = 0; i < 10000; i++)
  {
    var++;
  }
}

