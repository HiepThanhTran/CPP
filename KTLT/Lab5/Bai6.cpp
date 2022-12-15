#include<iostream>
#include<string>
using namespace std;
const int MAXSIZE = 50;

struct Kho
{
    string tenKho;
    double taiTrong;
};
void nhapKho(Kho *p)
{
    cin.ignore(1);
    cout << "Nhap ten kho: ";
    getline(cin, p->tenKho);
    cout << "Nhap tai trong kho: ";
    cin >> p->taiTrong;
}
void nhapDSKho(Kho *p, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap du lieu kho thu " << i + 1 << "\n";
        nhapKho(p + i);
    }
}
void xuatKho(Kho *p)
{
    cout << "\t" << p->tenKho;
    cout << "\t\t" << p->taiTrong << endl;
}
void xuatDSKho(Kho *p, int n)
{
    cout << "\n____________________________________________________________________________________________________\n\n";
    cout << "STT\tTen kho\t\tTai trong\n";
    for(int i = 0; i < n; i++)
    {
        cout << i + 1;
        xuatKho(p + i);
    }
    cout << "____________________________________________________________________________________________________\n";
}
void khoConTrong(Kho *p, int n)
{
    cout << "\n____________________________________________________________________________________________________\n\n";
    cout << "\tDANH SACH KHO CON TRONG\n";
    for(int i = 0; i < n; i++)
    {
        if((p + i)->taiTrong > 10)
            xuatKho(p + i);
    }
    cout << "____________________________________________________________________________________________________\n";
}
int main()
{
    int n;
    do{
        cout << "Nhap so luong kho: ";
        cin >> n;
        if(n < 1 || n > MAXSIZE) cout << "So luong kho khong hop le!\n";
    }while(n < 1 || n > MAXSIZE);
    Kho *p = new Kho[n];
    nhapDSKho(p, n);
    xuatDSKho(p, n);
    khoConTrong(p, n);
    delete p;
    system("pause");
    return 0;
}