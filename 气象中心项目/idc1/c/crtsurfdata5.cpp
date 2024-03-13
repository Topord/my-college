/*
 * 程序名：cursurfdata5.cpp 
 * 功能：本程序用于生成全国气象站点观测的分钟数据并生成.xml/.json文件
  作者：topord
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

//全国气象站点分钟观测数据结构
struct st_surfdata
{
  char obtid[11];      // 站点代码。
  char ddatetime[21];  // 数据时间：格式yyyymmddhh24miss
  int  t;              // 气温：单位，0.1摄氏度。
  int  p;              // 气压：0.1百帕。
  int  u;              // 相对湿度，0-100之间的值。
  int  wd;             // 风向，0-360之间的值。
  int  wf;             // 风速：单位0.1m/s
  int  r;              // 降雨量：0.1mm。
  int  vis;            // 能见度：0.1米。
};
vector<struct st_surfdata> vsurfdata; // 存放全国气象站点分钟观测数据的容器

// 模拟生成全国气象站点分钟观测数据, 存放在vsurfdata容器中.
void CrtSurfData();

// 把容器vsurfdata中的全国气象站点分钟观测数据写入文件。
bool CrtSurfFile(const char *outpath, const char *datafmt);

// 日志类
CLogFile logfile;

// 当前时间
char strdatetime[21];

int main(int argc, char *argv[])
{
  //infile -- 参数文件 outpath -- 生成数据的存放目录 logfile -- 程序日志 datafmt -- 文件格式
  if(argc != 5){
    printf("Using:./crtsurfdata5 infile outpath logfile datafmt\n");
    printf("Example:/project/idc2/bin/crtsurfdata5 /project/idc2/ini/stcode.ini /tmp/idc/surfdata /log/idc/crtsurfdata5.log json,csv,xml\n\n");

    printf("inifile 全国气象站点参数文件名\n");
    printf("outpath 全国气象站点数据文件存放的目录\n");
    printf("logfile 本程序运行的日志文件名\n");
    printf("datafmt 生成数据文件的格式\n\n");

    return -1;
  }	
  if(logfile.Open(argv[3]) == false)
  {
    printf("logfile.Open(%s) failed\n", argv[3]);
    return -1;
  }
   
  logfile.Write("crtsurfdata5 开始运行. \n");
  
  //把站点参数文件中加载到vstcode容器中
  if(LoadSTCode(argv[1]) == false) return -1;
  
  // 模拟生成全国气象站点分钟观测数据，存放在vsurfdata容器中。
  CrtSurfData();
  // 把容器vsurfdata中的全国气象站点分钟观测数据写入文件。
  // bool CrtSurfFile(const char *outpath, const char *datafmt);
  if(strstr(argv[4], "csv")!=0) CrtSurfFile(argv[2], "csv");
  if(strstr(argv[4], "xml")!=0) CrtSurfFile(argv[2], "xml");
  if(strstr(argv[4], "json")!=0)CrtSurfFile(argv[2], "json");
  
  logfile.Write("crtsurfdata5 结束运行. \n");  

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
/*测试代码
  for(int i = 1; i < vstcode.size(); i++){
    logfile.Write("i=%d, province=%s, obtid=%s, obtname=%s, lat=%.2f, lon=%.2f, height=%.2f\n",\
                   i, vstcode[i].provname,vstcode[i].obtid,vstcode[i].obtname,vstcode[i].lat,\
                   vstcode[i].lon, vstcode[i].height);
  }
*/
  return true;
}

// 模拟生成全国气象站点分钟观测数据，存放在vsurfdata容器中。
void  CrtSurfData()
{
  struct st_surfdata stsurfdata; 
  // 播随机数种子
  srand(time(0));
  // 获取当前时间, 当作观测时间
   memset(strdatetime, 0, sizeof(strdatetime));
  LocalTime(strdatetime, "yyyymmddhh24miss");
  // 遍历气象站点参数的vstcode容器。
  for(int i = 1; i < vstcode.size(); i++){
    memset(&stsurfdata, 0, sizeof(stsurfdata));
   
    // 用随机数填充分钟观测数据的结构体。
    strncpy(stsurfdata.obtid,vstcode[i].obtid,10); // 站点代码。
    strncpy(stsurfdata.ddatetime,strdatetime,14);  // 数据时间：格式yyyymmddhh24miss
    stsurfdata.t=rand()%351;          		    // 气温：单位，0.1摄氏度
    stsurfdata.p=rand()%265+10000;	            // 气压：0.1百帕
    stsurfdata.u=rand()%100+1;    		    // 相对湿度，0-100之间的值。
    stsurfdata.wd=rand()%360;     	            // 风向，0-360之间的值。
    stsurfdata.wf=rand()%150;     		    // 风速：单位0.1m/s
    stsurfdata.r=rand()%16;       		    // 降雨量：0.1mm
    stsurfdata.vis=rand()%5001+100000; 		    // 能见度：0.1米

    // 放入容器中
    vsurfdata.push_back(stsurfdata);
  }
  
  // 通过写入日志的方式进行验证
  /*
  for(int i = 0; i < vsurfdata.size(); i++){
    logfile.Write("obtid=%s, time=%s, t=%ld, p=%ld, u=%ld, wd=%ld, wf=%ld, r=%ld, vis=%ld\n", \
                vsurfdata[i].obtid, vsurfdata[i].ddatetime,vsurfdata[i].t, vsurfdata[i].p,\
                vsurfdata[i].u, vsurfdata[i].wd, vsurfdata[i].wf, vsurfdata[i].r, vsurfdata[i].vis);
   }
   */
  //用gbd进行调试
  // printf("aaa\n");
}

// 把容器vsurfdata中的全国气象站点分钟观测数据写入文件。
bool CrtSurfFile(const char *outpath, const char *datafmt)
{
  CFile File;
  // 拼接生成数据的文件名，例如：/tmp/idc/surfdata/SURF_ZH_20210629092200_2254.csv
  char strFileName[301];
  sprintf(strFileName, "%s/SURF_ZH_%s_%d.%s", outpath, strdatetime, getpid(), datafmt);
  // 打开文件
  // bool OpenForRename(const char *filename,const char *openmode,bool bEnBuffer=true);
  if(File.OpenForRename(strFileName, "w") == false)
  {
    logfile.Write("File.OpenForRename(%s) failed.\n", strFileName);
    return false;
  }
  // 写入第一行标题
  if(strcmp(datafmt, "csv") == 0)  File.Fprintf("站点代码,数据时间,气温,气压,相对湿度,风向,风速,降雨量,能见度\n");
  if(strcmp(datafmt, "xml") == 0)  File.Fprintf("<data>\n");
  if(strcmp(datafmt, "json") == 0) File.Fprintf("{\n  \"data\": [\n");
  // 将数据写入文件
  for(int i = 0; i < vsurfdata.size(); i++){
    if(strcmp(datafmt, "csv") == 0){
      File.Fprintf("%s,%s,%.1f,%.1f,%d,%d,%.1f,%.1f,%.1f\n",\
         vsurfdata[i].obtid,vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
         vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
     }
    if(strcmp(datafmt, "xml") == 0){
       File.Fprintf("<obtid>%s</obtid><ddatetime>%s</ddatetime><t>%.1f</t><p>%.1f</p><u>%d</u><wd>%d</wd>"\
                    "<wf>%.1f</wf><r>%.1f</r><vis>%.1f</vis>\n",\
         vsurfdata[i].obtid,vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
         vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
    }
    if(strcmp(datafmt, "json") == 0){
      File.Fprintf("  {\"obtid\":%s,\"ddatetime\":%s,\"t\":%.1f,\"p\":%.1f,\"u\":%d,\"wd\":%d,\"wf\":%.1f,"\
                      "\"r\":%.1f,\"vis\":%.1f}\n",\
         vsurfdata[i].obtid,vsurfdata[i].ddatetime,vsurfdata[i].t/10.0,vsurfdata[i].p/10.0,\
         vsurfdata[i].u,vsurfdata[i].wd,vsurfdata[i].wf/10.0,vsurfdata[i].r/10.0,vsurfdata[i].vis/10.0);
     }
  }
  if(strcmp(datafmt, "xml") == 0)  File.Fprintf("</data>\n");
  if(strcmp(datafmt, "json") == 0) File.Fprintf("  ]\n}");
  File.CloseAndRename();

  return true;
}
