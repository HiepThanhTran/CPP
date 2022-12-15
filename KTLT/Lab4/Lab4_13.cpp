#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cout << "Nhap vao 1 chuoi: ";
	getline(cin, s);
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i' ||
			s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I')
		{
			for (int j = i; j < n; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
		}
	}
	cout << "Chuoi sau khi xoa cac nguyen am: " << s << endl;
	return 0;
}