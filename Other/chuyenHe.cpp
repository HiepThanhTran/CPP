#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int A = 10, B = 11, C = 12, D = 13, E = 14, F = 15;
int n, m, p, q, k;
string a;

long ConvertDecimalToBinary(int n) // chuyen he 10 sang he 2
{
	if (n / 2 == 0)
		return n % 2;
	else
		return ConvertDecimalToBinary(n / 2) * 10 + n % 2;
}

long ConvertBinaryToDecimal(int n, double num = 0) // chuyen he 2 sang he 10
{
	if (n < 10)
	{
		return n % 10 * pow(2, num);
	}
	else
		return n % 10 * pow(2, num) + ConvertBinaryToDecimal(n / 10, num + 1);
}

long ConvertDecimalToOctal(int n) // chuyen he 10 sang he 8
{
	if (n / 8 == 0)
		return n % 8;
	else
		return ConvertDecimalToOctal(n / 8) * 10 + n % 8;
}

long ConvertOctalToDecimal(int n, double num = 0) // chuyen tu he 8 sang he 10
{
	if (n < 10)
	{
		return n % 10 * pow(8, num);
	}
	else
		return n % 10 * pow(8, num) + ConvertOctalToDecimal(n / 10, num + 1);
}

void ConvertDecimalToHexadecimal(int n) // chuyen he 10 sang he 16
{
	int temp;
	if (n == 0)
		return;
	else
	{
		temp = n % 16;
		if (temp >= 10)
			temp += 55;
		else
			temp += 48;
		ConvertDecimalToHexadecimal(n / 16);
		cout << (char)temp;
	}
}

long ConvertHexadecimalToDecimal(string a, double base = 0) // chuyen he 16 sang he 10
{
	if (a.length() == 1)
		if (a[a.length() - 1] >= '0' && a[a.length() - 1] <= '9')
			return (a[a.length() - 1] - 48) * pow(16, base);
		else
		{
			if (a[a.length() - 1] >= 'A' && a[a.length() - 1] <= 'F')
				return (a[a.length() - 1] - 55) * pow(16, base);
		}
	else if (a[a.length() - 1] >= '0' && a[a.length() - 1] <= '9')
		return (a[a.length() - 1] - 48) * pow(16, base) + ConvertHexadecimalToDecimal(a = a.erase(a.length() - 1), base + 1);
	else if (a[a.length() - 1] >= 'A' && a[a.length() - 1] <= 'F')
		return (a[a.length() - 1] - 55) * pow(16, base) + +ConvertHexadecimalToDecimal(a = a.erase(a.length() - 1), base + 1);
}

int main()
{
	cout << "Nhap so nguyen muon chuyen tu he 10 sang he 2: ";
	cin >> n;

	cout << "He 2 cua so vua nhap la: " << ConvertDecimalToBinary(n) << endl;

	cout << "Nhap mot so he 2 de chuyen thanh he 10: ";
	cin >> m;

	cout << "He 10 cua so vua nhap la: " << ConvertBinaryToDecimal(m) << endl;

	cout << "Nhap so can chuyen tu he 10 sang he 8: ";
	cin >> p;

	cout << "He 8 cua so vua nhap la: " << ConvertDecimalToOctal(p) << endl;

	cout << "Nhap so can chuyen tu he 8 sang he 10: ";
	cin >> q;

	cout << "He 10 cua so vua nhap la: " << ConvertOctalToDecimal(q) << endl;

	cout << "Nhap so can chuyen tu he 10 sang he 16: ";
	cin >> k;

	cout << "He 16 cua so vua nhap la: ";
	ConvertDecimalToHexadecimal(k);
	cout << endl;

	cout << "Nhap chuoi he 16 can chuyen sang 10: ";
	cin >> a;

	cout << "He 10 cua so vua nhap: " << ConvertHexadecimalToDecimal(a) << endl;
	system("pause");
	return 0;
}