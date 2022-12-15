#include<iostream>

using namespace std;

int main()
{
    int d, r;
    do {
        cout << "Nhap chieu dai: ";
        cin >> d;
        cout << "Nhap chieu rong: ";
        cin >> r;
        if(d<1 || r<1) cout << "Khong hop le!\n";
    }while(d<1 || r<1);

    for(int i=1; i<=d; i++) {
        for(int j=1; j<r; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}