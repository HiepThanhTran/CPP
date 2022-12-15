#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void random(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % 10 + 1;
}
void output(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
			cout << arr[i][j] << "\t";
		cout << "\n\n";
	}
}
int** add2Mat(int** matA, int** matB, int row, int col)
{
	int** tong = new int* [row];
	for (int i = 0; i < row; i++)
		tong[i] = new int[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tong[i][j] = matA[i][j] + matB[i][j];
	return tong;
}
int** multiply2Mat(int** matA, int** matB, int rA, int cB, int n)
{
	int** tich = new int* [rA];
	for (int i = 0; i < rA; i++)
		tich[i] = new int[cB];
	for(int i = 0; i < rA; i++)
		for (int j = 0; j < cB; j++)
		{
			tich[i][j] = 0;
			for (int k = 0; k < n; k++)
				tich[i][j] += matA[i][k] * matB[k][j];
		}
	return tich;
}
int main()
{
	srand(time(0));
	int rA, cA, rB, cB;
	do {
		cout << "Nhap so luong hang matA: ";
		cin >> rA;
		cout << "Nhap so luong cot matA: ";
		cin >> cA;
	} while (rA < 1 || cA < 1);
	// Cấp phát động matA
	int** matA = new int* [rA];
	for (int i = 0; i < rA; i++)
	{
		matA[i] = new int[cA];
	}
	random(matA, rA, cA);
	do {
		cout << "Nhap so luong hang matB: ";
		cin >> rB;
		cout << "Nhap so luong cot matB: ";
		cin >> cB;
	} while (rB < 1 || cB < 1);
	// Cấp phát động matB
	int** matB = new int* [rB];
	for (int i = 0; i < rB; i++)
		matB[i] = new int[cB];
	random(matB, rB, cB);
	cout << "MatA:\n";
	output(matA, rA, cA);
	cout << "MatB:\n";
	output(matB, rB, cB);
	int** tongMT = add2Mat(matA, matB, rA, cA);
	int** tichMT = multiply2Mat(matA, matB, rA, cB, cA);
	if (rA == rB && cA == cB)
	{
		cout << "Tong 2 ma tran:\n";
		output(tongMT, rA, cA);
	}
	else
		cout << "Khong the cong 2 ma tran\n";
	if (cA == rB)
	{
		cout << "Tich 2 ma tran:\n";
		output(tichMT, rA, cB);
	}
	else
		cout << "Khong the nhan 2 ma tran\n";
	// Hủy cấp phát động
	for (int i = 0; i < rA; i++)
		delete[] matA[i];
	delete[] matA;
	for (int i = 0; i < rB; i++)
		delete[] matB[i];
	delete[] matB;
	for (int i = 0; i < rA; i++)
	{
		delete[] tongMT[i];
		delete[] tichMT[i];
	}
	delete[] tongMT;
	delete[] tichMT;
	return 0;
}