#include<stdio.h>
#include<string.h>
int main()
{
	char a[] = "abcd";
	char b[] = "abcda";
	char c[] = "12";
	char d[] = "34";
	char m = '1';
	char n = '0';
	char s[100] = {0};
	s[0] = m;
	s[1] = n;
	printf("%s\n", strcat(c, d));
	printf("%s\n", s);
	printf("%d", strcmp(a, b));
	return 0;
}
//strcmp--->相同为0,不相同为-1
// 
