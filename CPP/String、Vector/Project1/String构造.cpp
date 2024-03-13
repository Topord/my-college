//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
////字符串的构造函数
//void test01()
//{
//	// 1） string()：创建一个长度为 0 的 string 对象（默认构造函数）。
//	string s1; // 创建一个长度为 0 的 string 对象
//	cout << "s1=" << s1 << endl; // 将输出 s1=
//	cout << "s1.capacity()=" << s1.capacity() << endl; // 返回当前容量，可以存放字符的总数。
//	cout << "s1.size()=" << s1.size() << endl; // 返回容器中数据的大小。cout << "容器动态数组的首地址=" << (void *)s1.c_str() << endl;
//	s1 = "xxxxxxxxxxxxxxxxxxxx";
//	cout << "s1.capacity()=" << s1.capacity() << endl; // 返回当前容量，可以存放字符的总数。
//	cout << "s1.size()=" << s1.size() << endl; // 返回容器中数据的大小。
//	cout << "容器动态数组的首地址=" << (void*)s1.c_str() << endl;
//
//	// 2） string(const char *s)：将 string 对象初始化为 s 指向的 NBTS（转换函数）。
//	string s2("hello world");
//	cout << "s2=" << s2 << endl; // 将输出 s2=hello world
//	string s3 = "hello world";
//	cout << "s3=" << s3 << endl; // 将输出 s3=hello world
//
//	// 3） string(const string & str)：将 string 对象初始化为 str（拷贝构造函数）。
//	string s4(s3); // s3 = "hello world";
//	cout << "s4=" << s4 << endl; // 将输出 s4=hello world
//	string s5 = s3;
//	cout << "s5=" << s5 << endl; // 将输出 s5=hello world
//
//	// 4） string(const char* s, size_t n)：将 string 对象初始化为 s 指向的 NBTS 的前 n 个字符，即使超过了 NBTS 结尾。
//	string s6("hello world", 5);
//	cout << "s6=" << s6 << endl; // 将输出 s6=hello
//	cout << "s6.capacity()=" << s6.capacity() << endl; // 返回当前容量，可以存放字符的总数。
//	cout << "s6.size()=" << s6.size() << endl; // 返回容器中数据的大小。
//	string s7("hello world", 50);
//	cout << "s7=" << s7 << endl; // 将输出 s7=hello 未知内容
//	cout << "s7.capacity()=" << s7.capacity() << endl; // 返回当前容量，可以存放字符的总数。
//	cout << "s7.size()=" << s7.size() << endl; // 返回容器中数据的大小。
//
//	// 5） string(const string & str, size_t pos = 0, size_t n = npos)：
//	// 将 string 对象初始化为 str 从位置 pos 开始到结尾的字符，或从位置 pos 开始的 n 个字符。
//	string s8(s3, 3, 5); // s3 = "hello world";
//	cout << "s8=" << s8 << endl; // 将输出 s8=lo wo
//	string s9(s3, 3);
//	cout << "s9=" << s9 << endl; // 将输出 s9=lo world
//	cout << "s9.capacity()=" << s9.capacity() << endl; // 返回当前容量，可以存放字符的总数。
//	cout << "s9.size()=" << s9.size() << endl; // 返回容器中数据的大小。
//	string s10("hello world", 3, 5);
//	cout << "s10=" << s10 << endl; // 将输出 s10=lo wo
//	string s11("hello world", 3); // 注意：不会用构造函数 5），而是用构造函数4）
//	cout << "s11=" << s11 << endl; // 将输出 s11=hel
//	// 6） template<class T> string(T begin, T end)：将 string 对象初始化为区间[begin, end]内的字符，
//	// 其中 begin 和 end 的行为就像指针，用于指定位置，范围包括 begin 在内，但不包括end。
//	// 
//	// 7） string(size_t n, char c)：创建一个由 n 个字符 c 组成的 string 对象。
//	string s12(8, 'x');
//	cout << "s12=" << s12 << endl; // 将输出 s12=xxxxxxxx
//	cout << "s12.capacity()=" << s12.capacity() << endl; // s12.capacity()=15
//	cout << "s12.size()=" << s12.size() << endl; // s12.size()=8
//	string s13(30, 0);
//	cout << "s13=" << s13 << endl; // 将输出 s13=
//	cout << "s13.capacity()=" << s13.capacity() << endl; // s13.capacity()=31
//	cout << "s13.size()=" << s13.size() << endl; // s12.size()=30
//}
//
////string空间的运用
//void test02()
//{
//	char cc[8]; // 在栈上分配 8 字节的内存空间。
//	// 把 cc 的内存空间用于字符串。
//	strcpy(cc, "hello");
//	cout << "cc=" << cc << endl << endl;
//	// 把 cc 的内存空间用于 int 型整数。
//	int* a, * b; a = (int*)cc; // 前 4 个字节的空间用于整数 a。
//	b = (int*)cc + 4; // 后 4 个字节的空间用于整数 b。
//	*a = 12345;
//	*b = 54321;
//	cout << "*a=" << *a << endl;
//	cout << "*b=" << *b << endl << endl;
//	// 把 cc 的内存空间用于 double。
//	double* d = (double*)cc;
//	*d = 12345.7;
//	cout << "*d=" << *d << endl << endl;
//	// 把 cc 的内存空间用于结构体。
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