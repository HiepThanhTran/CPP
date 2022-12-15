#include <iostream>
#include <cmath>
using namespace std;
int main13() {
	double a, b, c, delta=0, x1, x2;
	cout << "Nhap a,b,c: ";
	cin >> a >> b >> c;
	x1 = (-b + sqrt(delta)) / 2*a;
	x2 = (-b + sqrt(delta)) / 2*a;
	delta = b * b - 4 * a * c;
	if (a == 0 && b == 0 && c == 0) {
		cout << " pt vo so nghiem";
	}
	if (delta < 0) {
		cout << "pt vo nghiem";
	}
	else if (delta == 0)
	{
		cout << "pt co nghiem kep x1=x2=" << -b / 2*a;

	}
	else if (delta > 0) {
		cout << "pt co 2 nghiem phan biet x1= " << x1 << " va x2= " << x2;
	}
	system("pause");
	return 0;
}