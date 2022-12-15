#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

struct Node
{
   char data;
   Node *left;
   Node *right;
   Node(char _data)
   {
      data = _data;
      left = NULL;
      right = NULL;
   }
};

Node *root = NULL;
void insertNode(Node *&p, char x)
{
   if (p == NULL)
      p = new Node(x);
   else
   {
      if (p->data == x)
         return;
      else
      {
         if (p->data < x)
            insertNode(p->right, x);
         else
            insertNode(p->left, x);
      }
   }
}
void LNR(Node *root)
{
   if (root != NULL)
   {
      LNR(root->left);
      cout << root->data << " ";
      LNR(root->right);
   }
}
int countNode(Node *root)
{
   if (root == NULL)
      return 0;
   return 1 + countNode(root->left) + countNode(root->right);
}
int countEvenNode(Node *root)
{
   if (root == NULL)
      return 0;
   if (root->data % 2 == 0)
      return 1 + countEvenNode(root->left) + countEvenNode(root->right);
   return countEvenNode(root->left) + countEvenNode(root->right);
}
int countOddNode(Node *root)
{
   if (root == NULL)
      return 0;
   if (root->data % 2 != 0)
      return 1 + countOddNode(root->left) + countOddNode(root->right);
   return countOddNode(root->left) + countOddNode(root->right);
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
bool isSquare(int x)
{
   int sqr = sqrt(x);
   if (sqr * sqr == x)
      return true;
   return false;
}
int countPrimeNode(Node *root)
{
   if (root == NULL)
      return 0;
   if (isPrime(root->data))
      return 1 + countPrimeNode(root->left) + countPrimeNode(root->right);
   return countPrimeNode(root->left) + countPrimeNode(root->right);
}
int countSquareNode(Node *root)
{
   if (root == NULL)
      return 0;
   if (isSquare(root->data))
      return 1 + countPrimeNode(root->left) + countPrimeNode(root->right);
   return countPrimeNode(root->left) + countPrimeNode(root->right);
}
int main()
{
   string h;
   cout << "Nhap chuoi: ";
   cin >> h;
   for (int i = 0; i < h.length(); i++)
      insertNode(root, h[i]);
   LNR(root);
   _getch();
   return 0;
}