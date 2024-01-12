#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
const int MAX = 50;

struct NTN
{
	int ngay, thang, nam;
};
struct Sach
{
	char maSach[256], tenSach[256];
	NTN namSX;
};

void nhap1Sach(Sach& s)
{
	cin.ignore();
	cout << "Nhap ma sach: ";
	cin.getline(s.maSach, 256);
	cout << "Nhap ten sach: ";
	cin.getline(s.tenSach, 256);
	cout << "Nhap nam san xuat: ";
	cin >> s.namSX.ngay >> s.namSX.thang >> s.namSX.nam;
}
void nhapDSS(Sach* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "**Nhap thong tin san pham thu " << i + 1 << "**\n";
		nhap1Sach(ds[i]);
	}
}
void docFile(Sach*& ds, int& n)
{
	ifstream inFile("DuLieuSach.txt");
	if (inFile)
	{
		inFile >> n;
		ds = new Sach[n];
		for (int i = 0; i < n; i++)
		{
			inFile.getline(ds[i].maSach, 256, '#');
			inFile.getline(ds[i].tenSach, 256, '#');
			inFile >> ds[i].namSX.ngay; inFile.ignore();
			inFile >> ds[i].namSX.thang; inFile.ignore();
			inFile >> ds[i].namSX.nam; inFile.ignore();
		}
		inFile.close();
	}
	else
		cout << "\n**MO FILE KHONG DUOC**\n";
}
void xuat1Sach(Sach s)
{
	cout << "Ma sach: " << s.maSach << endl;
	cout << "Ten sach: " << s.tenSach << endl;
	cout << "Nam san xuat: "
		<< s.namSX.ngay << "/"
		<< s.namSX.thang << "/"
		<< s.namSX.nam << endl;
}
void xuatDSS(Sach* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "**Thong tin sach thu " << i + 1 << "**\n";
		xuat1Sach(ds[i]);
	}
}
void sapXep(Sach* ds, int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if (ds[i].namSX.nam < ds[j].namSX.nam)
			{
				Sach temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
}
int dem2020(Sach* ds, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (ds[i].namSX.nam == 2020)
			dem++;
	return dem;
}
int doDaiChuoi(char* p)
{
	int i = 0;
	while (p[i] != '\0')
		i++;
	return i;
}
void xoa1KT(char* p, int pos)
{
	int n = doDaiChuoi(p);
	for (int i = pos; i < n; i++)
		p[i] = p[i + 1];
	p[n - 1] = '\0';
}
void chuanHoa(char* p)
{
	int n = doDaiChuoi(p);
	for (int i = 0; i < n; i++)
		if (p[i] == ' ' && p[i + 1] == ' ')
		{
			xoa1KT(p, i);
			i--;
		}
	if (p[0] == ' ') xoa1KT(p, 0);
	if (p[n - 1] == ' ') xoa1KT(p, n - 1);
	/*if (p[0] >= 'a' && p[0] <= 'z') p[0] -= 32;
	for (int i = 1; i < n; i++)
	{
		if (p[i] != ' ' && p[i - 1] == ' ' && p[i] >= 'a' && p[i] <= 'z')
			p[i] -= 32;
		if (p[i] != ' ' && p[i - 1] != ' ' && p[i] >= 'A' && p[i] <= 'Z')
			p[i] += 32;
	}*/
}
int demTu(char* p)
{
	chuanHoa(p);
	int dem = 0;
	while (*p)
	{
		if (*p == ' ')
			dem++;
		p++;
	}
	return dem + 1;
}
int demSach(Sach* ds, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (demTu(ds[i].tenSach) == 4)
			dem++;
	return dem;
}
int main()
{
	Sach* ds = 0;
	int luachon, n = 0;
	bool input = false, read = false;
	do{
		system("cls");
		cout << "1- Nhap thong tin sach (toi da 50)\n"
			<< "2- Doc du lieu tu file\n"
			<< "3- Xuat thong tin sach\n"
			<< "4- Sap xep giam dan theo nam xuat ban\n"
			<< "5- Dem so sach co nam xuat ban 2020\n"
			<< "6- Dem so sach ma ten sach co 4 tu\n"
			<< "7- Thoat\n"
			<< "- Ban chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			do {
				cout << "Nhap so luong sach: ";
				cin >> n;
			} while (n < 1 || n > MAX);
			ds = new Sach[n];
			nhapDSS(ds, n);
			input = true;
			break;
		case 2:
			if (input) delete[] ds;
			docFile(ds, n);
			read = true;
			break;
		case 3:
			if (input || read)
				xuatDSS(ds, n);
			else
				cout << "\n**NHAP DU LIEU CHO SACH TRUOC**\n";
			break;
		case 4:
			if (input || read)
			{
				sapXep(ds, n);
				cout << "\n**SAP XEP THANH CONG**\n";
			}
			else
				cout << "\n**NHAP DU LIEU CHO SACH TRUOC**\n";
			break;
		case 5:
			if (input || read)
				cout << "So luong sach co nam xuat ban 2020: " << dem2020(ds, n) << endl;
			else
				cout << "\n**NHAP DU LIEU CHO SACH TRUOC**\n";
			break;
		case 6:
			if (input || read)
				cout << "So luong sach ma ten co 4 tu: " << demSach(ds, n) << endl;
			else
				cout << "\n**NHAP DU LIEU CHO SACH TRUOC**\n";
			break;
		default:
			cout << "\n**THOAT CHUONG TRINH**\n";
		}
		_getch();
	} while (luachon >= 1 && luachon <= 6);
	delete[] ds;
	return 0;
}