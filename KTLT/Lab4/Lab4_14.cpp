#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	char c;
	int count = 0;
	cout << "Nhap vao 1 chuoi: ";
	getline(cin, s);
	int n = s.size();
	cout << "Nhap vao 1 ki tu: ";
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)
			count++;
	}
	cout << "Ky tu " << c << " xuat hien trong chuoi [" << s << "] " << count << " lan\n";
	return 0;
}