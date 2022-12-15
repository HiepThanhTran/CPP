//Viết chương trình nhận vào 1 số nguyên dương n > 1.
//Tính và xuất ra màn hình kết quả tổng các số lẻ và tổng các số chẵn trong phạm vi từ 1 đến n.

#include<iostream>

using namespace std;

int main()
{
	int n, i=1, sum=0, sub=0;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if(n <= 1)
			cout << "So nguyen n phai lon hon 1. Xin nhap lai!\n";
	}while(n <= 1);

	while(i <= n) {
		if(i % 2 == 0) {
			sum += i;
		}else {
			sub += i;
		}
		i++;
	}
	cout << "Tong cac so le = " << sub << endl;
	cout << "Tong cac so chan = " << sum << endl;
	return 0;
}