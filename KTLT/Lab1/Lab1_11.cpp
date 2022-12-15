#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
using namespace std;
const int MAXR = 15, MAXC = 10, MAX = 10;
const int TG = 1000, PT = 800, TK = 500;

void taoDanhSach(int danhSach[][MAXC])
{
    for (int i = 0; i < MAXR; i++)
    {
        for (int j = 0; j < MAXC; j++)
        {
            danhSach[i][j] = rand() % 2;
        }
    }
}
void xuatDanhSach(int danhSach[][MAXC])
{
    cout << "\t\t";
    for (int i = 0; i < MAXC; i++)
    {
        cout << char(65 + i) << "\t";
    }
    cout << "\n";
    for (int i = 0; i < MAXR; i++)
    {
        cout << "Hang " << i + 1 << "\t\t";
        for (int j = 0; j < MAXC; j++)
        {
            (danhSach[i][j]) ? cout << "X\t" : cout << "*\t";
        }
        cout << "\n";
    }
    cout << "\t\t[*: VI TRI CON TRONG, X: VI TRI DA DAT]\n";
}
void datCho(int &hang, char &cot, int min, int max)
{
    do
    {
        cout << "Nhap hang ghe: ";
        cin >> hang;
        if (hang < min || hang > max)
            cout << "\n\t[HANG GHE KHONG HOP LE]\n\n";
    } while (hang < min || hang > max);
    do
    {
        cout << "Nhap cot ghe: ";
        cin >> cot;
        if (cot < 65 || cot > MAXC - 1 + 65)
            cout << "\n\t[COT GHE KHONG HOP LE!]\n\n";
    } while (cot < 65 || cot > MAXC - 1 + 65);
}
bool kiemTraCho(int danhSach[][MAXC], int hang, char cot)
{
    return (danhSach[hang][(int)cot - 65] == 0);
}
void datVe(int danhSach[][MAXC], int loaiVe[], int hangGhe[], char cotGhe[], int &soVe, int &ve, int hang, char cot, int &count, int &tongTien)
{
    int min = 2, max = 8;
    do
    {
        cout << "Nhap so luong ve: ";
        cin >> soVe;
        if (soVe < 1)
            cout << "\n[SO VE TOI THIEU LA 1]\n\n";
        if (soVe > MAX)
            cout << "\n[SO VE TOI DA " << MAX << "]\n\n";
    } while (soVe < 1 || soVe > MAX);
    system("cls");
    for (int i = 1; i <= soVe; i++)
    {
        xuatDanhSach(danhSach);
        do
        {
            cout << "\t[Thong tin ve thu " << i << "]\n";
            cout << "1. Thuong gia (Tu hang 1 -> 2)\n";
            cout << "2. Pho thong (Tu hang 3 -> 7)\n";
            cout << "3. Tiet kiem (Tu hang 8 -> 13)\n";
            cout << "Chon loai ve can mua: ";
            cin >> ve;
            if (ve < 1 || ve > 3)
                cout << "\n[LOAI VE KHONG HOP LE!]\n\n";
        } while (ve < 1 || ve > 3);
        switch (ve)
        {
        case 1:
            datCho(hang, cot, 1, min);
            break;
        case 2:
            datCho(hang, cot, min + 1, max - 1);
            break;
        case 3:
            datCho(hang, cot, max, MAXR);
            break;
        }
        if (kiemTraCho(danhSach, hang - 1, cot))
        {
            if (ve == 1)
                tongTien += TG;
            if (ve == 2)
                tongTien += PT;
            if (ve == 3)
                tongTien += TK;
            danhSach[hang - 1][(int)cot - 65] = 1;
            loaiVe[count] = ve;
            hangGhe[count] = hang;
            cotGhe[count] = cot;
            count++;
            cout << "\t[DAT VE MAY BAY THANH CONG!]\n";
            cout << "\t[DA CAP NHAT LAI VI TRI CHO NGOI]\n";
            system("pause");
            system("cls");
        }
        else
        {
            cout << "\n\t[VI TRI DA DUOC DAT. VUI LONG CHON LAI!]\n\n";
            i--;
            system("pause");
            system("cls");
        }
    }
}
void thanhToan(int loaiVe[], int hangGhe[], char cotGhe[], int count, int tongTien)
{
    cout << "\n\t  [TONG SO VE QUY KHACH DA DAT]\n\n";
    for (int i = 1; i < count; i++)
    {
        cout << "\t=============Ve thu " << i << "============\n";
        if (loaiVe[i] == 1)
        {
            cout << "\t|\tLoai ve: Thuong gia\t|\n";
        }
        else if (loaiVe[i] == 2)
        {
            cout << "\t|\tLoai ve: Pho thong\t|\n";
        }
        else
        {
            cout << "\t|\tLoai ve: Tiet kiem\t|\n";
        }
        cout << "\t|\tHang ghe: " << hangGhe[i] << "\t\t|\n";
        cout << "\t|\tCot ghe: " << cotGhe[i] << "\t\t|\n";
        cout << "\t=================================\n";
    }
    cout << "\n\t[TONG TIEN CAN PHAI THANH TOAN: " << tongTien << "$]\n\n";
}
int main()
{
    srand(time(NULL));
    int loaiVe[MAX], hangGhe[MAX], danhSach[MAXR][MAXC];
    int op, hang = 0, soVe, ve, count = 1, tongTien = 0;
    char cot = ' ', cotGhe[MAX];
    taoDanhSach(danhSach);
    do
    {
        system("cls");
        xuatDanhSach(danhSach);
        cout << "1. Dat ve may bay\n";
        cout << "2. Thanh toan\n";
        cout << "3. Thoat\n";
        cout << "Chon chuc nang can su dung: ";
        cin >> op;
        switch (op)
        {
        case 1:
            datVe(danhSach, loaiVe, hangGhe, cotGhe, soVe, ve, hang, cot, count, tongTien);
            break;
        case 2:
            system("cls");
            thanhToan(loaiVe, hangGhe, cotGhe, count, tongTien);
            system("pause");
            break;
        case 3:
            cout << "\n\t[THOAT CHUONG TRINH]\n\n";
            system("pause");
            return 0;
        default:
            cout << "\n\t[CHUC NANG HIEN CHUA CO]\n\n";
            system("pause");
        }
    } while (op != 3);
    return 0;
}