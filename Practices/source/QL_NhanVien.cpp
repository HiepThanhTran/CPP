#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

struct NhanVien
{
	string maNV, hoTen, gioiTinh, ngaySinh;
	int ngayCong = 0;
	double luongCB = 0, heSo = 0, thuong = 0, luongTL = 0;
} typedef NV;

void nhapNV(NV& nv)
{
	cin.ignore();
	cout << "- Ma nhan vien: "; getline(cin, nv.maNV);
	cout << "- Ho ten: "; getline(cin, nv.hoTen);
	cout << "- Gioi tinh: "; getline(cin, nv.gioiTinh);
	cout << "- Tuoi: "; getline(cin, nv.ngaySinh);
	cout << "- Luong co ban: "; cin >> nv.luongCB;
	cout << "- He so luong: "; cin >> nv.heSo;
	cout << "- Ngay cong: "; cin >> nv.ngayCong;
	nv.luongTL = nv.luongCB * nv.heSo * nv.ngayCong;
}
void nhapDSNV(NV*& ds, int& slNV)
{
	do {
		cout << "Nhap so luong nhan vien: ";
		cin >> slNV;
		if (slNV < 1 || slNV >INT_MAX)
			cout << "\n\t**SO LUONG NHAN VIEN KHONG HOP LE**\n";
	}while(slNV < 1 || slNV > INT_MAX);
	ds = new NV[slNV];
	for (int i = 0; i < slNV; i++)
	{
		cout << "\t==THONG TIN NHAN VIEN THU " << i + 1 << "==\n";
		nhapNV(ds[i]);
	}
}
void xuatNV(NV nv)
{
	cout << "| " << nv.maNV << "\t|";
	cout << " " << setw(10) << left << nv.hoTen << "\t|";
	cout << " " << setw(10) << left << nv.ngaySinh << "\t|";
	cout << setprecision(2) << fixed << " " << setw(10) << left << nv.luongTL << "\t|\n";
}
void xuatDSNV(NV* ds, int slNV)
{
	cout << "-------------------------------------------------------------------\n";
	cout << "| MaNV\t| Ho ten\t\t| Tuoi\t\t| Luong thuc linh |\n";
	cout << "-------------------------------------------------------------------\n";
	for (int i = 0; i < slNV; i++)
		xuatNV(ds[i]);
	cout << "-------------------------------------------------------------------\n";
}
double luongTB(NV* ds, int slNV)
{
	double TB = 0;
	for (int i = 0; i < slNV; i++)
		TB += ds[i].luongTL;
	return TB / slNV;
}
NV luongThap(NV* ds, int slNV)
{
	NV LTN = ds[0];
	double min = ds[0].luongTL;
	for (int i = 1; i < slNV; i++)
		if (ds[i].luongTL < min)
		{
			min = ds[i].luongTL;
			LTN = ds[i];
		}
	return LTN;
}
NV luongCao(NV* ds, int slNV)
{
	NV LCN = ds[0];
	double max = ds[0].luongTL;
	for(int i = 1; i < slNV; i++)
		if (ds[i].luongTL > max)
		{
			max = ds[i].luongTL;
			LCN = ds[i];
		}
	return LCN;
}
void phanLoai(NV* ds, int slNV)
{
	for (int i = 0; i < slNV; i++)
	{
		if (ds[i].ngayCong >= 24)
			ds[i].thuong = 500000;
		if (ds[i].ngayCong >= 23)
			ds[i].thuong = 300000;
		ds[i].luongTL += ds[i].thuong;
	}
}
void ghiFile(NV* ds, int slNV)
{
	ofstream outData("DSNV.txt");
	if (!outData)
	{
		for (int i = 0; i < slNV; i++)
		{
			outData << ds[i].maNV << '-';
			outData << ds[i].hoTen << '-';
			outData << ds[i].gioiTinh << '-';
			outData << ds[i].ngaySinh << '-';
			outData << ds[i].luongCB << '-';
			outData << ds[i].heSo << '-';
			outData << ds[i].ngayCong << '-';
			outData << ds[i].luongTL << endl;
		}
		outData.close();
		cout << "\n\t**GHI DANH SACH VAO FILE THANH CONG**\n";
	}
	else
		cout << "\n\t**MO FILE KHONG THANH CONG**\n";
}
int main()
{
	NV* list = 0;
	char luachon = ' ';
	int slNV = 0;
	bool input = false, xepLoai = false;
	do {
		system("cls");
		cout << "MENU QUAN LY LUONG NHAN VIEN KHOA CONG NGHE THONG TIN\n";
		cout << "===============================================================\n";
		cout << "1. NHAP THONG TIN NHAN VIEN\n";
		cout << "2. XUAT DANH SACH NHAN VIEN\n";
		cout << "3. TINH LUONG TRUNG BINH NHAN VIEN\n";
		cout << "4. TIM NHAN VIEN CO LUONG THAP NHAT, CAO NHAT VA IN RA MAN HINH\n";
		cout << "5. XEP LOAI NHAN VIEN\n";
		cout << "6. GHI DU LIEU NHAN VIEN RA FILE\n";
		cout << "===============================================================\n";
		luachon = _getch();
		switch (luachon)
		{
		case '1':
			nhapDSNV(list, slNV);
			input = true;
			cout << "\n\t**NHAP DANH SACH NHAN VIEN THANH CONG**\n";
			break;
		case '2':
			if (input && xepLoai)
			{
				xuatDSNV(list, slNV);
				cout << "\n\t**XUAT DANH SACH NHAN VIEN THANH CONG**\n";
			}
			else
				cout << "\n\t= Nhap danh sach hoac xep loai nhan vien truoc =\n";
			break;
		case '3':
			if(input && xepLoai)
				cout << "- Luong trung binh cua tat ca nhan vien: " << luongTB(list, slNV);
			else
				cout << "\n\t= Nhap danh sach hoac xep loai nhan vien truoc =\n";
			break;
		case '4':
			if (input && xepLoai)
			{
				cout << "-------------------------------------------------------------------\n";
				cout << "| MaNV\t| Ho ten\t\t| Tuoi\t\t| Luong thuc linh|\n";
				cout << "-------------------------------------------------------------------\n";
				xuatNV(luongCao(list, slNV));
				xuatNV(luongThap(list, slNV));
				cout << "-------------------------------------------------------------------\n";
			}
			else
				cout << "\n\t= Nhap danh sach hoac xep loai nhan vien truoc =\n";
			break;
		case '5':
			if (input)
			{
				phanLoai(list, slNV);
				xepLoai = true;
				cout << "\n\t**XEP LOAI NHAN VIEN THANH CONG**\n";
			}
			else
				cout << "\n\t= Nhap danh sach hoac xep loai nhan vien truoc =\n";
			break;
		case '6':
			if (input && xepLoai)
				ghiFile(list, slNV);
			else
				cout << "\n\t= Nhap danh sach hoac xep loai nhan vien truoc =\n";
			break;
		}
	} while (luachon >= '1' && luachon <= '6');
	if (luachon < '1' || luachon > '6')
		cout << "\n\t**KET THUC CHUONG TRINH**\n";
	delete[] list;
	return 0;
}