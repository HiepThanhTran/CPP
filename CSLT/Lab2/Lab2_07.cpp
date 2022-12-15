#include <iostream>
#include <math.h>
using namespace std;

int main7()
{
	double x1, x2, y1, y2;
	cout << "Nhap toa do diem thu nhat (x1,y1): ";
	cin >> x1 >> y1;
	cout << "Nhap toa do diem thu hai (x2,y2) : ";
	cin >> x2 >> y2;
	double kc = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	cout << " ==> Khoang cach giua (" << x1 << "," << y1 << ") va (" << x2 << "," << y2 << ") = " << kc << endl;
	system("pause");
	return 0;
}
