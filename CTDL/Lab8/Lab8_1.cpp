#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

struct Node
{
   int data;
   Node *pLeft;
   Node *pRight;
   Node(int _data)
   {
      data = _data;
      pLeft = NULL;
      pRight = NULL;
   }
};
typedef Node *Tree;

void LNR(Tree root)
{
   if (root != NULL)
   {
      LNR(root->pLeft);
      cout << root->data << " ";
      LNR(root->pRight);
   }
}
void insertNode(Tree &root, int value)
{
   if (root == NULL)
      root = new Node(value);
   else
   {
      if (root->data == value)
         return;
      if (root->data > value)
         insertNode(root->pLeft, value);
      else
         insertNode(root->pRight, value);
   }
}
void minValueNode(Tree &p, Tree &node)
{
   if (node->pLeft != NULL)
      minValueNode(p, node->pLeft);
   else
   {
      p->data = node->data;
      p = node;
      node = node->pRight;
   }
}
bool deleteNode(Tree &root, int value)
{
   if (root == NULL)
      return false;
   if (root->data > value)
      deleteNode(root->pLeft, value);
   else if (root->data < value)
      deleteNode(root->pRight, value);
   else
   {
      Tree p = root;
      if (root->pLeft == NULL)
         root = root->pRight;
      else if (root->pRight == NULL)
         root = root->pLeft;
      else
         minValueNode(p, root->pRight);
      delete p;
      return true;
   }
}
int countLeafNode(Tree root)
{
   if (root != NULL)
   {
      if (root->pLeft == NULL && root->pRight == NULL)
         return 1;
      return countLeafNode(root->pLeft) + countLeafNode(root->pRight);
   }
   return 0;
}
int sumOfNodes(Tree root)
{
   if (root == NULL)
      return 0;
   return root->data + sumOfNodes(root->pLeft) + sumOfNodes(root->pRight);
}
int node1CayCon(Tree root)
{
   if (root == NULL || (root->pLeft != NULL && root->pRight != NULL))
      return 0;
   return 1 + node1CayCon(root->pLeft) + node1CayCon(root->pRight);
}
void printNode1CayCon(Tree root)
{
   if (root == NULL)
      return;
   if ((root->pLeft == NULL && root->pRight != NULL) || (root->pLeft != NULL && root->pRight == NULL))
      cout << root->data << " ";
   printNode1CayCon(root->pLeft);
   printNode1CayCon(root->pRight);
}
int node2CayCon(Tree root)
{
   if (root == NULL || root->pLeft == NULL || root->pRight == NULL)
      return 0;
   return 1 + node2CayCon(root->pLeft) + node2CayCon(root->pRight);
}
void printNode2CayCon(Tree root)
{
   if (root == NULL || root->pLeft == NULL || root->pRight == NULL)
      return;
   cout << root->data << " ";
   printNode2CayCon(root->pLeft);
   printNode2CayCon(root->pRight);
}
int check2TreeEqual(Tree root1, Tree root2)
{
   int t;
   if ((root1 == NULL && root2 == NULL))
      t = 1;
   if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
      t = 0;
   else
   {
      if (root1->data == root2->data && check2TreeEqual(root1->pLeft, root2->pLeft) && check2TreeEqual(root1->pRight, root2->pRight) == 1)
         t = 1;
      else
         t = 0;
   }
   return t;
}
int heightOfTree(Tree root)
{
   if (root == NULL)
      return 0;
   int h1 = heightOfTree(root->pLeft);
   int h2 = heightOfTree(root->pRight);
   return ((h1 > h2) ? h1 : h2) + 1;
}
int depthNode(Tree root, int depth, int value)
{
   if (root == NULL)
      return -1;
   if (root->data == value)
      return depth;
   int l = depthNode(root->pLeft, depth + 1, value);
   int r = depthNode(root->pRight, depth + 1, value);
   return l > r ? l : r;
}
int lvNode(Tree root, int lv)
{
   if (root == NULL)
      return lv - 1;
   int l = lvNode(root->pLeft, lv + 1);
   int r = lvNode(root->pRight, lv + 1);
   return l > r ? l : r;
}
int main()
{
   srand(time(NULL));
   Tree root1 = NULL;
   Tree root2 = NULL;
   int choice, value;
   do
   {
      system("cls");
      cout << "1- Them Node vao cay thu 1\n";
      cout << "2- Them Node vao cay thu 2\n";
      cout << "3- Xoa Node khoi cay\n";
      cout << "4- Xuat cay ra man hinh\n";
      cout << "5- Dem Node la trong cay\n";
      cout << "6- Tong cac Node tren cay\n";
      cout << "7- Dem cac Node co 1 cay con\n";
      cout << "8- In ra cau 6\n";
      cout << "9- Dem cac Node co 2 cay con\n";
      cout << "10- In ra cau 8\n";
      cout << "11- Kiem tra 2 cay nhi phan bang nhau\n";
      cout << "12- Tinh chieu cao cua cay nhi phan\n";
      cout << "13- Tinh do sau cua 1 Node trong cay\n";
      cout << "14- Tinh muc cua cac Node la trong cay\n";
      cout << "15- Ket thuc\n";
      cout << "- Chon chuc nang: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         cout << "\n- Nhap gia tri can them: ";
         cin >> value;
         insertNode(root1, value);
         break;
      case 2:
         cout << "\n- Nhap gia tri can them: ";
         cin >> value;
         insertNode(root2, value);
         break;
      case 3:
         cout << "\n- Nhap gia tri can xoa: ";
         cin >> value;
         if (deleteNode(root1, value))
            cout << "\n-- Xoa thanh cong --\n";
         else
            cout << "\n-- Khong tim thay gia tri --\n";
         break;
      case 4:
         cout << "\n- Cay dang luu tru:\n";
         LNR(root1);
         cout << "\n";
         break;
      case 5:
         cout << "\n- So Node la trong cay: " << countLeafNode(root1) << "\n";
         break;
      case 6:
         cout << "\n- Tong cac Node tren cay: " << sumOfNodes(root1) << "\n";
         break;
      case 7:
         cout << "\n- So Node co 1 cay con: " << node1CayCon(root1) << "\n";
         break;
      case 8:
         cout << "\n- Cac Node co 1 cay con:\n";
         printNode1CayCon(root1);
         cout << "\n";
         break;
      case 9:
         cout << "\n- So Node co 2 cay con: " << node2CayCon(root1) << "\n";
         break;
      case 10:
         cout << "\n- Cac Node co 2 cay con:\n";
         printNode2CayCon(root1);
         cout << "\n";
         break;
      case 11:
         if (check2TreeEqual(root1, root2) == 1)
            cout << "\n- 2 cay giong nhau\n";
         else
            cout << "\n- 2 cay khong giong nhau\n";
         break;
      case 12:
         cout << "\n- Chieu cao cua cay: " << heightOfTree(root1) - 1 << "\n";
         break;
      case 13:
         cout << "\n- Nhap gia tri: ";
         cin >> value;
         cout << "\n- Do sau cua " << value << ": " << depthNode(root1, 0, value) << "\n";
         break;
      case 14:
         cout << "\n- Muc cua cac Node la trong cay: " << lvNode(root1, 0) << "\n";
         break;
      default:
         cout << "\n== KET THUC CHUONG TRINH ==\n";
      }
      _getch();
   } while (choice >= 1 && choice <= 14);
   return 0;
}