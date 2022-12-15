#include<iostream>
#include<fstream>
using namespace std;
const int MAXR = 50, MAXC = 50;

void input(int a[][MAXC], int& row, int& col)
{
	do {
		cout << "Nhap so dong ma tran: ";
		cin >> row;
		cout << "Nhap so cot ma tran: ";
		cin >> col;
		if (row < 1 || row > MAXR || col < 1 || col > MAXC)
			cout << "\n\t**SO DONG/COT KHONG HOP LE**\n\n";
	} while (row < 1 || row > MAXR || col < 1 || col > MAXC);
	for (int i = 0; i < row; i++)
	{
		cout << "Nhap " << col << " gia tri cho dong thu " << i + 1 << ": ";
		for (int j = 0; j < col; j++)
			cin >> a[i][j];
	}
}
void output(int a[][MAXC], int row, int col)
{
	cout << "Cac gia tri trong mang 2 chieu:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << a[i][j] << "\t";
		cout << "\n\n";
	}
}
void WriteFile(int a[][MAXC], int row, int col)
{
	ofstream outFile("TT_2.txt");
	if (outFile.is_open())
	{
		outFile << row << " " << col << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				outFile << a[i][j] << "\t";
			outFile << "\n\n";
		}
		outFile.close();
		cout << "\n\t**GHI FILE THANH CONG**\n\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n\n";
}
void ReadFile(int a[][MAXC], int& r, int& c)
{
	ifstream inFile("TT_2.txt");
	if (inFile.is_open())
	{
		inFile >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				inFile >> a[i][j];
		inFile.close();
		cout << "\n\tDOC FILE THANH CONG**\n\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n\n";
}
int sumOfElements(int a[MAXR][MAXC], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += a[i][j];
	return sum;
}
int main()
{
	int option = 0, a[MAXR][MAXC], row, col;
	int r = 0, c = 0, sum = 0;
	bool flag1 = false, flag2 = false;
	do {
		system("cls");
		cout << "1- Nhap ma tran\n";
		cout << "2- Xuat ma tran\n";
		cout << "3- Tinh tong cac phan tu cua ma tran\n";
		cout << "4- Ghi ma tran vao File\n";
		cout << "5- Doc ma tran tu File\n";
		cout << "6- Ket thuc\n";
		cout << "- Nhap chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			input(a, row, col);
			flag1 = true;
			break;
		case 2:
			if (flag2)
				output(a, r, c);
			else
				cout << "\n\t**VUI LONG DOC FILE TRUOC**\n\n";
			break;
		case 3:
			if (flag2)
			{
				sum = sumOfElements(a, r, c);
				cout << "Tong cac phan tu cua ma tran doc duoc tu File: " << sum << endl;
			}
			else
				cout << "\n\t**VUI LONG DOC FILE TRUOC**\n\n";
			break;
		case 4:
			if (flag1)
				WriteFile(a, row, col);
			else
				cout << "\n\t**VUI LONG NHAP MA TRAN TRUOC**\n\n";
			break;
		case 5:
			ReadFile(a, r, c);
			flag2 = true;
			break;
		case 6:
			cout << "\n\t**KET THUC CHUONG TRINH**\n\n";
			return 0;
		default:
			cout << "\n\t**CHUC NANG KHONG TON TAI**\n\n";
		}
		system("pause");
	} while (option >= 1 && option <= 6);
	return 0;
}