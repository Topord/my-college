//����2������10Ԫ�أ���������Ķ�̬����������ֵ����Сֵ��
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct stu
{
	int data;
	struct stu *next;
};
typedef struct stu S;
typedef struct stu * Pointer;
//���� 
Pointer CreateList(Pointer q)
{
	int i;
	q->data = rand()%100; 
	for(i = 0; i < 10; i++){
		q->next = (Pointer)malloc(sizeof(S));
		q = q->next;
		q->data = rand()%100;
		q->next = NULL; 
	}
	return q;
}
//����
Pointer Compere(Pointer p, Pointer m, Pointer h)
{
	int i, j, k, tmp;
	p = h;
	for(i = 0; i < 9; i++){ 
		for(j = i; j < 9; j++){
			m = h->next;
			for(k = 0; k < j; k++){
				m = m->next;
			}
			if(p->data > m->data){
				tmp = p->data;
				p->data = m->data;
				m->data = tmp;
			}
		} 
		p = p->next;
	}
	return p; 
} 
Pointer Print(Pointer p, Pointer h)
{
	int i, j = 1;
	p = h;
	j = 1;
	while(p != NULL){
		printf("struct%d's data = %d\n", j, p->data);
		j++;
		p = p->next; 
	}
	return p;
}
int main()
{
	int i, j, k, tmp;
	Pointer p, q, h, m;
	srand((unsigned)time(NULL));
	p = q = h = (Pointer)malloc(sizeof(S));
	//������̬���� 
	p = CreateList(q);
	//����������� 
	printf("����ǰ:\n");
	p = Print(p, h);
	printf("\n");
	//���������ݽ������� 
	p = Compere(p, m, h);
	//�������������
	printf("�����:\n");
    p = Print(p, h);
	free(h);
	return 0;
}
