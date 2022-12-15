#include<iostream>
using namespace std;
int main8p2() {
	int month, year, day, JDM = 0,maxofday=0;
	cout << "Nhap ngay: ";
	cin >> day;
	cout << "Nhap thang: ";
	cin >> month;
	cout << "Nhap nam: ";
	cin >> year;
	

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxofday = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxofday = 30;
		break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			maxofday = 29;
		else
			maxofday = 28;
		break;
	default:
		cout << "So thang khong hop le" << endl;
	}
	
	if (day<1 || day>maxofday)
	{
		cout << "Ngay khong hop le!";
	}else{
		JDM = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) + (365 * (year + 4800 - ((14 - month) / 12))) + ((year + 4800 - ((14 - month) / 12)) / 4) - ((year + 4800 - ((14 - month) / 12)) / 100) + ((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;

		switch (JDM) {
		case 0:
			cout << "Thu hai\n";
			break;
		case 1:
			cout << "Thu ba\n";
			break;
		case 2:
			cout << "Thu tu\n";
			break;
		case 3:
			cout << "Thu nam\n";
			break;
		case 4:
			cout << "Thu sau\n";
			break;
		case 5:
			cout << "Thu bay\n";
			break;
		case 6:
			cout << "Chu nhat\n";
			break;
		default:
			cout << "Khong hop le!\n";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}