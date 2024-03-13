/* 
 * 此程序主用来理解Linux信号
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void EXIT(int sig)
{
  printf("接收到了%d信号\n", sig);
  
  // 没有这行代码程序只会在遇见kill -9 + 进程号时停止
  exit(0);
}

int main()
{
  for(int i = 1; i <= 64; i++){
    signal(i, SIG_IGN);
  }
  signal(SIGINT, EXIT); signal(SIGTERM, EXIT);

  while(1){
    printf("执行了一次任务。\n");
    sleep(1);
  }

  return 0;
}
