/*��֪ʶ�㣺
1.�ṹ������������������
2.��̬�ͽṹ�嵥����
3.��̬�ͽṹ������
4.typedef��ʹ��
5.���������
����2������10Ԫ�أ���������Ķ�̬����������ֵ����Сֵ��
����3������10���Ԫ�صĶ�̬��ʼ���У�ÿ2�����һ���������ÿ1�����Ԫ�س��ӣ�����Ϊֹ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct Node Nod;		//��struct Node����ΪNod��������,NodΪ�ṹ������
typedef struct Node * Pointer;	//��struct Node *����ΪPointer��������,PointerΪ�ṹ��ָ������

struct Node		//����ṹ������Node
{
	int data;
	struct Node * pp;
}a,b;

int main()
{
	int i,j;
	Pointer p,q,h;
	srand((unsigned)time(NULL));
	p=q=h=(Pointer)malloc(sizeof(struct Node));		//������1���ڵ�
	
	for(i=0;i<5;i++)
	{
		q->data = rand()%100;		//��qָ��Ԫ�ص�data�������и�ֵ
		printf("\t%d\n",q->data);
		if(i<4)
		{
			q=(Pointer)malloc(sizeof(struct Node));	//����һ���½ڵ�
			p->pp=q;
			p=q;
		}
		else
			q->pp=NULL;			//���һ���ڵ㣬��ָ�������ֵNULL����Ϊ��־
	}

	p=h;
	printf("\n\n");
	while(p!=NULL)
	{
		printf("\t%d",p->data);
		Sleep(500);
		p=p->pp;
	}
	printf("\n\n");

	system("pause");
	return 0;
}

//ָ��������쵼��ѧ�����޹ܰ���