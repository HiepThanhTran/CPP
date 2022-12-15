//Viết chương trình nhận vào 1 số nguyên n ( n > 0 ).
//Tính và xuất ra màn hình kết quả tổng các số từ 1 đến n.

#include<iostream>

using namespace std;

int main()
{
	int n, sum = 0, i = 1;
	do {
		cout << "Nhap so nguyen n: ";
		cin >> n;
		if(n <= 0)
			cout << "So nguyen n phai lon hon 0. Xin nhap lai!\n";
	}while(n <= 0);
	
	while(i <= n) {
		sum += i;
		i++;
	}
	cout << "Ket qua = " << sum << endl;
	return 0;
}