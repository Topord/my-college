/*新知识点：
1.结构体变量（复合体变量）
2.动态型结构体单变量
3.动态型结构体数组
4.typedef的使用
5.链表与队列
任务2：建立10元素（随机数）的动态链表查找最大值和最小值；
任务3：建立10随机元素的动态起始队列，每2秒入队一个随机数，每1秒队首元素出队，出完为止；
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct Node Nod;		//将struct Node命名为Nod（别名）,Nod为结构体类型
typedef struct Node * Pointer;	//将struct Node *命名为Pointer（别名）,Pointer为结构体指针类型

struct Node		//定义结构体类型Node
{
	int data;
	struct Node * pp;
}a,b;

int main()
{
	int i,j;
	Pointer p,q,h;
	srand((unsigned)time(NULL));
	p=q=h=(Pointer)malloc(sizeof(struct Node));		//创建第1个节点
	
	for(i=0;i<5;i++)
	{
		q->data = rand()%100;		//对q指向元素的data分量进行赋值
		printf("\t%d\n",q->data);
		if(i<4)
		{
			q=(Pointer)malloc(sizeof(struct Node));	//创建一个新节点
			p->pp=q;
			p=q;
		}
		else
			q->pp=NULL;			//最后一个节点，其指针分量赋值NULL，作为标志
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

//指针举例：领导找学生，宿管阿姨