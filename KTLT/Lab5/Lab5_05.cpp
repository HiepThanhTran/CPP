#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 50;

struct NTN
{
	int ngay, thang, nam;
};
struct Sach
{
	char tenSach[21];
	char tenTG[21];
	NTN namXB;
};

void nhap1Sach(Sach& sach)
{
	cin.ignore();
	cout << "Nhap ten sach: ";
	cin.getline(sach.tenSach, 21);
	cout << "Nhap ten tac gia: ";
	cin.getline(sach.tenTG, 21);
	cout << "Nhap nam xuat ban: ";
	cin >> sach.namXB.ngay >> sach.namXB.thang >> sach.namXB.nam;
}
void nhapNSach(Sach* list, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "== NHAP THONG TIN SACH THU " << i + 1 << " ==\n";
		nhap1Sach(list[i]);
	}
}
void xuat1Sach(Sach sach)
{
	cout << "Ten sach: " << sach.tenSach << endl;
	cout << "Ten tac gia: " << sach.tenTG << endl;
	cout << "Nam xuat ban: " << sach.namXB.ngay << "/" << sach.namXB.thang << "/" << sach.namXB.nam << endl;
}
char* inHoa(char* s)
{
	char temp[21] = "";
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			temp[i] = s[i] - 32;
		else
			temp[i] = s[i];
	return temp;
}
void xuatSachTGTranDung(Sach* list, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(inHoa(list[i].tenTG), "TRAN DUNG"))
		{
			count++;
			if (count == 1)
			{
				cout << "== THONG TIN CAC QUYEN SACH CUA TAC GIA TRAN DUNG ==\n";
				xuat1Sach(list[i]);
			}
			else
				xuat1Sach(list[i]);
		}
	}
	if (count == 0)
		cout << "== KHONG CO QUYEN SACH NAO CUA TAC GIA TRAN DUNG ==\n";
}
int main()
{
	int n;
	do {
		cout << "Nhap so luong sach: ";
		cin >> n;
		if (n < 1 || n > MAX)
			cout << "== SO LUONG SACH KHONG HOP LE ==\n";
	} while (n < 1 || n > MAX);
	Sach* list = new Sach[n];
	nhapNSach(list, n);
	xuatSachTGTranDung(list, n);
	delete[] list;
	return 0;
}