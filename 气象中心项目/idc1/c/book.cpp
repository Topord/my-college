/* 
 * 此程序主用来理解Linux信号
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void handler(int sig)
{
  printf("接收到了%d信号\n", sig);
}

void alrm(int num)
{
  printf("闹钟接收到%d的信号\n", num);
  alarm(3);
}

int main()
{
  for(int i = i; i <= 64; i++){
    signal(i, handler);
  }
  signal(SIGALRM, alrm);
  alarm(3);
  while(1){
    printf("执行了一次任务。\n");
    sleep(1);
  }

  return 0;
}
