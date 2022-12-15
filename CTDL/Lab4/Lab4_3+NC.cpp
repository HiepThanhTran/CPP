#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
#define lb long double

struct Polynomial
{
	int deg;			// degree: bac
	lb coeff[MAX]; // coefficient: he so
} typedef Poly;

Poly A, B, Result, R; // remainder: phan du
void fill0(Poly &pln);
void input(Poly &pln);
void output(Poly pln);
void addPoly(Poly A, Poly B, Poly &Res);
void subPoly(Poly A, Poly B, Poly &Res);
void multiplyPoly(Poly A, Poly B, Poly &Res);
void divisionPoly(Poly A, Poly B, Poly &Res, Poly &R);

int main()
{
	int choice;
	do
	{
		system("cls");
		cout << "1- Nhap da thuc\n";
		cout << "2- Xuat da thuc\n";
		cout << "3- Cong 2 da thuc\n";
		cout << "4- Tru 2 da thuc\n";
		cout << "5- Nhan 2 da thuc\n";
		cout << "6- Chia 2 da thuc\n";
		cout << "7- Thoat\n";
		cout << "- Chon chuc nang: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "--NHAP DA THUC A--\n";
			input(A);
			cout << "--NHAP DA THUC B--\n";
			input(B);
			break;
		case 2:
			cout << "--XUAT DA THUC A--\n";
			output(A);
			cout << "--XUAT DA THUC B--\n";
			output(B);
			break;
		case 3:
			addPoly(A, B, Result);
			cout << "--KET QUA CONG 2 DA THUC--\n";
			output(Result);
			break;
		case 4:
			subPoly(A, B, Result);
			cout << "--KET QUA TRU 2 DA THUC--\n";
			output(Result);
			break;
		case 5:
			multiplyPoly(A, B, Result);
			cout << "--KET QUA NHAN 2 DA THUC--\n";
			output(Result);
			break;
		case 6:
			divisionPoly(A, B, Result, R);
			cout << "--KET QUA CHIA 2 DA THUC--\n";
			output(Result);
			cout << "- Du: ";
			output(R);
			break;
		default:
			cout << "\n==KET THUC VIEC TINH TOAN==\n";
		}
		_getch();
	} while (choice >= 1 && choice <= 6);
	return 0;
}
void fill0(Poly &pln)
{
	for (int i = 0; i <= pln.deg; i++)
		pln.coeff[i] = 0;
}
void input(Poly &pln)
{
	do
	{
		cout << "Nhap bac cua da thuc: ";
		cin >> pln.deg;
		if (pln.deg < 1)
			cout << "Bac cua da thuc phai lon hon 0\n";
	} while (pln.deg < 1);
	for (int i = 0; i <= pln.deg; i++)
	{
		cout << "Nhap he so a" << i << ": ";
		cin >> pln.coeff[i];
	}
}
void output(Poly pln)
{
	if (pln.deg == 0)
		cout << pln.coeff[0];
	else if (pln.deg == 1)
		cout << pln.coeff[0] << "x";
	else
		cout << pln.coeff[0] << "x^" << pln.deg;
	for (int i = 1; i <= pln.deg; i++)
	{
		if (pln.coeff[i] != 0)
			if (pln.coeff[i] < 0)
			{
				if (pln.deg - i == 0)
					cout << " - " << -pln.coeff[i];
				else if (pln.deg - i == 1)
					cout << " - " << -pln.coeff[i] << "x";
				else
					cout << " - " << -pln.coeff[i] << "x^" << pln.deg - i;
			}
			else
			{
				if (pln.deg - i == 0)
					cout << " + " << pln.coeff[i];
				else if (pln.deg - i == 1)
					cout << " + " << pln.coeff[i] << "x";
				else
					cout << " + " << pln.coeff[i] << "x^" << pln.deg - i;
			}
	}
	cout << "\n";
}
void addPoly(Poly A, Poly B, Poly &Res)
{
	if (A.deg > B.deg)
	{
		Res.deg = A.deg;
		for (int i = 0; i < A.deg - B.deg; i++)
			Res.coeff[i] = A.coeff[i];
		for (int i = 0; i <= B.deg; i++)
			Res.coeff[A.deg - B.deg + i] = A.coeff[A.deg - B.deg + i] + B.coeff[i];
	}
	else
	{
		Res.deg = B.deg;
		for (int i = 0; i < B.deg - A.deg; i++)
			Res.coeff[i] = B.coeff[i];
		for (int i = 0; i <= A.deg; i++)
			Res.coeff[B.deg - A.deg + i] = B.coeff[B.deg - A.deg + i] + A.coeff[i];
	}
}
void subPoly(Poly A, Poly B, Poly &Res)
{
	if (A.deg == B.deg)
	{
		if (A.coeff[0] == B.coeff[0])
		{
			Res.deg = A.deg - 1;
			for (int i = 0; i <= Res.deg; i++)
				Res.coeff[i] = A.coeff[i + 1] - B.coeff[i + 1];
		}
		else
		{
			Res.deg = A.deg;
			for (int i = 0; i <= Res.deg; i++)
				Res.coeff[i] = A.coeff[i] - B.coeff[i];
		}
	}
	else if (A.deg > B.deg)
	{
		Res.deg = A.deg;
		for (int i = 0; i < A.deg - B.deg; i++)
			Res.coeff[i] = A.coeff[i];
		for (int i = 0; i <= B.deg; i++)
			Res.coeff[A.deg - B.deg + i] = A.coeff[A.deg - B.deg + i] - B.coeff[i];
	}
	else
	{
		Res.deg = B.deg;
		for (int i = 0; i < B.deg - A.deg; i++)
			Res.coeff[i] = B.coeff[i];
		for (int i = 0; i <= A.deg; i++)
			Res.coeff[B.deg - A.deg + i] = B.coeff[B.deg - A.deg + i] - A.coeff[i];
	}
}
void multiplyPoly(Poly A, Poly B, Poly &Res)
{
	Res.deg = A.deg + B.deg;
	fill0(Res);
	for (int i = 0; i <= A.deg; i++)
		for (int j = 0; j <= B.deg; j++)
			Res.coeff[i + j] += A.coeff[i] * B.coeff[j];
}
void divisionPoly(Poly A, Poly B, Poly &Res, Poly &R)
{
	Res.deg = A.deg - B.deg;
	fill0(Res);
	Poly tmp;
	R = A;
	while (R.deg >= B.deg)
	{
		int index = Res.deg - (R.deg - B.deg);
		Res.coeff[index] = R.coeff[0] / B.coeff[0];
		tmp.deg = Res.deg - index + B.deg;
		fill0(tmp);
		for (int i = 0; i <= B.deg; i++)
			tmp.coeff[i] = Res.coeff[index] * B.coeff[i];
		subPoly(A, tmp, R);
		cout << R.deg << "\n";
		A = R;
	}
}