#include <iostream>
using namespace std;
int main4() {
	int a, b;
	cout << "nhap so nguyen a: " << endl;
	cin >> a;

	cout << "nhap so nguyen b: " << endl;
	cin >> b;
	if (a > b) {
		cout << a << " lon hon " << b << endl;
	}else if (a==b){ 
		cout << a << " bang " << b << endl ;

	}else {
		cout << a << " nho hon " << b << endl;

	}
	system("pause");
	return 0;
}