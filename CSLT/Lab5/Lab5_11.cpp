#include<iostream>

using namespace std;

int main()
{
    int c;
    do {
        cout << "Nhap canh hinh vuong: ";
        cin >> c;
        if(c<1) cout << "Canh hinh vuong > 0. Xin nhap lai!\n";
    }while(c<1);
    cout << "Cau a: Hinh vuong dac\n\n";
    for(int i=1; i<=c; i++) {
        for(int j=1; j<=c; j++) {
            cout << " *";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Cau b: Hinh vuong rong\n\n";
    for(int i=1; i<=c; i++) {
        for(int j=1; j<=c; j++) {
            if(i==1 || i==c || j==1 || j==c) {
                cout << " *";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}