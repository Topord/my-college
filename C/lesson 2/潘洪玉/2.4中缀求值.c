#include <stdio.h>
#include <stdlib.h>
typedef struct OPND//定义操作数栈 
{
	int data[100];
	int pt;
}*OPND;
typedef struct OPTR//定义运算符栈 
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
char optr[7] = { '+','-','*','/','(',')','#' };  /*运算符数组*/

char  seek[7][7] = {
				  {'>','>','<','<','<','>','>'},    /*用来进行比较运算符优先级的矩阵*/
				  {'>','>','<','<','<','>','>'},
				  {'>','>','>','>','<','>','>'},
				  {'>','>','>','>','<','>','>'},
				  {'<','<','<','<','<','=',' '},
				  {'>','>','>','>',' ','>','>'},
				  {'<','<','<','<','<',' ','='}
};

int Isoperator(char ch) //判断输入的字符是否是运算符 
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (optr[i] == ch) //如果输入的字符是运算符，则返回1 
			return 1;
	}
	return 0;
}
char Precede(char ch1, char ch2) //比较运算符优先级 
{
	int i=0, m=0, n=0;
	char p;
	for (i = 0; i < 7; i++)  //找出两个数的位置 
	{
		if (optr[i] == ch1)
			m = i;
		if (optr[i] == ch2)
			n = i;
	}
	p = seek[m][n];   //找到比较结果
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
								else printf("除数为0！");
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
	printf("请输入表达式(以#结尾)：\n");

	ch = getchar();
	
	while (ch != '#' || r->data[r->pt] != '#')
	{
		
		if (!Isoperator(ch))//不是运算符
		{
			
			x= ch - '0'; //转换为10进制；
			sum= 10*sum+x;
			ch = getchar();
		
		}
		else {//当是运算符 
			if (sum != 0) {
			
				pushD(d, sum);  //进操作数栈
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
			case '=': theta=popR(r);//脱括号
				ch = getchar();
				break;
			} 

		}
		
	}
	result = d->data[d->pt];
	printf("值为：%d", result);
	return 0;
}