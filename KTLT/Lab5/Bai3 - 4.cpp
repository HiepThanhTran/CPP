#include <iostream>
using namespace std;

struct PhanSo
{
    int tuSo, mauSo;
};
void nhapPS(PhanSo &PS)
{
    do
    {
        cout << "Nhap tu so: ";
        cin >> PS.tuSo;
        cout << "Nhap mau so: ";
        cin >> PS.mauSo;
        if (PS.mauSo == 0)
            cout << "\nPhan so khong hop le!\n";
    } while (PS.mauSo == 0);
}
int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}
void rutGon(PhanSo &PS)
{
    int d = UCLN(PS.tuSo, PS.mauSo);
    PS.tuSo /= d;
    PS.mauSo /= d;
}
void xuatPS(PhanSo PS)
{
    rutGon(PS);
    if (PS.tuSo % PS.mauSo == 0)
    {
        cout << PS.tuSo / PS.mauSo << endl;
    }
    else if (PS.mauSo < 0)
    {
        cout << (-1) * PS.tuSo << "/" << (-1) * PS.mauSo << endl;
    }
    else
    {
        cout << PS.tuSo << "/" << PS.mauSo << endl;
    }
}
PhanSo congPS(PhanSo a, PhanSo b)
{
    PhanSo ketQua;
    ketQua.tuSo = (a.tuSo * b.mauSo) + (b.tuSo * a.mauSo);
    ketQua.mauSo = a.mauSo * b.mauSo;
    rutGon(ketQua);
    return ketQua;
}
PhanSo truPS(PhanSo a, PhanSo b)
{
    PhanSo ketQua;
    ketQua.tuSo = (a.tuSo * b.mauSo) - (b.tuSo * a.mauSo);
    ketQua.mauSo = a.mauSo * b.mauSo;
    rutGon(ketQua);
    return ketQua;
}
PhanSo nhanPS(PhanSo a, PhanSo b)
{
    PhanSo ketQua;
    ketQua.tuSo = a.tuSo * b.tuSo;
    ketQua.mauSo = a.mauSo * b.mauSo;
    rutGon(ketQua);
    return ketQua;
}
PhanSo chiaPS(PhanSo a, PhanSo b)
{
    PhanSo ketQua;
    ketQua.tuSo = a.tuSo * b.mauSo;
    ketQua.mauSo = a.mauSo * b.tuSo;
    rutGon(ketQua);
    return ketQua;
}
int main()
{
    PhanSo a, b;
    cout << "Nhap phan so thu 1:\n";
    nhapPS(a);
    cout << "- Phan so vua nhap: ";
    xuatPS(a);
    cout << "\nNhap phan so thu 2:\n";
    nhapPS(b);
    cout << "- Phan so vua nhap: ";
    xuatPS(b);
    //
    cout << "\n- Ket qua tong cua 2 phan so: ";
    xuatPS(congPS(a, b));
    //
    cout << "- Ket qua hieu 2 phan so: ";
    xuatPS(truPS(a, b));
    //
    cout << "- Ket qua tich 2 phan so: ";
    xuatPS(nhanPS(a, b));
    //
    cout << "- Ket qua thuong 2 phan so: ";
    xuatPS(chiaPS(a, b));
    //
    system("pause");
    return 0;
}