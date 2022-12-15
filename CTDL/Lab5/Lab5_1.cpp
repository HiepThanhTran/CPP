#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;

void nhapDS(int Arr[], int &n)
{
   do
   {
      cout << "Nhap so luong phan tu: ";
      cin >> n;
      if (n < 1 || n > MAX)
         cout << "Khong hop le. Nhap lai!\n";
   } while (n < 1 || n > MAX);
   for (int i = 0; i < n; i++)
   {
      cout << "Nhap A[" << i << "]: ";
      cin >> Arr[i];
   }
}
void xuatDS(int Arr[], int n)
{
   cout << "Danh sach dang luu tru: ";
   for (int i = 0; i < n; i++)
      cout << Arr[i] << " ";
   cout << "\n";
}
void insertionSort(int Arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      int x = Arr[i];
      int j = i - 1;
      while (j >= 0 && x < Arr[j])
      {
         Arr[j + 1] = Arr[j];
         j--;
      }
      Arr[j + 1] = x;
   }
}
void selectionSort(int Arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int min = i;
      for (int j = i + 1; j < n; j++)
         if (Arr[min] < Arr[j])
            min = j;
      swap(Arr[min], Arr[i]);
   }
}
void interchangeSort(int Arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
         if (Arr[i] > Arr[j])
            swap(Arr[i], Arr[j]);
}
void bubbleSort(int Arr[], int n)
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n - 1 - i; j++)
         if (Arr[j] > Arr[j + 1])
            swap(Arr[j], Arr[j + 1]);
}
int main()
{
   int A[MAX], n = 0, choice;
   do
   {
      system("cls");
      cout << "1- Nhap danh sach\n";
      cout << "2- Xuat danh sach\n";
      cout << "3- Sap xep danh sach (InsertionSort)\n";
      cout << "4- Sap xep danh sach (SelectionSort)\n";
      cout << "5- Sap xep danh sach (InterchangeSort)\n";
      cout << "6- Sap xep danh sach (BubbleSort)\n";
      cout << "7- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         nhapDS(A, n);
         break;
      case 2:
         if (n == 0)
            cout << "\n--DANH SACH RONG--\n";
         else
            xuatDS(A, n);
         break;
      case 3:
         if (n == 0)
            cout << "\n--DANH SACH RONG--\n";
         else
         {
            insertionSort(A, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDS(A, n);
         }
         break;
      case 4:
         if (n == 0)
            cout << "\n--DANH SACH RONG--\n";
         else
         {
            selectionSort(A, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDS(A, n);
         }
         break;
      case 5:
         if (n == 0)
            cout << "\n--DANH SACH RONG--\n";
         else
         {
            interchangeSort(A, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDS(A, n);
         }
         break;
      case 6:
         if (n == 0)
            cout << "\n--DANH SACH RONG--\n";
         else
         {
            bubbleSort(A, n);
            cout << "\n--SAP XEP THANH CONG--\n";
            xuatDS(A, n);
         }
         break;
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 6);
   return 0;
}