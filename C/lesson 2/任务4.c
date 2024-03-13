#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack1
{
	int data[1000];
	int pointer;
};								//例 1+(2+1*9)  
struct Stack2
{
	char data[1000];
	int pointer;
};
typedef struct Stack1 S1;
typedef struct Stack2 S2;
typedef struct Stack1 * Spointer1;
typedef struct Stack2 * Spointer2;

void PushNum(Spointer1 p, int c);
void PushOp(Spointer2 p, char c);	//入栈
char PopNum(Spointer1 p);			//出栈
char PopOp(Spointer2 p); 
void Calc(Spointer1 p, char op);

int main()
{
	char in[200], op, ch;
	int i, temp;
	S1 s1;   //s1栈用来存放数字
	S2 s2;	//s2栈由来存放运算符
	Spointer1 p1;
	Spointer2 p2;
	p1 = (Spointer1)malloc(sizeof(s1));
	p2 = (Spointer2)malloc(sizeof(s2));
	p1->pointer = 0;
	p2->pointer = 0;
	gets(in);
//例 1+(2+1*9)
	for (i = 0; in[i] != '\0'; i++){							//读字符串 
		if (in[i] >= '0' && in[i] <= '9'){						//数字 
			temp = in[i] - '0';									//将字符转换为数值 
			while (in[i + 1] != '\0'){           				//多位数值获取
				if (in[i + 1] >= '0' && in[i + 1] <= '9'){
					temp = temp * 10 + in[i + 1] - '0';			
					i++;
				}else
					break;										//读到符号 
			}		
			PushNum(p1, temp);										//入栈 
		}
		else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '(' || in[i] == ')'){	
			if(in[i] == '+'){				//1+2+1+9
				if(p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' && p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/')
				{
					PushOp(p2, '+');
				}
				else                           
				{
					while (p2->pointer > 0 && p2->data[p2->pointer - 1] != '(')//将优先级高的运算符先输出计算，其中括号内的优先级最高 
					{
						op = PopOp(p2);
						Calc(p1, ch);//计算，并压运算数栈
					}
					PushOp(p2, '+');
					}
				}
			else if(in[i] == '-'){
				//上一个符号是(,放入栈中 
				if(p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' && p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/')
				{
					PushOp(p2, '-');
				}
				else//如果不是，则将之前的先数字都出栈并计算，然后再入栈
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//将优先级高的运算符先输出计算，其中括号内的优先级最高 
					{
						op = PopOp(p2);
						Calc(p1, ch);//计算，并压运算数人栈
					}
					PushOp(p2, '-');
					}
				}				//例 1+(2+1*9) 
			else if(in[i] == '*'){
				//上一个符号是(或者+和-,放入栈中 
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' )
				{
					PushOp(p2, '*');
				}							
				else//如果不是，则将之前的先数字都出栈并计算，然后再入栈
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//将优先级高的运算符先输出计算，其中括号内的优先级最高 
					{
						op = PopOp(p2);
						Calc(p1, ch);//计算，并压运算数人栈
					}
					PushOp(p2, '*');
					}
				}
			else if(in[i] == '/'){
				//上一个符号是(,放入栈中    
				if(p2->data[p2->pointer - 1] != '/' && p2->data[p2->pointer - 1] != '*' )
				{
					PushOp(p2, '/');
				}
				else//如果不是，则将之前的先数字都出栈并计算，然后再入栈
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//将优先级高的运算符先输出计算，其中括号内的优先级最高 
					{
						op = PopOp(p2);
						Calc(p1, ch);//计算，并压运算数入栈
					}
					PushOp(p2, '/');
					}
				}
			
			else if(in[i] == '('){
				PushOp(p2, '(');
			}						//例 1+(2+1*9)
			else if(in[i] == ')'){
				while (p2->data[p2->pointer - 1] != '(')
				{
					op = PopOp(p2);
					Calc(p1, op);//计算，并压运算数栈
				}
				PopOp(p2);//将'('也出栈，但并不计算
			}
		}
	}
		
	//例 1+(2+1*9)  1+11
	while (p2->pointer > 0)//将剩余的运算符出栈并计算 
	{
		op = PopOp(p2);
		Calc(p1, op);
	}
	temp = PopNum(p1);
	printf("%d", temp);
	free(p1);
	free(p2);
	return 0;
}
//加法
void Calc(Spointer1 p1, char op)//例 1+(2+1*9)
{
	int temp1, temp2;			//取两个变量 
	temp1 = PopNum(p1);
	temp2 = PopNum(p1);
	switch (op)
	{
	case '+':PushNum(p1, temp1 + temp2); break;
	case '-':PushNum(p1, temp2 - temp1); break;
	case '*':PushNum(p1, temp1 * temp2); break;
	case '/':PushNum(p1, temp1 / temp2); break;
	}
}
//出栈 num
char PopNum(Spointer1 p)
{
	if(p->pointer == 0){
		
	}else{
			p->pointer--;
	return p->data[p->pointer];
	}

}
//出栈  op
char PopOp(Spointer2 p)
{
	if(p->pointer == 0){
		
	}else{
			p->pointer--;
	return p->data[p->pointer];
	}
	 
}
void PushNum(Spointer1 p, int c)
{
	p->data[p->pointer] = c;
	p->pointer++;   
}
void PushOp(Spointer2 p, char c)
{
	p->data[p->pointer] = c;
	p->pointer++;   
}
