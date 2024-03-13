# 表达式求值

## 任务1-进制转换

求余存入栈，后取出

## 任务2-中缀变后缀

中缀转后缀电脑算法：

1)将中缀字符串从左向右扫描；

2)如果是运算数,直接添加到输出串；

3)如果是左括号,把左括号入栈；

4)如果是运算符，则必须装B入栈；

5)如果是右括号,则配对到左括号为止；

6)字符串扫描完毕，把栈取空

```c
//数字提出 
void Number(char str[100],char out_s[100],char ch,int *str_p,int *out_s_p){
	if(47<ch && ch<58){
		out_s[*out_s_p]=ch;
		(*out_s_p)++;
		//末尾的数字结尾的'#' 
		if(str[*str_p+1]=='\0'){
			out_s[*out_s_p]='#';
			(*out_s_p)++;
		}
	}
	//算试中的数字结尾的'#' 
	else if((47<out_s[*out_s_p-1] && out_s[*out_s_p-1]<58)){
		out_s[*out_s_p]='#';
		(*out_s_p)++;	
	}
} 
```

若为数字时使用。ch是数字且是该数字结尾就加‘#’，反之放入字符串out_s。

```c
//运算符出入栈判断       
void Pd(stack s,char ch,char out_s[100],int *out_s_p){
	char q; //栈顶值 
	q=Pop(s); 
	//请大哥'/'、'*'出去
	if((q=='*' || q=='/') && (ch=='+' || ch =='-')){
		out_s[*out_s_p]=q;
		(*out_s_p)++;
		Push(s,ch);
	}
	//括号内的符号提出
	else if (ch==')'){
		while(q!='('){
			out_s[*out_s_p]=q;
			(*out_s_p)++;
			q=Pop(s);			
		}
	}
	else{
		Push(s,q);
		Push(s,ch);
	}
}
```

若为非数字时使用。取前一个根据优先级分类。

## 任务3-后缀表达式求值

```c
// 后缀表达式计算
float Compute(place pc,char out_s[100]){
	char ch,w[100];
	int out_s_p=0,w_p=0;
	float nb_q,nb_h,n;
	
	ch=out_s[out_s_p];
	while(ch!='\0'){
		// 提出数字
		if('0'<=ch && ch<='9'){
			w[w_p]=ch;
			w_p++;
		}
		// 碰到'#'时转浮点型
		else if(ch=='#'){
			w[w_p]='\0';
			// 字符型转浮点型
			n=atof(w);
			Push(pc,n);
			w_p=0;
		}
		// 遇见运算符时计算
		else{
			nb_h=Pop(pc);
			nb_q=Pop(pc);
			switch (ch){
			case '-':n=nb_q-nb_h;break;
			case '*':n=nb_q*nb_h;break;
			case '/':n=nb_q/nb_h;break;
			default:n=nb_q+nb_h;break;
			}
			Push(pc,n);
		}
		out_s_p++;
		ch=out_s[out_s_p];
	}
	return Pop(pc);
}
```

若提取到数字，放入w；若取到‘#’，封闭w，将其转化为数字，入栈；若遇见运算符，取栈顶中两个数计算，将结果再入栈。

## 任务4-中缀表达式求值

将任务2和任务3结合：任务2中输出的后缀表达式求值导入到任务3中的out_s。