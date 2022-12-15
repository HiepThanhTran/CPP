#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ho, tenLot, ten;
	string kc = " ";
	cout << "Nhap ho: ";
	getline(cin, ho);
	cout << "Nhap ten lot: ";
	getline(cin, tenLot);
	cout << "Nhap ten: ";
	getline(cin, ten);
	cout << "Ho va ten day du: " << ho + kc + tenLot + kc + ten << endl;
	return 0;
}