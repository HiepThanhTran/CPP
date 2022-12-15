#include <iostream>
#include <conio.h>
#include "../resource/SingleLinkedList.h"
using namespace std;

void selectionSort(List &list)
{
   Node *p = list.head;
   Node *q = p->nxt;
   while (p != NULL)
   {
      Node *min = p;
      while (q != NULL)
      {
         if (min->data > q->data)
            min = q;
         q = q->nxt;
      }
      swap(p->data, min->data);
      p = p->nxt;
      q = q->nxt;
   }
}
void interchangeSort(List &list)
{
   Node *p = list.head;
   Node *q = p->nxt;
   while (p->nxt != NULL)
   {
      while (q != NULL)
      {
         if (p->data > q->data)
            swap(p->data, q->data);
         q = q->nxt;
      }
      p = p->nxt;
      q = p->nxt;
   }
}
int main()
{
   List newList;
   int choice, x;
   do
   {
      system("cls");
      cout << "1- Them phan tu vao danh sach\n";
      cout << "2- Xuat danh sach\n";
      cout << "3- Sap xep (SelectionSort)\n";
      cout << "4- Sap xep (InterchangeSort)\n";
      cout << "5- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         cout << "Nhap gia tri can them: ";
         cin >> x;
         insertLast(newList, x);
         break;
      case 2:
         if (!isEmpty(newList))
            output(newList);
         else
            cout << "\n--DANH SACH RONG--\n";
         break;
      case 3:
         if (!isEmpty(newList))
         {
            selectionSort(newList);
            cout << "\n--SAP XEP THANH CONG--\n";
            output(newList);
         }
         else
            cout << "\n--DANH SACH RONG--\n";
         break;
      case 4:
         if (!isEmpty(newList))
         {
            interchangeSort(newList);
            cout << "\n--SAP XEP THANH CONG--\n";
            output(newList);
         }
         else
            cout << "\n--DANH SACH RONG--\n";
         break;
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 4);
   return 0;
}