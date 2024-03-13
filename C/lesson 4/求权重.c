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
        // �����ֽڵı���
        if(a >= 224){
            b = fgetc(f);
            c = fgetc(f);
            jd = Compare(a, b, c, head);
        }
        // �����ֽ�
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
    // �����ֽڵı�����ʱ���
    unsigned char s1, s2, s3;
    Pointer *tmp;
	Pointer  h;          
    // ��ʱ�ṹ���ַ
    tmp = (Pointer *)malloc(sizeof(Pointer));
    // Ȩ������ͷ��ַ
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
        // ���ֽڵı���
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
        // ���ֽڵģ�����\n���ո�
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
    
    read = fopen("�������壨ԭ��.txt","r");
    write = fopen("Ȩ��.txt","w");
    
  	p = ReadFile(read);
    Print(p, write);
    
    fclose(read);
    fclose(write);
  
    return 0;
}
