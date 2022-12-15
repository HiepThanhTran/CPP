#include <iostream>
#include <cmath>
using namespace std;
int main10() {
	int a;
	cout << " Nhap vao 1 so nguyen: ";
	cin >> a;
	if (a % 2 == 0) {
		cout << a << " la so chan";
	}
	else {
		cout << a << " la so le";
	}
	system("pause");
	return 0;
}