/*
 * 程序名：cursurfdata1.cpp 
 * 功能：本程序用于生成日志文件
 * 作者：topord
*/

#include "_public.h"

CLogFile logfile(10);

int main(int argc, char *argv[])
{
  //infile -- 参数文件 outpath -- 生成数据的存放目录 logfile -- 程序日志
  if(argc != 4){
    printf("Using:./crtsurfdata1 infile out path logfile\n");
    printf("Example:/project/idc2/bin/crtsurfdata1 /project/idc2/ini/stcode.ini /tmp/surfdata /log/idc/crtsurfdata1.log\n\n");

    printf("inifile 全国气象站点参数文件名\n");
    printf("outpath 全国气象站点数据文件存放的目录\n");
    printf("logfile 本程序运行的日志文件名\n\n");

    return -1;
  }	
  if(logfile.Open(argv[3]) == false)
  {
    printf("logfile.Open(%s) failed\n", argv[3]);
    return -1;
  }
   
  logfile.Write("crtsurfdata1 开始运行. \n");
  
  //插入业务代码
  logfile.WriteEx("crtsurfdata1 结束运行. \n");  

  return 0;
}

