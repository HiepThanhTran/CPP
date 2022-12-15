#include<iostream>

using namespace std;

int main()
{
    int n1, n2;
    do {
        cout << "Nhap so nguyen duong n1: ";
        cin >> n1;
        cout << "Nhap so nguyen duong n2: ";
        cin >> n2;
        if(n1>=n2 || n1<1) cout << "Xin nhap lai!\n";
    }while(n1>=n2 || n1<1);

    cout << "Doan [n1,n2] co cac so nguyen to la: ";
    for(int i=n1; i<=n2; i++) {
        int count = 0;
        for(int j=1; j<=i; j++) {
            if(i % j == 0) {
                count++;
            }
        }
        if(count==2) cout << i << " ";
    }
    cout << "\n";
    return 0;
}