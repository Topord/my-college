#include<stdio.h>
#include<stdlib.h>
struct Stack1
{
	int data[100];
	int pointer;
};
struct Stack2
{
	char data[100];
	int pointer;
};
typedef struct Stack1 S1;
typedef struct Stack2 S2;
typedef struct Stack1 * Spointer1;
typedef struct Stack2 * Spointer2;

void PushNum(Spointer1 p, int c);
void PushOp(Spointer2 p, char c);
int PopNum(Spointer1 p);
char PopOp(Spointer2 p);
void Calc(Spointer1 p, char op);

int main()
{
	char in[200], op, ch;
	int i, temp;
	S1 s1;
	S2 s2;
	Spointer1 p1;
	Spointer2 p2;
	p1 = (Spointer1)malloc(sizeof(s1));
	p2 = (Spointer2)malloc(sizeof(s2));
	p1->pointer = 0;
	p2->pointer = 0;
	gets(in);
	
	for(i = 0; in[i] != '\0'; i++){
		if(in[i] >= '0' && in[i] <= '9'){
			temp = in[i] - '0';
			while(in[i + 1] != '\0'){
				if(in[i + 1] >= '0' && in[i + 1] <= '9'){
					temp = temp * 10 + in[i + 1] - '0';
					i++;
				}else{
					break;
				}
			}
			PushNum(p1, temp);
		}
		else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '(' || in[i] == ')'){
			if(in[i] == '+')
			{
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' && p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' ){
					PushOp(p2, '+');
				}
				else
				{
					while(p2->pointer > 0 && p2->data[p2->pointer - 1] != '(' )
					{
						op = PopOp(p2);
						Calc(p1, ch);
					}
					PushOp(p2, '+');
				}
				
			}
		
		}
		else if(in[i] == '-')
			{
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' && p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' ){
					PushOp(p2, '-');
				}
				else
				{
					while(p2->pointer > 0 && p2->data[p2->pointer - 1] != '(' )
					{
						op = PopOp(p2);
						Calc(p1, ch);
					}
					PushOp(p2, '-');
				}
				
			}
		
		else if(in[i] == '*')
			{
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' ){
					PushOp(p2, '*');
				}
				else
				{
					while(p2->pointer > 0 && p2->data[p2->pointer - 1] != '(' )
					{
						op = PopOp(p2);
						Calc(p1, ch);
					}
					PushOp(p2, '*');
				}
				
			}
		else if(in[i] == '/')
			{
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' ){
					PushOp(p2, '/');
				}
				else
				{
					while(p2->pointer > 0 && p2->data[p2->pointer - 1] != '(' )
					{
						op = PopOp(p2);
						Calc(p1, ch);
					}
					PushOp(p2, '/');
				}
				
			}
		else if(in[i] == '('){
			PushOp(p2, '(');
		}
		else if(in[i] == ')'){
			while(p2->data[p2->pointer - 1] != '('){
				op = PopOp(p2);
				Calc(p1, op);
			}
			PopOp(p2);
		}
	
	}
	
	
}
void Calc(Spointer1 p1, char op)
{
	int temp1, temp2;
	temp1 = PopNum(p1);
	temp2 = PopNum(p1);
	switch(op)
	{
		case '+': PushNum(p1, temp1 + temp2); break;
		case '-': PushNum(p1, temp1 - temp2); break;
		case '*': PushNum(p1, temp1 * temp2); break;
		case '/': PushNum(p1, temp1 / temp2); break;
	}
} 
int PopNum(Spointer1 p)
{
	if(p->pointer == 0){
		
	}else{
		p->pointer --;
	}
	return p->data[p->pointer]; 
}
char PopOp(Spointer2 p)
{
	if(p->pointer == 0){
		
	}else{
		p->pointer --;
	}
	return p->data[p->pointer]; 
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
