#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#pragma comment(lib,"winmm.lib")

#define  NUM 10

class jet
{
protected:
	int x, y;			//烟花弹坐标
	int hx, hy;			//烟花弹最高点坐标

	bool shoot;			//烟花弹是否处于发射状态
	DWORD t1, t2, dt;	//发射时间  引爆时间  间隔时间
	IMAGE img[2];		//2张图片 一明一暗 01下标
	byte n : 1;			//C结构体 位段	//n 变量 1个位
};

class Fire
{
protected:
	int x, y;				//烟花的坐标
	int r;					//烟花的半径
	int max_r;				//烟花的最大半径
	int cen_x, cen_y;		//中心距左上角的距离
	int width, height;		//长宽
	int xy[240][240];		//重要，像素，矩阵

	bool draw;				//画出
	bool show;				//显示
	DWORD t1, t2, dt;		//发射时间  引爆时间  间隔时间

};
//生成背景
void BackGround()
{
	//初始界面（1000，600）
	initgraph(1000, 600);
	//初始化种子
	srand((unsigned int)time(NULL));

	//音乐 爱的翅膀
	mciSendString(L"open .\fire\bk1.mp3 alias music", 0, 0, 0);	//send(发送)	string（字符串）
	mciSendString(L"play music", 0, 0, 0);
}

int main()
{
	BackGround();

	return 0;
}