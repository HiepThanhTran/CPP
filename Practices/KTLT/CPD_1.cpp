#include<iostream>
#include<cmath>
using namespace std;

void nhapPTBac2(double* a1, double* a2, double* a3)
{
	cout << "Nhap cac he so cho phuong trinh bac 2:\n";
	cout << "F(x) = a1x^2 + a2x + a3 = 0\n";
	cout << "Nhap he so a1: ";
	cin >> *a1;
	cout << "Nhap he so a2: ";
	cin >> *a2;
	cout << "Nhap he so a3: ";
	cin >> *a3;
}
void xuatPTBac2(double* a1, double* a2, double* a3)
{
	int tmp = 0;
	cout << "\nPhuong trinh bac 2 vua nhap:\n";
	cout << "F(x) = ";
	if (*a1 != 0)
	{
		cout << *a1 << "x^2";
		if (*a2 > 0)
		{
			if (*a3 > 0)
				cout << " + " << *a2 << "x + " << *a3 << endl;
			if (*a3 < 0)
			{
				tmp = abs(*a3);
				cout << " + " << *a2 << "x - " << tmp << endl;
			}
		}
		if (*a2 < 0)
		{
			tmp = abs(*a2);
			if (*a3 > 0)
				cout << " - " << tmp << "x + " << *a3 << endl;
			if(*a3 < 0)
			{
				tmp = abs(*a3);
				cout << " - " << tmp << "x - " << tmp << endl;
			}

		}
	}
	else
	{
		if (*a2 == 0)
		{
			if (*a3 == 0)
				cout << 0 << endl;
			else
				cout << *a3 << endl;
		}
		else
		{
			if (*a3 == 0)
				cout << *a2 << "x\n";
			else
			{
				if (*a2 > 0)
				{
					if (*a3 > 0)
						cout << *a2 << "x + " << *a3 << endl;
					if (*a3 < 0)
					{
						tmp = abs(*a3);
						cout << *a2 << "x - " << tmp << endl;
					}
				}
				if (*a2 < 0)
				{
					if (*a3 > 0)
						cout << *a2 << "x + " << *a3 << endl;
					if (*a3 < 0)
					{
						tmp = abs(*a3);
						cout << *a2 << "x - " << tmp << endl;
					}

				}
			}
		}
	}
}
void timNghiemPTBac2(double* a1, double* a2, double* a3)
{
	if (*a1 == 0)
	{
		if (*a2 == 0)
		{
			if (*a3 == 0)
				cout << "\nPhuong trinh vo so nghiem\n";
			else
				cout << "\nPhuong trinh vo nghiem\n";
		}
		else
			cout << "\nPhuong trinh co nghiem duy nhat x = " << -(*a3) / (*a2) << endl;
	}
	else
	{
		double delta = (*a2) * (*a2) - 4 * (*a1) * (*a3);
		if (delta > 0)
		{
			cout << "\nPhuong trinh co 2 nghiem phan biet:\n";
			double x1 = (-(*a2) + sqrt(delta)) / (2 * (*a1));
			double x2 = (-(*a2) - sqrt(delta)) / (2 * (*a1));
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		if (delta == 0)
			cout << "\nPhuong trinh co nghiem kep:\nx1 = x2 = " << -(*a2) / (2 * (*a1)) << endl;
		if (delta < 0)
			cout << "\nPhuong trinh vo nghiem\n";
	}
}
int main()
{
	double* a1 = new double;
	double* a2 = new double;
	double* a3 = new double;
	nhapPTBac2(a1, a2, a3);
	xuatPTBac2(a1, a2, a3);
	timNghiemPTBac2(a1, a2, a3);
	delete a1;
	delete a2;
	delete a3;
	return 0;
}