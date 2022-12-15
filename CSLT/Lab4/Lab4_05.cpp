//Viết chương trình nhận vào 1 số nguyên dương n.
//Xuất ra màn hình số đảo ngược của n.

#include<iostream>

using namespace std;

int main()
{
	int n, ts, sdn = 0;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if(n <= 0)
			cout << "So nguyen n phai lon hon 0. Xin nhap lai!\n";
	}while(n <= 0);

	cout << "So dao nguoc cua " << n << " la ";
	while(n > 0) {
		ts = n % 10;
		sdn = sdn*10 + ts;
		n /= 10;
	}
	cout << sdn << endl;
	return 0;
}