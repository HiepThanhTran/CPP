#include <iostream>
#include <string>

using namespace std;

int main12()
{
	string s;
	cout << "Nhap 1 chuoi bat ky: ";
	getline(cin, s);
	cout << "Chuoi vua nhap co " << s.length() << " ky tu (ke ca khoang trang)";
	system("pause");
	return 0;
}
