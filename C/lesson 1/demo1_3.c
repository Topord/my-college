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
};
Pointer deleter(Pointer p,Pointer q);
void print(Pointer n);
Pointer add(Pointer q,Pointer k);
int main()
{
	Pointer p,q,k;
	srand((unsigned)time(NULL));
	p=q=k=(Pointer)malloc(sizeof(struct Node));		//������1���ڵ�
	printf("ʮ��Ԫ��:\n");
	for(int i=0;i<10;i++)
	{
		q->data = rand()%100;		//��qָ��Ԫ�ص�data�������и�ֵ
		printf("%d\t",q->data);
		if(i<9)
		{	q=(Pointer)malloc(sizeof(struct Node));	//����һ���½ڵ�
			p->pp=q;
			p=q;}
		else q->pp=NULL;	//���һ���ڵ㣬��ָ�������ֵNULL����Ϊ��־
	}
	printf("\n"); 
	p=k;  //�׵�ַ 
	k=q;	//β��ַ 
	while(p)
	{
		p=deleter(p,q);//ɾ���ڵ㲢����p 
		if(!p)break;
		Sleep(1000);  
		k=add(q,k);  //���ӽڵ� 
		print(p);  //��ӡ���� 
		p=deleter(p,q); //ɾ���ڵ㲢����p 
		Sleep(1000);
	}
	system("pause");
	return 0;
}

//1.ɾ���ڵ� 
Pointer deleter(Pointer p,Pointer q)
{
	printf("ɾ��:%d\n",p->data);
	q=p->pp;
	free(p);
	p=q;
	print(q);
	return p;
}

//2.��ӡ����
void print(Pointer n)
{
	while(n!=NULL)
	{
		printf("%d\t",n->data);
		n=n->pp;
	}
	printf("\n");
} 

//3.���ӽڵ�
Pointer add(Pointer q,Pointer k)
{
	q=(Pointer)malloc(sizeof(struct Node));	//����һ���½ڵ�
	k->pp=q;
	q->data = rand()%100;//��qָ��Ԫ�ص�data�������и�ֵ
	printf("����:%d\n",q->data);
	q->pp=NULL;	//���һ���ڵ㣬��ָ�������ֵNULL����Ϊ��־
	return q;
 } 
