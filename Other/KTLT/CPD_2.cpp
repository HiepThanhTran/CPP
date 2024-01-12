#include<iostream>
#include<cmath>
using namespace std;

int* inArr(int& n)
{
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n < 1)
			cout << "So luong phan tu toi thieu la 1. Xin nhap lai!\n";
	} while (n < 1);
	int* a = new int[n];
	cout << "Nhap " << n << " gia tri cho mang: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	return a;
}
void outArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
bool isSquare(int n)
{
	double sqr = sqrt(n);
	if (sqr * sqr == n) return true;
	return false;
}
int countSquare(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (isSquare(a[i])) count++;
	return count;
}
bool isPerNum(int n)
{
	int sum = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i != sqrt(n))
				sum += i + n / i;
			else
				sum += i;
		}
	}
	if (sum == n && n != 1) return true;
	return false;
}
bool isNegativeNum(int* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] < 0) return true;
	return false;
}
int* firstSquare(int* a, int n)
{
	for (int i = 0; i < n; i++)
		if (isSquare(a[i])) return &a[i];
	return NULL;
}
int* finalPerNum(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		if (isPerNum(a[i])) return &a[i];
	return NULL;
}
int findMin(int* a, int n)
{
	int min = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < a[min]) min = i;
	return a[min];
}
int* firstMinNum(int* a, int n)
{
	int min = findMin(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] == min) return &a[i];
}
int* finalMinNum(int* a, int n)
{
	int min = findMin(a, n);
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == min) return &a[i];
}
int* delElements(int* a, int& n, int x)
{
	for (int i = x; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
	return a;
}
int* ascendingSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		if (!flag) break;
	}
	return a;
}
int* descendingSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		if (!flag) break;
	}
	return a;
}
int* sortHalfArr(int* a, int n)
{
	int mid = n / 2;
	for(int i = 0; i < mid - 1; i++)
		for (int j = i + 1; j < mid; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	for(int i = mid; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
	return a;
}
int* mergeArr(int* a, int* b, int na, int nb)
{
	int* result = new int[na + nb];
	int index = 0;
	for (int i = 0; i < na; i++)
		result[index++] = a[i];
	for (int i = 0; i < nb; i++)
		result[index++] = b[i];
	return result;
}
int main()
{
	int option, na, nb, amount = 0, x;
	bool input = false;
	int* a = 0;
	int* b = 0;
	int* c = 0;
	do {
		system("cls");
		cout << "01. Nhap gia tri cho mang 1 chieu\n";
		cout << "02. Xuat gia tri mang 1 chieu\n";
		cout << "03. Dem so chinh phuong trong mang 1 chieu\n";
		cout << "04. Kiem tra mang co so am khong?\n";
		cout << "05. Tra ve dia chi so chinh phuong dau tien\n";
		cout << "06. Tra ve dia chi so hoan thien cuoi cung\n";
		cout << "07. Tra ve dia chi phan tu nho nhat dau tien\n";
		cout << "08. Tra ve dia chi phan tu nho nhat cuoi cung\n";
		cout << "09. Xoa 1 phan tu ra khoi mang 1 chieu\n";
		cout << "10. Sap xep mang tang dan\n";
		cout << "11. Sap xep mang giam dan\n";
		cout << "12. Sap xep nua dau mang tang dan, nua sau mang giam dan\n";
		cout << "13. Gop 2 mang 1 chieu lai\n";
		cout << "14. Gop 2 mang da tang dan thanh 1 mang tang dan\n";
		cout << "15. Thoat chuong trinh\n";
		cout << "Nhap chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			a = inArr(na);
			input = true;
			cout << "\n\tNHAP GIA TRI THANH CONG\n";
			break;
		case 2:
			if (input)
			{
				cout << "Mang vua nhap: ";
				outArr(a, na);
				cout << "\n\tXUAT MANG THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 3:
			if (input)
			{
				amount = countSquare(a, na);
				cout << "Co " << amount << " so chinh phuong trong mang\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 4:
			if (input)
			{
				if (isNegativeNum(a, na))
					cout << "Mang co ton tai so am\n";
				else
					cout << "Mang khong ton tai so am\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 5:
			if (input)
			{
				int* square = firstSquare(a, na);
				if (square)
				{
					cout << "Dia chi phan tu dau tien: " << int(a) << endl;
					cout << "Dia chi so chinh phuong dau tien: " << int(square) << endl;
				}
				else
					cout << "Mang khong ton tai so chinh phuong\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 6:
			if (input)
			{
				int* perNum = finalPerNum(a, na);
				if (perNum)
				{
					cout << "Dia chi phan tu dau tien: " << int(a) << endl;
					cout << "Dia chi so hoan thien cuoi cung: " << int(perNum) << endl;
				}
				else
					cout << "Mang khong ton tai so hoan thien\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 7:
			if (input)
			{
				int* firstMin = firstMinNum(a, na);
				cout << "Dia chi phan tu dau tien: " << int(a) << endl;
				cout << "Dia chi phan tu nho nhat dau tien: " << int(firstMin) << endl;
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 8:
			if (input)
			{
				int* finalMin = finalMinNum(a, na);
				cout << "Dia chi phan tu dau tien: " << int(a) << endl;
				cout << "Dia chi phan tu nho nhat cuoi cung: " << int(finalMin) << endl;
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 9:
			if (input)
			{
				do {
					cout << "Nhap vi tri phan tu can xoa: ";
					cin >> x;
					if (x < 1 || x > na) cout << "\n\tVI TRI KHONG HOP LE. XIN NHAP LAI!\n";
				} while (x < 1 || x > na);
				delElements(a, na, x - 1);
				cout << "\n\tXOA THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 10:
			if (input)
			{
				ascendingSort(a, na);
				cout << "\n\tSAP XEP MANG TANG DAN THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 11:
			if (input)
			{
				descendingSort(a, na);
				cout << "\n\tSAP XEP MANG GIAM DAN THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 12:
			if (input)
			{
				sortHalfArr(a, na);
				cout << "\n\tSAP XEP NUA DAU TANG DAN, NUA SAU GIAM DAN THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 13:
			if (input)
			{
				cout << "\n\t--NHAP GIA TRI CHO MANG THU 2--\n";
				b = inArr(nb);
				c = mergeArr(a, b, na, nb);
				cout << "Mang sau khi gop 2 mang lai: ";
				outArr(c, na + nb);
				cout << "\n\tGOP 2 MANG THANH CONG\n";
			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 14:
			if (input)
			{

			}
			else
				cout << "\n\tVUI LONG NHAP GIA TRI CHO MANG 1 CHIEU\n";
			break;
		case 15:
			cout << "\n\tTHOAT CHUONG TRINH\n";
			break;
		default:
			cout << "\n\tCHUC NANG HIEN KHONG CO\n";
		}
		system("pause");
	} while (option != 15);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}