//Viết chương trình nhận vào 1 số nguyên n > 0.
//Xuất ra màn hình các giá trị thừa số nguyên tố của n.

#include<iostream>

using namespace std;

int main()
{
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if(n <= 0) {
            cout << "Xin nhap lai!\n";
        }
    }while(n <= 0);

    int i = 2;
    while(i <= n) {
        if(n % i == 0) {
            n /= i;
            cout << i;
            if(n > i) cout << " * ";
        }
        if(n % i != 0) i++;
    }
    cout << endl;
    return 0;
}