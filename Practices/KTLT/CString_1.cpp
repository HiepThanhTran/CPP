#include<iostream>
#include<cstring>
using namespace std;

bool checkDigit(char* p)
{
	int n = strlen(p);
	for (int i = 0; i < n; i++)
		if (p[i] >= '0' && p[i] <= '9') return true;
	return false;
}
bool checkSpace(char* p)
{
	int n = strlen(p);
	if (p[0] == ' ' || p[n - 1] == ' ') return true;
	return false;
}
void delSpace(char* p)
{
	// Xoa khoang trang thua dau chuoi
	while (p[0] == ' ')
	{
		int n = strlen(p);
		for (int i = 0; i < n - 1; i++)
			p[i] = p[i + 1];
		p[n - 1] = '\0';
	}
	// Xoa khoang trang thua cuoi chuoi
	while (p[strlen(p) - 1] == ' ')
	{
		int n = strlen(p);
		p[n - 1] = '\0';
	}
	// Xoa khoang trang thua ben trong
	while (*p)
	{
		if (*p == ' ' && *(p + 1) == ' ')
		{
			int n = strlen(p);
			for (int i = 0; i < n - 1; i++)
				p[i] = p[i + 1];
			p[n - 1] = '\0';
		}
		else
			p++;
	}
}
void separate(char* p)
{
	while (*p)
	{
		cout << *p;
		if (*p == ' ' && *(p + 1) != ' ')
			cout << "\n";
		p++;
	}
}
int demSoCau(char* p)
{
	int count = 0;
	int n = strlen(p);
	for (int i = 0; i < n; i++)
		if (p[i] == '.' || p[i] == '!' || p[i] == '?' || i == n - 1)
			count++;
	return count;
}
int demDauCau(char* p)
{
	int count = 0;
	while (*p)
	{
		if (*p == '.' || *p == '!' || *p == '?')
			count++;
		p++;
	}
	return count;
}
int main()
{
	int option, soCau = 0, soDauCau = 0;;
	char s[256];
	cout << "Nhap vao 1 chuoi bat ky: ";
	cin.getline(s, 256);
	char* p = s;
	do {
		cout << "1. Kiem tra chuoi co ki tu so khong?\n";
		cout << "2. Kiem tra chuoi co khoang trang dau/cuoi khong?\n";
		cout << "3. Ham xoa khoang trang thua o dau/cuoi/ben trong chuoi\n";
		cout << "4. Ham tach tung tu trong chuoi\n";
		cout << "5. Ham dem so cau trong chuoi\n";
		cout << "6. Ham dem so dau cau trong chuoi\n";
		cout << "7. Thoat\n";
		cout << "- Nhap chuc nang can su dung: ";
		cin >> option;
		switch (option)
		{
		case 1:
			if (checkDigit(p))
				cout << "Chuoi co chua ki tu so!\n";
			else
				cout << "Chuoi khong chua ki tu so\n";
			break;
		case 2:
			if (checkSpace(p))
				cout << "Chuoi co chua khoang trang dau/cuoi chuoi\n";
			else
				cout << "Chuoi khong chua khoang trang dau/cuoi chuoi\n";
			break;
		case 3:
			cout << "Chuoi ban dau: [" << p << "]\n";
			delSpace(p);
			cout << "Chuoi sau khi xoa khoang trang: [" << p << "]\n";
			break;
		case 4:

			break;
		case 5:
			soCau = demSoCau(p);
			cout << "Chuoi co " << soCau << " cau\n";
			break;
		case 6:
			soDauCau = demDauCau(p);
			cout << "Chuoi co " << soDauCau << " dau cau\n";
			break;
		case 7:
			cout << "\n**THOAT CHUONG TRINH**\n";
			break;
		default:
			cout << "\n**CHUC NANG HIEN CHUA CO**\n";
		}
	} while (option != 7);
	return 0;
}