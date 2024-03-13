#include <stdio.h>
//fscanf()读取至空格处
//fgets()读取至有\n处停止，并将文件指针换行 
int main()
{
   FILE *fp = NULL;
   char buff[255];
 
   fp = fopen("test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1: %s\n", buff );
 
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);
   printf("4: %s\n", buff );
   fclose(fp);
 
}
