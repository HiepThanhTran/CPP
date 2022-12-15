//Viết chương trình nhận vào 1 số nguyên n > 0.
//Tách từng chữ số của n và thể hiện chúng dưới dạng cách nhau một khoảng cách.

#include<iostream>

using namespace std;

int main()
{
    int n, t, s = 0;
    do {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n <= 0) {
            cout << "Xin nhap lai!\n";
        }
    }while(n <= 0);

    while(n > 0) {
        s = s*10 + n%10;
        n /= 10;
    }

    while(s > 0) {
        t = s % 10;
        cout << t << " ";
        s /= 10;
    }
    cout << endl;
    return 0;
}