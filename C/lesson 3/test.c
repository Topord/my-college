#include<stdio.h>
#include<stdlib.h>
typedef unsigned int Uint;
struct Node
{
	Uint weight;
	Uint left;
	Uint right;
	Uint parent;
};
typedef struct Node * Pointer;
void Init_Node(Pointer p, int* arr, int len1, int len2);
void Print(Pointer p, int len);
void Sort(Pointer p, Uint *x, Uint *y, int len, int m);

int main()
{
	int a[] = {11, 2, 4, 1, 8};
	Uint b[2] = {0};
	Uint c[2] = {0};
	Pointer ps, head;
	int lenth, i;
	lenth = sizeof(a)/sizeof(a[0]);
	head = ps = (Pointer)malloc((2*lenth - 1)*sizeof(struct Node));
	Init_Node(ps, a, 2*lenth-1, lenth);
	ps = head;
	Print(ps, 2*lenth-1);
	printf("------------------最优树-------------------\n");
	for(i = 5; i < 9; i++){
		ps = head;
		Sort(ps, b, c, 2*lenth - 1, i);
		(ps+i)->left = c[0];
		(ps+i)->right = c[1];
		(ps+i)->weight = b[0] + b[1];
		(ps+c[0])->parent = i;
		(ps+c[1])->parent = i;
	}
	ps = head;
	Print(ps, 2*lenth-1);
	free(head);
	return 0;
} 
void Init_Node(Pointer p, int* arr, int len1, int len2)
{
	int i;
	for(i = 0; i < len1; i++){
		if(i <= len2){
			p->weight = *arr;
			p->parent = -1;
			p->left = -1;
			p->right = -1;
			p++;
			arr++;
		}else{
			p->weight = 0;
			p->parent = -1;
			p->left = -1;
			p->right = -1;
			p++;
		}
	} 
}
void Print(Pointer p, int len)
{
	int i;
	for(i = 0; i< len; i++){
		printf("第%d个节点权重为%d, 父节点为%d, ", i, p->weight, p->parent);
		printf("左孩子为%d, 右孩子为%d.\n", p->left, p->right);
		p++;
	} 
}
void Sort(Pointer p, Uint *x, Uint *y, int len, int m)
{
	int i, t;
	Pointer q = p;
	*x = 0;
	*(x + 1) = 0;
	*y = 0;
	*(y + 1) = 0;
	t = p->weight;
	for(i = 1; i <= len; i++){
		if((p+1)->parent == -1){
			if(t > (p+1)->weight && t != 0 && (p+1)->weight != 0){
				t = (p+1)->weight;
				*y = i; 
			}	
		} 
		p++;
	}
	*x = t;
	p = q;
	t = p->weight;
	for(i = 1; i <= len; i++){
		if((p+1)->parent == -1){
			if(t > (p+1)->weight && t != 0 && (p+1)->weight != 0 && (p+1)->weight != *x){
				t = (p+1)->weight;
				*(y + 1) = i; 
			}
		} 
		p++;
	}
	*(x + 1)= t;
	p = q;
	if(*x == *(x + 1) && m == 8){
		*(x+1) = (p+7)->weight;
		*(y+1) = 7;
	}
	
}
