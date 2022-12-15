#include "../resource/SingleLinkedList.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;
const int MAX = 100;

int A[MAX], n, m, data;
bool isSort = false;
List B;
void printContinue()
{
   cout << "\nNhap phim bat ky de tiep tuc\n";
   _getch();
}
void nhapDS(int arr[], int &n)
{
   do
   {
      cout << "Nhap so luong phan tu: ";
      cin >> n;
   } while (n < 1 || n > MAX);
   // cout << "Nhap " << n << " phan tu: ";
   for (int i = 0; i < n; i++)
      arr[i] = rand() % 101;
}
void xuatDS(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << "\n";
}
void heapify(int arr[], int n, int i)
{
   int m = i;         // Node root
   int l = 2 * i + 1; // Node ben trai
   int r = 2 * i + 2; // Node ben phai

   // Tim vi tri co gia tri lon nhat (nho nhat) trong: arr[i], A[l], A[r]
   if (l < n && A[l] > A[m])
      m = l;
   if (r < n && A[r] > A[m])
      m = r;

   // Dieu kien dung de quy
   if (m != i)
   {
      swap(arr[i], arr[m]);
      heapify(arr, n, m); // Xet lai su lan truyen
   }
}
void heapSort(int arr[], int n)
{
   // Tao heap ban dau
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

   // Bat dau sap xep
   for (int i = n - 1; i > 0; i--)
   {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }
}
int searchBinary(int arr[], int size, int target)
{
   int l = 0, r = size - 1, m = (l + r) / 2;
   while (l <= r)
   {
      if (arr[m] == target)
         return m;
      if (target > arr[m])
         l = m + 1;
      else
         r = m - 1;
      m = (l + r) / 2;
   }
   return -1;
}
bool isPrime(int x)
{
   if (x < 2)
      return false;
   for (int i = 2; i <= sqrt(x); i++)
      if (x % i == 0)
         return false;
   return true;
}
void searchPrime(List list)
{
   Node *p = list.head;
   while (p != NULL)
   {
      if (isPrime(p->data))
         cout << p->data << " ";
      p = p->nxt;
   }
   cout << "\n";
}
bool isSquare(int x)
{
   int sqr = sqrt(x);
   if (sqr * sqr == x)
      return true;
   return false;
}
void searchSquare(List list)
{
   Node *p = list.head;
   while (p != NULL)
   {
      if (isSquare(p->data))
         cout << p->data << " ";
      p = p->nxt;
   }
   cout << "\n";
}
int findMax(int arr[], int size)
{
   if(isSort)
      return size - 1;
   int max = arr[0], pos = 0;
   for (int i = 1; i < size; i++)
      if (arr[i] > max)
      {
         max = arr[i];
         pos = i;
      }
   return pos;
}
void valueMax(int arr[], int size)
{
   int max = arr[findMax(arr, size)];
   for (int i = 0; i < size; i++)
      if (arr[i] == max)
         cout << arr[i] << " ";
   cout << "\n";
}
int findMin(int arr[], int size)
{
   if(isSort)
      return 0;
   int min = arr[0], pos = 0;
   for (int i = 1; i < size; i++)
      if (arr[i] < min)
      {
         min = arr[i];
         pos = i;
      }
   return pos;
}
void valueMin(int arr[], int size)
{
   int min = arr[findMin(arr, size)];
   for (int i = 0; i < n; i++)
      if (arr[i] == min)
         cout << arr[i] << " ";
   cout << "\n";
}
int main()
{
   srand(time(NULL));
   nhapDS(A, n);
   cout << "------------------------------\n";
   // do
   // {
   //    cout << "Nhap gia tri (Nhap -1 de ket thuc): ";
   //    cin >> data;
   //    insertLast(B, data); // Lay ca gia tri -1
   // } while (data != -1);
   for (int i = 0; i < n; i++)
   {
      data = rand() % 101;
      insertLast(B, data);
   }
   printContinue();
   int choice, x;
   do
   {
      system("cls");
      cout << "Danh sach dac dang luu tru: ";
      xuatDS(A, n);
      cout << "Danh sach lien ket dang luu tru: ";
      output(B);
      cout << "1- Tim x bang phuong phap nhi phan (Danh sach dac)\n";
      cout << "2- In ra tat ca so nguyen to/so chinh phuong bang phuong phap tuan tu (Danh sach lien ket)\n";
      cout << "3- In ra tat ca gia tri lon nhat/nho nhat (Danh sach dac)\n";
      cout << "4- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
      {
         cout << "Nhap gia tri x can tim: ";
         cin >> x;
         heapSort(A, n);
         isSort = true;
         int pos = searchBinary(A, n, x);
         if (pos != -1)
            cout << "- Tim thay gia tri " << x << " o vi tri (sau khi sap xep) " << pos + 1 << "\n";
         else
            cout << "- Khong tim thay gia tri " << x << "\n";
         break;
      }
      case 2:
      {
         int option2;
         do
         {
            cout << "\n1- So nguyen to\n";
            cout << "2- So chinh phuong\n";
            cout << "3- Quay lai\n";
            cout << "- Chon chuc nang: ";
            cin >> option2;
            switch (option2)
            {
            case 1:
               cout << "- Cac so nguyen to trong danh sach: ";
               searchPrime(B);
               break;
            case 2:
               cout << "- Cac so chinh phuong trong danh sach: ";
               searchSquare(B);
               break;
            }
         } while (option2 >= 1 && option2 <= 2);
         break;
      }
      case 3:
      {
         int option3;
         do
         {
            cout << "\n1- So lon nhat\n";
            cout << "2- So nho nhat\n";
            cout << "3- Quay lai\n";
            cout << "- Chon chuc nang: ";
            cin >> option3;
            switch (option3)
            {
            case 1:
               cout << "- Cac so lon nhat trong danh sach: ";
               valueMax(A, n);
               break;
            case 2:
               cout << "- Cac so nho nhat trong danh sach: ";
               valueMin(A, n);
               break;
            }
         } while (option3 >= 1 && option3 <= 2);
         break;
      }
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      printContinue();
   } while (choice >= 1 && choice <= 3);
   return 0;
}