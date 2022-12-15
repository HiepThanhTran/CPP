#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

struct Students
{
	string hoTen, gioiTinh, ID;
	int age = 0;
	double points1 = 0, points2 = 0, points3 = 0, average = 0;
} typedef S;

void printLine(char kt, int n)
{
	for (int i = 0; i < n; i++)
		cout << kt;
	cout << "\n";
}
int DocFile(S*& sv)
{
	int count = 0;
	string newline;
	ifstream inFile("resource\\DSSV.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, newline))
			count++;
		inFile.close();
		inFile.open("resource\\DSSV.txt");
		sv = new S[count];
		for (int i = 0; i < count; i++)
		{
			getline(inFile, sv[i].hoTen, '#');
			getline(inFile, sv[i].gioiTinh, '#');
			getline(inFile, sv[i].ID, '#');
			inFile >> sv[i].age; inFile.ignore(1);
			inFile >> sv[i].points1; inFile.ignore(1);
			inFile >> sv[i].points2; inFile.ignore(1);
			inFile >> sv[i].points3; inFile.ignore(1);
			sv[i].average = (sv[i].points1 + sv[i].points2 + sv[i].points3) / 3;
			cout << "     \t     Doc vao sinh vien thu " << i + 1 << "\n";
		}
		inFile.close();
		cout << "\t**DOC DANH SACH SINH VIEN THANH CONG**\n";
		char kt = _getch();
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n";
	return count;
}
void nhapSV(S& sv)
{
	cin.ignore();
	cout << "Nhap ho va ten sinh vien: "; getline(cin, sv.hoTen);
	cout << "Nhap gioi tinh: "; getline(cin, sv.gioiTinh);
	cout << "Nhap ID sinh vien: "; getline(cin, sv.ID);
	cout << "Nhap tuoi: "; cin >> sv.age;
	cout << "Nhap diem mon thu 1: "; cin >> sv.points1;
	cout << "Nhap diem mon thu 2: "; cin >> sv.points2;
	cout << "Nhap diem mon thu 3: "; cin >> sv.points3;
	sv.average = (sv.points1 + sv.points2 + sv.points3) / 3;
}
void nhapDSSV(S* sv, int amount, int slsv)
{
	for (int i = 0; i < slsv; i++)
	{
		system("cls");
		cout << "\n\t**NHAP THONG TIN SINH VIEN THU " << amount + i + 1 << "**\n";
		nhapSV(sv[amount + i]);
	}
}
void xuatSV(S sv)
{
	cout << "\t" << setw(25) << left << sv.hoTen;
	cout << "\t   " << setw(5) << left << sv.gioiTinh;
	cout << "\t" << setw(10) << left << sv.ID;
	cout << "\t " << sv.age;
	cout << "\t " << sv.points1;
	cout << "\t " << sv.points2;
	cout << "\t " << sv.points3;
	cout << setprecision(2) << "\t " << sv.average << endl;
}
void xuatDSSV(S* sv, int amount)
{
	printLine('_', 115);
	cout << "STT\tHO TEN\t\t\t\tGIOI TINH\t    ID\t\tTUOI\tDIEM 1\tDIEM 2\tDIEM 3\tDIEM TB\n";
	printLine('-', 115);
	for (int i = 0; i < amount; i++)
	{
		cout << i + 1;
		xuatSV(sv[i]);
	}
	printLine('_', 115);
}
void capNhatTTSV(S* sv, int amount)
{
	int stt = 0;
	do {
		cout << "- Nhap so thu tu sinh vien can chinh sua: ";
		cin >> stt;
		if (stt < 1 || stt > amount)
			cout << "\n\t**SO THU TU KHONG HOP LE**\n";
	} while (stt < 1 || stt > amount);
	cout << "\n\t**CAP NHAT THONG TIN SINH VIEN THU " << stt << "**\n";
	nhapSV(sv[stt - 1]);
}
S* themNSV(S* sv, int& amount, int slAdd)
{
	int newAmount = amount + slAdd;
	S* newSV = new S[newAmount];
	for (int i = 0; i < amount; i++)
		newSV[i] = sv[i];
	nhapDSSV(newSV, amount, slAdd);
	delete[] sv;
	amount = newAmount;
	return newSV;
}
void xoa1SV(S* sv, int& amount)
{
	int stt;
	do {
		cout << "Nhap so thu tu sinh vien can xoa: ";
		cin >> stt;
		if (stt < 1 || stt > amount)
			cout << "\n\t**SO THU TU KHONG HOP LE**\n";
	} while (stt < 1 || stt > amount);
	for (int i = stt - 1; i < amount - 1; i++)
		sv[i] = sv[i + 1];
	amount--;
}
S* xoaNSV(S* sv, int& amount, int slDel)
{
	for (int i = 0; i < slDel; i++)
		xoa1SV(sv, amount);
	S* newSV = new S[amount];
	for (int i = 0; i < amount; i++)
		newSV[i] = sv[i];
	delete[] sv;
	return newSV;
}
void xepHangTB(S* sv, int amount)
{
	for (int i = 0; i < amount - 1; i++)
		for (int j = i + 1; j < amount; j++)
			if (sv[i].average < sv[j].average)
			{
				S tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;
			}
}
void timKiemID(S* sv, int amount)
{
	string nID;
	cout << "- Nhap ID sinh vien can tim kiem: ";
	getline(cin, nID);
	printLine('_', 115);
	cout << "STT\tHO TEN\t\t\t\tGIOI TINH\t    ID\t\tTUOI\tDIEM 1\tDIEM 2\tDIEM 3\tDIEM TB\n";
	printLine('-', 115);
	for (int i = 0; i < amount; i++)
		if (sv[i].ID == nID)
		{
			cout << i + 1;
			xuatSV(sv[i]);
		}
	printLine('_', 115);
}
void doanXY(S* sv, int amount)
{
	int x, y, count = 0;
	do {
		cout << "- Nhap vao doan [x, y]: ";
		cin >> x >> y;

	} while (x >= y || x < 1 || y > 10);
	cout << "\t**DANH SACH CAC SINH VIEN CO DIEM TB TRONG DOAN [" << x << ", " << y << "]**\n";
	printLine('_', 115);
	cout << "STT\tHO TEN\t\t\t\tGIOI TINH\t    ID\t\tTUOI\tDIEM 1\tDIEM 2\tDIEM 3\tDIEM TB\n";
	printLine('-', 115);
	for (int i = 0; i < amount; i++)
		if (sv[i].average >= x && sv[i].average <= y)
		{
			count++;
			cout << i + 1;
			xuatSV(sv[i]);
		}
	if (count == 0)
		cout << "\n\t**KHONG CO SINH VIEN NAO THOA DIEU KIEN**\n";
	printLine('_', 115);
}
void svDau(S* sv, int amount)
{
	cout << "\t**DANH SACH CAC SINH VIEN DAU**\n";
	printLine('_', 115);
	cout << "STT\tHO TEN\t\t\t\tGIOI TINH\t    ID\t\tTUOI\tDIEM 1\tDIEM 2\tDIEM 3\tDIEM TB\n";
	printLine('-', 115);
	for (int i = 0; i < amount; i++)
		if (sv[i].average >= 5)
		{
			cout << i + 1;
			xuatSV(sv[i]);
		}
	printLine('_', 115);
}
void svRot(S* sv, int amount)
{
	cout << "\t**DANH SACH CAC SINH VIEN ROT**\n";
	printLine('_', 115);
	cout << "STT\tHO TEN\t\t\t\tGIOI TINH\t    ID\t\tTUOI\tDIEM 1\tDIEM 2\tDIEM 3\tDIEM TB\n";
	printLine('-', 115);
	for (int i = 0; i < amount; i++)
		if (sv[i].average < 5)
		{
			cout << i + 1;
			xuatSV(sv[i]);
		}
	printLine('_', 115);
}
void GhiFile(S* sv, int amount)
{
	ofstream outFile("resource\\DSSV.txt", ios::app);
	if (outFile.is_open())
	{
		ofstream nf("tmp.txt");
		for (int i = 0; i < amount; i++)
		{
			nf << sv[i].hoTen << '#';
			nf << sv[i].gioiTinh << '#';
			nf << sv[i].ID << '#';
			nf << sv[i].age << '#';
			nf << sv[i].points1 << '#';
			nf << sv[i].points2 << '#';
			nf << sv[i].points3 << endl;
		}
		nf.close();
		outFile.close();
		remove("resource\\DSSV.txt");
		int result = rename("tmp.txt", "resource\\DSSV.txt");
		if (result == 0)
			cout << "\n\t**GHI DANH SACH SINH VIEN VAO FILE THANH CONG**\n";
		else
			cout << "\n\t**GHI DANH SACH SINH VIEN VAO FILE KHONG THANH CONG**\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n";
}
int main()
{
	S* sv = nullptr;
	int amount = DocFile(sv);
	int option = 0, option8 = 0, slAdd = 0, slDel = 0;
	do {
		system("cls");
		cout << "\t\t    - Danh sach hien co " << amount << " sinh vien -\n";
		printLine('*', 76);
		cout << "*\t1- Xuat danh sach sinh vien                                        *\n";
		cout << "*\t2- Cap nhat thong tin sinh vien theo STT                           *\n";
		cout << "*\t3- Them sinh vien vao danh sach                                    *\n";
		cout << "*\t4- Xoa sinh vien ra khoi danh sach theo STT                        *\n";
		cout << "*\t5- Xep hang sinh vien theo diem TB                                 *\n";
		cout << "*\t6- Tim kiem sinh vien theo ID                                      *\n";
		cout << "*\t7- Xuat danh sach cac sinh vien co diem TB trong doan [x, y]       *\n";
		cout << "*\t8- Xuat danh sach cac sinh vien DAU/ROT                            *\n";
		cout << "*\t9- Ghi danh sach sinh vien vao File                                *\n";
		cout << "*\t0- Ket thuc                                                        *\n";
		printLine('*', 76);
		cout << "- Nhap chuc nang can su dung: ";
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1:
			xuatDSSV(sv, amount);
			break;
		case 2:
			capNhatTTSV(sv, amount);
			cout << "\n\t**CAP NHAT THONG TIN THANH CONG**\n";
			break;
		case 3:
			do {
				cout << "- Nhap so luong sinh vien can them: ";
				cin >> slAdd;
				if (slAdd < 1)
					cout << "\n\t**SO LUONG KHONG HOP LE**\n";
			} while (slAdd < 1);
			sv = themNSV(sv, amount, slAdd);
			cout << "\n\t**THEM SINH VIEN THANH CONG**\n";
			break;
		case 4:
			do {
				cout << "- Nhap so luong sinh vien can xoa: ";
				cin >> slDel;
				if (slDel < 1)
					cout << "\n\t**SO LUONG KHONG HOP LE**\n";
			} while (slDel < 1);
			sv = xoaNSV(sv, amount, slDel);
			cout << "\n\t**XOA SINH VIEN THANH CONG**\n\n";
			break;
		case 5:
			xepHangTB(sv, amount);
			cout << "\n\t**XEP HANG THEO DIEM TB THANH CONG**\n";
			break;
		case 6:
			timKiemID(sv, amount);
			break;
		case 7:
			doanXY(sv, amount);
			break;
		case 8:
			do {
				cout << "1- Danh sach sinh vien DAU\n";
				cout << "2- Danh sach sinh vien ROT\n";
				cout << "0- Quay lai\n";
				cout << "- Nhap chuc nang can su dung: ";
				cin >> option8;
				switch (option8)
				{
				case 1:
					svDau(sv, amount);
					break;
				case 2:
					svRot(sv, amount);
					break;
				}
			} while (option8 != 0);
			break;
		case 9:
			GhiFile(sv, amount);
			break;
		case 0:
			cout << "\n\t**KET THUC CHUONG TRINH**\n";
			delete[] sv;
			return 0;
		default:
				cout << "\n\t**CHUC NANG HIEN CHUA CO**\n";
		}
		system("pause");
	} while (option != 0);
}