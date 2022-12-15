#include<iostream>
#include <cmath>
using namespace std;
int main12() {
	double a, b;
	cout << "Nhap vao a va b: ";
	cin >> a >> b;
	if (a == 0) {
		if (b == 0) {
			cout << "phuong trinh vo so nghiem";
		}else{
			cout << "phuong trinh vo nghiem";
		}

	}
	else {
		cout << "nghiem cua phuong trinh la: " << -b / a;
	}
	system("pause");
	return 0;

}