#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXSIZE = 30;

struct NTN
{
    int ngay;
    int thang;
    int nam;
};
struct SinhVien
{
    string hoTen;
    NTN ngaySinh;
    double diemToan;
};
void nhapSV(SinhVien *sv)
{
    cin.ignore(1);
    cout << "Nhap ho va ten: ";
    getline(cin, sv->hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> sv->ngaySinh.ngay;
    cout << "Nhap thang sinh: ";
    cin >> sv->ngaySinh.thang;
    cout << "Nhap nam sinh: ";
    cin >> sv->ngaySinh.nam;
    cout << "Nhap diem toan: ";
    cin >> sv->diemToan;
}
void nhapDSSV(SinhVien *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << "\n";
        nhapSV(sv + i);
    }
}
void xuatSV(SinhVien *sv)
{
    cout << "\t" << sv->hoTen;
    cout << " \t" << sv->ngaySinh.ngay;
    cout << "\t\t" << sv->ngaySinh.thang;
    cout << "\t\t" << sv->ngaySinh.nam;
    cout << "\t\t" << sv->diemToan << endl;
}
void line()
{
    cout << "\n";
    for (int i = 0; i < 100; i++)
    {
        cout << "_";
    }
    cout << "\n";
}
void xuatDSSV(SinhVien *sv, int n)
{
    line();
    cout << "STT\tHo va ten\t\tNgay sinh\tThang sinh\tNam sinh\tDiem toan\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1;
        xuatSV(sv + i);
    }
    line();
}
void diemToanCaoHonTB(SinhVien *sv, int n)
{
    line();
    cout << "\tDANH SACH SINH VIEN CO DIEM TOAN CAO HON DIEM TRUNG BINH CA LOP\n";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (sv + i)->diemToan;
    }
    double avg = sum / n;
    for (int i = 0; i < n; i++)
    {
        if ((sv + i)->diemToan > avg)
        {
            xuatSV(sv + i);
        }
    }
    line();
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so luong sinh vien (toi da " << MAXSIZE << "): ";
        cin >> n;
        if (n < 1 || n > MAXSIZE)
            cout << "So luong khong hop le!\n";
    } while (n < 1 || n > MAXSIZE);
    SinhVien *sv;
    sv = new SinhVien[n];
    nhapDSSV(sv, n);
    xuatDSSV(sv, n);
    diemToanCaoHonTB(sv, n);
    delete sv;
    system("pause");
    return 0;
}