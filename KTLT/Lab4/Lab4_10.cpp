#include<iostream>
#include<cstring>
using namespace std;

bool checkYear(int year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}
int checkMonth(int month, int year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (checkYear(year))
			return 29;
		return 28;
	}
}
int getDay(char* p)
{
	return atoi(strtok(p, "-"));
}
int getMonth(char* p)
{
	return atoi(strtok(p, "-"));
}
int getYear(char* p)
{
	return atoi(strtok(p, "-"));
}
void doiDinhDang(int day, int month, int year)
{
	switch (month)
	{
	case 1:
		cout << "January " << day << ", " << year << endl;
		break;
	case 2:
		cout << "February " << day << ", " << year << endl;
		break;
	case 3:
		cout << "March " << day << ", " << year << endl;
		break;
	case 4:
		cout << "April " << day << ", " << year << endl;
		break;
	case 5:
		cout << "May " << day << ", " << year << endl;
		break;
	case 6:
		cout << "June " << day << ", " << year << endl;
		break;
	case 7:
		cout << "July " << day << ", " << year << endl;
		break;
	case 8:
		cout << "August " << day << ", " << year << endl;
		break;
	case 9:
		cout << "September " << day << ", " << year << endl;
		break;
	case 10:
		cout << "October " << day << ", " << year << endl;
		break;
	case 11:
		cout << "November " << day << ", " << year << endl;
		break;
	case 12:
		cout << "December " << day << ", " << year << endl;
		break;
	}
}
int main()
{
	char NTN[256];
	char* p = NTN;
	int len = 0, day = 0, month = 0, year = 0;
	do {
		cout << "Nhap vao Ngay-Thang-Nam: ";
		cin.getline(p, 256);
		len = strlen(p);
		day = getDay(p);
		month = getMonth(NULL);
		year = getYear(NULL);
		if (!(len == 10) || day < 1 || day > checkMonth(month, year) || month < 1 || month > 12 || year < 1) cout << "\nDinh dang Ngay-Thang-Nam khong hop le!\n";
	} while (!(len == 10) || day < 1 || day > checkMonth(month, year) || month < 1 || month > 12 || year < 1);
	cout << "\n";
	doiDinhDang(day, month, year);
	return 0;
}