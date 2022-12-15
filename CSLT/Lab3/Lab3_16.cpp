#include <iostream>
#include <cmath>
using namespace std;
int main15() {

	double a = 0, b = 0, c = 0;
	cout << "Nhap vao canh thu 1, canh thu 2, canh thu 3: ";
	cin >> a >> b >> c;
	if (a < b + c && b < a + c && c < a + b) {
		if (a == b && b == c) {
			cout << "Tam giac deu";
		}
		else if (a == b || a == c || b == c) {
			cout << "Tam giac can";
		}
		else if (c == (sqrt(a * a + b * b)) || a == (sqrt(b * b + c * c)) || b == (sqrt(a * a + c * c))) {

			cout << "Tam giac vuong";
		}
		else if ((a == b || a == c || b == c) && (c == (sqrt(a * a + b * b)) || a == (sqrt(b * b + c * c)) || b == (sqrt(a * a + c * c)))) {
			cout << "Tam giac vuong can";
		}
		else {
			cout << "Tam giac thuong";

		}
	}
	else {
		cout << "Ba canh a, b, c khong phai la ba canh cua mot tam giac";
	
	}
	system("pause");
	return 0;
}