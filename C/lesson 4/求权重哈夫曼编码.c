#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct WordNode
{
	int cnt;
    unsigned char fst;
    unsigned char scd;
    unsigned char thd;
    struct WordNode* next;
};
typedef struct WordNode* Pointer;
struct Word
{
	int cnt;
    unsigned char fst;
    unsigned char scd;
    unsigned char thd;
    long int lchild;
    long int rchild;
    long int parent;
};
typedef struct Word* WordPointer;
//生成含有权重和字符的链表 
int Compare(unsigned char a, unsigned char b, unsigned char c, Pointer head);
void Judge(char str, FILE* f, Pointer head, Pointer* temp);
Pointer ReadFile(FILE *f);
//将链表转换成结构体数组
WordPointer Trans(Pointer p);
//初始化树
void Init_Tree(WordPointer sp);
//生成哈夫曼树及哈夫曼编码 
void get_two_min(WordPointer p,int * w,int n);	
void Fill_Tree(WordPointer p, int min[]);
//创建哈夫曼编码
void Create_HufCode(WordPointer head,char **huf, int num, FILE* w);	

int main()
{
	int i;
	int min[2] = {0};
	char **HufCode;
	Pointer p;
	WordPointer sp;
    FILE *read, *write;
    
    read = fopen("三国演义（原）.txt","r");
    write = fopen("权重（哈夫曼编码）.txt", "w");
    
  	p = ReadFile(read); //p为链表的首地址 
  	//-------------------------------------------------------将链表转换为结构体数组
	sp = Trans(p);
  	//-------------------------------------------------------初始化结构体数组 
    Init_Tree(sp);
    //-------------------------------------------------------生成哈夫曼树
	Fill_Tree(sp, min);
	//-------------------------------------------------------生成哈夫曼编码
	HufCode=(char **)malloc( 4005 * sizeof(char *));
	Create_HufCode(sp, HufCode, 4005, write); 
    fclose(read);
	free(p);
	free(sp);
	printf("finish"); 
	
    return 0;
}
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
    Pointer* tmp;
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
WordPointer Trans(Pointer p)
{
	WordPointer m;
	m = (WordPointer)malloc(8009*sizeof(struct Word));
	WordPointer h = m;
	while(p != NULL){
		h->fst = p->fst;
		h->scd = p->scd;
		h->thd = p->thd;
		h->cnt = p->cnt;
		h++;
		p = p->next;     
	}	
	return m;
} 
void Init_Tree(WordPointer sp)
{
	WordPointer p = sp;
	int i;
	for(i = 0; i < 8009; i++){
		p->lchild = -1;
		p->rchild = -1;
		p->parent = -1;
		if(i > 4005){
			p->cnt = 0;
		}
		p++;
	}
}
void get_two_min(WordPointer p,int * w,int n)	
{
	WordPointer head;
	head = p;
	int i,*min,*vice_min;	
	min=w;vice_min=w+1;
	for (i=0;i<n;i++)	{
        if((p+i)->parent == -1){
            *min = i;
            break;
        }
	}
    //第2次扫描：找出权值最小的单节点
    for(i=0; i<n; i++){
        if((p+i)->cnt < (p + *min)->cnt){
        	if((p+i)->parent == -1){
				*min = i;
       	 	}
		}
    }
	//第3次扫描：找到首个没被min指定的孤儿结点，将其锁定为首个次小结点
	for (i=0;i<n;i++)	{
        if((p+i)->parent == -1 && i!=*min ){
            *vice_min = i;
            break;
        }
	}
    //第4次扫描：找出权值次小的单节点
    for(i=0; i<n; i++){
        if((p+i)->parent == -1 && i!=*min){
            if((p+i)->cnt < (p + *vice_min)->cnt)
				*vice_min = i;
        }
    }
}
void Fill_Tree(WordPointer p, int min[])
{
	int i;
	for(i=4005;i<8009;i++)
	{
		get_two_min(p,min,i);		
		(p+min[0])->parent=i;			
		(p+min[1])->parent=i;			
		(p+i)->lchild=min[0];		
		(p+i)->rchild=min[1];		
		(p+i)->cnt=(p+min[0])->cnt+(p+min[1])->cnt;
	}
}
void Create_HufCode(WordPointer head,char **huf, int num, FILE* w)	
{
	int i;			
    int sit;	
    int pp;		
    int c;			
    char *tmp = (char *)malloc(num * sizeof(char));
    WordPointer h = head;
    tmp[num-1] = '\0';				
    for(i = 0; i < num; i++)	
    {
        sit = num - 1;		
        for(c = i, pp = head[i].parent; pp != -1; c =pp, pp= head[pp].parent)
        {
            if( head[pp].lchild == c)
				tmp[--sit] = '0';  
            else
                tmp[--sit] = '1'; 
        }
        huf[i] = (char *)malloc((num - sit) * sizeof(char));
        strcpy(huf[i], &tmp[sit]);
		//写入文件
		if(h->fst >= 224){
        	if(h->fst == 238){
            	fprintf(w, "%d/%d/%d" , h->fst, h->scd, h->thd);
        	}
        	else{
            	fputc(h->fst, w);
            	fputc(h->scd, w);
            	fputc(h->thd, w);
        	}
   		 }
    // 单字节的（包含\n、空格）
    	else{
        	if(h->fst == 10){
            	fprintf(w, "\\n");
        	}
        	else{
            	fputc(h->fst, w);
        	}
    	}
    	fprintf(w, "\t%s\n", huf[i]);
		h++;
	}
        free(tmp);		
}

