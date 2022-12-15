#include<iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if(n<1) cout << "Xin nhap lai!\n";
    }while(n<1);

    for(int i = 1; i<=n; i++) {
        sum += i;
    }
    cout << "Ket qua = " << sum << endl;
    return 0;
}