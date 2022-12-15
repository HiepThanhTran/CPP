#include<iostream>
#include<iomanip>

using namespace std;

long long giaiThua(int n) {
	long long gt = 1;
	for (int i = 1; i <= n; i++) {
		gt *= i;
	}
	return gt;
}
long long toHop(int n, int k) {
	return giaiThua(n) / (giaiThua(k) * giaiThua(n - k));
}
void tamGiacPascal(int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << toHop(i, j) << " ";
		}
		cout << endl;
	}
}
int main()
{
	long long n, k, h;
	do {
		cout << "Nhap phan tu n (n >= 0): ";
		cin >> n;
		cout << "Nhap phan tu k (k >= 0): ";
		cin >> k;
		cout << "Nhap chieu cao h (h > 0): ";
		cin >> h;
		if (n < 0 || k < 0 || h < 1) cout << "Khong hop le. Xin nhap lai!!\n";
	} while (n < 0 || k < 0 || h < 1);
	cout << "\nKet qua cua " << n << "! = " << giaiThua(n) << endl;
	cout << "\nTo hop cua C(" << n << "," << k << ")" << " = " << toHop(n, k) << endl;
	cout << "\n-----TAM GIAC PASCAL-----\n";
	tamGiacPascal(h);
	system("pause");
	return 0;
}