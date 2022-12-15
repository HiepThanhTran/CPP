#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 10;

struct SinhVien
{
	string maSV, hoTen;
	int namSinh = 0;
} typedef SV;

void nhap1SV(SV& sv)
{
	cin.ignore();
	cout << "Nhap ma sinh vien: "; getline(cin, sv.maSV);
	cout << "Nhap ho va ten: "; getline(cin, sv.hoTen);
	cout << "Nhap nam sinh: "; cin >> sv.namSinh;
}
void nhapDSSV(SV* list, int slsv)
{
	for (int i = 0; i < slsv; i++)
	{
		cout << "== Nhap thong tin sinh vien " << i + 1 << " ==\n";
		nhap1SV(list[i]);
	}
}
void ghiFile(SV* list, int slsv, string path)
{
	ofstream outData(path);
	if (outData.is_open())
	{
		for (int i = 0; i < slsv; i++)
		{
			outData << list[i].maSV << '#';
			outData << list[i].hoTen << '#';
			outData << list[i].namSinh << endl;
		}
		outData.close();
		cout << "\n**Ghi file thanh cong**\n";
	}
	else
		cout << "\n**Mo file khong thanh cong**\n";
}
void xuatTTTheoMaSV(string id, string path)
{
	SV sv;
	ifstream inData(path);
	if (inData.is_open())
	{
		bool flag = false;
		while (!inData.eof())
		{
			getline(inData, sv.maSV, '#');
			getline(inData, sv.hoTen, '#');
			inData >> sv.namSinh; inData.ignore(1);
			if (sv.maSV == id)
			{
				cout << "\n== Thong tin sinh vien can tim ==\n";
				cout << "Ma sinh vien: " << sv.maSV << endl;
				cout << "Ho va ten: " << sv.hoTen << endl;
				cout << "Nam sinh: " << sv.namSinh << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "\n**Khong tim thay sinh vien**\n";
		inData.close();
		cout << "\n**Doc file thanh cong**\n";
	}
	else
		cout << "\n**Mo file khong thanh cong**\n";
}
bool kiemTraHo(string s)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	if (s == "NGUYEN") return true;
	return false;
}
void locHoNguyen(SV* list, int slsv, SV*& newList, int& newSL)
{
	newList = new SV[slsv];
	newSL = 0;
	for (int i = 0; i < slsv; i++)
	{
		if (kiemTraHo(list[i].hoTen.substr(0, 6)))
		{
			newList[newSL] = list[i];
			newSL++;
		}
	}
}
int main()
{
	SV* newList = 0;
	int slsv = 0, newSL;
	string id;
	do {
		cout << "- Nhap vao so luong sinh vien: ";
		cin >> slsv;
		if (slsv < 1 || slsv > MAX)
			cout << "\n**So luong sinh vien khong hop le**\n";
	} while (slsv < 1 || slsv > MAX);
	SV* list = new SV[slsv];
	nhapDSSV(list, slsv);
	ghiFile(list, slsv, "BT10.txt");
	cout << "\nNhap ma sinh vien can tim: ";
	cin >> id;
	xuatTTTheoMaSV(id, "BT10.txt");
	locHoNguyen(list, slsv, newList, newSL);
	ghiFile(newList, newSL, "dsHoNguyen.txt");
	delete[] list;
	delete[] newList;
	return 0;
}