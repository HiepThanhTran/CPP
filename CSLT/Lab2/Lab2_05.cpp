#include <iostream>
#include <math.h>
using namespace std;

int main5()
{
	double a = 0, b = 0, c = 0, p = 0, dientich = 0;
	cout << "Nhap chieu dai canh thu nhat cua tam giac: ";
	cin >> a;
	cout << "Nhap chieu dai canh thu hai cua tam giac: ";
	cin >> b;
	cout << "Nhap chieu dai canh thu ba cua tam giac: ";
	cin >> c;
	p = (a + b + c) / 2;
	dientich = sqrt((p - a) * (p - b) * (p - c));
	cout << " ==> Dien tich tam giac = " << dientich << endl;
	system("pause");
	return 0;
}
