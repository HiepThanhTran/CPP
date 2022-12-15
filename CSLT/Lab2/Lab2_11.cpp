#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main11()
{
	double goc;
	cout << "Nhap vao so do cua goc: ";
	cin >> goc;
	double radian = goc * 3.14 / 180;
	cout << "==> Sin(" << radian << ")= " << fixed << setprecision(2) << sin(radian) << endl;
	cout << "==> Cos(" << radian << ")= " << fixed << setprecision(2) << cos(radian) << endl;
	cout << "==> Tang(" << radian << ")= " << fixed << setprecision(2) << tan(radian) << endl;
	system("pause");
	return 0;

}