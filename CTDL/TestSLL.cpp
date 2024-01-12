#include "../resource/SingleLinkedList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
   int choice, data, pos;
   List list;
   do
   {
      system("cls");
      cout << "1- Them Node vao dau danh sach\n";
      cout << "2- Them Node vao cuoi danh sach\n";
      cout << "3- Them Node sau 1 Node xac dinh\n";
      cout << "4- Tim kiem gia tri cua 1 Node\n";
      cout << "5- Xoa Node dau danh sach\n";
      cout << "6- Xoa Node cuoi danh sach\n";
      cout << "7- Xoa Node sau 1 Node xac dinh\n";
      cout << "8- Xoa 1 Node xac dinh\n";
      cout << "9- Xoa ca danh sach\n";
      cout << "10- Xuat danh sach ra man hinh\n";
      cout << "11- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         cout << "Nhap gia tri muon them: ";
         cin >> data;
         insertFirst(list, data);
         cout << "Them thanh cong\n";
         break;
      case 2:
         cout << "Nhap gia tri muon them: ";
         cin >> data;
         insertLast(list, data);
         cout << "Them thanh cong\n";
         break;
      case 3:
         cout << "Nhap gia tri muon them: ";
         cin >> data;
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         insertAfter(list, pos, data);
         break;
      case 4:
      {
         cout << "Nhap gia tri muon tim: ";
         cin >> data;
         Node *node = searchDataNode(list, data);
         if (node)
            cout << "\n--GIA TRI CO TRONG DANH SACH--\n";
         else
            cout << "\n--KHONG TIM THAY GIA TRI TRONG DANH SACH--\n";
         break;
      }
      case 5:
         if (deleteFirst(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 6:
         if (deleteLast(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 7:
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         if (deleteAfter(list, pos))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 8:
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         if (deleteNode(list, pos))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 9:
         if (deleteList(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 10:
         if (!isEmpty(list))
            output(list);
         else
            cout << "\n--DANH SACH RONG--\n";
         break;
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 10);
   return 0;
}