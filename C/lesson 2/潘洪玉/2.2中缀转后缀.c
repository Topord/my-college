//#include <stdio.h>
//#include <stdlib.h>
//typedef struct Node
//{
//	char data[100];
//	int pt;
//}*Stack;
//void push(Stack s, char c)	//��ջ����
//{
//	s->pt++;
//	s->data[s->pt] = c;
//}
//
//char pop(Stack s)			//��ջ����
//{
//	if (s->pt == -1)
//		return 0;
//	s->pt--;
//	return s->data[s->pt + 1];
//}
//char comp(char c1, char c2)//�ȳ˳���Ӽ����ȳ��ֵ����ȼ���
//{
//	int n1 = 1, n2 = 1;
//	if (c1 == '*' || c1 == '/')
//		n1++;
//	if (c2 == '*' || c2 == '/')
//		n2++;
//	return ((n1 > n2) ? '>' : '!');//ֻ�����ȼ��ߣ�>���ſ�����ջ
//}
//int main()
//{
//	Stack s = (Stack)malloc(sizeof(struct Node));
//	s->pt = -1;
//	char str[100], out[100];
//	push(s, '#');
//	printf("��������׺���ʽ��\n");
//	gets(str);
//	int i = 0, j = 0;
//	char ch, t;
//	while (str[i] != '\0')
//	{
//		ch = str[i];
//		if (ch >= '0' && ch <= '9')//����ֱ�ӷ�����ʽ
//		{
//			out[j] = ch;
//			j++;
//		}
//		if (ch == '(')//ֱ�ӽ�ջ
//		{
//			push(s, ch);
//		}
//		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//		{
//			
//			out[j] = '#';//���롮#���ָ�
//			j++;
//		
//			while (1)
//			{
//				t = s->data[s->pt];
//			
//				if (comp(ch, t) == '>'||t=='('||t=='#') //���ȼ�������ջ,��('�͡�#'�����ȼ����
//				{
//					push(s, ch);
//					
//					break;
//				}
//				else
//				{
//					out[j] = pop(s);//������������ʽ
//					j++;
//				}
//			}
//		}
//
//		if (ch == ')')
//		{
//			if (out[j - 1] >= '0' && out[j - 1] <= '9')
//			{
////				out[j] = '#'; //�ոմ���������ַ������Ϸָ���
//				j++;
//			}
//			t = pop(s);
//			while (t != '(')//��Բ��ɹ�ͳͳȡ����ֱ����Գɹ�
//			{
//				out[j] = t;
//				j++;
//				t = pop(s);
//			}
//		}
//		i++;
//	}
//	//ɨ�����
//	if (out[j - 1] >= '0' && out[j - 1] <= '9')
//	{
//		out[j] = '#'; //�ոմ���������ַ������Ϸָ���
//		j++;
//	}
//	t = pop(s);
//	while (t != '#')//��Բ��ɹ�ͳͳȡ��
//	{
//		out[j] = t;
//		j++;
//		t = pop(s);
//	}
//	out[j] = '\0';
//	printf("ת����ĺ�׺���ʽΪ��%s\n", out);
//	return 0;
//}