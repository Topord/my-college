/*
 * 该程序主要用文件打开与关闭来演示父进程与子进程的关系 以及 僵尸进程相关的知识
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
// 在文件中书写
void test01()
{
  FILE *fp;
  fp = fopen("/log/idc/text.txt", "w+");
  fprintf(fp, "开始写入1111111111111111\n");
  fflush(fp);
  int pid = fork();
  
  if(pid == 0){
    printf("这是子进程%d\n", getpid());
    fprintf(fp, "子进程写入2222222222\n");
  }
  if(pid > 0){
    printf("这是父进程%d\n", getpid());
    fprintf(fp, "父进程写入11111111111\n");
  }
  fclose(fp);
}

// 关闭文件或打开文件不影响两个进程
void test02()
{
  FILE *fp;
  fp = fopen("/log/idc/text1.txt", "w+");
  fprintf(fp, "开始写入1111111111111111\n");
  fflush(fp);
  int pid = fork();

  if(pid == 0){
    printf("这是子进程%d\n", getpid());
    fclose(fp);
    fprintf(fp, "子进程写入2222222222\n");
  }
  if(pid > 0){
    printf("这是父进程%d\n", getpid());
    fprintf(fp, "父进程写入11111111111\n"); sleep(1);
    fprintf(fp, "父进程写入11111111112\n"); sleep(1);
    fprintf(fp, "父进程写入11111111113\n"); sleep(1);
    fclose(fp);
  }
}

// 如果父进程先退出，内核会向父进程发送SIGCHLD信号，若父进程不处理这个信号,子进程将变成僵尸进程
void test03()
{ 
  signal(SIGCHLD, SIG_IGN); // 通过忽略该信号来达成目的
  int pid = fork();
  
  if(pid == 0){
    printf("这是子进程%d, 将执行子进程的任务\n", getpid());
    sleep(5);
  }
  if(pid > 0){
    printf("这是父进程%d, 将执行父进程的任务\n", getpid());
    sleep(10);
  }
}

int main()
{
 // test01();
 // test02();
  test03();
  return 0;
}
