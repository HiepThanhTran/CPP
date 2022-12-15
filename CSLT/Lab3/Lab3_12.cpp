#include <iostream>
using namespace std;
int main11() {
	int a;
	cout << "Nhap vao 1 so nguyen: ";
	cin >> a;
	if (a > 0) {
		cout << a << " la so duong";
	}
	else if (a == 0) {
		cout << a << " la so 0";
	}else{
		cout << a << " la so am";

	}
	system("pause");
	return 0;
}