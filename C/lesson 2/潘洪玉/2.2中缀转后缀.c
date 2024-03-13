//#include <stdio.h>
//#include <stdlib.h>
//typedef struct Node
//{
//	char data[100];
//	int pt;
//}*Stack;
//void push(Stack s, char c)	//入栈操作
//{
//	s->pt++;
//	s->data[s->pt] = c;
//}
//
//char pop(Stack s)			//出栈操作
//{
//	if (s->pt == -1)
//		return 0;
//	s->pt--;
//	return s->data[s->pt + 1];
//}
//char comp(char c1, char c2)//先乘除后加减，先出现的优先级高
//{
//	int n1 = 1, n2 = 1;
//	if (c1 == '*' || c1 == '/')
//		n1++;
//	if (c2 == '*' || c2 == '/')
//		n2++;
//	return ((n1 > n2) ? '>' : '!');//只有优先级高（>）才可以入栈
//}
//int main()
//{
//	Stack s = (Stack)malloc(sizeof(struct Node));
//	s->pt = -1;
//	char str[100], out[100];
//	push(s, '#');
//	printf("请输入中缀表达式；\n");
//	gets(str);
//	int i = 0, j = 0;
//	char ch, t;
//	while (str[i] != '\0')
//	{
//		ch = str[i];
//		if (ch >= '0' && ch <= '9')//数字直接放入表达式
//		{
//			out[j] = ch;
//			j++;
//		}
//		if (ch == '(')//直接进栈
//		{
//			push(s, ch);
//		}
//		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//		{
//			
//			out[j] = '#';//放入‘#’分隔
//			j++;
//		
//			while (1)
//			{
//				t = s->data[s->pt];
//			
//				if (comp(ch, t) == '>'||t=='('||t=='#') //优先级高则入栈,‘('和’#'的优先级最低
//				{
//					push(s, ch);
//					
//					break;
//				}
//				else
//				{
//					out[j] = pop(s);//否则输出到表达式
//					j++;
//				}
//			}
//		}
//
//		if (ch == ')')
//		{
//			if (out[j - 1] >= '0' && out[j - 1] <= '9')
//			{
////				out[j] = '#'; //刚刚处理的是数字符，加上分隔符
//				j++;
//			}
//			t = pop(s);
//			while (t != '(')//配对不成功统统取出，直到配对成功
//			{
//				out[j] = t;
//				j++;
//				t = pop(s);
//			}
//		}
//		i++;
//	}
//	//扫描完成
//	if (out[j - 1] >= '0' && out[j - 1] <= '9')
//	{
//		out[j] = '#'; //刚刚处理的是数字符，加上分隔符
//		j++;
//	}
//	t = pop(s);
//	while (t != '#')//配对不成功统统取出
//	{
//		out[j] = t;
//		j++;
//		t = pop(s);
//	}
//	out[j] = '\0';
//	printf("转换后的后缀表达式为：%s\n", out);
//	return 0;
//}