#include<stdio.h>
#include<stdlib.h>
typedef unsigned int Uint;
struct Node
{
    Uint weight;		//结点权值； unsigned 更节省空间，2字节
    Uint parent;		//指向父结点的指针
    Uint lChild;		//指向左孩子结点的指针
    Uint rChild;		//指向右孩子结点的指针
    struct Node *next;  //指向下一个节点的指针 
};
typedef struct Node * Pointer;

/*
功能：将数据填入哈夫曼树中 
参数：p->链表的首地址， 
算法： 无 
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
功能：将链表内容输出并打印 
参数：p-->链表首地址，len-->链表长度 
算法： 无 
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
功能：找到第n个结点前的最小权重和次小权重孤儿结点号
参数：p->链表地址；w->两元素的整形数组首址；n->查找范围
算法： 4次扫描法(第1、2次扫描找到最小权重值，第3、4次扫描找到次小权重值)
*/
void get_two_min(Pointer p, int * w, int n)	
{
	Pointer head, q;
	head = q = p;
	int i, j, t, *min, *vice_min;	
	min = w; vice_min = w + 1;//min指向最小数序号存放单元，即数组首元素；vice_min次小数指针

	//第1次扫描：找到首个孤儿结点，将其锁定为首个最小权重结点
	for (i = 0; i < n; i++)	
	{ 
        if(p->parent == -1)		
        {
            *min = i;
            break;
        }
        
        p = p->next; 
	}
	//第2次扫描：找出权值最小的单节点
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
 	//第3次扫描：找到首个没被min指定的孤儿结点，将其锁定为首个次小结点
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
    //第4次扫描：找出权值次小的单节点
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
功能：构造最优树 
参数：p->链表首地址;len->链表长度;min->存放最小元素的地址的数组 
算法：无 
*/ 
void CreateTree(Pointer p, int len, int* min)
{
	int i, j;
	Pointer m, n, q, head;
	m = n = q = head = p;               //用m和n来表示有最小值和次小值的节点的位置 
	for(i = len; i < 2*len - 1; i++){
		if(i <= 7)
		{
			get_two_min(p, min, i);		    //获取最小权值的两个孤结点
			printf("i = %d\n", i);
			printf("最小 = %d\n", min[0]);
			printf("次小 = %d\n", min[1]);
			for(j = 0; j < min[0]; j++){	//最小权重叶子结点填写父指针
				p = p->next; 
			}
			m = p; p->parent = i; p = head;
			for(j = 0; j < min[1]; j++){	//次小权重叶子结点填写父指针
				p = p->next; 
			}
			n = p; p->parent = i; p = head;
			for(j = 0; j < i; j++){			//当前父结点填写左孩子
				p = p->next; 
			}
			p->lChild = min[0]; p = head;
			for(j = 0; j < i; j++){			//当前父结点填写右孩子
				p = p->next; 
			}
			p->rChild = min[1]; p = head;		
			for(j = 0; j < i; j++){			//当前父结点填写权重值
				p = p->next; 
			}
			p->weight = m->weight + n->weight; p =head;
			}
		else
		{									//最后一次不进行比较，直接相加 
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

int main()
{
	int i, j, lenth;
	int min[2] = {0};			//min[0]装最小权重结点号，min[1]装次小权重结点号
	Pointer p, head, m, n, q;
	Uint num[]={6,2,7,4,5};							//叶子结点权重值
	lenth = sizeof(num)/sizeof(num[0]);			//求数组的元素个数
	head = p = q = (Pointer)malloc(sizeof(struct Node));	//创建空哈夫曼树数组2n-1个元素
	Init_HufTree(p, num, lenth);
	p = head;
	printf("--------------------初始状态的哈夫曼树为--------------------\n");
	Print(p, lenth);
	p = head;
	printf("--------------------构建完成的哈夫曼树为--------------------\n");
	CreateTree(p, lenth, min);
    p = head;
	Print(p, lenth);

	free(head);
	return 0;
}
