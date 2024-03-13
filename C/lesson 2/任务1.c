#include<stdio.h>
#include<stdlib.h>
#define N 7
struct Node
{
	int data[2000];
	int pointer;
};
typedef struct Node *stack;
//��ջ����
void Push(stack s,int c);	
//��ջ���� 
int Pop(stack s);		
//���ջ
void Output(stack p); 

int main()
{
	stack ps;
	int end = 99;                             //end ��ʾջβ 
	int num = 2345;                 
	int shang = 1, yushu;                    //shang��ֵʹ�ܹ�����ѭ�� 
	
	ps=(stack)malloc(sizeof(struct Node));
	ps->pointer = -1;
	Push(ps, end);
	
	shang = num / N;
	yushu = num % N;
	Push(ps, yushu);	
	
	while(shang != 0){
		yushu = shang % N;
		shang = shang / N;
		Push(ps, yushu);
	}
	
	Output(ps);
	
	free(ps);
	return 0;
	
}
//��ջ 
void Push(stack s,int c)	
{
	s->pointer++;
	s->data[s->pointer] = c;
}
//��ջ
int Pop(stack s)			
{
	if (s->pointer == -1)
		return 0;
	s->pointer--;
	return s->data[s->pointer+1];
}
//���ջ
void Output(stack p)
{
	int ch;
	ch = Pop(p);
	while(ch != 99)
	{
		printf("%d", ch);
		ch = Pop(p);
	}
}  
