#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NhanVien
{
    string hoTen;
    int tuoi;
};

void nhap(NhanVien nv[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << "\n";
        cout << "Nhap ho va ten: ";
        getline(cin, nv[i].hoTen);
        cout << "Nhap tuoi: ";
        cin >> nv[i].tuoi;
        cin.ignore(1);
    }
}
void xuat(NhanVien nv[])
{
    cout << "\nSTT\tHo va ten\t\tTuoi\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "\t" << nv[i].hoTen << " \t" << nv[i].tuoi << endl;
    }
}
int main()
{
    NhanVien nv[10];
    cout << "Nhap vao thong tin cua 10 nhan vien\n";
    nhap(nv);
    xuat(nv);
    system("pause");
    return 0;
}