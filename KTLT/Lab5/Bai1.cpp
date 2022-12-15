#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
    string maNV;
    string hoTen;
    int namSinh = 0;
    string chucVu;
    double bacLuong = 0;
};
int main()
{
    NhanVien nv;
    cout << "Nhap ma cua nhan vien: ";
    getline(cin, nv.maNV);
    cout << "Nhap ho va ten cua nhan vien: ";
    getline(cin, nv.hoTen);
    cout << "Nhap nam sinh cua nhan vien: ";
    cin >> nv.namSinh;
    cin.ignore(1);
    cout << "Nhap chuc vu cua nhan vien: ";
    getline(cin, nv.chucVu);
    cout << "Nhap bac luong cua nhan vien: ";
    cin >> nv.bacLuong;
    cout << "Ma nhan vien: " << nv.maNV << endl;
    cout << "Ho va ten: " << nv.hoTen << endl;
    cout << "Nam sinh: " << nv.namSinh << endl;
    cout << "Chuc vu: " << nv.chucVu << endl;
    cout << "Bac luong: " << nv.bacLuong << endl;
    system("pause");
    return 0;
}