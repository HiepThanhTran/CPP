#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
   int data;
   Node *next;
   Node *prev;
   Node(int _data)
   {
      data = _data;
      next = NULL;
      prev = NULL;
   }
};
void insertFirst(Node *&head, Node *&tail, int data)
{
   Node *p = new Node(data);
   if (head == NULL)
   {
      head = tail = p;
      return;
   }
   p->next = head;
   head->prev = p;
   head = p;
}
void output(Node *&head, Node *&tail)
{
   cout << "Danh sach dang luu tru: ";
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

void bubbleSort(Node *&head, Node *&tail) // Hàm áp dụng cho cả dslk đơn và kép đều được
{
   Node *i = head;
   Node *tmp = nullptr;
   while (i != NULL)
   {
      Node *j = head;
      while (j->next != tmp)
      {
         if (j->data > j->next->data)
            swap(j->data, j->next->data);
         j = j->next;
      }
      tmp = j;
      i = i->next;
   }
}
void insertionSort(Node *&head, Node *&tail) // Hàm chỉ áp dụng được cho dslk kép
{
   Node *i = head;
   while (i != NULL)
   {
      int x = i->data;
      Node *j = i->prev;
      while (j != NULL && j->data > x)
      {
         j->next->data = j->data;
         j = j->prev;
      }
      if (j != NULL)
         j->next->data = x;
      else
         head->data = x;
      i = i->next;
   }
}
int main()
{
   Node *head = NULL;
   Node *tail = NULL;
   insertFirst(head, tail, 7);
   insertFirst(head, tail, 8);
   insertFirst(head, tail, 1);
   insertFirst(head, tail, 6);
   insertFirst(head, tail, 9);
   insertFirst(head, tail, 12);
   insertFirst(head, tail, 5);
   insertFirst(head, tail, 2);
   insertFirst(head, tail, 16);
   insertFirst(head, tail, 13);
   insertionSort(head, tail);
   output(head, tail);
   getch();
   return 0;
}