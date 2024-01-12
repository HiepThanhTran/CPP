#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;

void WriteFile(int a[], int n)
{
	ofstream outFile("TT_1.txt", ios::app);
	if (outFile.is_open())
	{
		for (int i = 0; i < n; i++)
			outFile << a[i] << endl;
		outFile.close();
		cout << "\n\t**GHI FILE THANH CONG**\n\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n\n";
}
int ReadFile(int a[])
{
	int count = 0;
	ifstream inFile("TT_1.txt");
	if (inFile.is_open())
	{
		while (inFile >> a[count])
			count++;
		inFile.close();
		cout << "\n\t**DOC FILE THANH CONG**\n\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n\n";
	return count;
}
void input(int a[], int& n)
{
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n < 1 || n > MAX)
			cout << "\n\t**SO LUONG PHAN TU KHONG HOP LE**\n\n";
	} while (n < 1 || n > MAX);
	cout << "Nhap " << n << " gia tri cho mang 1 chieu: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n)
{
	cout << "Cac gia tri trong mang 1 chieu: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[MAX], option, n;
	int amount = 0;
	bool flag1 = false, flag2 = false;
	do {
		system("cls");
		cout << "1. Nhap gia tri cho mang 1 chieu\n";
		cout << "2. Xuat gia tri trong mang 1 chieu\n";
		cout << "3. Doc File\n";
		cout << "4. Ghi File\n";
		cout << "5. Ket thuc\n";
		cout << "- Nhap chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			input(a, n);
			flag1 = true;
			break;
		case 2:
			if (flag2)
				output(a, amount);
			else
				cout << "\n\t**VUI LONG DOC FILE TRUOC**\n\n";
			break;
		case 3:
			amount = ReadFile(a);
			flag2 = true;
			break;
		case 4:
			if (flag1)
				WriteFile(a, n);
			else
				cout << "\n\t**VUI LONG NHAP GIA TRI TRUOC**\n\n";
			break;
		case 5:
			cout << "\n\t**KET THUC CHUONG TRINH**\n\n";
			return 0;
		default:
			cout << "\n\t**CHUC NANG KHONG TON TAI**\n\n";
		}
		system("pause");
	} while (option >= 1 && option <= 5);
	return 0;
}