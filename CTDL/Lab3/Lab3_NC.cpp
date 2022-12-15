#include "../resource/MyStack.h"
#include<iostream>
using namespace std;

void convert(int dec, int base)
{
	while (dec != 0)
	{
		Push(dec % base);
		dec /= base;
	}
}
void show(int dec, int base)
{
	convert(dec, base);
	cout << dec << " (10) -> " << "(" << base << "): ";
	while (!isEmpty())
	{
		int data;
		Pop(data);
		if (data >= 10) cout << char(data - 10 + 'A');
		else cout << data;
	}
	cout << "\n";
}
int main()
{
	int dec, base;
	char cnt;
	do {
		cout << "Nhap so he thap phan (10): ";
		cin >> dec;
		do {
			cout << "Nhap he can chuyen sang: ";
			cin >> base;
			if (base > dec) cout << "\n-He can chuyen phan nho hon hoac bang so thap phan-\n";
		} while (base < 1 || base > dec);
		show(dec, base);
		cout << "\nTiep tuc (y) / Ket thuc(n): ";
		cin >> cnt;
	} while (cnt == 'y' || cnt == 'Y');
	return 0;
}