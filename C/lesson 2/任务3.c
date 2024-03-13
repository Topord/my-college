#include<stdio.h>
struct Stack                                              //定义结构体
{
    int data[100];
    int pointer;
};
typedef struct Stack S;
int main()
{
    int ret = 0;
    char in[100];
    int i, temp, k;

    S s;
    s.pointer = -1;
    gets(in);
    for(i = 0; in[i] != '\0'; i++){
        if(in[i] <= '9' && in [i] >= '0'){
            s.pointer++;
            temp = in[i]-'0';
            k = i + 1;
            while(in[k] != '#'){
                if(in[k] <= '9' && in[k] >= '0'){
                    temp = 10*temp + (in[k] - '0');
                    i++;
                    k++;
                }else{
                	break;
				} 
            }
            printf("%d\n", in[i] - '0');
            s.data[s.pointer] = temp;
        }else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/'){
            switch(in[i])
            {
            case '+':
                ret = s.data[s.pointer - 1] + s.data[s.pointer];
                break;
            case '-':
                ret = s.data[s.pointer - 1] - s.data[s.pointer];
                break;
            case '*':
                ret = s.data[s.pointer - 1] * s.data[s.pointer];
                break;
            case '/':
                ret = s.data[s.pointer - 1] / s.data[s.pointer];
                break;
            }
            s.data[s.pointer - 1] = ret;                                          //往前一位存储
            s.data[s.pointer] = 0;
            s.pointer--;
        }
    }
    printf("%d", ret);                                    //输出最后结果
    return 0;
}

