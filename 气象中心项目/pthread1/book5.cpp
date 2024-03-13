// 本程序演示线程同步-互斥锁
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int var = 0;

pthread_mutex_t mutex;     // 声明互斥锁

void* thmain(void* arg);   // 线程主函数


int main(int argc, char* argv[])
{
  pthread_t thid = 0;  // 线程id typedef unsigned long pthread_t

  pthread_mutex_init(&mutex, NULL);   // 初始化锁

  // 创建线程
  if (pthread_create(&thid, NULL, thmain, NULL) != 0)
  {
    printf("pthread_create() failed\n");
  }
  
  
  // 等待子线程退出
  printf("join...\n");
  pthread_join(thid, NULL);
  printf("var = %d\n", var);
  printf("join ok.\n");

  pthread_mutex_destroy(&mutex);   // 销毁锁

  return 0;
}

void* thmain(void* arg)
{
  for (int i = 0; i < 10000; i++)
  {
    pthread_mutex_lock(&mutex);    // 加锁
    var++;
    pthread_mutex_unlock(&mutex);  // 解锁
  }
}


