//Viết chương trình nhận vào 1 số nguyên dương n.
//Xuất ra màn hình số chữ số và tổng các chữ số của n.

#include<iostream>

using namespace std;

int main()
{
	long n, temp, res, dem = 0, sum = 0;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if(n <= 0)
			cout << "So nguyen n phai lon hon 0. Xin nhap lai!\n";
	}while(n <= 0);

	temp = n;
	while(temp != 0) {
		res = temp % 10;
		sum += res;
		temp /= 10;
		dem++;
	}
	cout << "So chu so cua " << n << " la: " << dem << " chu so\n";
	cout << "Tong cac chu so = " << sum << endl;
	return 0;
}