#include <iostream>
#include <math.h>
using namespace std;

int main6()
{
	long so;
	cout << "Nhap mot so nguyen co 3 chu so: ";
	cin >> so;
	int sodonvi = (so % 100) % 10;
	int sochuc = (so / 10) % 10;
	int sotram = so / 100;
	cout << " ==> Tong 3 so la = " << sodonvi + sochuc + sotram << endl;
	cout << " ==> So viet nguoc la = " << 100 * sodonvi + 10 * sochuc + sotram << endl;
	system("pause");	
	return 0;
}
