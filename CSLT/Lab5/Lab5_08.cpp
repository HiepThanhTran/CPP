#include<iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le!\n";
    }while(n<1);

    for(int i=1; i<=n; i+=2) {
        sum += i;
    }
    cout << "Tong cac so le tu 1 toi " << n << " = " << sum << endl;
    return 0;
}