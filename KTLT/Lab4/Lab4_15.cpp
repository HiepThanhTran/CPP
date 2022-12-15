#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	int pos;
	cout << "Nhap vao chuoi thu 1: ";
	getline(cin, s1);
	int n1 = s1.size();
	cout << "Nhap vao chuoi thu 2: ";
	getline(cin, s2);
	int n2 = s2.size();
	cout << "Chuoi s1 truoc khi chen: " << s1 << endl;
	cout << "Nhap vao vi tri can chen s2 vao s1: ";
	cin >> pos;
	if (pos < 1 || pos > n1)
	{
		s1.insert(pos - 1, s2);
		cout << "Chuoi s1 sau khi chen s2 vao: " << s1 << endl;
	}
	else
	{
		cout << "\nVi tri chen khong hop le!\n";
	}
	return 0;
}