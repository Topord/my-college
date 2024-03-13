#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned int Uint;
typedef struct Node * Huf_Node;
struct Node
{
    Uint weight;		//���Ȩֵ�� unsigned ����ʡ�ռ䣬2�ֽ�
    Uint parent;		//ָ�򸸽���ָ��
    Uint lChild;		//ָ�����ӽ���ָ��
    Uint rChild;		//ָ���Һ��ӽ���ָ��
};

void Print_HufTree(Huf_Node p,int n)		//��ʾ������������ȫ�����
//2��������1.���׽���ַ��2.���ܽ�������
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("��%d�����Ȩ�ء������š����Ӻš��Һ��Ӻţ�",i);
		printf("\t%d\t%d\t%d\t%d\n",p->weight,p->parent,p->lChild,p->rChild);
		p++;
	}
}

void Init_HufTree(Huf_Node p,Uint * w,int sum,int n)		//��ʼ��������������Ȩ��ֵ��0��ָ����-1
//4��������1.���׽���ַ��2.��ʼҶ�ӽ�����ݣ�3.���ܽ�������4.��ʼҶ�����ݸ���
{
	Huf_Node head;
	head=p;
	int i;
	for (i=0;i<sum;i++)	//��ȫ����ʼ��
	{
		p->weight=0;
		p->parent=-1;
		p->lChild=-1;
		p->rChild=-1;
		p++;
	}
	p=head;
	for (i=0;i<n;i++)	//���Ѹ�����Ȩ��ֵ���뵽������Ҷ�ӽ����
	{
		p->weight=*w;
		p++;
		w++;
	}
}

void get_two_min(Huf_Node p,int * w,int n)	//�ҵ���n�����ǰ����СȨ�غʹ�СȨ�ع¶�����
//4��������1.���׽���ַ��2.��Ԫ�ص�����������ַ��3.���ҷ�Χ��ǰn���ڵ�
//���ڣ�����������Ԫ�ص���������w�У������ر�ǿ������֪ʶҪ��ʵ��
//�㷨��4��ɨ�跨(��1��2��ɨ���ҵ���СȨ��ֵ����3��4��ɨ���ҵ���СȨ��ֵ)
{
	Huf_Node head;
	head=p;
	int i,*min,*vice_min;	
	min=w;vice_min=w+1;//minָ����С����Ŵ�ŵ�Ԫ����������Ԫ�أ�vice_min��С��ָ��
	//��1��ɨ�裺�ҵ��׸��¶���㣬��������Ϊ�׸���СȨ�ؽ��
	for (i=0;i<n;i++)	//��ȫ����ʼ��
	{
    //����˽��Ϊ�¶���㣬��ô�ѽ��Ÿ�ֵ��*min����ʵ��װ�뵽��������min[0]��������ѭ��
        if((p+i)->parent == -1)		//ע��ѭ����pֵδ�ı�
        {
            *min = i;
            break;
        }
	}
    //��2��ɨ�裺�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(i=0; i<n; i++)
    {
    //����˽��ĸ���Ϊ�գ������ if
        if((p+i)->parent == -1)
        {
        //����˽���Ȩֵ�� min ����ȨֵС����ô���� min ��㣬��������ʼ�� min
            if((p+i)->weight < (p + *min)->weight)
				*min = i;
        }
    }
    //�ҵ�����СȨֵ�Ľ�㣬��ʾһ��
    //printf("��СȨ�ؽ���Ϊ %d \n",*min);

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
    //����˽��ĸ���Ϊ�գ���δ��minָ������� if
        if((p+i)->parent == -1 && i!=*min)
        {
    //����˽���Ȩֵ�� vive_min ����ȨֵС����ô����vive_min ��㣬��������ʼ��vive_min
            if((p+i)->weight < (p + *vice_min)->weight)
				*vice_min = i;
        }
    }
    //�ҵ��˴�СȨֵ�Ľ�㣬��ʾһ��
    //printf("��СȨ�ؽ���Ϊ %d \n",*vice_min);
}

void Fill_HufTree(Huf_Node p,int min[],int n)		//��һ���ѳ�ʼ�������������
{
	int i;
	for(i=n;i<2*n - 1;i++)
	{
		get_two_min(p,min,i);		//��ȡ��СȨֵ�������½��
		(p+min[0])->parent=i;			//��СȨ��Ҷ�ӽ����д��ָ��
		(p+min[1])->parent=i;			//��СȨ��Ҷ�ӽ����д��ָ��
		(p+i)->lChild=min[0];			//��ǰ�������д����
		(p+i)->rChild=min[1];			//��ǰ�������д�Һ���
		(p+i)->weight=(p+min[0])->weight+(p+min[1])->weight;//��ǰ�������дȨ��ֵ
	}
}

//��������������ϣ��� n ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
void Create_HufCode(Huf_Node head,char **huf, int num)	//��������������
//���ܣ��Ը������ƵĹ�����������ȷ��Ҷ��������ȡ��Ȩ��ֵ�Ĺ��������룬�������ڱ���������
//������head--����������ͷ����ַ��huf--ָ��ָ���������ָ�룬num--Ҷ�ӵĽ�����
//�㷨��ʹ�ö����̬
{
	int i;			//ָʾbiaoji
    int sit;		//����Ĵ���λ��ָ�룬ÿ���һ������λ���������tmp[sit]��
    int pp;			//ָ��ǰ���ĸ��ڵ�
    Uint c;			//���� n ��Ҷ�ӽ���ָʾ��� c
    char *tmp = (char *)malloc(num * sizeof(char));	//������ǰ����Ĺ����ռ�
    printf("num = %d\n", num); 
    tmp[num-1] = '\0';				//����������λ��ű��룬���ȴ�ű��������
    for(i = 0; i < num; i++)		//��n��Ҷ�ӽ���Ӧ�Ĺ���������
    {
        sit = num - 1;		//��ʼ������λָ�롣ÿ���һ������λ���������tmp[sit]��
        //��Ҷ�ӵ�����������
        for(c = i, pp = head[i].parent; pp != -1; c =pp, pp= head[pp].parent)
        {
        	printf("1\n");
            if( head[pp].lChild == c)
				tmp[--sit] = '0';  //���֧��0 ,���ҵ����˳�������������
            else
                tmp[--sit] = '1';  //�ҷ�֧��1
        }
        
        huf[i] = (char *)malloc((num - sit) * sizeof(char));//Ϊ��i�����봴���ռ�
        strcpy(huf[i], &tmp[sit]);
        //printf("c = %d\n", c);
		printf("��ǰȨ��Ϊ��%d,����ı���Ϊ��%s\n",(head)[i].weight,huf[i]);
    }
    free(tmp);		//�ͷ���ʱ�ռ�
}

int main()
{
	int i,*p,num,tmp=0;
	int min[2];			//min[0]װ��СȨ�ؽ��ţ�min[1]װ��СȨ�ؽ���
	Huf_Node sp;
	char **HufCode;		//���ָ��ָ��һ��ָ�����飨Ԫ�ظ���=Ҷ�Ӹ�������
	//�����е�ÿ��Ԫ��ָ��һ����̬�ַ����ռ䣨װ�����Ĺ��������룩
	Uint leaf_weight[]={6,2,7,4,5};					//Ҷ�ӽ��Ȩ��ֵ
	num=sizeof(leaf_weight)/sizeof(leaf_weight[0]);			//�������Ԫ�ظ���
	sp=(Huf_Node)malloc((2*num - 1) * sizeof(struct Node));	//�����չ�����������2n-1��Ԫ��
	Init_HufTree(sp,leaf_weight,2*num - 1,num);				//��ʼ����������
	printf("\n\n------------------------��ʼ״̬�Ĺ�������Ϊ��----------------------------\n");
	Print_HufTree(sp,2*num - 1);							//��ʾȫ���Ĺ�������
	printf("\n\n------------------------������ɵĹ�������Ϊ��----------------------------\n");
	Fill_HufTree(sp, min, num);								//�����������������
	Print_HufTree(sp,2*num - 1);							//��ʾȫ���Ĺ�������
	printf("\n\n----------------------------����������Ϊ��--------------------------------\n");
	HufCode=(char **)malloc( num * sizeof(char *));			//����ָ������������ָ������
	Create_HufCode(sp, HufCode, num);
	free(sp);
	printf("\n\n");
	system("pause");
	return 0;
}
