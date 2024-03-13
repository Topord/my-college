#include<stdio.h>
#include<stdlib.h>
struct WordNode
{
	int cnt;
    unsigned char fst;
    unsigned char scd;
    unsigned char thd;
    struct WordNode* next;
};
typedef struct WordNode* Pointer;

int Compare(unsigned char a, unsigned char b, unsigned char c, Pointer head)
{
	Pointer p;
	p = head;
	while(p != NULL){
		if(a == p->fst && b == p->scd && c == p->thd){
            p->cnt++;
            return 1;
        }
        p = p->next; 
    }
    return 0;
} 

void Judge(char str, FILE* f, Pointer head, Pointer* temp)
{
	int jd;
	unsigned char a, b, c;
	while(str != EOF){
        a = str;
        // 三个字节的编码
        if(a >= 224){
            b = fgetc(f);
            c = fgetc(f);
            jd = Compare(a, b, c, head);
        }
        // 单个字节
        else{
            b = c = 0;
            jd = Compare(a, b, c, head);
        }
        if(jd != 1){
        	(*temp)->fst = a;
        	(*temp)->scd = b;
        	(*temp)->thd = c;
        	(*temp)->cnt++;
        	(*temp)->next=(Pointer)malloc(sizeof(struct WordNode));
        	(*temp) = (*temp)->next;
        	(*temp)->cnt=0;
       	    (*temp)->next=NULL;
		}
        str = fgetc(f);
    }	
    
}
Pointer ReadFile(FILE *f)
{
	char str;
    // 三个字节的编码临时存放
    unsigned char s1, s2, s3;
    Pointer *tmp;
	Pointer  h;          
    // 临时结构体地址
    tmp = (Pointer *)malloc(sizeof(Pointer));
    // 权重链表头地址
    h = (*tmp) = (Pointer)malloc(sizeof(struct WordNode));
    (*tmp)->cnt = 0;
    (*tmp)->next = NULL;
    str = fgetc(f);
    Judge(str, f, h, tmp);
    
    return h;
}
void Print(Pointer head,FILE* f){
    Pointer h = head;
    while(h->next != NULL){
        // 三字节的编码
        if(h->fst >= 224){
            if(h->fst == 238){
                fprintf(f, "%d/%d/%d" , h->fst, h->scd, h->thd);
            }
            else{
                fputc(h->fst, f);
                fputc(h->scd, f);
                fputc(h->thd, f);
            }
        }
        // 单字节的（包含\n、空格）
        else{
            if(h->fst == 10){
                fprintf(f, "\\n");
            }
            else{
                fputc(h->fst, f);
            }
        }
        fprintf(f, " %d\n", h->cnt);
        h = h->next;
    }
}
int main()
{
	Pointer p;
    FILE *read, *write;
    
    read = fopen("三国演义（原）.txt","r");
    write = fopen("权重.txt","w");
    
  	p = ReadFile(read);
    Print(p, write);
    
    fclose(read);
    fclose(write);
  
    return 0;
}
