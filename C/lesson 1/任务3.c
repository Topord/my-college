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
int main()
{
	int i, j, k;
	Pointer p, q, head, m, tmp;
	srand((unsigned)time(NULL));
	m = p = q = head = (Pointer)malloc(sizeof(N));//p,q创建链表,m为头结点,head用来free,tmp用来找尾结点 
	
	//创建动态链表 
	for(i = 0; i < 10; i++){
		q->data = rand()%100;
		if(i < 9){
			q = (Pointer)malloc(sizeof(N));
			p->next = q;
			p = q;
		}else{
			q->next = NULL;
			tmp = q;
		}
	}
	//输出链表内容 
	p = head;
	while(p != NULL){
		printf("%d  %d\n",p,p->data);
		j++;
		p = p->next; 
	}
	printf("\n");
	//队列
	q = p = head;
	printf("%d",head);
	while(1){
		//出队
		printf("出队:\n");
		printf("%d\n", p->data);
		m = p->next;
		free(p); 
		p = m;
		if(m->next == NULL){
			printf("出队:\n");
			printf("%d\t\%d\n", m,m->data);
			printf("break");
			break;
		}
		//入队
		//Sleep(1000); 
		while(1){
			if(p == NULL){
				tmp = (Pointer)malloc(sizeof(N));
				tmp->data = rand()%100;
				tmp->next = NULL;
				p = tmp;
				printf("入队:\n");
				printf("%d\n", tmp->data);
				break;
			}
			p=p->next;
		}
		Sleep(1000);
		//出队
		printf("出队:\n");
		printf("%d\n", p->data);
		m = p->next;
		free(p); 
		p = m;
		if(m->next == NULL){
			printf("出队:\n");
			printf("%d\n", m->data);  
			printf("break");
			break;
		}
	}

	 
	free(head);
	return 0;
}
