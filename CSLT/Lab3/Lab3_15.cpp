#include <iostream>
#include <cmath>
using namespace std;
int main14() {
	int a, b, c, d, x;
	cin >> a >> b >> c >> d ;
	if (a < b)
	{
		x = a;
		a = b;
		b = x;
	}
	if (a < c)
	{
		x = a;
		a = c;
		c = x;
	}
	if (a < d) {
		x = a;
		a = d;
		d = x;
	}
	if (b < c)
	{
		x = b;
		b = c;
		c = x;
	}
	if (b < d) {
		x = b;
		b = d;
		d = x;
	}
	if (c < d){
		x = c;
		c = d;
		d = x;
		}
	cout << "so thu tu giam dan:  " << a << " " << b << " " << c << " " << d <<"\n";
	system("pause");
	return 0;
}