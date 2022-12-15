#include <iostream>
#include <string>
using namespace std;
int main3() {
	string name;
	long songay, sotienluong1ngay, sotienluonglamduoc;
	cout << " Nhap ten cua ban: " << endl;
	getline(cin, name);
	cout << " Nhap so ngay lam: " << endl;
	cin >> songay;
	cout << " So tien luong 1 ngay la: " << endl;
	cin >> sotienluong1ngay;
	sotienluonglamduoc = sotienluong1ngay * songay;
	cout << name;
	cout << "So tien luong lam duoc la: " << sotienluonglamduoc << endl;
	system("pause");
	return 0;
}