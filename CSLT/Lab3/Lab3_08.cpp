#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int year = 0, month = 0;
    cout << "Nhap nam va thang:";
    cin >> year >> month;
    if (month < 1 || month>12 || year<=0)
        cout << "Khong hop le";
    switch (month) {
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            cout << "thang " << month << " co 29 ngay";
        }
        else {
            cout << "thang " << month << " co 28 ngay";
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "thang " << month << " co 31 ngay";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "thang " << month << " co 30 ngay";
        break;
    }
    cout << endl;
    system("pause");
    return 0;
}