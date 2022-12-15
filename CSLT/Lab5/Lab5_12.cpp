#include<iostream>

using namespace std;

int main()
{
    int h;
    do {
        cout << "Nhap chieu cao cua tam giac: ";
        cin >> h;
        if(h<1) cout << "Chieu cao phai > 0.\n";
    }while(h<1);
    cout << "Cau a:\n\n";
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=h; j++) {
            if(j==1 || j==i || i==h) {
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Cau b:\n\n";
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=h-i; j++) {
            cout << "  ";
        }
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Cau c:\n\n";
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=h-i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Cau d:\n\n";
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=i-1; j++) {
            cout << "  ";
        }
        for(int j=1; j<=h-i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Cau e:\n\n";
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=h-i; j++) {
            cout << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}