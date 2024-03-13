#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<iostream>

using namespace std;

#pragma comment(lib,"winmm.lib")

#define NUM 10			//�̻����������̻�

//�̻���
class Fire
{
public:
	int x, y;			//�̻�������
	int hx, hy;			//�̻�����ߵ�����

	bool shoot;			//�̻����Ƿ��ڷ���״̬
	DWORD t1, t2, dt;	//����ʱ��  ����ʱ��  ���ʱ��
	IMAGE img[2];		//2��ͼƬ һ��һ�� 01�±�
	byte n : 1;			//C�ṹ�� λ��	//n ���� 1��λ	0��1 n++ 0��1��0��1
public:
	//��ʼ���̻���
	Fire(int m)
	{
		t1 = GetTickCount();	//GetTickCount()���شӲ���ϵͳ��������ǰ�������ĺ�������ʹ��ǰ����windows.h��
		shoot = false;		//δ����
		dt = 10;				//����ʱ��
		n = m;
	}
	//�����̻���ͼƬ����Ե���
	void  JetLoad(Fire& jet)
	{

		int n = rand() % 5;			//01234
		getimage(&jet.img[0], n * 20, 0, 20, 50);
		getimage(&jet.img[1], (n + 5) * 20, 0, 20, 50);

		//	SetWorkingImage(NULL);
	}
	//ѡ���̻���
};

//�̻�
class Flower
{
public:
	int x, y;				//�̻�������
	int r;					//�̻��İ뾶
	int max_r;				//�̻������뾶
	int cen_x, cen_y;		//���ľ����Ͻǵľ���
	int width, height;		//����
	int xy[240][240];		//��Ҫ�����أ�����

	bool draw;				//����
	bool show;				//��ʾ
	DWORD t1, t2, dt;		//����ʱ��  ����ʱ��  ���ʱ��
public:
	//��ʼ���̻�
	Flower(int z)
	{
		show = false;		//δ����
		this->r = z;
		dt = 5;				//����ʱ��
		t1 = GetTickCount();
		max_r = rand() % 50 + 100;	//100-149
		cen_x = rand() % 30 + 80;	//���ľ����Ͻǵľ���
		cen_y = rand() % 30 + 80;	//
		width = 240;				//��
		height = 240;				//��
	}
	//����
	void FireLoad(Flower& work, int i, IMAGE x1, IMAGE x2)
	{
		SetWorkingImage(&x2);
		getimage(&x1, i * 240, 0, 240, 240);
		SetWorkingImage(&x1);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				work.xy[a][b] = getpixel(a, b);
			}
		}
	}
};

//���ɱ���
void BackGround()
{
	//��ʼ���棨1000��600��
	initgraph(1000, 600);
	//��ʼ������
	srand((unsigned int)time(NULL));

	//���� ���ĳ��
	mciSendString(L"open ./fire/bk1.mp3 alias music", 0, 0, 0);	//send(����)	string���ַ�����
	mciSendString(L"play music", 0, 0, 0);
}

//ѡ���̻���
void ChoiceJet(DWORD& t1, Fire* jet, Flower* fire)
{
	DWORD t2 = GetTickCount();

	if (t2 - t1 > 100)		//�̻������ֵ�ʱ����100ms
	{
		//�̻�������
		int i = rand() % 10;

		//�����ڷ���״̬
		if (jet[i].shoot == false && fire[i].show == false)
		{
			//�̻���
			jet[i].x = rand() % 1000;
			jet[i].y = rand() % 100 + 450;	//450-549
			jet[i].hx = jet[i].x;
			jet[i].hy = rand() % 300;		//0-299
			jet[i].shoot = true;			//����״̬

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
		}
		t1 = t2;
	}
}

//��ʼ����
void Shoot(Fire* jet, Flower* fire)
{
	for (int i = 0; i < NUM; i++)
	{
		jet[i].t2 = GetTickCount();

		if (jet[i].t2 - jet[i].t1 >= jet[i].dt && jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y >= jet[i].hy)
			{
				jet[i].n++;			//��˸
				jet[i].y -= 5;
			}

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y <= jet[i].hy)
			{
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				jet[i].shoot = false;
				//�ﵽ���߶ȣ������������̻�
				//���·���
				fire[i].x = jet[i].hx;
				fire[i].y = jet[i].hy;
				fire[i].show = true;
			}
		}
		jet[i].t1 = jet[i].t2;
	}
}

//��ʾ�̻�����ը
void ShowFire(DWORD* pMem, Flower* fire, Fire* jet)
{
	int drt[16] = { 5,5,5,5,5,10,25,25,25,25,55,55,55,55,55,65 };

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = GetTickCount();
		if (fire[i].t2 - fire[i].t1 >= fire[i].dt && fire[i].show == true)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];
				fire[i].draw = true;
			}

			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				jet[i].t1 = GetTickCount();	//GetTickCount()���شӲ���ϵͳ��������ǰ�������ĺ�������ʹ��ǰ����windows.h��
				jet[i].shoot = false;		//δ����
				jet[i].dt = 10;				//����ʱ��
				jet[i].n = 0;				//

				//��ʼ���̻�
				fire[i].show = false;		//δ����
				fire[i].r = 0;
				fire[i].dt = 5;				//����ʱ��
				fire[i].t1 = GetTickCount();
				fire[i].max_r = rand() % 50 + 100;	//100-149
				fire[i].cen_x = rand() % 30 + 80;	//���ľ����Ͻǵľ���
				fire[i].cen_y = rand() % 30 + 80;	//
				fire[i].width = 240;				//��
				fire[i].height = 240;				//��
			}
			fire[i].t1 = fire[i].t2;

			// ����ú��ڻ��ɱ�ը�����ݵ�ǰ��ը�뾶���̻�����ɫֵ�ӽ���ɫ�Ĳ������
			if (fire[i].draw)
			{
				for (double a = 0; a <= 6.28; a += 0.01)
				{
					int x1 = (int)(fire[i].cen_x + fire[i].r * cos(a));
					int y1 = (int)(fire[i].cen_y - fire[i].r * sin(a));

					if (x1 > 0 && x1 < fire[i].width && y1>0 && y1 < fire[i].height)
					{
						int b = fire[i].xy[x1][y1] & 0xff;
						int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
						int r = (fire[i].xy[x1][y1] >> 16);

						// �̻����ص��ڴ����ϵ�����
						int xx = (int)(fire[i].x + fire[i].r * cos(a));
						int yy = (int)(fire[i].y - fire[i].r * sin(a));

						//�ϰ������ص㲻�������ֹԽ��
						if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1000 && yy >0 && yy < 600)
						{
							pMem[yy * 1000 + xx] = BGR(fire[i].xy[x1][y1]);
						}
						fire[i].draw = false;
					}
				}
			}
		}
	}
}

//������
int main()
{
	//�̻���ʼ��
	Fire jet[NUM] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Flower fire[NUM] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// ��ʾ����
	BackGround(); 
	//�趨ʱ�����
	DWORD t1 = GetTickCount(); 
	DWORD* pMem = GetImageBuffer();
	//�����̻���ͼƬ 
	IMAGE jetimg;
	loadimage(&jetimg, L"./fire/shoot.jpg", 200, 50);
	SetWorkingImage(&jetimg);
	for (int i = 0; i < NUM; i++)
	{
		jet[i].JetLoad(jet[i]);
	}
	//�����̻�ͼƬ 
	IMAGE fireimage, Fireimage;
	loadimage(&Fireimage, L"./fire/flower.jpg", 3120, 240);
	for (int j = 0; j < NUM; j++)
	{
		fire[j].FireLoad(fire[j], j, fireimage, Fireimage);
	}
	//��ʼ����
	SetWorkingImage(NULL);

	//����������ڿ�ʼ������ͼ��ִ�к��κλ�ͼ����������ʱ���������ͼ�����ϣ�
	//ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
	BeginBatchDraw();

	while (1)
	{
		// ���ѡ�����ص����
		for (int clr = 0; clr < 200; clr++)
		{
			int px1 = rand() % 1000; //[0, 1000)
			int py1 = rand() % 600;

			// ��ֹԽ��
			if (py1 < 599)
			{
				//���Դ渳ֵ�������ص�
				pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;
			}
		}
		ChoiceJet(t1, jet, fire);
		Shoot(jet, fire);
		ShowFire(pMem, fire, jet);
		FlushBatchDraw();
	}

	system("pause");
	return 0;
}


/*
	//ͼƬ
	//����һ��ͼƬ
	IMAGE img;
	//����һ��ͼƬ
	loadimage(&img, L"./fire/shoot.jpg", 200, 50);
	//��ͼ
	putimage(400, 550, &img);

	//��ȡ����ͼƬ
	IMAGE img1;
	SetWorkingImage(&img);	//�������ȡ��img
	getimage(&img1, 180, 0, 20, 50);	//��ȡһ��
	SetWorkingImage(NULL);	//������
	putimage(0, 0, &img1);	//��ͼ����

*/