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
struct Word
{
	int cnt;
	char rst[100];
    unsigned char fst;
    unsigned char scd;
    unsigned char thd;
    long int lchild;
    long int rchild;
    long int parent;
};
typedef struct Word* WordPointer;
//���ɺ���Ȩ�غ��ַ������� 
int Compare(unsigned char a, unsigned char b, unsigned char c, Pointer head);
void Judge(char str, FILE* f, Pointer head, Pointer* temp);
Pointer ReadFile(FILE *f);
//������ת���ɽṹ������
WordPointer Trans(Pointer p);
//��ʼ����
void Init_Tree(WordPointer sp);
//���ɹ������� 
void get_two_min(WordPointer p,int * w,int n)	
{
	WordPointer head;
	head = p;
	int i,*min,*vice_min;	
	min=w;vice_min=w+1;
	for (i=0;i<n;i++)	
	{
        if((p+i)->parent == -1)
        {
            *min = i;
            break;
        }
	}
    //��2��ɨ�裺�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(i=0; i<n; i++)
    {
        if((p+i)->cnt < (p + *min)->cnt)
        {
        	if((p+i)->parent == -1)
        	{
				*min = i;
       	 	}
        	
		}
        
    }
	//��3��ɨ�裺�ҵ��׸�û��minָ���Ĺ¶���㣬��������Ϊ�׸���С���
	for (i=0;i<n;i++)	//��ȫ����ʼ��
	{
        if((p+i)->parent == -1 && i!=*min )		
        {
            *vice_min = i;
            break;
        }
	}
    //��4��ɨ�裺�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(i=0; i<n; i++)
    {
        if((p+i)->parent == -1 && i!=*min)
        {
            if((p+i)->cnt < (p + *vice_min)->cnt)
				*vice_min = i;
        }
    }
}

int main()
{
	int i;
	int min[2] = {0};
	Pointer p;
	WordPointer sp;
    FILE *read;
    
    read = fopen("�������壨ԭ��.txt","r");
  	p = ReadFile(read); //pΪ������׵�ַ 
  	//������ת��Ϊ�ṹ������
	sp = Trans(p);
  	//��ʼ���ṹ������ 
    Init_Tree(sp);
    //------------------------------------------------------���ɹ�������
	for(i = 4005; i < 8009; i++)  
	{
		get_two_min(sp,min,i);		    //��ȡ��СȨֵ�������½��
		(sp+min[0])->parent=i;			//��СȨ��Ҷ�ӽ����д��ָ��
		(sp+min[1])->parent=i;			//��СȨ��Ҷ�ӽ����д��ָ��
		(sp+i)->lchild=min[0];			//��ǰ�������д����
		(sp+i)->rchild=min[1];			//��ǰ�������д�Һ���
		(sp+i)->cnt=(sp+min[0])->cnt+(sp+min[1])->cnt;//��ǰ�������дȨ��ֵ
	}
    fclose(read);
	free(p);
	

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
    Pointer* tmp;
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
WordPointer Trans(Pointer p)
{
	int i = 0;
	WordPointer m;
	m = (WordPointer)malloc(8009*sizeof(struct Word));
	WordPointer h = m;
	while(p != NULL){
		h->fst = p->fst;
		h->scd = p->scd;
		h->thd = p->thd;
		h->cnt = p->cnt;
		h++;
		printf("%d\n", i++);
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
		p->parent = 0;
		if(i > 4005){
			p->cnt = 0;
		}
		p++;
	}
}
