#include<iostream>
#include<string>
using namespace std;
const int MAX = 50;

struct SV
{
	string mssv, hT, maLop;
	double diemTB = 0;
};
struct DSSV
{
	SV* sv = 0;
	int n = 0;
};

void printLine(int n)
{
	for (int i = 0; i < n; i++)
		cout << "_";
	cout << "\n";
}
void nhapSV(SV& sv)
{
	cin.ignore(1);
	cout << "_ Nhap ma so sinh vien: ";
	getline(cin, sv.mssv);
	cout << "_ Nhap ho va ten: ";
	getline(cin, sv.hT);
	cout << "_ Nhap ma lop: ";
	getline(cin, sv.maLop);
	cout << "_ Nhap diem trung binh: ";
	cin >> sv.diemTB;
}
void nhapDSSV(DSSV& ds)
{
	printLine(50);
	do {
		cout << "Nhap so luong sinh vien: ";
		cin >> ds.n;
		if (ds.n < 1 || ds.n > MAX)
			cout << "\n**SO LUONG SINH VIEN KHONG HOP LE**\n";
	} while (ds.n < 1 || ds.n > MAX);
	ds.sv = new SV[ds.n];
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t**NHAP THONG TIN SINH VIEN THU " << i + 1 << "**\n";
		nhapSV(ds.sv[i]);
	}
	printLine(50);
}
void xuatSV(SV& sv)
{
	cout << "_ MSSV: " << sv.mssv << endl;
	cout << "_ Ho va ten: " << sv.hT << endl;
	cout << "_ Ma lop: " << sv.maLop << endl;
	cout << "_ Diem trung binh: " << sv.diemTB << endl;
}
void xuatDSSV(DSSV& ds)
{
	printLine(50);
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t**THONG TIN SINH VIEN THU " << i + 1 << "**\n";
		xuatSV(ds.sv[i]);
	}
	printLine(50);
}
int demTH73(DSSV ds)
{
	int count = 0;
	for (int i = 0; i < ds.n; i++)
		if (ds.sv[i].maLop == "TH73")
			count++;
	return count;
}
int demTB(DSSV ds)
{
	int count = 0;
	for (int i = 0; i < ds.n; i++)
		if (ds.sv[i].diemTB >= 8)
			count++;
	return count;
}
void sapXepGiamDan(DSSV& ds)
{
	for (int i = 0; i < ds.n - 1; i++)
	{
		for (int j = i + 1; j < ds.n; j++)
			if (ds.sv[i].diemTB < ds.sv[j].diemTB)
			{
				SV tmp = ds.sv[i];
				ds.sv[i] = ds.sv[j];
				ds.sv[j] = tmp;
			}
	}
}
void capNhatTT(DSSV& ds)
{
	int stt = 0;
	do {
		cout << "_Nhap so thu tu sinh vien can sua thong tin: ";
		cin >> stt;
		if (stt < 1 || stt > ds.n)
			cout << "\n\t**SINH VIEN KHONG TON TAI**\n";
	} while (stt < 1 || stt > ds.n);
	cout << "\n\t**SUA THONG TIN SINH VIEN THU " << stt << "**\n";
	nhapSV(ds.sv[stt - 1]);
}
void xoaSV(DSSV& ds, int stt)
{
	for (int i = stt; i < ds.n - 1; i++)
		ds.sv[i] = ds.sv[i + 1];
	DSSV newDS;
	newDS.n = ds.n - 1;
	newDS.sv = new SV[newDS.n];
	for (int i = 0; i < newDS.n; i++)
		newDS.sv[i] = ds.sv[i];
	delete[] ds.sv;
	ds = newDS;
}
void themSV(DSSV& ds)
{
	DSSV newDS;
	newDS.n = ds.n + 1;
	newDS.sv = new SV[newDS.n];
	for (int i = 0; i < newDS.n - 1; i++)
		newDS.sv[i] = ds.sv[i];
	cout << "\n\t**THONG TIN SINH VIEN THU " << ds.n << "**\n";
	nhapSV(newDS.sv[newDS.n - 1]);
	delete[] ds.sv;
	ds = newDS;
}
bool ktTAnh(string s)
{
	string tmp = "Anh";
	int len = 0;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == ' ')
		{
			for (int j = i + 1; j < n; j++)
				if (s[j] != tmp[len++]) return false;
			return true;
		}
}
void lietKeTAnh(DSSV ds)
{
	int count = 0;
	cout << "\n\t**DANH SACH CAC SINH VIEN CO TEN 'ANH'**\n";
	printLine(50);
	for (int i = 0; i < ds.n; i++)
		if (ktTAnh(ds.sv[i].hT))
		{
			count++;
			cout << "\n**SINH VIEN THU " << count << "**\n";
			xuatSV(ds.sv[i]);

		}
	if (count == 0)
		cout << "\n\t**KHONG CO SINH VIEN TEN 'ANH' TRONG DANH SACH**\n";
	printLine(50);
}
int main()
{
	int option = 0, soLuongTH73 = 0, soLuongTB8 = 0, stt = 0;
	bool flag = false;
	DSSV ds;
	do {
		system("cls");
		cout << "1. Nhap danh sach sinh vien (Toi da: 50 sinh vien)\n";
		cout << "2. Xuat danh sach sinh vien\n";
		cout << "3. So luong sinh vien co ma lop TH73\n";
		cout << "4. So luong sinh vien co diem TB 8.0 tro len\n";
		cout << "5. Sap xep danh sach sinh vien theo diem TB giam dan\n";
		cout << "6. Cap nhat thong tin sinh vien theo so thu tu\n";
		cout << "7. Xoa 1 sinh vien ra khoi danh sach\n";
		cout << "8. Them 1 sinh vien vao danh sach\n";
		cout << "9. Xuat danh sach sinh vien co ten la 'Anh'\n";
		cout << "0. Thoat\n";
		cout << "- Chon chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			nhapDSSV(ds);
			cout << "\n**NHAP DANH SACH SINH VIEN THANH CONG**\n";
			break;
		case 2:
			xuatDSSV(ds);
			cout << "\n**XUAT DANH SACH SINH VIEN THANH CONG**\n";
			break;
		case 3:
			soLuongTH73 = demTH73(ds);
			cout << "So luong sinh vien co ma lop TH73: " << soLuongTH73 << endl;
			break;
		case 4:
			soLuongTB8 = demTB(ds);
			cout << "So luong sinh vien co diem TB 8.0 tro len: " << soLuongTB8 << endl;
			break;
		case 5:
			sapXepGiamDan(ds);
			cout << "\n\t**SAP XEP THANH CONG**\n";
			break;
		case 6:
			capNhatTT(ds);
			cout << "\n\t**CAP NHAT THONG TIN SINH VIEN THANH CONG**\n";
			break;
		case 7:
			do {
				cout << "Nhap so thu tu sinh vien can xoa: ";
				cin >> stt;
				if (stt < 1 || stt > ds.n)
					cout << "\n\t**SINH VIEN KHONG TON TAI**\n\n";
			} while (stt < 1 || stt > ds.n);
			xoaSV(ds, stt - 1);
			cout << "\n\t**XOA SINH VIEN THANH CONG**\n";
			break;
		case 8:
			themSV(ds);
			cout << "\n\t**THEM SINH VIEN THANH CONG**\n";
			break;
		case 9:
			lietKeTAnh(ds);
			break;
		case 0:
			cout << "\n\t**THOAT CHUONG TRINH**\n";
			delete[] ds.sv;
			return 0;
		default:
			cout << "\n\t**CHUC NANG HIEN CHUA CO**\n";
		}
		system("pause");
	} while (option >= 1 && option <= 9);
	return 0;
}