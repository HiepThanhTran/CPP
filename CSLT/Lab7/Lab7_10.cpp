#include<iostream>

using namespace std;

bool checkYear(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
int checkMonth(int month, int year) {
    switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if(checkYear(year)) return 29;
        return 28;
    }
}
int count(int day, int month, int year) {
    int count = day;
    for(int i = 1; i < month; i++) {
            count += checkMonth(i, year);
    }
    return count;
}
int main() {
    int day, month, year;
    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;
    if(day < 1 || day > checkMonth(month, year) || month < 1 || month > 12 || year < 1) {
        cout << "Khong hop le. Xin kiem tra lai!\n";
    }else{
        cout << day << "/" << month << "/" << year << " la ngay thu " << count(day, month, year) << endl; 
    }
    system("pause");
    return 0;
}