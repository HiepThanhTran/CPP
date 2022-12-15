#include<iostream>

using namespace std;

bool checkYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int main()
{
    int year;
    do{
        cout << "Nhap nam can kiem tra: ";
        cin >> year;
        if(year<1) cout << "So nam phai lon hon 0. Xin nhap lai!!\n";
    }while(year<1);
    if(checkYear(year)) {
        cout << "Nam " << year << " la nam nhuan\n";
    }else{
        cout << "Nam " << year << " khong phai nam nhuan\n";
    }
    system("pause");
    return 0;
}