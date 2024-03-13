#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int var;

void* thmain1(void* arg) { printf("var1=%d\n", (int*)(long)arg);printf("这是线程1的主函数\n"); }
void* thmain2(void* arg) { printf("var2=%d\n", (int*)(long)arg);printf("这是线程2的主函数\n"); }
void* thmain3(void* arg) { printf("var3=%d\n", (int*)(long)arg);printf("这是线程3的主函数\n"); }
void* thmain4(void* arg) { printf("var4=%d\n", (int*)(long)arg);printf("这是线程4的主函数\n"); }
void* thmain5(void* arg) { printf("var5=%d\n", (int*)(long)arg);printf("这是线程5的主函数\n"); }

int main(int argc, char* argv[])
{
  pthread_t thid1, thid2, thid3, thid4, thid5;

  var = 1;
  if (pthread_create(&thid1,NULL,thmain1,(void*)(long)var) != 0) {printf("create pthread1 failed\n");}
  var = 2;
  if (pthread_create(&thid2,NULL,thmain2,(void*)(long)var) != 0) {printf("create pthread2 failed\n");}
  var = 3;
  if (pthread_create(&thid3,NULL,thmain3,(void*)(long)var) != 0) {printf("create pthread3 failed\n");}
  var = 4;
  if (pthread_create(&thid4,NULL,thmain4,(void*)(long)var) != 0) {printf("create pthread4 failed\n");}
  var = 5;
  if (pthread_create(&thid5,NULL,thmain5,(void*)(long)var) != 0) {printf("create pthread5 failed\n");}


  printf("join...\n");
  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);
  pthread_join(thid3, NULL);
  pthread_join(thid4, NULL);
  pthread_join(thid5, NULL);
  printf("join ok\n");

  return 0;
}