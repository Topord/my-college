/*
 * 功能：此程序主要用来进行处理文件的3个方式
 * 作者：topord
 */
#include "_public.h"
#include "_ftp.h"

struct st_arg
{
  char host[31];           // 远程服务端的IP和端口。
  int  mode;               // 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。
  char username[31];       // 远程服务端ftp的用户名。
  char password[31];       // 远程服务端ftp的密码。
  char remotepath[301];    // 远程服务端存放文件的目录。
  char localpath[301];     // 本地文件存放的目录。
  char matchname[101];     // 待下载文件匹配的规则。
  char listfilename[301];  // 下载前列出服务器文件名的文件。 
  int ptype;               // 下载后服务端文件的处理方式：1-什么也不做；2-删除；3-备份
  char remotepathbak[301]; // 下载后服务端文件的备份目录。
} starg;

struct st_fileinfo
{
  char filename[301]; // 文件名
  char mtime[21];     // 文件时间
};

vector<struct st_fileinfo> vfileinfo; // 存放下载前列出服务器文件名的窗口

CLogFile logfile;

Cftp ftp;

// 程序退出和信号2、15的处理函数
void EXIT(int sig);

// 帮助函数
void _help();

// 解析xml的函数
bool _xmltoarg(char* strxmlbuffer);

// 下载文件功能的主函数
bool _ftpgetfiles();

// 把ftp.nlist()方法获取到的list文件加载到vfilelist中
bool LoadListFile();

int main(int argc, char* argv[])
{
  if (argc != 3) { _help(); return -1;}

  // 处理程序的退出信号
  // CloseIOAndSignal();
  signal(SIGINT, EXIT); signal(SIGTERM,EXIT);

  // 打开日志文件
  if (logfile.Open(argv[1]) == false) 
  {
    printf("logfile,open() failed\n"); 
    return -1;
  }
  // 解析xml, 得到程序运行参数
  if (_xmltoarg(argv[2]) == false)
  {
    logfile.Write("获取xml信息失败\n");
    return -1;
  }
  // ftp登入服务器
  if (ftp.login(starg.host, starg.username, starg.password) == false)
  {
    logfile.Write("ftp.login(%s, %s, %s) failed\n", starg.host, starg.username, starg.password);
    return -1;
  }
  
  logfile.Write("ftp.login(%s, %s, %s) ok\n", starg.host, starg.username, starg.password);

  _ftpgetfiles();

  ftp.logout(); 

  return 0;
}

// 下载文件功能的主函数
bool _ftpgetfiles()
{
  // 进入ftp服务器存放文件的目录
  if (ftp.chdir(starg.remotepath) == false) 
  { 
    logfile.Write("ftp.chdir(%s) failed\n", starg.remotepath);
    return false;
  }
  // 调用
  if (ftp.nlist(".", starg.listfilename) == false)
  {
    logfile.Write("ftp.nlist(%s) failed\n", starg.listfilename);
    return false;
  } 

  // 把ftp.nlist()方法获取到的list文件加载到容器vfilelist中
  if (LoadListFile() == false)
  {
    logfile.Write("LoadFileList() failed\n");
    return false;  
  }
  
  // 遍历容器vfileinfo
  char strlocalfilename[301]; char strremotefilename[301];
  memset(strlocalfilename, 0, sizeof(strlocalfilename)); memset(strremotefilename, 0, sizeof(strremotefilename));
  for (int i = 0; i < vfileinfo.size(); i++)
  {
    SNPRINTF(strlocalfilename, sizeof(strlocalfilename), 300, "%s/%s", starg.localpath, vfileinfo[i].filename);
    SNPRINTF(strremotefilename, sizeof(strremotefilename), 300, "%s/%s", starg.remotepath, vfileinfo[i].filename);
    // 调用ftp.get()来下载文件
    if (ftp.get(strremotefilename, strlocalfilename) == false)
    {
      logfile.Write("upload file failed(%s->%s)--------------------------------\n", strremotefilename, strlocalfilename);
      return false;
    }
    logfile.Write("upload file ok(%s->%s)\n", strremotefilename, strlocalfilename);   
    if (starg.ptype == 1)
    {
      
    }
    if (starg.ptype == 2)
    {
      if (ftp.ftpdelete(strremotefilename) == false)
      {
        logfile.Write("ftp.ftpdelete(%s) failed\n", strremotefilename); return false;
      }
      logfile.Write("ftp.ftpdelete(%s) ok\n", strremotefilename); 
    }
    if (starg.ptype == 3)
    {
      char strremotefilenamebak[301];
      SNPRINTF(strremotefilenamebak, sizeof(strremotefilenamebak), 300, "%s/%s", starg.remotepathbak, vfileinfo[i].filename);
      if (ftp.ftprename(strremotefilename, strremotefilenamebak) == false)
      {
        logfile.Write("ftp.ftprename(%s) failed\n", strremotefilenamebak); return false;
      }
      logfile.Write("ftp.ftprename(%s) ok\n", strremotefilenamebak); 
    }  
   
  }
  return true;
}

// 把ftp.nlist()方法获取到的list文件加载到容器vfilelist中
bool LoadListFile()
{
  memset(&vfileinfo, 0, sizeof(vfileinfo));
 
  CFile File;

  if (File.Open(starg.listfilename, "r") == false)
  {
    logfile.Write("File.Open(%s) failed\n", starg.listfilename);
    return false;
  } 

  struct st_fileinfo stfileinfo;   

  while (true)
  {
    memset(&stfileinfo, 0, sizeof(stfileinfo));
    if (File.Fgets(stfileinfo.filename, 300, true) == false) break;    
    if (MatchStr(stfileinfo.filename, starg.matchname) == false) continue;
     
    vfileinfo.push_back(stfileinfo);
  }
  /* 测试
  
  for (int i = 0; i < vfileinfo.size(); i++)
  {
    logfile.Write("%s\n", vfileinfo[i].filename);
  }*/
  
  return true;
}

// 解析xml的函数
bool _xmltoarg(char* strxmlbuffer)
{
  memset(&starg, 0, sizeof(struct st_arg));

  GetXMLBuffer(strxmlbuffer, "host", starg.host, 30);   // 远程服务端的IP和端口。
  if (strlen(starg.host) == 0)
  {
    logfile.Write("host is null\n"); return false;
  }

  GetXMLBuffer(strxmlbuffer,"mode",&starg.mode);   // 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。
  if (starg.mode!=2)  starg.mode=1;
 
  GetXMLBuffer(strxmlbuffer, "username", starg.username, 30);   // 远程服务端ftp的用户名。
  if (strlen(starg.username) == 0)
  {
    logfile.Write("username is null\n"); return false;
  } 

  GetXMLBuffer(strxmlbuffer, "password", starg.password, 30);   // 远程服务端ftp的密码
  if (strlen(starg.password) == 0)
  {
    logfile.Write("password is null\n"); return false;
  }
 
  GetXMLBuffer(strxmlbuffer, "remotepath", starg.remotepath, 300);   // 远程服务端存放文件的目录
  if (strlen(starg.remotepath) == 0)
  {
    logfile.Write("remotepath is null\n"); return false;
  }

  GetXMLBuffer(strxmlbuffer, "localpath", starg.localpath, 300);   // 本地文件存放的目录
  if (strlen(starg.localpath) == 0)
  {
    logfile.Write("localpath is null\n"); return false;
  }
  
  GetXMLBuffer(strxmlbuffer, "listfilename", starg.listfilename, 300);   // 下载前列出服务器文件名的文件
  if (strlen(starg.listfilename) == 0)
  {
    logfile.Write("listfilename is null\n"); return false;
  }
 
  GetXMLBuffer(strxmlbuffer, "matchname", starg.matchname, 100);   // 待下载文件匹配的规则。
  if (strlen(starg.matchname) == 0)
  {
    logfile.Write("matchname is null\n"); return false;
  }

  GetXMLBuffer(strxmlbuffer,"ptype",&starg.ptype);   // 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。
  if ((starg.ptype!=1)&&(starg.ptype!=2)&&(starg.ptype!=3))
  {
    logfile.Write("starg.ptype error\n"); return false;
  }
  
  GetXMLBuffer(strxmlbuffer, "remotepathbak", starg.remotepathbak, 300);   // 下载前列出服务器文件名的文件
  if (strlen(starg.remotepathbak) == 0)
  {
    logfile.Write("remotepathbak is null\n"); return false;
  }

  return true;
}

void EXIT(int sig)
{
  printf("程序退出，sig = %d\n\n", sig);
  exit(0);
}

void _help()
{
  printf("\n");
  printf("Using:/project/tools2/bin/ftpgetfiles logfilename xmlbuffer\n\n");

  printf("Sample:/project/tools2/bin/procctl 30 /project/tools2/bin/ftpgetfiles /log/idc/ftpgetfiles_surfdata.log \"<host>172.20.119.29:21</host><mode>1</mode><username>topord</username><password>723916zxcv</password><localpath>/idcdata/surfdata</localpath><remotepath>/tmp/idc/surfdata</remotepath><matchname>SURF_ZH*.XML,SURF_ZH*.CSV</matchname><listfilename>/idcdata/ftplist/ftpgetfiles_surfdata.list</listfilename><ptype>3</ptype><remotepathbak>/tmp/idc/surfdatabak</remotepathbak>\"\n\n\n");

  printf("本程序是通用的功能模块，用于把远程ftp服务端的文件下载到本地目录。\n");
  printf("logfilename是本程序运行的日志文件。\n");
  printf("xmlbuffer为文件下载的参数，如下：\n");
  printf("<host>127.0.0.1:21</host> 远程服务端的IP和端口。\n");
  printf("<mode>1</mode> 传输模式，1-被动模式，2-主动模式，缺省采用被动模式。\n");
  printf("<username>wucz</username> 远程服务端ftp的用户名。\n");
  printf("<password>wuczpwd</password> 远程服务端ftp的密码。\n");
  printf("<localpath>/idcdata/surfdata</localpath> 本地文件存放的目录。\n");
  printf("<remotepath>/tmp/idc/surfdata</remotepath> 远程服务端存放文件的目录。\n");
  printf("<matchname>SURF_ZH*.XML,SURF_ZH*.CSV</matchname> 待下载文件匹配的规则。"\
         "不匹配的文件不会被下载，本字段尽可能设置精确，不建议用*匹配全部的文件。\n");
  printf("<listfilename>/idcdata/surfdata</listfilename> 下载前列出服务器的文件目录\n");
  printf("<ptype>3</ptype> 下载后服务端文件的处理方式：1-什么也不做；2-删除；3-备份\n");
  printf("<remotepathbak>/tmp/idc/surfdatabak</remotepathbak> 文件下载成功后，服务端文件的备份目录，此参数只有当ptype=3时才有效。\n\n");
}
