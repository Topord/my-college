//任务2：建立10元素（随机数）的动态链表查找最大值和最小值；
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
//建立 
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
//排序
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
	//创建动态链表 
	p = CreateList(q);
	//输出链表内容 
	printf("排序前:\n");
	p = Print(p, h);
	printf("\n");
	//对链表数据进行排序 
	p = Compere(p, m, h);
	//输出排序后的内容
	printf("排序后:\n");
    p = Print(p, h);
	free(h);
	return 0;
}
