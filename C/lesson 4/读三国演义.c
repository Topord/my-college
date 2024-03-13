#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//fscanf()读取至空格处
//fgets()读取至有\n处停止，并将文件指针换行 
//fgets()在读取ANSI编码时可以,读取UTF-8时是乱码
//fgetc()在读取UTF-8时可以，读取ANSI编码时为乱码 
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

	fp = fopen("三国演义（原）.txt", "r");  //三国演义（原）为UTF-8编码 

	fgets(buff, 255, (FILE*)fp);
	
	printf("%d: %s\n", cnt, buff);
	len = strlen(buff);
	printf("%d\n", len);

	

	fclose(fp);

return 0;
}
