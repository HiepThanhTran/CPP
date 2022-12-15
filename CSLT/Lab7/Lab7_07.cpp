#include<iostream>

using namespace std;

void menu() {
    cout << "1 - Cong (+)\n";
    cout << "2 - Tru (-)\n";
    cout << "3 - Nhan (*)\n";
    cout << "4 - Chia (/)\n";
}
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int multi(int a, int b) {
    return a * b;
}
double divi(double a, double b) {
    return a / b;
}
int main()
{
    int a, b, c, tiep;
    do {
        cout << "-----CASIO FAKE-----\n";
        menu();
        cout << "Nhap 2 so nguyen: ";
        cin >> a >> b;
        cout << "Chon (1 - 4): ";
        cin >> c;
        switch(c) {
        case 1:
            cout << a << " + " << b << " = " << add(a, b) << endl;
            break;
        case 2:
            cout << a << " - " << b << " = " << sub(a, b) << endl;
            break;
        case 3:
            cout << a << " * " << b << " = " << multi(a, b) << endl;
            break;
        case 4:
            if(b==0) { 
                cout << "INVALID!\n";
            }else{
                cout << a << " / " << b << " = " << divi(a, b) << endl;
            }
            break;
        default:
            cout << "INVALID!\n";
            return 0;
        }
        do {
            cout << "Tiep tuc (1) / Thoat (0): ";
            cin >> tiep;
        } while(tiep!=1 && tiep!=0);
    } while(tiep==1);
    if(tiep==0) cout << "Ket thuc chuong trinh.\n";
    system("pause");
    return 0;
}