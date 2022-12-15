#include <iostream>
using namespace std;
int main7() {
	int thang;
	cout << "Nhap thang: ";
	cin >> thang;
	if (thang == 1 || thang == 3 || thang == 5 || thang== 7 || thang== 8 || thang== 10 || thang ==12) {
		cout << "so ngay cua thang " << thang << "la 31 ngay";
	}
	else if (thang == 4 || thang ==6 || thang== 9 || thang ==11) {
		cout << "so ngay cua thang " << thang << "la 30 ngay";
	}
	else if (thang == 2) {
		cout << "so ngay cua thang " << thang << "la 28 hoac 29 ngay";
	}
	else {
		cout << "khong hop le!";
	}
	system("pause");
	return 0;
}