#include<iostream>

using namespace std;

int main()
{
    long long n, giaithua = 1;
    do {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n<0) cout << "Xin nhap lai!\n";
    }while(n<0);

    for(int i=1; i<=n; i++) {
        giaithua *= i;
    }
    cout << "Giai thua cua " << n << " la: " << giaithua << endl;
    return 0;
}