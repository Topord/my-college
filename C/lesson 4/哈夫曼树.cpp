/*新知识点：【警告】不允许程序截图，不建议回看（建议：弄清算法，做笔记，按自己的方法编程）
0.数据结构是学什么的
1.树，二叉树
2.哈夫曼树（最优树）、带权路径长度WPL、构建哈夫曼树的算法（6，2，7，4，5）并计算其WPL
3.哈夫曼树的结点总数2n-1
4.哈夫曼树的存储结构及代码实现
5.函数中的地址传递与多值返回（基本功）
6.指针中的（地址+偏移量）的含义与用法
7.如何界定子函数的功能、参数与返回值
8.复杂编程中的工程方法---扩展编程法与关键变量显示法，忌讳一编到底的新手风格
9.子函数的位置与代码风格，子函数的描述文档，程序的通俗注释，学习编程的自我心态
*/
//任务1：手工构建叶子结点为（4，2，8，12，6，9）的哈夫曼树，并计算其带权路径长度（拍照提交）
//任务2：构建一个6叶子的哈夫曼树，并显示出来，要求有创建子函数。
//任务3：证明哈夫曼树的结点总数是2n-1个，能默写证明过程
#include<stdio.h>
#include<stdlib.h>

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

void Init_HufTree(Huf_Node p,Uint * w,int sum,int n)		
//初始化哈夫曼树，将权重值置0和指针置-1
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
		p->weight=*w;   //*是&的逆运算，取单元运算
		p++;
		w++;
	}
}

void get_two_min(Huf_Node p,int * w,int n)	
//找到第n个结点前的最小权重和次小权重孤儿结点号
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
    //如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
        if((p+i)->weight < (p + *min)->weight)//此结点的父亲为空，则进入if
        {
        	if((p+i)->parent == -1)
        	{
				*min = i;
       	 	}
        	
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


int main()
{
	int i,*p,num,tmp=0;
	int min[2];			//min[0]装最小权重结点号，min[1]装次小权重结点号
	Huf_Node sp;
	Uint leaf_weight[]={6,2,7,4,5};							//叶子结点权重值
	num=sizeof(leaf_weight)/sizeof(leaf_weight[0]);			//求数组的元素个数
	sp=(Huf_Node)malloc((2*num - 1) * sizeof(struct Node));	//创建空哈夫曼树数组2n-1个元素
	Init_HufTree(sp,leaf_weight,2*num - 1,num);				//初始化哈夫曼树
	printf("\n\n------------------------初始状态的哈夫曼树为：----------------------------\n");
	Print_HufTree(sp,2*num - 1);							//显示全部的哈夫曼树
	printf("\n\n------------------------构建完成的哈夫曼树为：----------------------------\n");
	for(i=num;i<2*num - 1;i++)  //num --> 5~9
	{
		get_two_min(sp,min,i);		    //获取最小权值的两个孤结点
		(sp+min[0])->parent=i;			//最小权重叶子结点填写父指针
		(sp+min[1])->parent=i;			//次小权重叶子结点填写父指针
		(sp+i)->lChild=min[0];			//当前父结点填写左孩子
		(sp+i)->rChild=min[1];			//当前父结点填写右孩子
		(sp+i)->weight=(sp+min[0])->weight+(sp+min[1])->weight;//当前父结点填写权重值
	}
	Print_HufTree(sp,2*num - 1);							//显示全部的哈夫曼树
	printf("\n\n");
	free(sp);

	return 0;
}
