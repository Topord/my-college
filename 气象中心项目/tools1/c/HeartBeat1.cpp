/*
 * 功能：用框架中的CPActive类对心跳程序进行简化
 * 作者：topord
 */

#include "_public.h"

int main(int argc, char* argv[])
{
  if(argv < 2){
    printf("Using: ./HeartBeat + procname. \n");
    return -1;
    }

  CPActive PActive;
  PActive.AddPInfo(30, argv[1]);

  while(true){
    PActive.UptATime();
    sleep(10);
  }

  return 0;

}
