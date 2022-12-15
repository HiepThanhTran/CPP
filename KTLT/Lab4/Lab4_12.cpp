#include<iostream>
#include<string>
using namespace std;

string daoNguocChuoi(string s)
{
	int len = s.size();
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}
	return s;
}
int main()
{
	string s;
	cout << "Nhap vao 1 chuoi: ";
	getline(cin, s);
	cout << "Chuoi sao khi dao nguoc: " << daoNguocChuoi(s) << endl;
	return 0;
}