#include<iostream>

using namespace std;

double dienTichHCN(double a, double b) {
    double dt;
    dt = a * b;
    return dt;
}
double chuViHCN(double a, double b) {
    double cv;
    cv = (a + b) * 2;
    return cv;
}
int main()
{
    double a, b;
    cout << "Nhap chieu dai HCN: ";
    cin >> a;
    cout << "Nhap chieu rong HCN: ";
    cin >> b;
    cout << "Dien tich HCN la " << dienTichHCN(a, b) << endl;
    cout << "Chu vi HCN la " << chuViHCN(a, b) << endl;
    system("pause");
    return 0;
}