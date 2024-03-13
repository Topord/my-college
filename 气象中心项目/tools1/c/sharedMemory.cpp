/*
 * 功能：此程序主要用来测试于共享内存相关的几个函数
 * shmget()\shmat()\shmdt()\shmctl()
 * 作者：Topord
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

struct sharedm
{
  char name[51];
  int pid;
};
int main(int argc, char* argv[])
{
  // shmget 获取共享内存
  int shmpid = 0;
  shmpid = shmget(0x1234, sizeof(struct sharedm),0640|IPC_CREAT);
  if(shmpid == -1){
    printf("establish shared memory failed\n");
    return -1;
  }

  // shmat 将共享内存与程序连接
  struct sharedm* stpid = 0;
  if((stpid = (struct sharedm*)shmat(shmpid, 0, 0)) == (void*)-1){
    printf("shmat(%d, 0, 0) failed\n", shmpid);
    return -1;
  }

  printf("stpid->name = %s; stpid->pid = %d\n", stpid->name, stpid->pid);
  strcpy(stpid->name, argv[1]); stpid->pid = getpid();
  printf("stpid->name = %s; stpid->pid = %d\n", stpid->name, stpid->pid);

  // shmdt 把共享内存从当前的程序分离
  shmdt(stpid); 
  /*char* tmp = (char*)"1111";
  stpid->name = tmp;
  printf("stpid->name = %s; stpid->pid = %d\n", stpid->name, stpid->pid);
  已分离，无法进行赋值操作*/

  // shctl 删除共享内存
  // if(shmctl(shmpid, IPC_RMID, 0) == -1){
  //  printf("shmctl failed\n"); return -1;
  //  }  
  return 0;

}
