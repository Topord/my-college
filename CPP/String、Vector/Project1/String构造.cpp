//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
////�ַ����Ĺ��캯��
//void test01()
//{
//	// 1�� string()������һ������Ϊ 0 �� string ����Ĭ�Ϲ��캯������
//	string s1; // ����һ������Ϊ 0 �� string ����
//	cout << "s1=" << s1 << endl; // ����� s1=
//	cout << "s1.capacity()=" << s1.capacity() << endl; // ���ص�ǰ���������Դ���ַ���������
//	cout << "s1.size()=" << s1.size() << endl; // �������������ݵĴ�С��cout << "������̬������׵�ַ=" << (void *)s1.c_str() << endl;
//	s1 = "xxxxxxxxxxxxxxxxxxxx";
//	cout << "s1.capacity()=" << s1.capacity() << endl; // ���ص�ǰ���������Դ���ַ���������
//	cout << "s1.size()=" << s1.size() << endl; // �������������ݵĴ�С��
//	cout << "������̬������׵�ַ=" << (void*)s1.c_str() << endl;
//
//	// 2�� string(const char *s)���� string �����ʼ��Ϊ s ָ��� NBTS��ת����������
//	string s2("hello world");
//	cout << "s2=" << s2 << endl; // ����� s2=hello world
//	string s3 = "hello world";
//	cout << "s3=" << s3 << endl; // ����� s3=hello world
//
//	// 3�� string(const string & str)���� string �����ʼ��Ϊ str���������캯������
//	string s4(s3); // s3 = "hello world";
//	cout << "s4=" << s4 << endl; // ����� s4=hello world
//	string s5 = s3;
//	cout << "s5=" << s5 << endl; // ����� s5=hello world
//
//	// 4�� string(const char* s, size_t n)���� string �����ʼ��Ϊ s ָ��� NBTS ��ǰ n ���ַ�����ʹ������ NBTS ��β��
//	string s6("hello world", 5);
//	cout << "s6=" << s6 << endl; // ����� s6=hello
//	cout << "s6.capacity()=" << s6.capacity() << endl; // ���ص�ǰ���������Դ���ַ���������
//	cout << "s6.size()=" << s6.size() << endl; // �������������ݵĴ�С��
//	string s7("hello world", 50);
//	cout << "s7=" << s7 << endl; // ����� s7=hello δ֪����
//	cout << "s7.capacity()=" << s7.capacity() << endl; // ���ص�ǰ���������Դ���ַ���������
//	cout << "s7.size()=" << s7.size() << endl; // �������������ݵĴ�С��
//
//	// 5�� string(const string & str, size_t pos = 0, size_t n = npos)��
//	// �� string �����ʼ��Ϊ str ��λ�� pos ��ʼ����β���ַ������λ�� pos ��ʼ�� n ���ַ���
//	string s8(s3, 3, 5); // s3 = "hello world";
//	cout << "s8=" << s8 << endl; // ����� s8=lo wo
//	string s9(s3, 3);
//	cout << "s9=" << s9 << endl; // ����� s9=lo world
//	cout << "s9.capacity()=" << s9.capacity() << endl; // ���ص�ǰ���������Դ���ַ���������
//	cout << "s9.size()=" << s9.size() << endl; // �������������ݵĴ�С��
//	string s10("hello world", 3, 5);
//	cout << "s10=" << s10 << endl; // ����� s10=lo wo
//	string s11("hello world", 3); // ע�⣺�����ù��캯�� 5���������ù��캯��4��
//	cout << "s11=" << s11 << endl; // ����� s11=hel
//	// 6�� template<class T> string(T begin, T end)���� string �����ʼ��Ϊ����[begin, end]�ڵ��ַ���
//	// ���� begin �� end ����Ϊ����ָ�룬����ָ��λ�ã���Χ���� begin ���ڣ���������end��
//	// 
//	// 7�� string(size_t n, char c)������һ���� n ���ַ� c ��ɵ� string ����
//	string s12(8, 'x');
//	cout << "s12=" << s12 << endl; // ����� s12=xxxxxxxx
//	cout << "s12.capacity()=" << s12.capacity() << endl; // s12.capacity()=15
//	cout << "s12.size()=" << s12.size() << endl; // s12.size()=8
//	string s13(30, 0);
//	cout << "s13=" << s13 << endl; // ����� s13=
//	cout << "s13.capacity()=" << s13.capacity() << endl; // s13.capacity()=31
//	cout << "s13.size()=" << s13.size() << endl; // s12.size()=30
//}
//
////string�ռ������
//void test02()
//{
//	char cc[8]; // ��ջ�Ϸ��� 8 �ֽڵ��ڴ�ռ䡣
//	// �� cc ���ڴ�ռ������ַ�����
//	strcpy(cc, "hello");
//	cout << "cc=" << cc << endl << endl;
//	// �� cc ���ڴ�ռ����� int ��������
//	int* a, * b; a = (int*)cc; // ǰ 4 ���ֽڵĿռ��������� a��
//	b = (int*)cc + 4; // �� 4 ���ֽڵĿռ��������� b��
//	*a = 12345;
//	*b = 54321;
//	cout << "*a=" << *a << endl;
//	cout << "*b=" << *b << endl << endl;
//	// �� cc ���ڴ�ռ����� double��
//	double* d = (double*)cc;
//	*d = 12345.7;
//	cout << "*d=" << *d << endl << endl;
//	// �� cc ���ڴ�ռ����ڽṹ�塣
//	struct stt
//	{
//		int a;
//		char b[4];
//	}*st;
//	st = (struct stt*)cc;
//	st->a = 38;
//	strcpy(st->b, "abc");
//	cout << "st->a=" << st->a << endl;
//	cout << "st->b=" << st->b << endl;
//	// void* malloc(size_t size);
//	//char* cc1 = (char*)malloc(8);
//	//int* cc1 = (int*)malloc(8);
//}
////int main()
////{
////	//test01();
////	test02();
////
////	return 0;
////}