#include <stdio.h>
#include <stdlib.h>
typedef struct OPND//���������ջ 
{
	int data[100];
	int pt;
}*OPND;
typedef struct OPTR//���������ջ 
{
	char data[100];
	int pt;
}*OPTR;
void pushR(OPTR r, char ch)
{
	
	r->pt++;
	r->data[r->pt] = ch;
}
void pushD(OPND d, int a)
{
	
	d->pt++;
	d->data[d->pt] =a;
}
char popR(OPTR r)
{
	if (r->pt == -1) return;
	r->pt--;
	return r->data[r->pt + 1];
}
int popD(OPND d)
{
	if (d->pt == -1) return;
	d->pt--;
	return d->data[d->pt + 1];
}
char optr[7] = { '+','-','*','/','(',')','#' };  /*���������*/

char  seek[7][7] = {
				  {'>','>','<','<','<','>','>'},    /*�������бȽ���������ȼ��ľ���*/
				  {'>','>','<','<','<','>','>'},
				  {'>','>','>','>','<','>','>'},
				  {'>','>','>','>','<','>','>'},
				  {'<','<','<','<','<','=',' '},
				  {'>','>','>','>',' ','>','>'},
				  {'<','<','<','<','<',' ','='}
};

int Isoperator(char ch) //�ж�������ַ��Ƿ�������� 
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (optr[i] == ch) //���������ַ�����������򷵻�1 
			return 1;
	}
	return 0;
}
char Precede(char ch1, char ch2) //�Ƚ���������ȼ� 
{
	int i=0, m=0, n=0;
	char p;
	for (i = 0; i < 7; i++)  //�ҳ���������λ�� 
	{
		if (optr[i] == ch1)
			m = i;
		if (optr[i] == ch2)
			n = i;
	}
	p = seek[m][n];   //�ҵ��ȽϽ��
	return p;
}
int operate(int m, int n, char ch)
{
	int r=0;
	switch (ch)
		
						{
						case '+':r= n+ m; //printf("%d", n+m);
							break;
						case '-':r= n - m;  break;
						case '*':r= n *m; break;
						case '/':if (m != 0)
							r = n / m;
								else printf("����Ϊ0��");
							break;
						}
	return r;

}
int main()
{
	OPTR r = (OPTR)malloc(sizeof(struct OPTR));
	r->pt = -1;
	OPND d = (OPND)malloc(sizeof(struct OPND));
	d->pt = -1;
	
	pushR(r, '#');
	
	char str[100];
	char ch,e;
	char  theta;
	int sum = 0,x,n1,n2,result;
	printf("��������ʽ(��#��β)��\n");

	ch = getchar();
	
	while (ch != '#' || r->data[r->pt] != '#')
	{
		
		if (!Isoperator(ch))//���������
		{
			
			x= ch - '0'; //ת��Ϊ10���ƣ�
			sum= 10*sum+x;
			ch = getchar();
		
		}
		else {//��������� 
			if (sum != 0) {
			
				pushD(d, sum);  //��������ջ
				sum = 0;
			}
			e = r->data[r -> pt];
			switch (Precede(e, ch))
			{
			case '<':pushR(r, ch);
				ch = getchar();
				break;
			case '>':theta = popR(r);
				n1 = popD(d);
				n2 = popD(d);
				result=operate(n1, n2, theta);
				pushD(d,result);
				break;
			case '=': theta=popR(r);//������
				ch = getchar();
				break;
			} 

		}
		
	}
	result = d->data[d->pt];
	printf("ֵΪ��%d", result);
	return 0;
}