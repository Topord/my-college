//����3������10���Ԫ�صĶ�̬��ʼ���У�ÿ2�����һ���������ÿ1�����Ԫ�س��ӣ�����Ϊֹ��
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
	m = p = q = head = (Pointer)malloc(sizeof(N));//p,q��������,mΪͷ���,head����free,tmp������β��� 
	
	//������̬���� 
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
	//����������� 
	p = head;
	while(p != NULL){
		printf("%d  %d\n",p,p->data);
		j++;
		p = p->next; 
	}
	printf("\n");
	//����
	q = p = head;
	printf("%d",head);
	while(1){
		//����
		printf("����:\n");
		printf("%d\n", p->data);
		m = p->next;
		free(p); 
		p = m;
		if(m->next == NULL){
			printf("����:\n");
			printf("%d\t\%d\n", m,m->data);
			printf("break");
			break;
		}
		//���
		//Sleep(1000); 
		while(1){
			if(p == NULL){
				tmp = (Pointer)malloc(sizeof(N));
				tmp->data = rand()%100;
				tmp->next = NULL;
				p = tmp;
				printf("���:\n");
				printf("%d\n", tmp->data);
				break;
			}
			p=p->next;
		}
		Sleep(1000);
		//����
		printf("����:\n");
		printf("%d\n", p->data);
		m = p->next;
		free(p); 
		p = m;
		if(m->next == NULL){
			printf("����:\n");
			printf("%d\n", m->data);  
			printf("break");
			break;
		}
	}

	 
	free(head);
	return 0;
}
