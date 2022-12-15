#include <iostream>
#include <iomanip>
using namespace std;
int main9() {
	double so1, so2;
	char dau;
	cout << "Nhap so thu 1 va so thu 2 ";
	cin >> so1 >> so2;
	cout << "Ban muon + hay - hay * hay / ";
	cin >> dau;
	switch (dau) {
	case '+':
		cout << so1 + so2;
		break;
	case '-':
		cout << so1 - so2;
		break;
	case '*':
		cout << so1 * so2;
		break;
	case '/':
			if (so2 == 0) {
				cout << "Loi chia 0";

			}
			else {
				cout << fixed << setprecision(2) << so1 / so2;
			}

	}
	system("pause");
		return 0;
}
