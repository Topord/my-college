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

void Push(Spointer p, char c);	//入栈
char Pop(Spointer p);			//出栈

int main()
{
	struct Stack S;             			//创建S栈,存放运算符 
	Spointer ps;							//指向S栈的指针ps
	char in[200], out[200], str;			//in接受表达式,out存放数字
	int cout = 0, jd = 0;
	ps = (Spointer)malloc(sizeof(s));
	ps->pointer = -1;
	
	printf("请输入表达式:  ");
	gets(in);
	

	//对表达式进行分解  123+-/*
	while(in[cout] != '\0'){
		str = in[cout]; 
		if('0' <= str && str <= '9'){			//in[i]为数字 
			out[jd] = str;
			jd++;
		}else{
			Push(ps, str);
		}
		cout++;
	}


	//输出字符串
	for(jd = 0; jd < strlen(out); jd++){
		printf("%c#", out[jd]);	
	}
	
    //输出符号 
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
	p->pointer++;   //一定要先让pointer自增 
	p->data[p->pointer] = c;
}

char Pop(Spointer p)
{
	if(p->pointer == -1)
		return 0;
	p->pointer--;
	return p->data[p->pointer + 1]; 
}



