#include <iostream>
using namespace std;
int main4 (){
	double r = 0, dientich = 0, chuvi = 0;
	const double pi = 3.141593;
	cout << "Ban kinh la: ";
	cin >> r;
	dientich = pi * r * r;
	chuvi = 2 * pi * r;
	cout << " Dien tich cua hinh tron la: " << dientich << endl;
	cout << " Chu vi cua hinh tron la: " << chuvi << endl; 
	system("pause");
	return 0;

}