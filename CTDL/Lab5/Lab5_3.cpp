#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;

struct NhanVien
{
   char maNV[4];
   char hoTen[40];
   int luong = 0;
} typedef NV;

void nhap1NV(NV &nv)
{
   cin.ignore();
   cout << "Nhap ma nhan vien: ";
   cin.getline(nv.maNV, 4);
   cout << "Nhap ho ten nhan vien: ";
   cin.getline(nv.hoTen, 40);
   cout << "Nhap luong: ";
   cin >> nv.luong;
}
void nhapDSNV(NV DSNV[], int &n)
{
   do
   {
      cout << "Nhap so luong nhan vien: ";
      cin >> n;
      if (n < 1 || n > MAX)
         cout << "Khong hop le. Nhap lai!\n";
   } while (n < 1 || n > MAX);
   for (int i = 0; i < n; i++)
   {
      cout << "--NHAP THONG TIN NHAN VIEN THU " << i + 1 << "--\n";
      nhap1NV(DSNV[i]);
   }
}
void xuat1NV(NV nv)
{
   cout << "Ma nhan vien: " << nv.maNV << endl;
   cout << "Ho ten nhan vien: " << nv.hoTen << endl;
   cout << "Luong: " << nv.luong << endl;
}
void xuatDSNV(NV DSNV[], int n)
{
   cout << "\n==DANH SACH NHAN VIEN DANG LUU TRU==\n";
   for (int i = 0; i < n; i++)
   {
      cout << "\n--THONG TIN NHAN VIEN THU " << i + 1 << "--\n";
      xuat1NV(DSNV[i]);
   }
}
void selectionSort(NV DSNV[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int min = i;
      for (int j = i + 1; j < n; j++)
         if (DSNV[min].luong > DSNV[j].luong)
            min = j;
      swap(DSNV[min], DSNV[i]);
   }
}
void insertionSort(NV DSNV[], int n)
{
   for (int i = 0; i < n; i++)
   {
      NV tmp = DSNV[i];
      int j = i - 1;
      while (j >= 0 && DSNV[j].luong > tmp.luong)
      {
         DSNV[j + 1] = DSNV[j];
         j--;
      }
      DSNV[j + 1] = tmp;
   }
}
int main()
{
   NV DSNV[MAX];
   int choice, n;
   bool input = false;
   do
   {
      system("cls");
      cout << "1- Nhap danh sach nhan vien\n";
      cout << "2- Xuat danh sach nhan vien\n";
      cout << "3- Sap xep theo luong tang dan (SelectionSort)\n";
      cout << "4- Sap xep theo luong tang dan (InsertionSort)\n";
      cout << "5- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         nhapDSNV(DSNV, n);
         input = true;
         break;
      case 2:
         if (input)
            xuatDSNV(DSNV, n);
         else
            cout << "\n--VUI LONG NHAP DANH SACH TRUOC--\n";
         break;
      case 3:
         if (input)
         {
            selectionSort(DSNV, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDSNV(DSNV, n);
         }
         else
            cout << "\n--VUI LONG NHAP DANH SACH TRUOC--\n";
         break;
      case 4:
         if (input)
         {
            insertionSort(DSNV, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDSNV(DSNV, n);
         }
         else
            cout << "\n--VUI LONG NHAP DANH SACH TRUOC--\n";
         break;
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 4);
   return 0;
}