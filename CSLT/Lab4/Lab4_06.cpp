//Viết chương trình nhận vào 1 số nguyên n.
//Xuất ra màn hình thông báo n có phải là số nguyên tố hay không.

#include<iostream>

using namespace std;

int main()
{
	int n;
	int i = 2;
	int count = 0;
	cout << "Nhap n: ";
	cin >> n;
	if(n < 2) {
		cout << n << " khong phai so nguyen to\n";
	}else{
		while(i<=n/2) {
			if(n % i == 0) {
				count++;
			}
			i++;
		}
		if(count==0) {
			cout << n << " la so nguyen to\n";
		}else{
			cout << n << " khong phai so nguyen to\n";
		}
	}
	return 0;
}