#include <iostream>
#include <math.h>
using namespace std;
int main6() {
    int year =0;
    cout << " Nam ";
    cin >> year;
    if (year % 100 == 0)

    {
        if (year % 400 == 0) {
            cout << year << " la nam nhuan";
        }
        else {
            cout << year << " khong phai la nam nhuan";
        }
    }
    else if (year % 4 == 0) {
        cout << year << " la nam nhuan";
    }
    else {
        cout << year << " khong phai la nam nhuan";
    }
    system("pause");
    return 0;
}