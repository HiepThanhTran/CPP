#include <iostream>
using namespace std;

struct NODE
{
   int data;
   NODE *nxt;
   NODE(int _data)
   {
      data = _data;
      nxt = NULL;
   }
};

int Length(NODE *head)
{
   NODE *curr = head;
   int i = 1;
   if (head == NULL)
      return 0;
   curr = curr->nxt;
   while (curr != head)
   {
      i++;
      curr = curr->nxt;
   }
   return i;
}
void processList(NODE *head)
{
   NODE *curr = head;
   if (head != NULL)
   {
      do
      {
         cout << curr->data << "\t";
         curr = curr->nxt;
      } while (curr != head);
      cout << "\n";
   }
}
NODE *searchNode(NODE *head, int target)
{
   NODE *curr = head;
   do
   {
      if (curr->data == target)
         return curr;
      curr = curr->nxt;
   } while (curr != head);
   return NULL;
}
void insertFirst(NODE *&head, int value)
{
   NODE *newNode = new NODE(value);
   if (head == NULL)
      newNode->nxt = newNode;
   else
   {
      NODE *curr = head;
      while (curr->nxt != head)
         curr = curr->nxt;
      curr->nxt = newNode;
      newNode->nxt = head;
   }
   head = newNode;
}
void insertLast(NODE *&head, int value)
{
   insertFirst(head, value);
   head = head->nxt;
}
void insertArbitrary(NODE *&head, int value, int location)
{
   int len = Length(head);
   if (head == NULL || location == 1 || location == len + 1)
   {
      insertFirst(head, value);
      return;
   }
   NODE *newNode = new NODE(value);
   NODE *curr = head, *prv = NULL;
   for (int i = 1; i < location; i++)
   {
      prv = curr;
      curr = curr->nxt;
   }
   prv->nxt = newNode;
   newNode->nxt = curr;
}
bool deleteFirst(NODE *&head)
{
   if (head != NULL)
   {
      NODE *curr = head, *tail = head;
      while (tail->nxt != head)
         tail = tail->nxt;
      tail->nxt = curr->nxt;
      head = head->nxt;
      if (curr == tail)
         head = NULL;
      delete curr;
      return true;
   }
   return false;
}
bool deleteLast(NODE *&head)
{
   if (head != NULL)
   {
      NODE *tail = head, *prv = head;
      while (tail->nxt != head)
      {
         prv = tail;
         tail = tail->nxt;
      }
      prv->nxt = head;
      if (tail == prv)
         head = NULL;
      delete tail;
      return true;
   }
   return false;
}
bool deleteByLocation(NODE *&head, int location)
{
   if (head != NULL)
   {
      int len = Length(head);
      if (location == 1 || location == len + 1)
         deleteFirst(head);
      else if (location == len)
         deleteLast(head);
      else
      {
         NODE *curr = head, *prv = NULL;
         for (int i = 1; i < location; i++)
         {
            prv = curr;
            curr = curr->nxt;
         }
         prv->nxt = curr->nxt;
         delete curr;
      }
      return true;
   }
   return false;
}
bool deleteByValue(NODE *&head, int value)
{
   NODE *node = searchNode(head, value);
   if (node)
   {
      NODE *curr = head;
      int location = 1;
      while (curr != node)
      {
         location++;
         curr = curr->nxt;
      }
      deleteByLocation(head, location);
      return true;
   }
   return false;
}
bool deleteList(NODE *&head)
{
   if (head != NULL)
   {
      while (head != NULL)
         deleteLast(head);
      return true;
   }
   return false;
}