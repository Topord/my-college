#include <stdio.h>
#include <string.h>
// ���÷������ȼ�
int compareReturn(char str1) {
    if (str1 == '#') {
        return 0;
    } else if (str1 == '+' || str1 == '-') {
        return 1;
    } else if (str1 == '*' || str1 == '/') {
        return 2;
    } else if (str1 == '(' || str1 == ')') {
        return 0;
    }
    else {
        // ��ʱΪ����
        return -1;
    }
}
#include <stdio.h>
int main (void) {
    char s1[100];
    int top1 = -1;
    int s2[100];
    char top2 = -1;
    char str[100];
//    char ans;
    printf("��������׺���ʽ\n");
    scanf("%s", str);
    int length = (int)strlen(str);
    for (int i = 0; i < length; ) {
        if (compareReturn(str[i]) == -1) {
            s1[++top1] = str[i++];
        } else if (str[i] == '(') {
            s2[++top2] = str[i++];
        } else if (str[i] == ')') {
            while (compareReturn(s2[top2]) != 0) {
                s1[++top1] = s2[top2--];
            }
            top2--;
            i++;
        } else {
            if (top2 == -1 || compareReturn(s2[top2]) < compareReturn(str[i])) {
                s2[++top2] = str[i++];
            } else {
                s1[++top1] = s2[top2--];
            }
            if (str[i] == '#') {
                break;
            }
        }
    }
//    printf("%d", top2);
    for (int i = 0; i < top1 + 1; i++) {
        printf("%c#", s1[i]);
    }
}


