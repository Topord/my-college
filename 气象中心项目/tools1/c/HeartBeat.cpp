/*
 * 功能：本程序主要用来生成共享内存的心跳机制（在共享内存中写入改程序的信息）. 该程序即为_public.h中CPative类中方法的类似代码。
 * 作者：topord
 */

#include "_public.h"

struct st_pinfo
{
  int pmid;
  char pname[30];
  int timeout;
  time_t atime;
};

const int MAXLEN_ = 1000;
const int SHMKEY_ = 0x5069;

int main(int argc, char* argv[])
{
  if(argc < 2){
    printf("Using: ./sharedMemory + procame\n");
    return 0;
  } 
  // 创建共享内存
  int shmpid = 0;
  if((shmpid = shmget(SHMKEY_, MAXLEN_*sizeof(struct st_pinfo), 0640|IPC_CREAT)) == -1){
    printf("shmget(%d) failed\n", SHMKEY_); return -1;
  }
  // 加锁
  CSEM m_sem;
  if((m_sem.init(SHMKEY_) == false)){
    printf("m_sem.init(%x) failed\n", SHMKEY_);
    return -1;
  }
  // 连接共享内存
  struct st_pinfo* shmptr;
  if((shmptr = (struct st_pinfo*)shmat(shmpid, 0, 0)) == (void*)-1){
    printf("shmat(%d, 0, 0) failed\n", shmpid);
    return -1;
  } 
  // 创建当前进程的心跳机制结构体变量，并将其写入共享内存'
  struct st_pinfo stpinfo;
  memset(&stpinfo, 0, sizeof(struct st_pinfo));
  STRNCPY(stpinfo.pname, sizeof(stpinfo.pname), argv[1], 50); // 进程名称
  stpinfo.pmid = getpid(); // 进程id
  stpinfo.timeout = 30;   // 超时时间。单位：秒
  stpinfo.atime = time(0); // 最后一次心跳时间，填当前时间
  
  int m_pos = -1;

  // 查找是否有异常的内存
  for(int i = 0; i < MAXLEN_; i++){
    if((shmptr+i)->pmid == getpid()){
      m_pos = i; break;
    }
  }
  m_sem.P();
  // 在共享内存中找一个空位置，把当前信息填入共享内存中
  if(m_pos != -1){
    for(int i = 0; i < MAXLEN_; i++){
      if((shmptr + i)->pmid == 0) // 找到空位置
      {
        m_pos = i;  
        break;
      }
    }
  }
  if(m_pos == -1){
    m_sem.V();
    printf("没找到共享内存的空位置\n");
    return -1;
  }
  
  // 把当前进程的心跳信息存入共享内存中
  memcpy(shmptr+m_pos, &stpinfo, sizeof(struct st_pinfo)); 
  
  m_sem.V();
  while(true){
    // 更新共享内存中本进程的心跳时间
    (shmptr+m_pos)->atime = time(0);
     sleep(10);
  }
  // 把当前进程从共享内存中移去
  memset(shmptr+m_pos, 0, sizeof(struct st_pinfo));
  
  // 把共享内存从当前进程中分离
  shmdt(shmptr);

  return 0;
}
