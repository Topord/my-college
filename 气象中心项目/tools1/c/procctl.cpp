/*
 *功能: 此程序主要开发一个调度其他程序的程序
 *作者: topord
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    printf("Using:./procctl timetvl program argv ...\n");
    printf("Example:/project/tools1/bin/procctl 5 /usr/bin/tar zcvf /tmp/tmp.tgz /usr/include\n\n");

    printf("本程序是服务程序的调度程序，周期性启动服务程序或shell脚本。\n");
    printf("timetvl 运行周期，单位：秒。被调度的程序运行结束后，在timetvl秒后会被procctl重新启动。\n");
    printf("program 被调度的程序名，必须使用全路径。\n");
    printf("argvs   被调度的程序的参数。\n");
    printf("注意，本程序不会被kill杀死，但可以用kill -9强行杀死。\n\n\n");

    return -1;
  }
    
  // 关闭所有信号，该程序不希望被打扰
  for(int i = 1; i <= 64; i++){
    signal(i, SIG_IGN); close(i);
  }
  
  // 生成子进程，父进程退出，让程序运行在后台，由系统1号进程托管
  if(fork() != 0) exit(0);
  
  // 将*argv中的参数拷贝到pargc中，便于使用excev函数
  char* pargv[argc];
  for(int i = 2; i < argc; i++){
    pargv[i - 2] = argv[i];
  }
  pargv[argc - 2] = NULL;

  while(true){
    if(fork() == 0){
      execv(argv[2], pargv);
      exit(0);
    } 
    else{
      int status;
      wait(&status);
      sleep(atoi(argv[1]));
    } 
  }
  return 0;
}
