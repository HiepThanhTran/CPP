#include <iostream>
#include <string>
using namespace std;
const int YEAR = 2022;

struct NhanVien
{
    string maNV, hoTen;
    int namLam, namSinh;
} typedef NV;
struct ThamNien
{
    int tuoi, thamNien;
} typedef TN;

void nhapTT(NV &nv)
{
    cout << "Nhap ma nhan vien: ";
    getline(cin, nv.maNV);
    cout << "Nhap ho va ten nhan vien: ";
    getline(cin, nv.hoTen);
    cout << "Nhap nam vao lam cua nhan vien: ";
    cin >> nv.namLam;
    cout << "Nhap nam sinh cua nhan vien: ";
    cin >> nv.namSinh;
}
void xuatTT(NV nv)
{
    cout << "Ma nhan vien: " << nv.maNV << endl;
    cout << "Ho va ten nhan vien: " << nv.hoTen << endl;
    cout << "Nam vao lam cua nhan vien: " << nv.namLam << endl;
    cout << "Nam sinh cua nhan vien: " << nv.namSinh << endl;
}
TN TVTN(NV nv)
{
    TN tmp;
    tmp.tuoi = YEAR - nv.namSinh;
    tmp.thamNien = YEAR - nv.namLam;
    return tmp;
}
int main()
{
    NV nv1;
    cout << "\tNHAP THONG TIN NHAN VIEN\n";
    nhapTT(nv1);
    cout << "\nXUAT THONG TIN NHAN VIEN VUA NHAP\n";
    xuatTT(nv1);
    cout << "\nTuoi cua nhan vien: " << TVTN(nv1).tuoi << endl;
    cout << "Tham nien cua nhan vien: " << TVTN(nv1).thamNien << endl;
    system("pause");
    return 0;
}