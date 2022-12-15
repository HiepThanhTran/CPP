#include<iostream>
#include<cstring>
#include<string>
#include<conio.h>
using namespace std;
const int MAX = 30;

struct SanPham
{
	char maSP[11]{};
	string tenSP;
	double donGia = 0;
	int slTonKho = 0;
} typedef SP;
void nhap1SP(SP& sp)
{
	cin.ignore();
	cout << "- Ma san pham: ";
	cin.getline(sp.maSP, 11);
	cout << "- Ten san pham: ";
	getline(cin, sp.tenSP);
	cout << "- Don gia: ";
	cin >> sp.donGia;
	cout << "- So luong ton kho: ";
	cin >> sp.slTonKho;
}
void nhapNSP(SP* list, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "== NHAP THONG TIN SAN PHAM " << i + 1 << " ==\n";
		nhap1SP(*(list + i));
	}
}
void xuat1SP(SP sp)
{
	cout << "_ Ma san pham: " << sp.maSP << endl;
	cout << "_ Ten san pham: " << sp.tenSP << endl;
	cout << "_ Don gia: " << sp.donGia << endl;
	cout << "_ So luong ton kho: " << sp.slTonKho << endl;
}
void xuatNSP(SP* list, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "== THONG TIN SAN PHAM " << i + 1 << " ==\n";
		xuat1SP(*(list + i));
	}
}
void suaTT1SP(SP* list, int n, int stt)
{
	if (!(stt >= 1 && stt <= n))
	{
		cout << "== STT CAN SUA KHONG HOP LE ==\n";
		return;
	}
	int chon;
	do {
		system("cls");
		cout << "1- Sua ma SP\n"
			<< "2- Sua ten SP\n"
			<< "3- Sua don gia\n"
			<< "4- Sua so luong ton kho\n"
			<< "5- Sua tat ca\n"
			<< "6- Hoan tat\n"
			<< "- Chon TT can sua: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cin.ignore();
			cout << "_ Nhap ma SP moi: ";
			cin.getline(list[stt - 1].maSP, 11);
			break;
		case 2:
			cin.ignore();
			cout << "_ Nhap ten SP moi: ";
			getline(cin, list[stt - 1].tenSP);
			break;
		case 3:
			cout << "_ Nhap don gia moi: ";
			cin >> list[stt - 1].donGia;
			break;
		case 4:
			cout << "_ Nhap so luong ton kho moi: ";
			cin >> list[stt - 1].slTonKho;
			break;
		case 5:
			cout << "_ Nhap thong tin moi cho san pham " << stt << endl;
			nhap1SP(list[stt - 1]);
			break;
		default:
			cout << "== HOAN TAT VIEC SUA THONG TIN ==\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 5);
}
SP* xoaTT1SP(SP* list, int& n, int stt)
{
	for (int i = stt - 1; i < n - 1; i++)
		list[i] = list[i + 1];
	n--;
	SP* newList = new SP[n];
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[] list;
	return newList;
}
void sapXep(SP* list, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (list[i].slTonKho > list[j].slTonKho)
				swap(list[i], list[j]);
}
int main()
{
	int luaChon, n, stt = 0;
	bool input = false;
	SP* list = 0;
	do {
		system("cls");
		cout << "1- Nhap thong tin cho toi da 30 SP\n"
			<< "2- Xuat thong tin cac san pham\n"
			<< "3- Sua thong tin 1 san pham\n"
			<< "4- Xoa thong tin 1 san pham\n"
			<< "5- Sap xep theo so luong ton kho tang dan\n"
			<< "6- Ket thuc\n"
			<< "- Nhap chuc nang can su dung: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			do {
				cout << "- Nhap so luong san pham: ";
				cin >> n;
				if (n < 1 || n > MAX)
					cout << "== SO LUONG SAN PHAM KHONG HOP LE ==\n";
			} while (n < 1 || n > MAX);
			list = new SP[n];
			nhapNSP(list, n);
			input = true;
			break;
		case 2:
			if (input)
				xuatNSP(list, n);
			else
				cout << "== NHAP TT SAN PHAM TRUOC ==\n";
			break;
		case 3:
			if (input)
			{
				cout << "- Nhap STT SP can sua TT: ";
				cin >> stt;
				suaTT1SP(list, n, stt);
			}
			else
				cout << "== NHAP TT SAN PHAM TRUOC ==\n";
			break;
		case 4:
			if (input)
			{
				do {
					cout << "- Nhap STT SP can xoa TT: ";
					cin >> stt;
					if (stt < 1 || stt > n)
						cout << "== STT KHONG HOP LE ==\n";
				} while (stt < 1 || stt > n);
				list = xoaTT1SP(list, n, stt);
				cout << "== XOA TT SP THANH CONG ==\n";
			}
			else
				cout << "== NHAP TT SAN PHAM TRUOC ==\n";
			break;
		case 5:
			if (input)
			{
				sapXep(list, n);
				cout << "== SAP XEP THANH CONG ==\n";
			}
			else
				cout << "== NHAP TT SAN PHAM TRUOC ==\n";
			break;
		default:
			cout << "== KET THUC CHUONG TRINH ==\n";
			delete[] list;
		}
		_getch();
	} while (luaChon >= 1 && luaChon <= 5);
	return 0;
}