#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
struct Node
{
	int data;
	struct Node * next;
};
typedef struct Node N;
typedef struct Node * Pointer;
//创建
Pointer CreateList(Pointer p)
{
	int i = 0;
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
		printf("出队\n");
		printf("%d\n", m->data);
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
			printf("入队\n");
			printf("%d\n", tmp->data);
			break;
		}
		p = p->next; 
	}
	return tmp;
}
int main()
{
	int i, j, k;
	Pointer p, m ,head, tmp;
	srand((unsigned)time(NULL));
	p = m = head = (Pointer)malloc(sizeof(N));
	//创建
	p = CreateList(p); 
	//输出
	p = head;
	for(i = 0; i < 10; i++){
		printf("%d\t", p->data);
		p = p->next;
	} 
	printf("\n");
	//队列
	while(1){
		//出队
		p = LeaveQueue(p, m);
		m = p;
		if(m->next == NULL){
			printf("end");
			break;
		}
		Sleep(1000);
		//入队
		tmp = InsertQueue(p, tmp); 
		Sleep(1000);
		//出队
		p = LeaveQueue(p, m); 
		m = p;
		if(m->next == NULL){
			printf("end");
			break;
		}
	} 
	free(m);
	return 0;	
} 
