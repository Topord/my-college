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
};
Pointer deleter(Pointer p,Pointer q);
void print(Pointer n);
Pointer add(Pointer q,Pointer k);
int main()
{
	Pointer p,q,k;
	srand((unsigned)time(NULL));
	p=q=k=(Pointer)malloc(sizeof(struct Node));		//创建第1个节点
	printf("十个元素:\n");
	for(int i=0;i<10;i++)
	{
		q->data = rand()%100;		//对q指向元素的data分量进行赋值
		printf("%d\t",q->data);
		if(i<9)
		{	q=(Pointer)malloc(sizeof(struct Node));	//创建一个新节点
			p->pp=q;
			p=q;}
		else q->pp=NULL;	//最后一个节点，其指针分量赋值NULL，作为标志
	}
	printf("\n"); 
	p=k;  //首地址 
	k=q;	//尾地址 
	while(p)
	{
		p=deleter(p,q);//删除节点并更新p 
		if(!p)break;
		Sleep(1000);  
		k=add(q,k);  //增加节点 
		print(p);  //打印数据 
		p=deleter(p,q); //删除节点并更新p 
		Sleep(1000);
	}
	system("pause");
	return 0;
}

//1.删除节点 
Pointer deleter(Pointer p,Pointer q)
{
	printf("删除:%d\n",p->data);
	q=p->pp;
	free(p);
	p=q;
	print(q);
	return p;
}

//2.打印数据
void print(Pointer n)
{
	while(n!=NULL)
	{
		printf("%d\t",n->data);
		n=n->pp;
	}
	printf("\n");
} 

//3.增加节点
Pointer add(Pointer q,Pointer k)
{
	q=(Pointer)malloc(sizeof(struct Node));	//创建一个新节点
	k->pp=q;
	q->data = rand()%100;//对q指向元素的data分量进行赋值
	printf("加入:%d\n",q->data);
	q->pp=NULL;	//最后一个节点，其指针分量赋值NULL，作为标志
	return q;
 } 
