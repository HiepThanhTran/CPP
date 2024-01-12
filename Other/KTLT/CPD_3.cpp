#include<iostream>
#include<cmath>
using namespace std;

double* nhapDaThuc(double& bac)
{
	do {
		cout << "Nhap bac cua da thuc: ";
		cin >> bac;
	} while (bac < 1);
	double* A = new double[bac + 1];
	for (int i = 0; i <= bac; i++)
	{
		cout << "Nhap he so a" << i + 1 << ": ";
		cin >> A[i];
	}
	return A;
}
void xuatDaThuc(double* A, double bac, char c)
{
	cout << c << "(x) = " << A[0] << "x^" << bac;
	for (int i = 1; i <= bac; i++)
	{
		double tmp = 0;
		if (A[i] > 0)
		{
			if (i == bac)
				cout << " + " << A[i];
			else if (i == bac - 1)
				cout << " + " << A[i] << "x";
			else
				cout << " + " << A[i] << "x^" << bac - i;
		}
		if (A[i] < 0)
		{
			tmp = abs(A[i]);
			if (i == bac)
				cout << " - " << tmp;
			else if (i == bac - 1)
				cout << " - " << tmp << "x";
			else
				cout << " - " << tmp << "x^" << bac - i;
		}
	}
	cout << "\n";
}
double tinhGiaTriDaThuc(double* A, double bac, double& x)
{
	double fx = 0;
	cout << "\nNhap vao gia tri x bat ky: ";
	cin >> x;
	for (int i = 0; i <= bac; i++)
		fx += A[i] * pow(x, bac - i);
	return fx;
}
double* tong2DaThuc(double* A, double* B, double bacA, double bacB, int& sizeS)
{
	sizeS = (bacA > bacB) ? bacA : bacB;
	int k = abs(bacA - bacB);
	double* tong = new double[sizeS];
	if (bacA > bacB)
	{
		for (int i = 0; i < k; i++)
			tong[i] = A[i];
		for (int i = 0; i <= bacB; i++)
		{
			tong[k] = A[k] + B[i];
			k++;
		}
	}

	else if (bacA < bacB)
	{
		for (int i = 0; i < k; i++)
			tong[i] = B[i];
		for (int i = 0; i <= bacA; i++)
		{
			tong[k] = A[i] + B[k];
			k++;
		}
	}
	else
	{
		for (int i = 0; i <= sizeS; i++)
			tong[i] = A[i] + B[i];
	}

	return tong;
}
double* tich2DaThuc(double* A, double* B, double bacA, double bacB, int& sizeP)
{
	double* tich = new double[bacA + bacB];
	
	return tich;
}
int main()
{
	int option = 0, daThuc = 0, sizeS, sizeP;
	double* Fx = 0, * Gx = 0, * tongDaThuc = 0, * tichDaThuc = 0;
	double x, kq, bacFx, bacGx;
	bool flag = false;
	do {
		system("cls");
		cout << "1. Nhap vao 2 da thuc\n";
		cout << "2. Tinh gia tri cua da thuc tai gia tri x bat ky\n";
		cout << "3. Tinh tong 2 da thuc\n";
		cout << "4. Tinh tich 2 da thuc\n";
		cout << "5. Thoat\n";
		cout << "Nhap chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "--Nhap da thuc thu 1--\n";
			Fx = nhapDaThuc(bacFx);
			cout << "\n--Nhap da thuc thu 2--\n";
			Gx = nhapDaThuc(bacGx);
			flag = true;
			break;
		case 2:
			if (flag)
			{
				do {
					cout << "1. ";
					xuatDaThuc(Fx, bacFx, 'F');
					cout << "\n2. ";
					xuatDaThuc(Gx, bacGx, 'G');
					cout << "\nChon da thuc can tinh gia tri: ";
					cin >> daThuc;
					if (daThuc < 1 || daThuc > 2) cout << "\n\tDA THUC KHONG HOP LE\n";
				} while (daThuc < 1 || daThuc > 2);
				switch (daThuc)
				{
				case 1:
					kq = tinhGiaTriDaThuc(Fx, bacFx, x);
					cout << "F(" << x << ") = " << kq << endl;
					break;
				case 2:
					kq = tinhGiaTriDaThuc(Gx, bacGx, x);
					cout << "G(" << x << ") = " << kq << endl;
					break;
				}
			}
			else
				cout << "\n\tVUI LONG NHAP DA THUC TRUOC KHI THUC HIEN TINH TOAN\n";
			break;
		case 3:
			if (flag)
			{
				xuatDaThuc(Fx, bacFx, 'F');
				xuatDaThuc(Gx, bacGx, 'G');
				tongDaThuc = tong2DaThuc(Fx, Gx, bacFx, bacGx, sizeS);
				cout << "--------------------\n";
				xuatDaThuc(tongDaThuc, sizeS, 'S');
			}
			else
				cout << "\n\tVUI LONG NHAP DA THUC TRUOC KHI THUC HIEN TINH TOAN\n";
			break;
		case 4:
			if (flag)
			{
				xuatDaThuc(Fx, bacFx, 'F');
				xuatDaThuc(Gx, bacGx, 'G');
				tichDaThuc = tich2DaThuc(Fx, Gx, bacFx, bacGx, sizeP);
				cout << "--------------------\n";
				xuatDaThuc(tichDaThuc, sizeP, 'P');
			}
			else
				cout << "\n\tVUI LONG NHAP DA THUC TRUOC KHI THUC HIEN TINH TOAN\n";
			break;
		case 5:
			cout << "\n\tTHOAT CHUONG TRINH\n";
			break;
		default:
			cout << "\n\tCHUC NANG HIEN KHONG CO\n";
		}
		system("pause");
	} while (option != 5);
	delete[] Fx;
	delete[] Gx;
	delete[] tongDaThuc;
	delete[] tichDaThuc;
	return 0;
}