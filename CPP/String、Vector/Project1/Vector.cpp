#include<iostream>
#include<vector>
using namespace std;

//vector�Ĺ��캯��
void test01()
{
	vector<int> v1;
	v1 = { 1,2,3,4,5 }; // ʹ��ͳһ��ʼ���б�ֵ��
	for (int ii = 0; ii < v1.size(); ii++) cout << v1[ii] << " ";
	cout << endl;
	
	vector<int> v2;
	v2 = v1; // ������ v1 ��ֵ����ǰ������
	for (int ii = 0; ii < v2.size(); ii++) cout << v2[ii] << " ";
	cout << endl;

	vector<int> v3;
	v3.assign({ 1,2,3,4,5 }); // �� assign()��������ǰ������ֵ��������ͳһ��ʼ���б�
	for (int ii = 0; ii < v3.size(); ii++) cout << v3[ii] << " ";
	cout << endl;
}
//vector��Ƕ��
void test02()
{
	vector<vector<int>> vint;
	vector<int> v1;
	vector<int> v2;
	vector<vector<string>> vstring;
	vector<string> v3;
	vector<string> v4;

	v1 = { 1, 2, 49, 23, 12, 43, 13 };
	v2 = { 1, 9, 3, 1, 3, 13 };
	v3 = { "first", "peter", "jason", "purple" };
	v4 = { "leo", "hello", "world"};

	//vint����
	vint.emplace_back(v1);
	vint.emplace_back(v2);
	for (int i = 0; i < vint.size(); i++) {
		cout << "this is (int)v" << i << ":" << endl;
		for (int j = 0; j < vint[i].size(); j++) {
			cout << " " << vint[i][j];
		}
		cout << endl;
	}
	//vstring����
	vstring.emplace_back(v3);
	vstring.emplace_back(v4);
	for (int i = 0; i < vstring.size(); i++) {
		cout << "this is (string)v" << i + 2 << ":" << endl;
		for (int j = 0; j < vstring[i].size(); j++) {
			cout << " " << vstring[i][j];
		}
		cout << endl;
	}
}

int main()
{
	//test01();
	test02();

	return 0;
}