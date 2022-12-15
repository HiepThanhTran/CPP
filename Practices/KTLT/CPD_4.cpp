#include<iostream>
#include<cmath>
using namespace std;

int** nhapMaTran(int& r, int& c)
{
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r < 1 || c < 1 || r > INT_MAX || c > INT_MAX)
			cout << "So dong hoac so cot khong hop le\n";
	} while (r < 1 || c < 1 || r > INT_MAX || c > INT_MAX);
	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[c];
	for (int i = 0; i < r; i++)
	{
		cout << "Nhap " << c << " gia tri cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}
	return arr;
}
void xuatMaTran(int** p, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << p[i][j] << "\t";
		cout << "\n\n";
	}
}
int sumOfElements(int** p, int r, int c)
{
	int sum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sum += *(*(p + i) + j);
	return sum;
}
bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n * 1.0); i++)
		if (n % i == 0) return false;
	return true;
}
void Prime(int** p, int r, int c, int* q, int& index)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (isPrime(*(*(p + i) + j)))
				q[index++] = *(*(p + i) + j);
}
void output(int* q, int index)
{
	for (int i = 0; i < index; i++)
		cout << q[i] << " ";
	cout << "\n";
}
int* oddNumber(int** p, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (p[i][j] % 2 != 0)
				return &p[i][j];
	return NULL;
}
void posOddNumber(int** p, int r, int c, int* address, int& row, int& col)
{
	for (int i = 0; i < r; i++)
	{
		int kc = address - &p[i][0];
		if (kc >= 0 && kc < c && &p[i][kc] == address)
		{
			row = i;
			col = kc;
			return;
		}
	}
}
int main()
{
	int r, c, result, index = 0, row, col;
	int** p = nhapMaTran(r, c);
	int* q = new int[r * c];
	cout << "Ma tran vua nhap:\n";
	xuatMaTran(p, r, c);
	result = sumOfElements(p, r, c);
	cout << "Tong cac phan tu trong ma tran: " << result << endl;
	Prime(p, r, c, q, index);
	cout << "Cac so nguyen to trong ma tran: ";
	output(q, index);
	int* address = oddNumber(p, r, c);
	if (address)
	{
		cout << "Dia chi so le dau tien: " << int(address) << endl;
		posOddNumber(p, r, c, address, row, col);
		cout << "Dia chi phan tu dau tien o hang " << row << ": " << int(&p[row][0]) << endl;
		cout << "Tai hang " << row << " cot " << col << endl;
	}
	else
		cout << "Ma tran khong co so le\n";
	for (int i = 0; i < r; i++)
		delete[] p[i];
	delete[] p;
	delete[] q;
	return 0;
}