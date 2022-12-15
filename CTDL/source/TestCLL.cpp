#include "../resource/CircularLinkedList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
   NODE *head = NULL;
   insertLast(head, 5);
   insertLast(head, 1);
   insertLast(head, 3);
   insertLast(head, 10);
   insertLast(head, 4);
   processList(head);
   cout << "\n- Do dai danh sach hien tai: " << Length(head) << "\n\n";

   getch();
   return 0;
}