#include <iostream>
using namespace std;
int main5() {
	double a;
	cout << "Dien tich luy cua ban la: ";
	cin >> a;
	if (a < 0 ||a > 10 ) {
		cout <<  "Khong hop le, xin nhap lai! ";
		
	}
	
	if (a >= 0) {
		if (a < 5) {
			cout << "Loai Yeu";
		}
		else if (a >= 5 && a < 6) {
			cout << "Loai Trung Binh";
		}
		else if (a >= 6 && a < 7) {
			cout << "Loai Trung binh Kha";
		}
		else if (a >= 7 && a < 8) {
			cout << "Loai Kha";
		}
		else if (a >= 8 && a < 9) {
			cout << "Loai Gioi";
		}
		else if (a >= 9 && a<=10) {
			cout << "Loai Xuat Sac";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}