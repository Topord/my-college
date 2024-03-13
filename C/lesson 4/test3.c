#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//���ʽڵ�
struct WordNode
{
    char* word;//���浥�ʵ��ַ���
    int count;//�õ��ʵ���Ŀ
    struct WordNode* next;//��һ�����ʽڵ�
};
 
//��������
struct WordList
{
   struct WordNode* first;//����������׽ڵ�
   struct WordNode* last;//���������ĩ�ڵ�
   int nodeCount; //���ʽڵ����Ŀ
};
//��ӡ�ʻ��max_numΪ��ӡ�ʻ�ĸ����������-1����ȫ����ӡ
void PrintWordList(struct WordList* wordlist, int max_num);
 
//�ʻ������isAscend=trueΪ�������򣬷���Ϊ��������
void SortWordList(struct WordList* wordlist, bool isAscend);
 
//�Ӵʻ���в���ĳ���ʻ㣬wordΪҪ���ҵĴʻ㣬����ʻ���ڱ��У��򷵻ظôʻ�Ľڵ�ָ�룬���򷵻�NULL
struct WordNode* FindWord(struct WordList* wordlist, const char* word);
 
//���ļ��ж�ȡ�ַ��������浽�ַ����У�wordsΪ�����ַ�����ַ��countָ����ȡ�ַ����������������ֵΪʵ�ʶ�ȡ���ַ�����
int ReadWordsFromFile(FILE* fp, char* words, int count);
 
//�ʻ�ͳ�ƣ�wordsΪ�Ѿ������˴ʻ���ַ�����wordlistΪ��Ҫ���ɵĴʻ��flag���Ϊtrue���ʾ���ִ�Сд��Ϊfalse�����ִ�Сд��
void WordsStatistic(const char* words, struct WordList* wordlist,bool flag);
 
//���ַ����ж�ȡһ�����ʣ�startΪԴ�ַ���words�Ŀ�ʼλ���±꣬end�������ն�ȡһ�����ʺ�words���±ꡣ����ֵΪ���ʵĳ��ȣ��������-1����ʾ�Ѿ��������еĵ��ʡ�
int ReadWordFromString(const char* words, int start, int* end, char* word);
 
//�ͷŴʻ����ڴ�ռ�
void FreeWordList(struct WordList wordlist);
int main()
{
    char* words;
    FILE* fp;
    fp = fopen("GBK test.txt", "r");
 
    //��ȡ�ļ����ֽ���
    int file_size;
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
 
    //�����ļ�ָ�뵽��ͷ
    fseek(fp, 0, SEEK_SET);
 
    //���ļ��ж�ȡ���ʵ��ַ���
    words = (char*)malloc(file_size + 1);
    ReadWordsFromFile(fp, words, file_size);
 
    //��ӡԭ�� 
    printf("ԭ�ģ�\n");
    printf("%s\n", words);
 
    //����Ƶ��ͳ�ƣ������ִ�Сд
    struct WordList wordlist;
    wordlist.first = NULL;
    wordlist.last = NULL;
    wordlist.nodeCount = 0;
    WordsStatistic(words, &wordlist,false);//false��ʾ�����ִ�Сд
 
    //��ӡ�ʻ��б�ȫ����ӡ
    printf("��Ƶͳ�Ʊ�\n");
    PrintWordList(&wordlist,-1);//-1λ��ӡȫ������ڵ�
 
    //�ʻ�����򣬽�������
    SortWordList(&wordlist,false);//false��ʾ��������
 
    //��ӡƵ����ߵ�10������
    printf("��Ƶ�ʻ㣺\n");
    PrintWordList(&wordlist,10);
 
    fclose(fp);
    free(words);
    FreeWordList(wordlist);
    getchar();
    return 0;
}
//���ļ��ж�ȡ�����ֽڵĵ��ʡ�
//fp:�ǿյ��ļ�ָ��
//words:�������������ļ����ַ���
//count:���ļ��ж�ȡ���ֽ���������ò��������ļ�ʵ�ʵ��ֽ�������ȥȡȫ�����ֽ�
int ReadWordsFromFile(FILE* fp, char* words, int count)
{
	int i;
    //��ȡ�ļ����ֽ���
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
 
    //��ʼ��ȡ�ַ�
    fseek(fp, 0, SEEK_SET);
    int buffer_len = count;
    if (count > file_size)buffer_len = file_size;
    for (i = 0; i < buffer_len; i++)
    {
        char ch;
        fread(&ch, 1, 1, fp);
        words[i] = ch;
    }
    //�ַ�����β
    words[buffer_len] = '\0';
    return buffer_len;
}
//���ַ����ж�ȡһ������,��Ϊÿ��ֻ�ܶ�ȡһ�����ʣ�����Ϊ���ܹ����������ַ�������ȡ��һ��
//����֮�󣬾ͷ��ص�ǰ��ָ��λ�ã��´ζ�ȡһ�����ʣ�ָ��ʹӴ˿�ʼ�����������ļ��Ķ�ȡ��
//words:����Ӣ�Ķ�����ַ���
//start:���ַ��������λ�ÿ�ʼ��ȡһ������
//end:���շ��ص�ָ��λ��
//word:j���ն����ĵ���
//����ֵ�����ض����ĵ��ʵĳ��ȣ�-1��ʾ�Ѿ����˽�β��0��ʾû�ж�ȡ������
int ReadWordFromString(const char* words, int start, int* end, char* word)
{
    char ch;
    int count = 0;//���ʵĳ���
 
    *end = start;
    while (true)
    {
        ch = words[*end];
        (*end)++;
        if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))//�����˭������ĸ�����ȡΪ���ʵ�һ����
        {
            word[count] = ch;
            count++;
        }
        else if (ch == '\0') return -1;//��������ַ���ĩβ���򷵻ؽ�����־-1
        else break;//����ַ��Ǳ�㡢�ո񡢻��еȷ���ĸ���������ַ������жϣ���ʾ�Ѿ����һ�����ʵĶ�ȡ
    }
    word[count] = '\0';
    return count;
}
//�ӵ����б��в��ҵ��ʣ�����ҵ�ָ���ĵ��ʣ��򷵻ظõ��ʵĽڵ�ָ�룬���򷵻�NULL
//wordlist:��������
//word:Ҫ���ҵĵ���
struct WordNode* FindWord(struct WordList* wordlist, const char* word)
{
 
 	int i;
    int count = wordlist->nodeCount;
    struct WordNode* node = wordlist->first;
    //���취�������������������Ƿ����ָ���ĵ���
    for (i = 0; i < count; i++)
    {
        if (strcmp(word, node->word) == 0)return node;
        node = node->next;
    }
 
    return NULL;
}
 
//ͳ�Ƶ��ʲ����ɵ����б�
//words:����Ӣ�������ַ���
//wordlist��һ���յĵ����б�
//flag:ָʾ�Ƿ����ִ�Сд�����Ϊtrue,�������ִ�Сд��false���ǲ����ִ�Сд
void WordsStatistic(const char* words, struct WordList* wordlist,bool flag )
{
    int start = 0, end;
    while (true)
    {
        char word[100] = { '\0' };//һ��û�е��ʳ���100����ĸ�İɣ����Զ���100�ֽڵ������㹻��
        int word_len, i;
        word_len = ReadWordFromString(words, start, &end, word);//���ַ����ж�ȡһ������
        start = end;
        if (word_len == -1)break;//�ַ����Ѿ����˽�β����ʾ�����Ѿ������꣬����ֹͣ��ȡ����
        if (word_len == 0)continue;//û�ж�ȡ�����ʣ��������ٴζ�ȡ
        
        //�����ִ�Сд�Ļ���Is ��is����Ϊ��ͬһ�����ʣ����򽫵���ȫ����ΪСд����Is��Ϊis��
        if (flag==false)for (i = 0; i < word_len; i++)
        {
            if (word[i] >= 65 && word[i] <= 90)word[i] = word[i] + (char)32;
        }
      
        struct WordNode* node;
        node = FindWord(wordlist, word);//��ȡ��һ�����ʣ�����������������Ƿ��ڵ��������У�������򷵻ظõ��ʵĽڵ�ָ��
        if (node == NULL)//������������в����ڸõ��ʣ��򽫸õ�����ӽ�ȥ������
        {
            struct WordNode* word_node = (struct WordNode*)malloc(sizeof(struct WordNode));//����һ�����ʽڵ�
            int word_len = strlen(word);
            word_node->word = (char*)malloc(word_len + 1);//Ϊ���ʽڵ��word��Ա����ռ�
            word_node->word[word_len] = '\0';
            word_node->count = 1;
            strcpy(word_node->word, word);//�����ʸ��Ƶ����ʽڵ���
            word_node->next = NULL;
 
            if (wordlist->first == NULL)//�����������Ϊ�գ���������²���
            {
                wordlist->nodeCount = 1;
                wordlist->first = word_node;
                wordlist->last = word_node;
            }
            else//�����б�λ�գ���������²���
            {
                wordlist->last->next = word_node;
                wordlist->last = word_node;
                wordlist->nodeCount++;
            }
        }
        else//��������Ѿ����ڵ����б��У��򽫸õ��ʵ���Ŀ��1
        {
            node->count++;
        }
    }
}
//��ӡ�����б��ǰ
//wordlist:�����б�
//max_num����ӡ���ʽڵ����������������-1�����ʾ��ӡ���������������max_num���������ʵ�ʳ��ȣ�Ҳ��ӡȫ������ڵ㡣
void PrintWordList(struct WordList* wordlist, int max_num)
{
	int i;
    struct WordNode* node = wordlist->first;
    int n = max_num;
    if (max_num == -1 || max_num > wordlist->nodeCount)n = wordlist->nodeCount;
    //����������ӡ
    for (i = 0; i < n; i++)
    {
        printf("%s��%d\n", node->word, node->count);
        node = node->next;
    }
}
//������������ð�����򣬿��ǵ�WordNode�ĳ�Ա���Ƚ��٣�ֱ�Ӳ���ֵ�����ķ���������������ڵ�ָ��Ľ���
//wordlist:��������
//isAscend���Ƿ���������trueΪ��������falseΪ��������
void SortWordList(struct WordList* wordlist, bool isAscend)
{
	int i, j;
    struct WordNode* p;
 
    if (wordlist->nodeCount <= 1)return;//�����������ĳ���С��1��ֱ�ӽ�������
 
    for (i = wordlist->nodeCount - 1; i > 0; i--)
    {
        p = wordlist->first;
        for (j = 0; j < i; j++)
        {
            if ((isAscend && p->count > p->next->count) || (!isAscend && p->count < p->next->count))
            {
                char* s;
                int c;
                s = p->word;
                c = p->count;
                p->word = p->next->word;
                p->count = p->next->count;
                p->next->word = s;
                p->next->count = c;
            }
            p = p->next;
        }
    }
 
}
//�ͷŵ����б�
void FreeWordList(struct WordList wordlist)
{
	int i;
    struct WordNode* cur, * next;
    cur = wordlist.first;
    for (i = 0; i < wordlist.nodeCount; i++)
    {
        next = cur->next;
        free(cur->word);//�ͷ�word��Աָ����ڴ�
        free(cur);//�ͷŽڵ���ڴ�
        cur = next;
    }
}
