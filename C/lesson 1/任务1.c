#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int main()
{
	int i, j, a;
	int *p, *q;
	int tmp;
	srand((unsigned)time(NULL));
	//����
	q = p = (int *)malloc(sizeof(int)*10);
	//��ֵ 
	for(i = 0; i < 10; i++){
		*(p+i) = rand()%100;
	}
	//��ʾ 
	for(i = 0; i < 10; i++){
		printf("%d\t", *(p+i));
	}
	printf("\n");
	//����
	 for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(*(p + i) < *(p + j)){
				tmp = *(p + j);
				*(p + j) = *(p + i);
				*(p + i) = tmp;
			}
		}
	}
	//��ʾ����� 
	for(i = 0; i < 10; i++){
		printf("%d\t", *(p + i));
	}
	free(q);
	return 0;
}
