#include <iostream>
#include<string>
using namespace std;

struct PhongBan
{
    string maPhongBan, tenPhongBan;
} typedef PB;

int main()
{
    PB pb1;
    cout << "Nhap ma phong ban: ";
    getline(cin, pb1.maPhongBan);
    cout << "Nhap ten phong ban: ";
    getline(cin, pb1.tenPhongBan);
    cout << "\n";
    cout << "Ma phong ban vua nhap: " << pb1.maPhongBan << endl;
    cout << "Ten phong ban vua nhap: " << pb1.tenPhongBan << endl;
    system("pause");
    return 0;
}