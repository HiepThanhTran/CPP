#include <iostream>
#include <conio.h>
using namespace std;

struct Leaf
{
   int data;
   Leaf *pLeft;
   Leaf *pRight;
   Leaf(int _data)
   {
      data = _data;
      pLeft = NULL;
      pRight = NULL;
   }
};
typedef Leaf *Tree;
struct Node
{
   int data;
   Node *nxt;
   Node(int _data)
   {
      data = _data;
      nxt = NULL;
   }
};
Node *sp = NULL; // Stack
Node *de = NULL; // de-Queue
Node *en = NULL; // en-Queue

bool isEmptySt()
{
   if (sp == NULL)
      return true;
   return false;
}
bool isEmptyQu()
{
   if (de == NULL)
      return true;
   return false;
}
void Push(int data)
{
   Node *p = new Node(data);
   p->nxt = sp;
   sp = p;
}
void Pop(int &data)
{
   Node *p = sp;
   data = p->data;
   sp = sp->nxt;
   delete p;
}
void enQueue(int data) // Push
{
   Node *newNode = new Node(data);
   if (de == NULL)
      de = en = newNode;
   else
   {
      en->nxt = newNode;
      en = newNode;
   }
}
void deQueue(int &data) // Pop
{
   Node *p = de;
   data = de->data;
   de = de->nxt;
   delete p;
}
Tree searchNode_deRecursive(Tree root, int value)
{
   Tree cur = root;
   while (cur != NULL && cur->data != value)
   {
      if (cur->data > value)
         cur = cur->pLeft;
      else if (cur->data < value)
         cur = cur->pRight;
   }
   return cur;
}
void insertNode_deRecursive(Tree &root, int value)
{
   Tree cur = root, q = NULL;
   while (cur != NULL)
   {
      q = cur;
      if (cur->data == value)
         return;
      if (cur->data > value)
         cur = cur->pLeft;
      else
         cur = cur->pRight;
   }
   if (q == NULL)
      root = new Leaf(value);
   else if (q->data > value)
      q->pLeft = new Leaf(value);
   else
      q->pRight = new Leaf(value);

   // if(p == NULL)
   //    root = new Leaf(value);
   // else
   //    cur = new Leaf(value);
}
void NLR_deRecursive(Tree root) // PreOrder
{
   Tree cur = root;
   while (cur != NULL || !isEmptySt())
   {
      // if (cur != NULL)
      // {
      //    cout << cur->data << "\t";
      //    Push(cur->data);
      //    cur = cur->pLeft;
      // }
      // else
      // {
      //    int x;
      //    Pop(x);
      //    cur = searchNode_deRecursive(root, x);
      //    cur = cur->pRight;
      // }

      while (cur != NULL)
      {
         cout << cur->data << "\t";
         Push(cur->data);
         cur = cur->pLeft;
      }
      int x;
      Pop(x);
      cur = searchNode_deRecursive(root, x);
      cur = cur->pRight;
   }
   cout << "\n";
}
void LNR_deRecursive(Tree root) // InOrder
{
   Tree cur = root;
   while (cur != NULL || !isEmptySt())
   {
      // if (cur != NULL)
      // {
      //    Push(cur->data);
      //    cur = cur->pLeft;
      // }
      // else
      // {
      //    int x;
      //    Pop(x);
      //    cout << x << "\t";
      //    cur = searchNode_deRecursive(root, x);
      //    cur = cur->pRight;
      // }

      while (cur != NULL)
      {
         Push(cur->data);
         cur = cur->pLeft;
      }
      int x;
      Pop(x);
      cout << x << "\t";
      cur = searchNode_deRecursive(root, x);
      cur = cur->pRight;
   }
   cout << "\n";
}
void LRN_deRecursive(Tree root) // PostOrder
{
   Tree cur = root;
   while (cur != NULL || !isEmptySt())
   {
      while (cur != NULL)
      {
         Push(cur->data);
         Push(cur->data);
         cur = cur->pLeft;
      }
      int x;
      Pop(x);
      cur = searchNode_deRecursive(root, x);
      if (!isEmptySt() && x == sp->data)
         cur = cur->pRight;
      else
      {
         cout << x << "\t";
         cur = NULL;
      }
   }
   cout << "\n";
}
/*
               39
             /    \
            /      \
           8        62
         /  \      /  \
        /    \    /    \
       5     14  50    73
NLR: 39 8 5 14 62 50 73
LNR: 5 8 14 39 50 62 73
LRN: 5 14 8 50 73 62 39
*/
int main()
{
   Tree root = NULL;
   insertNode_deRecursive(root, 39);
   insertNode_deRecursive(root, 8);
   insertNode_deRecursive(root, 62);
   insertNode_deRecursive(root, 5);
   insertNode_deRecursive(root, 14);
   insertNode_deRecursive(root, 50);
   insertNode_deRecursive(root, 73);
   cout << "Duyet cay theo thu tu (PreOrder) Node - Left - Right:\n\n";
   NLR_deRecursive(root);
   cout << "\nDuyet cay theo thu tu (InOrder) Left - Node - Right:\n\n";
   LNR_deRecursive(root);
   cout << "\nDuyet cay theo thu tu (PostOrder) Left - Right - Node:\n\n";
   LRN_deRecursive(root);
   _getch();
   return 0;
}