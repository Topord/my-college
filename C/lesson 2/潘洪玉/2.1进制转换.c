//#include <stdio.h>
//#define N 7
//typedef struct Node
//{
//	int data[100];
//	int pt;
//}*Stack;
//void push(Stack s, int a)
//{
//	s->pt++;
//	s->data[s->pt] = a;
//	
//}
//int pop(Stack s)
//{
//	if (s->data[s->pt] == -1)
//		return 0;
//	s->pt--;
//	return s->data[s->pt + 1];
//
//}
//int main()
//{
//	int a = 2345;
//	Stack s = (Stack)malloc(sizeof(struct Node));
//	s->pt = -1;
//	int m;
//	
//	while (a != 0)
//	{
//		m = a % N;
//		a = a - m;
//		push(s, m);
//		a = a / N;
//		
//	}
//	
//	printf("10进制数2345的7进制为：\n");
//	while ((s->pt)!= -1)
//	{
//		printf("%d", pop(s));
//	   
//	}
//	return 0;
//}
