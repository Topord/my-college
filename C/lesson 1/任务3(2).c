//任务3：建立10随机元素的动态起始队列，每2秒入队一个随机数，每1秒队首元素出队，出完为止；
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node N;
typedef struct Node * Pointer;
//创建动态链表
Pointer CreateList(Pointer p)
{
	int i;
	p->data = rand()%100; 
	for(i = 0; i < 10; i++){
		p->next = (Pointer)malloc(sizeof(N));
		p = p->next;
		p->data = rand()%100;
		p->next = NULL; 
	}
	return p;
}
//出队
Pointer LeaveQueue(Pointer p, Pointer m)
{
	p = m;
	printf("出队:\n");
	printf("%d\n", p->data);
	m = p->next;
	free(p); 
	p = m;
	if(m->next == NULL){
		printf("出队:\n");
		printf("%d\n", m->data);
		printf("break");
	}	
	return p;
} 
//入队
Pointer InsertQueue(Pointer p, Pointer tmp)
{
	while(1){
		if(p->next == NULL){
			tmp = (Pointer)malloc(sizeof(N));
			tmp->data = rand()%100;
			p->next = tmp;
			tmp->next = NULL;
			printf("入队:\n");
			printf("%d\n", tmp->data);
			break;
		}
		p = p->next;
	}
	return tmp; //用tmp来接收新节点的地址 
} 
int main()
{
	int i, j, k;
	Pointer p, head, m, tmp;
	srand((unsigned)time(NULL));
	m = p = head = (Pointer)malloc(sizeof(N));//p创建链表,m为头结点,head用来记录头结点,tmp用来找尾结点 
	//创建动态链表 
	p = CreateList(p);
	//输出链表内容 
	p = head;
	while(p != NULL){
		printf("%d\t", p->data);
		p = p->next; 
	}
	printf("\n");
	//队列
	p = head;
	while(1){
		//出队
		p = LeaveQueue(p, m);
		m = p;
		if(m->next == NULL) break;
		//入队
		Sleep(1000); 
		tmp = InsertQueue(p, tmp);
		Sleep(1000);
		//出队
		p = LeaveQueue(p, m);
		m = p;
		if(m->next == NULL) break;
	}
	free(p);
	return 0;
}
