#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack1
{
	int data[1000];
	int pointer;
};								//�� 1+(2+1*9)  
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
void PushOp(Spointer2 p, char c);	//��ջ
char PopNum(Spointer1 p);			//��ջ
char PopOp(Spointer2 p); 
void Calc(Spointer1 p, char op);

int main()
{
	char in[200], op, ch;
	int i, temp;
	S1 s1;   //s1ջ�����������
	S2 s2;	//s2ջ������������
	Spointer1 p1;
	Spointer2 p2;
	p1 = (Spointer1)malloc(sizeof(s1));
	p2 = (Spointer2)malloc(sizeof(s2));
	p1->pointer = 0;
	p2->pointer = 0;
	gets(in);
//�� 1+(2+1*9)
	for (i = 0; in[i] != '\0'; i++){							//���ַ��� 
		if (in[i] >= '0' && in[i] <= '9'){						//���� 
			temp = in[i] - '0';									//���ַ�ת��Ϊ��ֵ 
			while (in[i + 1] != '\0'){           				//��λ��ֵ��ȡ
				if (in[i + 1] >= '0' && in[i + 1] <= '9'){
					temp = temp * 10 + in[i + 1] - '0';			
					i++;
				}else
					break;										//�������� 
			}		
			PushNum(p1, temp);										//��ջ 
		}
		else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '(' || in[i] == ')'){	
			if(in[i] == '+'){				//1+2+1+9
				if(p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' && p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/')
				{
					PushOp(p2, '+');
				}
				else                           
				{
					while (p2->pointer > 0 && p2->data[p2->pointer - 1] != '(')//�����ȼ��ߵ��������������㣬���������ڵ����ȼ���� 
					{
						op = PopOp(p2);
						Calc(p1, ch);//���㣬��ѹ������ջ
					}
					PushOp(p2, '+');
					}
				}
			else if(in[i] == '-'){
				//��һ��������(,����ջ�� 
				if(p2->data[p2->pointer - 1] != '+' && p2->data[p2->pointer - 1] != '-' && p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/')
				{
					PushOp(p2, '-');
				}
				else//������ǣ���֮ǰ�������ֶ���ջ�����㣬Ȼ������ջ
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//�����ȼ��ߵ��������������㣬���������ڵ����ȼ���� 
					{
						op = PopOp(p2);
						Calc(p1, ch);//���㣬��ѹ��������ջ
					}
					PushOp(p2, '-');
					}
				}				//�� 1+(2+1*9) 
			else if(in[i] == '*'){
				//��һ��������(����+��-,����ջ�� 
				if(p2->data[p2->pointer - 1] != '*' && p2->data[p2->pointer - 1] != '/' )
				{
					PushOp(p2, '*');
				}							
				else//������ǣ���֮ǰ�������ֶ���ջ�����㣬Ȼ������ջ
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//�����ȼ��ߵ��������������㣬���������ڵ����ȼ���� 
					{
						op = PopOp(p2);
						Calc(p1, ch);//���㣬��ѹ��������ջ
					}
					PushOp(p2, '*');
					}
				}
			else if(in[i] == '/'){
				//��һ��������(,����ջ��    
				if(p2->data[p2->pointer - 1] != '/' && p2->data[p2->pointer - 1] != '*' )
				{
					PushOp(p2, '/');
				}
				else//������ǣ���֮ǰ�������ֶ���ջ�����㣬Ȼ������ջ
				{
					while (s2.pointer > 0 && s2.data[s2.pointer - 1] != '(')//�����ȼ��ߵ��������������㣬���������ڵ����ȼ���� 
					{
						op = PopOp(p2);
						Calc(p1, ch);//���㣬��ѹ��������ջ
					}
					PushOp(p2, '/');
					}
				}
			
			else if(in[i] == '('){
				PushOp(p2, '(');
			}						//�� 1+(2+1*9)
			else if(in[i] == ')'){
				while (p2->data[p2->pointer - 1] != '(')
				{
					op = PopOp(p2);
					Calc(p1, op);//���㣬��ѹ������ջ
				}
				PopOp(p2);//��'('Ҳ��ջ������������
			}
		}
	}
		
	//�� 1+(2+1*9)  1+11
	while (p2->pointer > 0)//��ʣ����������ջ������ 
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
//�ӷ�
void Calc(Spointer1 p1, char op)//�� 1+(2+1*9)
{
	int temp1, temp2;			//ȡ�������� 
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
//��ջ num
char PopNum(Spointer1 p)
{
	if(p->pointer == 0){
		
	}else{
			p->pointer--;
	return p->data[p->pointer];
	}

}
//��ջ  op
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
