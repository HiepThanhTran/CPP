#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct QuanLyDoiBong
{
    string ten, viTri, CLB;
    int soAo;
};

int slCauthu = 0;
string temp;

void koTonTai(int dem)
{
    if (dem == 0)
    {
        cout << "Khong ton tai cau thu" << endl;
    }
}

void inTungCauThu(QuanLyDoiBong *p, int i)
{
    cout << "Ten: " << p[i].ten << endl
         << "Vi tri: " << p[i].viTri << endl
         << "So ao: " << p[i].soAo << endl
         << "CLB: " << p[i].CLB << endl
         << endl;
}

// In danh sach cau thu theo vi tri thi dau
void inDSTheoViTriThiDau(string VITRI, QuanLyDoiBong *p)
{
    int dem = 0;
    for (int i = 0; i < slCauthu; i++)
    {
        if (p[i].viTri == VITRI)
        {
            inTungCauThu(p, i);
            dem++;
        }
    }
    koTonTai(dem);
}

// In cau thu theo so ao
void inCauThuTheoSoAo(int SOAO, QuanLyDoiBong *p)
{
    int dem = 0;
    for (int i = 0; i < slCauthu; i++)
    {
        if (p[i].soAo == SOAO)
        {
            inTungCauThu(p, i);
            dem++;
        }
    }
    koTonTai(dem);
}

// In danh sach cau thu theo CLB
void inDSTheoCLB(string clb, QuanLyDoiBong *p)
{
    int dem = 0;
    for (int i = 0; i < slCauthu; i++)
    {
        if (p[i].CLB == clb)
        {
            inTungCauThu(p, i);
            dem++;
        }
    }
    koTonTai(dem);
}

int main()
{
    ifstream inFile("E:\\Code\\Project1\\TapTin\\DoiTuyenQuocGiaVN.txt");
    if (!inFile.is_open())
    {
        cout << "Mo file that bai";
        return -1;
    }
    // Doc File lan 1 lay ra so luong cau thu
    while (!inFile.eof())
    {
        getline(inFile, temp);
        slCauthu++;
    }
    inFile.close();

    QuanLyDoiBong *p = new QuanLyDoiBong[slCauthu];

    // Doc file lan 2 lay thong tin vao mang bang cap phat dong
    inFile.open("E:\\Code\\Project1\\TapTin\\DoiTuyenQuocGiaVN.txt");
    for (int i = 0; i < slCauthu; i++)
    {
        getline(inFile, p[i].ten, ',');
        getline(inFile, p[i].viTri, ',');
        inFile >> p[i].soAo;
        inFile.ignore(1);
        getline(inFile, p[i].CLB);
    }
    inFile.close();
    // Menu

    int chon = 1;
    do
    {
        do
        {
            if (chon < 1 || chon > 4)
            {
                cout << "Lua chon khong ton tai. Vui long nhap lai" << endl;
            }
            cout << "1. In danh sach cau thu theo vi tri thi dau" << endl
                 << "2. In cau thu theo so ao" << endl
                 << "3. In danh sach cau thu theo CLB" << endl
                 << "4. Ket thuc" << endl;
            cout << "Nhap lua chon: ";
            cin >> chon;
            cin.ignore(1);
        } while (chon < 1 || chon > 4);

        if (chon == 1)
        {
            string VITRI;
            cout << "Nhap vi tri thi dau: ";
            getline(cin, VITRI);
            inDSTheoViTriThiDau(VITRI, p);
        }
        else if (chon == 2)
        {
            int SOAO;
            cout << "Nhap so ao: ";
            cin >> SOAO;
            inCauThuTheoSoAo(SOAO, p);
        }
        else if (chon == 3)
        {
            string clb;
            cout << "Nhap ten CLB: ";
            getline(cin, clb);
            inDSTheoCLB(clb, p);
        }
    } while (chon != 4);
    delete[] p;
    p = nullptr;
    return 0;
}