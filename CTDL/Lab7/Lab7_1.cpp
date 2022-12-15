#include "../resource/BinarySearchTree.h"
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int main()
{
   Tree root = NULL;
   insertNode(root, 8);
   insertNode(root, 3);
   insertNode(root, 10);
   insertNode(root, 1);
   insertNode(root, 6);
   insertNode(root, 14);
   insertNode(root, 4);
   insertNode(root, 7);
   insertNode(root, 13);
   /////
   cout << "--------------------\n\n";
   NLR(root);
   cout << "\n";
   NLR(root);
   /////
   cout << "\n\n--------------------\n\n";
   LNR(root);
   cout << "\n";
   LNR(root);
   /////
   cout << "\n\n--------------------\n\n";
   LRN(root);
   cout << "\n";
   LRN(root);
   _getch();
   return 0;
}