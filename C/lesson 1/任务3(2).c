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
//������̬����
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
//����
Pointer LeaveQueue(Pointer p, Pointer m)
{
	p = m;
	printf("����:\n");
	printf("%d\n", p->data);
	m = p->next;
	free(p); 
	p = m;
	if(m->next == NULL){
		printf("����:\n");
		printf("%d\n", m->data);
		printf("break");
	}	
	return p;
} 
//���
Pointer InsertQueue(Pointer p, Pointer tmp)
{
	while(1){
		if(p->next == NULL){
			tmp = (Pointer)malloc(sizeof(N));
			tmp->data = rand()%100;
			p->next = tmp;
			tmp->next = NULL;
			printf("���:\n");
			printf("%d\n", tmp->data);
			break;
		}
		p = p->next;
	}
	return tmp; //��tmp�������½ڵ�ĵ�ַ 
} 
int main()
{
	int i, j, k;
	Pointer p, head, m, tmp;
	srand((unsigned)time(NULL));
	m = p = head = (Pointer)malloc(sizeof(N));//p��������,mΪͷ���,head������¼ͷ���,tmp������β��� 
	//������̬���� 
	p = CreateList(p);
	//����������� 
	p = head;
	while(p != NULL){
		printf("%d\t", p->data);
		p = p->next; 
	}
	printf("\n");
	//����
	p = head;
	while(1){
		//����
		p = LeaveQueue(p, m);
		m = p;
		if(m->next == NULL) break;
		//���
		Sleep(1000); 
		tmp = InsertQueue(p, tmp);
		Sleep(1000);
		//����
		p = LeaveQueue(p, m);
		m = p;
		if(m->next == NULL) break;
	}
	free(p);
	return 0;
}
