#include<iostream>
#include<string>
using namespace std;

struct Lop
{
	string maLop, tenLop, tenKhoa;
	int soSV = 0;
};

void nhap1Lop(Lop& lop)
{
	cin.ignore();
	cout << "Nhap ma lop: "; getline(cin, lop.maLop);
	cout << "Nhap ten lop: "; getline(cin, lop.tenLop);
	cout << "Nhap ten khoa: "; getline(cin, lop.tenKhoa);
	cout << "Nhap so sinh vien: "; cin >> lop.soSV;
}
void nhapDSL(Lop*& ds, int& n)
{
	do {
		cout << "Nhap so luong lop: ";
		cin >> n;
		if (n < 1 || n > INT_MAX)
			cout << "So luong lop khong hop le. Nhap lai!\n";
	} while (n < 1 || n > INT_MAX);
	ds = new Lop[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\n**Nhap thong tin lop thu " << i + 1 << "**\n";
		nhap1Lop(ds[i]);
	}
}
void xuat1Lop(Lop lop)
{
	cout << "Ma lop: " << lop.maLop << endl;
	cout << "Ten lop: " << lop.tenLop << endl;
	cout << "Ten khoa: " << lop.tenKhoa << endl;
	cout << "So sinh vien: " << lop.soSV << endl;
}
void xuatDSL(Lop* ds, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t**Thong tin lop thu " << i + 1 << "**\n";
		xuat1Lop(ds[i]);
	}
}
int tongSVIT(Lop* ds, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (ds[i].tenKhoa == "CNTT" || ds[i].tenKhoa == "Cong nghe thong tin" || ds[i].tenKhoa == "CONG NGHE THONG TIN" || ds[i].tenKhoa == "cong nghe thong tin")
			count++;
	return count;
}
int khoaNN(Lop* ds, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (ds[i].tenKhoa == "NN" || ds[i].tenKhoa == "Ngoai ngu" || ds[i].tenKhoa == "NGOAI NGU" || ds[i].tenKhoa == "ngoai ngu")
			count++;
	return count;
}
Lop* xoa1Lop(Lop* ds, int &n, int stt)
{
	for (int i = stt; i < n - 1; i++)
		ds[i] = ds[i + 1];
	n--;
	Lop* newDS = new Lop[n];
	for (int i = 0; i < n; i++)
		newDS[i] = ds[i];
	delete[] ds;
	return newDS;
}
int main()
{
	Lop* list = 0;
	int option = 0, n, stt = 0;
	bool input = false;
	do
	{
		system("cls");
		cout << "1. Nhap danh sach cac lop\n";
		cout << "2. Xuat danh sach cac lop\n";
		cout << "3. Tong sinh vien khoa 'Cong nghe thong tin'\n";
		cout << "4. Tong lop khoa 'Ngoai ngu'\n";
		cout << "5. Xoa 1 lop ra khoi danh sach\n";
		cout << "6. Xoa cac lop 'Co ban' trong danh sach\n";
		cout << "7. Thoat\n";
		cout << "- Chon chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			nhapDSL(list, n);
			cout << "\n\t**NHAP DANH SACH LOP THANH CONG**\n";
			input = true;
			break;
		case 2:
			if (input)
			{
				xuatDSL(list, n);
				cout << "\n\t**XUAT DANH SACH LOP THANH CONG**\n";
			}
			else
				cout << "\n\t**VUI LONG NHAP DANH SACH LOP TRUOC**\n";
			break;
		case 3:
			if (input)
				cout << "Khoa CNTT co " << tongSVIT(list, n) << " sinh vien\n";
			else
				cout << "\n\t**VUI LONG NHAP DANH SACH LOP TRUOC**\n";
			break;
		case 4:
			if (input)
				cout << "Khoa NN co " << khoaNN(list, n) << " lop\n";
			else
				cout << "\n\t**VUI LONG NHAP DANH SACH LOP TRUOC**\n";
			break;
		case 5:
			if (input)
			{
				do {
					cout << "Nhap so thu tu lop can xoa: ";
					cin >> stt;
					if (stt < 1 || stt > n)
						cout << "\n\t**LOP KHONG TON TAI**\n";
					system("cls");
				} while (stt < 1 || stt > n);
				list = xoa1Lop(list, n, stt - 1);
				cout << "\n\t**XOA LOP THANH CONG**\n";
			}
			else
				cout << "\n\t**VUI LONG NHAP DANH SACH LOP TRUOC**\n";
			break;
		case 6:
			if (input)
			{

				cout << "\n\t**XOA CAC KHOA CO BAN THANH CONG**\n";
			}
			else
				cout << "\n\t**VUI LONG NHAP DANH SACH LOP TRUOC**\n";
			break;
		case 7:
			cout << "\n\t**THOAT CHUONG TRINH**\n";
			delete[] list;
			return 0;
		default:
			cout << "\n\t**THOAT CHUONG TRINH**\n";
		}
		system("pause");
	} while (option >= 1 && option <= 7);
	return 0;
}