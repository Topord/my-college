#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
	char data[1000];
	int pointer;
};
typedef struct Stack s;
typedef struct Stack * Spointer;

void Push(Spointer p, char c);	//��ջ
char Pop(Spointer p);			//��ջ

int main()
{
	struct Stack S;             			//����Sջ,�������� 
	Spointer ps;							//ָ��Sջ��ָ��ps
	char in[200], out[200], str;			//in���ܱ��ʽ,out�������
	int cout = 0, jd = 0;
	ps = (Spointer)malloc(sizeof(s));
	ps->pointer = -1;
	
	printf("��������ʽ:  ");
	gets(in);
	

	//�Ա��ʽ���зֽ�  123+-/*
	while(in[cout] != '\0'){
		str = in[cout]; 
		if(48 <= str && str <= 57){			//in[i]Ϊ���� 
			if(48 <= in[cout + 1] && in[cout + 1] <= 57){
				str = (int)str + (int)in[cout + 1] - '0'*2;
				printf("%d\n", str);
				str = (char)str;
				cout++;
			}
			printf("%c\n", str);
			out[jd] = str;
			jd++;
		}else{
			if(str != 40 && str != 41){
				Push(ps, str);
			}
		}
		cout++;
	}


	//����ַ���
	for(jd = 0; jd < strlen(out); jd++){
		printf("%c#", out[jd]);
	}
    //������� 
	str = Pop(ps);
	while(str != 0){
		printf("%c", str);
		str = Pop(ps);
	}
	
	free(ps);
	
	return 0;		
}


void Push(Spointer p, char c)
{  
	p->pointer++;   //һ��Ҫ����pointer���� 
	p->data[p->pointer] = c;
}

char Pop(Spointer p)
{
	if(p->pointer == -1)
		return 0;
	p->pointer--;
	return p->data[p->pointer + 1]; 
}



