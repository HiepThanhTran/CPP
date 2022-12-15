//Viết chương trình nhận vào 1 số nguyên dương n > 1.
//Tính và xuất tích các số lẻ trong phạm vi từ 1 đến n.

#include<iostream>

using namespace std;

int main()
{
	int n, i = 1, multi = 1;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if(n <= 1)
			cout << "So nguyen n phai lon hon 1. Xin nhap lai!\n";
	}while(n <= 1);

	while(i <= n) {
		multi *= i;
		i+=2;
	}
	cout << "Ket qua = " << multi << endl;
	return 0;
}