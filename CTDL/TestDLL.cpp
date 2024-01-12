#include "../resource/DoubleLinkedList.h"
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
      cout << "\t1- Them Node vao dau danh sach\n";
      cout << "\t2- Them Node vao cuoi danh sach\n";
      cout << "\t3- Them Node sau 1 Node xac dinh\n";
      cout << "\t4- Them Node truoc 1 Node xac; dinh\n";
      cout << "\t5- Tim kiem gia tri 1 Node\n;";
      cout << "\t6- Xoa Node dau danh sach\n";
      cout << "\t7- Xoa Node cuoi danh sach\n";
      cout << "\t8- Xoa Node sau 1 Node xac dinh\n";
      cout << "\t9- Xoa Node truoc 1 Node x;ac dinh\n";
      cout << "\t10- Xoa 1 Node xac dinh;\n";
      cout << "\t11- Xoa ca danh sach\n";
      cout << "\t12- Xuat da;nh sach ra man hinh\n";
      cout << "\t0- Thoat\n";
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
         cout << "Nhap gia tri muon them: ";
         cin >> data;
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         insertBefore(list, pos, data);
         break;
      case 5:
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
      case 6:
         if (deleteFirst(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 7:
         if (deleteLast(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 8:
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         if (deleteAfter(list, pos))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 9:
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         if (deleteBefore(list, pos))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 10:
         cout << "Nhap vi tri Node: ";
         cin >> pos;
         if (deleteNode(list, pos))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 11:
         if (deleteList(list))
            cout << "\n--XOA THANH CONG--\n";
         else
            cout << "\n--XOA KHONG THANH CONG. KIEM TRA LAI DANH SACH!--\n";
         break;
      case 12:
         if (!isEmpty(list))
            output(list);
         else
            cout << "\n--DANH SACH RONG--\n";
         break;
      default:
         cout << "\n==THOAT CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 12);
   return 0;
}