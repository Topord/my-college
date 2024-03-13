//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct Node
//{
//	int data[100];
//	int pt;
//}*Stack;
//void push(Stack s,int a)
//{
//	s->pt++;
//	s->data[s->pt] = a;
//}
//int pop(Stack s)
//{
//	if (s->pt == -1)return;
//	s->pt--;
//	return s->data[s->pt+1];
//}
//int main()
//{
//	Stack s = (Stack)malloc(sizeof(struct Node));
//	s->pt = -1;
//	char str[20];
//
//	char ch;
//	
//	int m, n;
//	int i = 0,j=0,sum=0,x;
//	gets(str);
//	ch = str[i];
//	
//	while (ch != '\0')
//	{
//		
//		if (ch >= '0' && ch <= '9')
//		{
//			while (ch != '#')
//			{
//				x = ch - '0';//转换成10进制数
//				sum = sum * 10 + x;
//				i++;
//				ch = str[i];
//			}
//		
//			push(s, sum);
//			sum = 0;
//		
//		}
//		else if (ch == '#') {
//			i++;
//			ch = str[i];
//
//		}
//		else {//运算符
//			m = pop(s);
//			
//			n= pop(s);
//			
//				switch (ch)
//				{
//				case '+':push(s, n+ m); 
//					break;
//				case '-':push(s, n - m); break;
//				case '*':push(s, n * m); break;
//				case '/':push(s, n /m); break;
//				}
//				
//				i++;
//				ch = str[i];
//		}
//		
//		
//	}
//	/*while (s->pt != -1)
//	{
//		m = pop(s);
//		printf("%d", m);
//	}*/
//	m = pop(s);
//	printf("%d", m);
//	return 0;
//}