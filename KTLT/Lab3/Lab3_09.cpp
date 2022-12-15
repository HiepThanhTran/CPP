#include<iostream>
#include<cmath>
using namespace std;

void input(int** p, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap " << c << " gia tri cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++)
			cin >> p[i][j];
	}
}
void output(int** p, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << p[i][j] << "\t";
		cout << "\n\n";
	}
}
bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}
int sumOfPrime(int** p, int r, int c)
{
	int sum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (isPrime(p[i][j]))
				sum += p[i][j];
	return sum;
}
void Prime(int** p, int* tmp, int r, int c, int& index)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (isPrime(p[i][j]))
				tmp[index++] = p[i][j];
}
int main()
{
	int r, c, index = 0;
	do {
		cout << "Nhap so luong hang (r > 0): ";
		cin >> r;
		cout << "Nhap so luong cot (c > 0): ";
		cin >> c;
	} while (r < 1 || c < 1 || r > INT_MAX || c > INT_MAX);
	// Cấp phát động
	int** p = new int* [r];
	for (int i = 0; i < r; i++)
		p[i] = new int[c];
	input(p, r, c);
	cout << "Ma tran vua nhap:\n";
	output(p, r, c);
	int sum = sumOfPrime(p, r, c);
	if (sum > 0)
	{
		cout << "Tong cac so nguyen to trong ma tran la " << sum << endl;
		int* tmp = new int[r * c];
		Prime(p, tmp, r, c, index);
		cout << "Cac so nguyen to trong ma tran: ";
		for (int i = 0; i < index; i++)
			cout << tmp[i] << " ";
		delete[] tmp;
	}
	else
		cout << "Mang khong co so nguyen to\n";
	// Hủy cấp phát động
	for (int i = 0; i < r; i++) {
		delete[] p[i];
	}
	delete[] p;
	return 0;
}