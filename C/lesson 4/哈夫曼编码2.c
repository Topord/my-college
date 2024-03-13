#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned int Uint;
typedef struct Node * Huf_Node;
struct Node
{
    Uint weight;		//结点权值； unsigned 更节省空间，2字节
    Uint parent;		//指向父结点的指针
    Uint lChild;		//指向左孩子结点的指针
    Uint rChild;		//指向右孩子结点的指针
};

void Print_HufTree(Huf_Node p,int n)		//显示整个哈夫曼树全部结点
//2个参数：1.树首结点地址；2.树总结点个数；
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("第%d个结点权重、父结点号、左孩子号、右孩子号：",i);
		printf("\t%d\t%d\t%d\t%d\n",p->weight,p->parent,p->lChild,p->rChild);
		p++;
	}
}

void Init_HufTree(Huf_Node p,Uint * w,int sum,int n)		//初始化哈夫曼树，将权重值置0和指针置-1
//4个参数：1.树首结点地址；2.初始叶子结点数据；3.树总结点个数；4.初始叶子数据个数
{
	Huf_Node head;
	head=p;
	int i;
	for (i=0;i<sum;i++)	//先全部初始化
	{
		p->weight=0;
		p->parent=-1;
		p->lChild=-1;
		p->rChild=-1;
		p++;
	}
	p=head;
	for (i=0;i<n;i++)	//把已给定的权重值填入到哈夫曼叶子结点中
	{
		p->weight=*w;
		p++;
		w++;
	}
}

void get_two_min(Huf_Node p,int * w,int n)	//找到第n个结点前的最小权重和次小权重孤儿结点号
//4个参数：1.树首结点地址；2.两元素的整形数组首址；3.查找范围：前n个节点
//出口：结果存放在两元素的整形数组w中（这里特别强调基础知识要扎实）
//算法：4次扫描法(第1、2次扫描找到最小权重值，第3、4次扫描找到次小权重值)
{
	Huf_Node head;
	head=p;
	int i,*min,*vice_min;	
	min=w;vice_min=w+1;//min指向最小数序号存放单元，即数组首元素；vice_min次小数指针
	//第1次扫描：找到首个孤儿结点，将其锁定为首个最小权重结点
	for (i=0;i<n;i++)	//先全部初始化
	{
    //如果此结点为孤儿结点，那么把结点号赋值给*min（其实是装入到主函数的min[0]），跳出循环
        if((p+i)->parent == -1)		//注意循环中p值未改变
        {
            *min = i;
            break;
        }
	}
    //第2次扫描：找出权值最小的单节点
    for(i=0; i<n; i++)
    {
    //如果此结点的父亲为空，则进入 if
        if((p+i)->parent == -1)
        {
        //如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
            if((p+i)->weight < (p + *min)->weight)
				*min = i;
        }
    }
    //找到了最小权值的结点，显示一下
    //printf("最小权重结点号为 %d \n",*min);

	//第3次扫描：找到首个没被min指定的孤儿结点，将其锁定为首个次小结点
	for (i=0;i<n;i++)	//先全部初始化
	{
        if((p+i)->parent == -1 && i!=*min )		
        {
            *vice_min = i;
            break;
        }
	}
    //第4次扫描：找出权值次小的单节点
    for(i=0; i<n; i++)
    {
    //如果此结点的父亲为空，且未被min指定则进入 if
        if((p+i)->parent == -1 && i!=*min)
        {
    //如果此结点的权值比 vive_min 结点的权值小，那么更新vive_min 结点，否则就是最开始的vive_min
            if((p+i)->weight < (p + *vice_min)->weight)
				*vice_min = i;
        }
    }
    //找到了次小权值的结点，显示一下
    //printf("次小权重结点号为 %d \n",*vice_min);
}

void Fill_HufTree(Huf_Node p,int min[],int n)		//将一个已初始化的树填充完善
{
	int i;
	for(i=n;i<2*n - 1;i++)
	{
		get_two_min(p,min,i);		//获取最小权值的两个孤结点
		(p+min[0])->parent=i;			//最小权重叶子结点填写父指针
		(p+min[1])->parent=i;			//次小权重叶子结点填写父指针
		(p+i)->lChild=min[0];			//当前父结点填写左孩子
		(p+i)->rChild=min[1];			//当前父结点填写右孩子
		(p+i)->weight=(p+min[0])->weight+(p+min[1])->weight;//当前父结点填写权重值
	}
}

//哈夫曼树建立完毕，从 n 个叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
void Create_HufCode(Huf_Node head,char **huf, int num)	//创建哈夫曼编码
//功能：对给定完善的哈夫曼树及明确的叶子数，获取各权重值的哈夫曼编码，并保存在编码数组中
//参数：head--哈夫曼树的头结点地址，huf--指向指针数组的总指针，num--叶子的结点个数
//算法：使用多个动态
{
	int i;			//指示biaoji
    int sit;		//编码的存入位置指针，每求出一个编码位，将存放在tmp[sit]中
    int pp;			//指向当前结点的父节点
    Uint c;			//遍历 n 个叶子结点的指示标记 c
    char *tmp = (char *)malloc(num * sizeof(char));	//分配求当前编码的工作空间
    printf("num = %d\n", num); 
    tmp[num-1] = '\0';				//从右向左逐位存放编码，首先存放编码结束符
    for(i = 0; i < num; i++)		//求n个叶子结点对应的哈夫曼编码
    {
        sit = num - 1;		//初始化编码位指针。每求出一个编码位，将存放在tmp[sit]中
        //从叶子到根结点求编码
        for(c = i, pp = head[i].parent; pp != -1; c =pp, pp= head[pp].parent)
        {
        	printf("1\n");
            if( head[pp].lChild == c)
				tmp[--sit] = '0';  //左分支标0 ,从右到左的顺序编码入数组内
            else
                tmp[--sit] = '1';  //右分支标1
        }
        
        huf[i] = (char *)malloc((num - sit) * sizeof(char));//为第i个编码创建空间
        strcpy(huf[i], &tmp[sit]);
        //printf("c = %d\n", c);
		printf("当前权重为：%d,保存的编码为：%s\n",(head)[i].weight,huf[i]);
    }
    free(tmp);		//释放临时空间
}

int main()
{
	int i,*p,num,tmp=0;
	int min[2];			//min[0]装最小权重结点号，min[1]装次小权重结点号
	Huf_Node sp;
	char **HufCode;		//这个指针指向一个指针数组（元素个数=叶子个数），
	//数组中的每个元素指向一个动态字符串空间（装有最后的哈夫曼编码）
	Uint leaf_weight[]={6,2,7,4,5};					//叶子结点权重值
	num=sizeof(leaf_weight)/sizeof(leaf_weight[0]);			//求数组的元素个数
	sp=(Huf_Node)malloc((2*num - 1) * sizeof(struct Node));	//创建空哈夫曼树数组2n-1个元素
	Init_HufTree(sp,leaf_weight,2*num - 1,num);				//初始化哈夫曼树
	printf("\n\n------------------------初始状态的哈夫曼树为：----------------------------\n");
	Print_HufTree(sp,2*num - 1);							//显示全部的哈夫曼树
	printf("\n\n------------------------构建完成的哈夫曼树为：----------------------------\n");
	Fill_HufTree(sp, min, num);								//将哈夫曼树填充完善
	Print_HufTree(sp,2*num - 1);							//显示全部的哈夫曼树
	printf("\n\n----------------------------哈夫曼编码为：--------------------------------\n");
	HufCode=(char **)malloc( num * sizeof(char *));			//创建指向哈夫曼编码的指针数组
	Create_HufCode(sp, HufCode, num);
	free(sp);
	printf("\n\n");
	system("pause");
	return 0;
}
