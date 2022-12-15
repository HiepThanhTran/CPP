#include <iostream>
#include <string>
using namespace std;
const int MAX = 45;

struct SinhVien
{
    string mssv, hoTen, diaChi, loai;
    int namSinh;
    double diemToan, diemVan, diemNN, diemTB;
} typedef SV;

void printLine()
{
    for (int i = 0; i < 120; i++)
    {
        cout << "_";
    }
    cout << "\n";
}
void pressToContinue()
{
    system("pause");
    system("cls");
}
void nhapTT(SV &sv)
{
    cin.ignore(1);
    cout << "Nhap ma so sinh vien: ";
    getline(cin, sv.mssv);
    cout << "Nhap ho va ten cua sinh vien: ";
    getline(cin, sv.hoTen);
    cout << "Nhap dia chi cua sinh vien: ";
    getline(cin, sv.diaChi);
    cout << "Nhap nam sinh cua sinh vien: ";
    cin >> sv.namSinh;
    cout << "Nhap diem toan cua sinh vien: ";
    cin >> sv.diemToan;
    cout << "Nhap diem van cua sinh vien: ";
    cin >> sv.diemVan;
    cout << "Nhap diem ngoai ngu cua sinh vien: ";
    cin >> sv.diemNN;
}
void nhapDSSV(SV *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\tNHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
        nhapTT(sv[i]);
    }
}
void xuatTT(SV sv)
{
    cout << "\t" << sv.mssv;
    cout << " \t" << sv.hoTen;
    cout << " \t" << sv.diaChi;
    cout << " \t" << sv.namSinh;
    cout << "\t\t" << sv.diemToan;
    cout << "\t\t" << sv.diemVan;
    cout << "\t\t" << sv.diemNN << endl;
}
void xuatDSSV(SV *sv, int n)
{
    printLine();
    cout << "STT\tMSSV\t\tHO&TEN\t\t\tDIA CHI\t\tNAM SINH\tDIEM TOAN\tDIEM VAN\tDIEM NN\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1;
        xuatTT(sv[i]);
    }
    printLine();
}
void diemTB(SV *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        sv[i].diemTB = ((sv[i].diemToan + sv[i].diemVan) * 2 + sv[i].diemNN) / 5;
    }
    cout << "\tDANH SACH DIEM TRUNG BINH CUA TUNG SINH VIEN\n";
    printLine();
    cout << "\nSTT\tMSSV\t\tHO&TEN\t\t\tDiem TB\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1;
        cout << " \t" << sv[i].mssv;
        cout << " \t" << sv[i].hoTen;
        cout << " \t" << sv[i].diemTB << endl;
    }
    printLine();
}
void xepLoai(SV *sv, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (sv[i].diemTB >= 8)
            sv[i].loai = "Gioi";
        else if (sv[i].diemTB >= 6.5 && sv[i].diemTB < 8)
            sv[i].loai = "Kha";
        else if (sv[i].diemTB >= 5 && sv[i].diemTB < 6.5)
            sv[i].loai = "TB";
        else
            sv[i].loai = "Duoi TB";
    }
    printLine();
    cout << "STT\tMSSV\t\tHO&TEN\t\t\tDIEM TB\t\tXEP LOAI\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1;
        cout << "\t" << sv[i].mssv;
        cout << " \t" << sv[i].hoTen;
        cout << " \t" << sv[i].diemTB;
        cout << "\t\t" << sv[i].loai << endl;
    }
    printLine();
}
int main()
{
    SV *sv;
    int op, n, stt;
    bool flag1 = false, flag2 = false;
    do
    {
        cout << "1. Nhap thong tin sinh vien cua 1 lop\n";
        cout << "2. Xuat danh sach lop\n";
        cout << "3. Xuat thong tin 1 sinh vien\n";
        cout << "4. Tinh va xuat diem trung binh cua tung sinh vien\n";
        cout << "5. Xep loai sinh vien\n";
        cout << "6. Thoat\n";
        cout << "Chon tien ich: ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            do
            {
                cout << "Nhap so luong sinh vien cua lop: ";
                cin >> n;
                if (n < 1 || n > MAX)
                    cout << "\nSo luong sinh vien khong hop le!\n";
            } while (n < 1 || n > MAX);
            sv = new SV[n];
            nhapDSSV(sv, n);
            flag1 = true;
            pressToContinue();
            break;
        }
        case 2:
            if (!flag1)
            {
                cout << "\nVui long nhap thong tin sinh vien truoc!\n";
                pressToContinue();
            }
            else
            {
                cout << "\tDANH SACH LOP\n";
                xuatDSSV(sv, n);
                pressToContinue();
            }
            break;
        case 3:
            if (!flag1)
            {
                cout << "\nVui long nhap thong tin sinh vien truoc!\n";
                pressToContinue();
            }
            else
            {
                do
                {
                    cout << "Nhap so thu tu cua sinh vien can kiem tra: ";
                    cin >> stt;
                    if (stt < 1 || stt > n)
                        cout << "\nSo thu tu khong hop le!\n";
                } while (stt < 1 || stt > n);
                printLine();
                cout << "STT\tMSSV\t\tHO&TEN\t\t\tDIA CHI\t\tNAM SINH\tDIEM TOAN\tDIEM VAN\tDIEM NN\n";
                cout << stt;
                xuatTT(sv[stt - 1]);
                printLine();
                pressToContinue();
            }
            break;
        case 4:
            if (!flag1)
            {
                cout << "\nVui long nhap thong tin sinh vien truoc!\n";
                pressToContinue();
            }
            else
            {
                diemTB(sv, n);
                flag2 = true;
                pressToContinue();
            }
            break;
        case 5:
            if (!flag1)
            {
                cout << "\nVui long nhap thong tin sinh vien truoc!\n";
                pressToContinue();
            }
            else if (!flag2)
            {
                cout << "\nVui long tinh diem trung binh cua sinh vien truoc!\n";
                pressToContinue();
            }
            else
            {
                xepLoai(sv, n);
                pressToContinue();
            }
            break;
        case 6:
            cout << "\nThoat chuong trinh\n";
            return 0;
        default:
            cout << "\nTien ich hien khong co!\n";
            pressToContinue();
        }
    } while (op != 6);

    delete sv;
    system("pause");
    return 0;
}