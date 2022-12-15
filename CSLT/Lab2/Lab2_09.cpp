#include<iostream>
using namespace std;
int main9() {
	long tongsosach, tongsotien;
	double thue, tienvanchuyen, tonggiatridonhang;
	cout << "Tong so sach: "<< endl;
	cin >> tongsosach;
	cout << "Tong so tien: " << endl;
	cin >> tongsotien;
	thue = tongsotien * 7.5 / 100;
	tienvanchuyen = tongsosach * 2000;
	tonggiatridonhang = tongsotien + thue + tienvanchuyen;
	cout << "thue: " << thue << endl;
	cout << "tien van chuyen: " << tienvanchuyen << endl;
	cout << " tong gia tri don hang la: " << tonggiatridonhang;
	system("pause");
	return 0;

}