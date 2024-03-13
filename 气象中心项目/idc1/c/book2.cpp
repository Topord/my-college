/*
 * 该程序主要演示fork()函数和父进程与子进程的关系
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

// 一个现有的进程调用函数fork()创建一个新的进程
// 子进程和父进程继续执行fork函数后的代码
void test01()
{
  printf("aaa = %d\n", getpid());
  sleep(10);
  printf("bbb = %d\n", getpid());
  printf("添加子进程\n");
  fork();

  printf("ccc = %d\n", getpid());
  sleep(15);
  printf("ddd = %d\n", getpid());
}

// fork函数调用一次，返回两次
// 子进程返回0，父进程返回子进程的进程ID
void test02()
{
  printf("父进程 = %d\n", getpid());
  sleep(5);
  printf("添加子进程\n");
  int pid = fork();
  
  if(pid == 0){
     printf("这是子进程%d，因为pid == 0, 将执行子进程的任务\n", getpid());
     sleep(10);
  }
  if(pid > 0){
     printf("这是父进程%d, 因为pid > 0,  将执行父进程的任务\n", getpid());
     sleep(15);
  }
}

// 子进程是父进程的副本
// 子进程获得父进程的数据空间，堆和栈的副本，不是共享
void test03()
{ 
  int ii = 0;
  printf("父进程 = %d\n", getpid());
  printf("ii = %d\n", ii);
  sleep(5);
  printf("添加子进程\n");

  int pid = fork();

  if(pid == 0){
     printf("这是子进程%d，因为pid == 0, 将执行子进程的任务\n", getpid());
     printf("aaaa ii = %d\n", ii++); sleep(1);
     printf("aaaa ii = %d\n", ii++); sleep(1);
     printf("aaaa ii = %d\n", ii++); sleep(1);
     printf("aaaa ii = %d\n", ii++); sleep(1);
  }
  if(pid > 0){
     printf("这是父进程%d, 因为pid > 0,  将执行父进程的任务\n", getpid());
     printf("bbbb ii = %d\n", ii); sleep(1);
     printf("bbbb ii = %d\n", ii); sleep(1);
     printf("bbbb ii = %d\n", ii); sleep(1);
     printf("bbbb ii = %d\n", ii); sleep(1);
  }
}


int main()
{
 // test01();
 // test02();
  test03();
  return 0;
}
