#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//fscanf()��ȡ���ո�
//fgets()��ȡ����\n��ֹͣ�������ļ�ָ�뻻�� 
//fgets()�ڶ�ȡANSI����ʱ����,��ȡUTF-8ʱ������
//fgetc()�ڶ�ȡUTF-8ʱ���ԣ���ȡANSI����ʱΪ���� 
struct WordNode
{
	char letter;
	int Count;
};
//typedef WordNode word;
int main()
{
	int cnt = 1, len = 0;
	FILE *fp = NULL;
	char buff[255];

	fp = fopen("�������壨ԭ��.txt", "r");  //�������壨ԭ��ΪUTF-8���� 

	fgets(buff, 255, (FILE*)fp);
	
	printf("%d: %s\n", cnt, buff);
	len = strlen(buff);
	printf("%d\n", len);

	

	fclose(fp);

return 0;
}
