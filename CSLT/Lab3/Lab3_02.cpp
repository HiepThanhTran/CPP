#include <iostream>
using namespace std;
int main2() {
	int a, b;
	cout << "nhap so nguyen a: ";
    cin >> a;
	cout << "nhap so nguyen b: ";
	cin >> b;
	if (a > b) {
		cout << "so lon nhat la " << a << endl;

	}else if(a < b)  {
		cout << "so lon nhat la " << b << endl;

	}else {
		cout << "khong ton tai so lon nhat" << endl;

	}
	system("pause");
	return 0;
}