#include<iostream>

using namespace std;

int main()
{
    int h;
    do {
        cout << "Nhap chieu cao cua tam giac: ";
        cin >> h;
        if(h < 1) cout << "Chieu cao phai > 0.\n";
    }while(h < 1);

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}