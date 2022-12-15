#include <iostream>
#include <conio.h>
#include "..\resource\SingleLinkedList.h"
using namespace std;

List newList;
void nhapX(int &x)
{
   cout << "Nhap vao gia tri can them: ";
   cin >> x;
}
void nhapVT(int &pos)
{
   int sz = getSize(newList);
   do
   {
      cout << "Nhap vi tri: ";
      cin >> pos;
   } while (pos < 1 || pos > sz);
}
bool searchAndDelete(List &list, int target)
{
   Node *p = list.head;
   int cnt = 0, pos = 0;
   while (p != NULL)
   {
      cnt++;
      if (p->data == target)
      {
         pos = cnt;
         break;
      }
      p = p->nxt;
   }
   if (pos != 0)
   {
      deleteNode(list, pos);
      return true;
   }
   return false;
}
int changes(List list, int *&arr)
{
   int sz = getSize(list), i = 0;
   arr = new int[sz];
   Node *p = list.head;
   while (p != NULL)
   {
      arr[i++] = p->data;
      p = p->nxt;
   }
   return sz;
}
int main()
{
   int choice, x, pos, sz;
   int *arr = NULL;
   do
   {
      system("cls");
      cout << "1- Them phan tu vao dau danh sach\n";
      cout << "2- Them phan tu vao cuoi danh sach\n";
      cout << "3- Them phan tu sau 1 Node\n";
      cout << "4- Tim 1 phan tu trong danh sach\n";
      cout << "5- Tim 1 Node\n";
      cout << "6- Xoa phan tu dau ra khoi danh sach\n";
      cout << "7- Xoa phan tu cuoi ra khoi danh sach\n";
      cout << "8- Xoa 1 phan tu sau 1 Node\n";
      cout << "9- Xoa 1 Node\n";
      cout << "10- Xoa ca danh sach\n";
      cout << "11- Tim 1 phan tu va xoa ra khoi danh sach\n";
      cout << "12- Chuyen thanh danh sach co thu tu\n";
      cout << "13- Xuat danh sach\n";
      cout << "0- Thoat\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         nhapX(x);
         insertFirst(newList, x);
         output(newList);
         break;
      case 2:
         nhapX(x);
         insertLast(newList, x);
         output(newList);
         break;
      case 3:
      {
         nhapX(x);
         nhapVT(pos);
         insertAfter(newList, pos, x);
         output(newList);
         break;
      }
      case 4:
         nhapX(x);
         if (searchDataNode(newList, x))
            cout << "Phan tu co trong danh sach\n";
         else
            cout << "Khong tim thay phan tu\n";
         break;
      case 5:
      {
         nhapVT(pos);
         Node *node = searchNode(newList, pos);
         cout << "Gia tri cua Node can tim: " << node->data << "\n";
         break;
      }
      case 6:
         if (deleteFirst(newList))
         {
            cout << "Xoa thanh cong\n";
            output(newList);
         }
         else
            cout << "Xoa khong thanh cong\n";
         break;
      case 7:
         if (deleteLast(newList))
         {
            cout << "Xoa thanh cong\n";
            output(newList);
         }
         else
            cout << "Xoa khong thanh cong\n";
         break;
      case 8:
         nhapVT(pos);
         if (deleteAfter(newList, pos))
         {
            cout << "Xoa thanh cong\n";
            output(newList);
         }
         else
            cout << "Xoa khong thanh cong\n";
         break;
      case 9:
      {
         nhapVT(pos);
         if (deleteNode(newList, pos))
         {
            cout << "Xoa thanh cong\n";
            output(newList);
         }
         else
            cout << "Xoa khong thanh cong\n";
         break;
      }
      case 10:
         if (deleteList(newList))
            cout << "Xoa thanh cong\n";
         else
            cout << "Xoa khong thanh cong\n";
         break;
      case 11:
         nhapX(x);
         if (searchAndDelete(newList, x))
         {
            cout << "Tim thay va xoa thanh cong\n";
            output(newList);
         }
         else
            cout << "Phan tu khong co trong danh sach\n";
         break;
      case 12:
         sz = changes(newList, arr);
         for (int i = 0; i < sz; i++)
            cout << arr[i] << " ";
         cout << "\n";
         break;
      case 13:
         if (isEmpty(newList))
            cout << "Danh sach rong\n";
         else
            output(newList);
         break;
      default:
         cout << "\n== THOAT CHUONG TRINH ==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 13);
   return 0;
}