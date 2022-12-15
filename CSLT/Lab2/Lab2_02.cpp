#include <iostream>
using namespace std;
int main() {
	double a = 0, b=0; 
	double dientich = 0, chuvi = 0;
	cout << "Nhap do dai canh hv: ";
	cin >> a;
	if (a < 0) {
		cout << "Khong the duoc!" << endl;
	}else {
		dientich = a * a;
		chuvi = a * 4;
		cout << "Dien tich hv la: " << dientich << endl;
		cout << "Chu vi hv la: " << chuvi << endl;
		b = a * sqrt(2);
		cout << "Duong cheo hv la: " << b << endl;
	}
	system("pause");
	return 0;
}