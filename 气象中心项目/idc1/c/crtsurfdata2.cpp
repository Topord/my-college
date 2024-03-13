/*
 * 程序名：cursurfdata2.cpp 
 * 功能：本程序用于将数据写入结构元素进行处理后并写入文件中
 * 作者：topord
*/

#include "_public.h"
// 例子: 省   站号  站名 纬度   经度  海拔
//     广西,59046,柳州,24.21,109.24,96.8  

// 全球气象站点参数
struct st_stcode
{
  char provname[30]; // 省
  char obtid[11];    // 站号
  char obtname[31];  // 站名
  double lat;        // 纬度
  double lon;        // 经度
  double height;     // 海拔高度
};
 
// 存放全国气象站点参数的容器
vector<struct st_stcode> vstcode;

// 把站点参数文件中加载到vstcode容器中
bool LoadSTCode(const char *inifile);

// 日志类
CLogFile logfile;

int main(int argc, char *argv[])
{
  //infile -- 参数文件 outpath -- 生成数据的存放目录 logfile -- 程序日志
  if(argc != 4){
    printf("Using:./crtsurfdata2 infile out path logfile\n");
    printf("Example:/project/idc2/bin/crtsurfdata2 /project/idc2/ini/stcode.ini /tmp/surfdata /log/idc/crtsurfdata2.log\n\n");

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
   
  logfile.Write("crtsurfdata2 开始运行. \n");
  
  //把站点参数文件中加载到vstcode容器中
  if(LoadSTCode(argv[1]) == false) return -1;
  
  logfile.Write("crtsurfdata2 结束运行. \n");  

  return 0;
}

bool LoadSTCode(const char* inifile)
{
  CFile File;
  // 打开站点参数文件
  if(File.Open(inifile, "r") == false){
    logfile.Write("File.Open(%s) failed.\n", inifile); return false;
  }
  
  char strBuffer[301];

  CCmdStr CmdStr; 

  struct st_stcode stcode;

  // 全球气象站点参数
  while(true)
  {
    // 从站点参数文件中读取一行，如果已读取完，跳出循环。
    if(File.Fgets(strBuffer, 100, true) == false) break;
    // 把读取到的一行拆分。
    CmdStr.SplitToCmd(strBuffer, ",", true);  
    // 把站点参数的每个数据项保存到站点参数结构体中。
    CmdStr.GetValue(0, stcode.provname, 30);
    CmdStr.GetValue(1, stcode.obtid, 30);
    CmdStr.GetValue(2, stcode.obtname, 30);
    CmdStr.GetValue(3, &stcode.lat);
    CmdStr.GetValue(4, &stcode.lon);
    CmdStr.GetValue(5, &stcode.height);
    // 把站点参数结构体放入站点参数容器。
    vstcode.push_back(stcode);
  }

  for(int i = 1; i < vstcode.size(); i++){
    logfile.Write("i=%d, province=%s, obtid=%s, obtname=%s, lat=%.2f, lon=%.2f, height=%.2f\n",\
                   i, vstcode[i].provname,vstcode[i].obtid,vstcode[i].obtname,vstcode[i].lat,\
                   vstcode[i].lon, vstcode[i].height);
  }

  return true;
}
