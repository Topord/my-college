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
	int x, y;			//�̻�������
	int hx, hy;			//�̻�����ߵ�����

	bool shoot;			//�̻����Ƿ��ڷ���״̬
	DWORD t1, t2, dt;	//����ʱ��  ����ʱ��  ���ʱ��
	IMAGE img[2];		//2��ͼƬ һ��һ�� 01�±�
	byte n : 1;			//C�ṹ�� λ��	//n ���� 1��λ
};

class Fire
{
protected:
	int x, y;				//�̻�������
	int r;					//�̻��İ뾶
	int max_r;				//�̻������뾶
	int cen_x, cen_y;		//���ľ����Ͻǵľ���
	int width, height;		//����
	int xy[240][240];		//��Ҫ�����أ�����

	bool draw;				//����
	bool show;				//��ʾ
	DWORD t1, t2, dt;		//����ʱ��  ����ʱ��  ���ʱ��

};
//���ɱ���
void BackGround()
{
	//��ʼ���棨1000��600��
	initgraph(1000, 600);
	//��ʼ������
	srand((unsigned int)time(NULL));

	//���� ���ĳ��
	mciSendString(L"open .\fire\bk1.mp3 alias music", 0, 0, 0);	//send(����)	string���ַ�����
	mciSendString(L"play music", 0, 0, 0);
}

int main()
{
	BackGround();

	return 0;
}