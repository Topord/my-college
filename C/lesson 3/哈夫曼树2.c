#include<stdio.h>
#include<stdlib.h>
typedef unsigned int Uint;
typedef struct Node{
	Uint weight,father,lson,rson;
}* Hf;
void Init_hf(Hf s,Uint n,Uint num[]){
	int i;
	for(i=0;i<2*n-1;i++){
		if(i<n)
			(s+i)->weight=num[i];
		else
			(s+i)->weight=0;
		(s+i)->lson=0;
		(s+i)->rson=0;
		(s+i)->father=0;
	}
}
void Creat_hf(Hf s,Uint q){
	int n, i;
	for(n=q;n<2*q-1;n++)
	{
		Uint j=1000,k=1,m=1000,p=1;
		for(i=0;i<n;i++){
			if((s+i)->father==0)
			{
				if(j>=((s+i)->weight)){
					j=((s+i)->weight);
					k=i;
				}
			}
		}
		(s+k)->father=n;
		(s+n)->lson=k;
		for(i=0;i<n;i++){
			if((s+i)->father==0){
				if(m>=((s+i)->weight)){
					m=((s+i)->weight);
					p=i;
				}
			}
		}
		(s+p)->father=n;
		(s+n)->rson=p;
		(s+n)->weight=j+m;		
	}
}
int main()
{
	int i;
	printf("请输入你要输入的节点的数量:\n");
	Uint N;
	scanf("%u",&N);
	Uint num[N];
	printf("请输入节点:\n");
	for(i=0;i<N;i++)
		scanf("%u",num+i);
	Hf ps=(Hf)malloc(sizeof(struct Node)*(2*N-1));
	Init_hf(ps,N,num);
	Creat_hf(ps,N);
	for(i=0;i<2*N-1;i++)
		printf("第%d个节点:\t%-8d%-8d%-8d%-8d\n",i,(ps+i)->weight,(ps+i)->father,(ps+i)->lson,(ps+i)->rson);
	return 0;
}
