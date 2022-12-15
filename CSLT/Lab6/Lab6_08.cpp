#include<iostream>

using namespace std;

double chuViHV(double a) {
    return 4 * a;
}
double dienTichHV(double a) {
    return a * a;
}
void veHVRong(int a, char c) {
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=a; j++) {
            if(i==1 || j==1 || i==a || j==a) {
                cout << " " << c << " ";
            }else{
                cout << "   ";
            }
        }
        cout << endl;
    }
}
int main()
{
    double a;
    char c;
    cout << "Chon ky tu muon ve HV: ";
    cin >> c;
    do{
        cout << "Nhap canh HV: ";
        cin >> a;
        if(a<1) cout << "Canh HV phai > 0. Xin nhap lai!\n";
    }while(a<1);
    cout << "Chu vi HV = " << chuViHV(a) << endl;
    cout << "Dien tich HV = " << dienTichHV(a) << endl;
    cout << "Hinh vuong duoc ve voi ky tu " << c << endl;
    veHVRong(a, c);
    system("pause");
    return 0;
}