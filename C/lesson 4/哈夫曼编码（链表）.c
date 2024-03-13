#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned int Uint;
struct Node
{
    Uint weight;		//���Ȩֵ�� unsigned ����ʡ�ռ䣬2�ֽ�
    Uint parent;		//ָ�򸸽���ָ��
    Uint lChild;		//ָ�����ӽ���ָ��
    Uint rChild;		//ָ���Һ��ӽ���ָ��
    struct Node *next;  //ָ����һ���ڵ��ָ�� 
};
typedef struct Node * Pointer;

/*
���ܣ�������������������� 
������p->������׵�ַ�� 
�㷨�� �� 
*/
void Init_HufTree(Pointer p, Uint* w, int len)		
{
	int i;
 	for(i = 0; i < 2*len-1; i++){
		if(i < len){
			p->weight = *(w + i);
			p->parent = -1;
			p->lChild = -1;
			p->rChild = -1;
			p->next = (Pointer)malloc(sizeof(struct Node));
			p = p->next;
			p->next = NULL;
		}else{
			p->weight = 0;
			p->parent = -1;
			p->lChild = -1;
			p->rChild = -1;
			p->next = (Pointer)malloc(sizeof(struct Node));
			p = p->next;
			p->next = NULL;
		}
	}
}
/*
���ܣ������������������ӡ 
������p-->�����׵�ַ��len-->������ 
�㷨�� �� 
*/ 
void Print(Pointer p, int len)
{
	int i;
	for(i = 0; i < 2*len - 1; i++){
		printf("i:%d\tweight:%d\tparent:%d\tlChild:%d\trChild:%d\t\n", i, p->weight, p->parent, p->lChild, p->rChild);
		p = p->next;
	}
}
/*
���ܣ��ҵ���n�����ǰ����СȨ�غʹ�СȨ�ع¶�����
������p->�����ַ��w->��Ԫ�ص�����������ַ��n->���ҷ�Χ
�㷨�� 4��ɨ�跨(��1��2��ɨ���ҵ���СȨ��ֵ����3��4��ɨ���ҵ���СȨ��ֵ)
*/
void get_two_min(Pointer p, int * w, int n)	
{
	Pointer head, q;
	head = q = p;
	int i, j, t, *min, *vice_min;	
	min = w; vice_min = w + 1;//minָ����С����Ŵ�ŵ�Ԫ����������Ԫ�أ�vice_min��С��ָ��

	//��1��ɨ�裺�ҵ��׸��¶���㣬��������Ϊ�׸���СȨ�ؽ��
	for (i = 0; i < n; i++)	
	{ 
        if(p->parent == -1)		
        {
            *min = i;
            break;
        }
        
        p = p->next; 
	}
	//��2��ɨ�裺�ҳ�Ȩֵ��С�ĵ��ڵ�
	p = head;
	for(i = 0; i < n; i++){
		for(j = 0; j < i; j++){
			q = q->next; 
		}
		for(j = 0; j < *min; j++){
			p = p->next; 
		}
		if(q->weight < p->weight){
			if(q->parent == -1 && p->parent == -1){
				*min = i;
			}
		}
		p = q = head;
	}
 	//��3��ɨ�裺�ҵ��׸�û��minָ���Ĺ¶���㣬��������Ϊ�׸���С���
	for (i = 0; i < n && i != *min; i++)	
	{
        if(p->parent == -1)		
        {
            *vice_min = i;
            break;
        }
        p = p->next; 
	}
	q = p = head;
    //��4��ɨ�裺�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(i = 0; i < n; i++)
    {
    	if(q->parent == -1 && i != *min){
    		for(j = 0; j < i; j++){
				q = q->next; 
			}
			for(j = 0; j < *vice_min; j++){
				p = p->next; 
			}
			t = p->weight;
			if(q->weight < t && q->parent == -1 && p->parent == -1){
				*vice_min = i;
			}
		}
		p = q = head;
    }   
}
/*
���ܣ����������� 
������p->�����׵�ַ;len->������;min->�����СԪ�صĵ�ַ������ 
�㷨���� 
*/ 
void CreateTree(Pointer p, int len, int* min)
{
	int i, j;
	Pointer m, n, q, head;
	m = n = q = head = p;               //��m��n����ʾ����Сֵ�ʹ�Сֵ�Ľڵ��λ�� 
	for(i = len; i < 2*len - 1; i++){
		if(i <= 7)
		{
			get_two_min(p, min, i);		    //��ȡ��СȨֵ�������½��
			for(j = 0; j < min[0]; j++){	//��СȨ��Ҷ�ӽ����д��ָ��
				p = p->next; 
			}
			m = p; p->parent = i; p = head;
			for(j = 0; j < min[1]; j++){	//��СȨ��Ҷ�ӽ����д��ָ��
				p = p->next; 
			}
			n = p; p->parent = i; p = head;
			for(j = 0; j < i; j++){			//��ǰ�������д����
				p = p->next; 
			}
			p->lChild = min[0]; p = head;
			for(j = 0; j < i; j++){			//��ǰ�������д�Һ���
				p = p->next; 
			}
			p->rChild = min[1]; p = head;		
			for(j = 0; j < i; j++){			//��ǰ�������дȨ��ֵ
				p = p->next; 
			}
			p->weight = m->weight + n->weight; p =head;
			}
		else
		{									//���һ�β����бȽϣ�ֱ����� 
			for(j = 0; j < 8; j++){
				p = p->next; 
			}
			for(j = 0; j < 7; j++){
				q = q->next; 
			}
			q->parent = i;
			p->weight = q->weight;
			p->lChild = i - 2;
			p->rChild = i - 1;
			q = head;
			for(j = 0; j < 6; j++){
				q = q->next; 
			}
			q->parent = i;
			p->weight += q->weight;
		}
    }
}
//���ܣ��Ը������ƵĹ�����������ȷ��Ҷ��������ȡ��Ȩ��ֵ�Ĺ��������룬�������ڱ���������
//������head--����������ͷ����ַ��node--ָ��ָ���������ָ�룬num--Ҷ�ӵĽ�����
//�㷨��ʹ�ö����̬
void Create_HufCode(Pointer p,char **node, int num)	//��������������
{
	Pointer q = p;
	int j, i;			//ָʾbiaoji
    int sit;		//����Ĵ���λ��ָ�룬ÿ���һ������λ���������tmp[sit]��
    int pp;			//ָ��ǰ���ĸ��ڵ�
    Uint c;			//���� n ��Ҷ�ӽ���ָʾ��� c
    char *tmp = (char *)malloc(num * sizeof(char));	//������ǰ����Ĺ����ռ�
    tmp[num-1] = '\0';				//����������λ��ű��룬���ȴ�ű��������
    for(i = 0; i < num; i++)		//��n��Ҷ�ӽ���Ӧ�Ĺ���������
    {
        sit = num - 1;		//��ʼ������λָ�롣ÿ���һ������λ���������tmp[sit]��
        //��Ҷ�ӵ�����������
        p = q;
        for(j = 0; j < i; j++){
        		p = p->next; 
			}
		pp = p->parent; 
		c = i;
        while(1)
        {
        	if(pp == -1)	break;
        	p = q;
        	for(j = 0; j < c; j++){
        		p = p->next; 
			}
			pp = p->parent; 
			p = q;
			for(j = 0; j < pp; j++){
        		p = p->next; 
			}
            if( p->lChild == c)
				tmp[--sit] = '0';  //���֧��0 ,���ҵ����˳�������������
            else
                tmp[--sit] = '1';  //�ҷ�֧��1
            c = pp;
            p = q;
            for(j = 0; j < pp; j++){
        		p = p->next; 
			}
			pp = p->parent; 
        }	
        p = q;
        for(j = 0; j < i; j++){
        	p = p->next; 
		}
		node[i] = (char *)malloc((num - sit) * sizeof(char));//Ϊ��i�����봴���ռ�	
        strcpy(node[i], &tmp[sit]);
		printf("��ǰȨ��Ϊ��%d,����ı���Ϊ��%s\n", p->weight, node[i]);
    }
    free(tmp);		//�ͷ���ʱ�ռ�
}
int main()
{
	int i, j, lenth;
	int min[2] = {0};			//min[0]װ��СȨ�ؽ��ţ�min[1]װ��СȨ�ؽ���
	Pointer p, head, m, n, q;
	char **Huf;
	Uint num[]={6,2,7,4,5};							//Ҷ�ӽ��Ȩ��ֵ
	lenth = sizeof(num)/sizeof(num[0]);			//�������Ԫ�ظ���
	head = p = q = (Pointer)malloc(sizeof(struct Node));	//�����չ�����������2n-1��Ԫ��
	Init_HufTree(p, num, lenth);
	Huf=(char **)malloc( lenth * sizeof(char *));
	p = head;
	printf("--------------------��ʼ״̬�Ĺ�������Ϊ--------------------\n");
	Print(p, lenth);
	p = head;
	printf("--------------------������ɵĹ�������Ϊ--------------------\n");
	CreateTree(p, lenth, min);
    p = head;
	Print(p, lenth);
	printf("-----------------------����������Ϊ-------------------------\n");
	p = head;
	Create_HufCode(p, Huf, lenth);

	free(head);
	return 0;
}
