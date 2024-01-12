#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Product
{
   int id;
   string date;
   double value;
   int amount;
   string name;
   int status; // 0: Dang cho giao __ 1: Tren duong giao __ 2: Da giao
};
struct Node
{
   Product product;
   Node *link;
};

void initList(Node *&head)
{
   head = NULL;
}

void input(Product &product)
{
   cin.ignore();
   cout << "- Nhap ma don hang: ";
   cin >> product.id;
   cout << "- Nhap ngay don hang: ";
   cin >> product.date;
   cout << "- Nhap tong gia tri don hang: ";
   cin >> product.value;
   cout << "- Nhap tong so don hang: ";
   cin >> product.amount;
   cout << "- Nhap ten khach hang: ";
   cin >> product.name;
   cout << "- Nhap trang thai don hang: ";
   cin >> product.status;
}
void output(Product product)
{
   cout << "- Ma don hang: " << product.id << "\n";
   cout << "- Ngay don hang: " << product.date[0] << product.date[1]
        << "-" << product.date[2] << product.date[3] << "-" << product.date[4]
        << product.date[5] << product.date[6] << product.date[7] << "\n";
   cout << "- Tong gia tri don hang: " << product.value << "\n";
   cout << "- Tong so san pham: " << product.amount << "\n";
   cout << "- Trang thai don hang: " << product.status << "\n";
}

Node *createNode(Product product)
{
   Node *newNode = new Node;
   newNode->product = product;
   newNode->link = NULL;
   return newNode;
}
void insertFirst(Node *&head, Product product)
{
   Node *newNode = createNode(product);
   newNode->link = head;
   head = newNode;
}
bool removeFirst(Node *&head)
{
   if (head != NULL)
   {
      Node *tmp = head;
      head = head->link;
      delete tmp;
      return true;
   }
   return false;
}
Node *searchByName(Node *head, string name)
{
   Node *p = head;
   while (p != NULL && p->product.name != name)
      p = p->link;
   return p;
}
Node *searchByDate(Node *head, string date)
{
   Node *p = head;
   while (p != NULL && p->product.date != date)
      p = p->link;
   return p;
}
int sumOfRevenue(Node *head, string day)
{
   int sum = 0;
   string tmp = "";
   while (head != NULL)
   {
      tmp = head->product.date[0] + head->product.date[1];
      if (tmp == day)
         sum += head->product.value;
      head = head->link;
   }
   return sum;
}
void processList(Node *head)
{
   while (head != NULL)
   {
      output(head->product);
      head = head->link;
   }
}

int main()
{
   Node *head;
   initList(head);
   int choice;
   do
   {
      system("cls");
      cout << "1- Them don hang\n";
      cout << "2- Xoa don hang\n";
      cout << "3- Xuat don hang\n";
      cout << "4- Tim don hang\n";
      cout << "5- Tong doanh thu mot ngay\n";
      cout << "6- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
      {
         cout << "\n--NHAP THONG TIN SAN PHAM--\n";
         Product product;
         input(product);
         insertFirst(head, product);
         cout << "\n--THEM THANH CONG--\n";
         break;
      }
      case 2:
         removeFirst(head);
         cout << "\n--XOA THANH CONG--\n";
         break;
      case 3:
         cout << "\n--DANH SACH DON HANG--\n";
         processList(head);
         break;
      case 4:
      {
         string name, date;
         int option4;
         cout << "1- Tim kiem theo ten khach hang\n";
         cout << "2- Tim kiem theo ngay don hang\n";
         cin >> option4;
         switch (option4)
         {
         case 1:
         {
            cout << "- Nhap ten khach hang: ";
            cin >> name;
            Node *p = searchByName(head, name);
            if (p)
            {
               cout << "\n--THONG TIN KHACH HANG TIM THAY--\n";
               output(p->product);
            }
            else
               cout << "\n--KHONG TIM THAY KHACH HANG--\n";
            break;
         }
         case 2:
         {
            cout << "- Nhap ngay don hang: ";
            cin >> date;
            Node *p = searchByDate(head, date);
            if (p)
            {
               cout << "\n--THONG TIN DON HANG TIM THAY--\n";
               output(p->product);
            }
            else
               cout << "\n--KHONG TIM THAY DON HANG--\n";
            break;
         }
         default:
            cout << "\n--KHONG HOP LE--\n";
         }
         break;
      }
      case 5:
      {
         string day;
         cout << "- Nhap ngay can tinh tong doanh thu: ";
         cin >> day;
         cout << "- Tong doanh thu cua ngay " << day << " la: " << sumOfRevenue(head, day) << "\n";
         break;
      }
      default:
         cout << "\n==KET THUC CHUONG TRINH==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 5);
   return 0;
}