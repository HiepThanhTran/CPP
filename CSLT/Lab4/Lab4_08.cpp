//Viết chương trình nhận vào 1 số nguyên n > 0.
//Tính và xuất tổng các chữ số lẻ của n

#include<iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if(n <= 0) {
            cout << "Xin nhap lai!\n";
        }
    }while(n <= 0);

    int i = 1;
    while(i <= n) {
        if(i % 2 != 0)
        sum += i;
        i++;
    }
    cout << "Tong cac so le = " << sum << endl;
    return 0;
}