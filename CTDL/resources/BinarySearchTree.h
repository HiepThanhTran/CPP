#include <iostream>
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

/* Duyệt cây */
// Node - Left - Right
void NLR(Tree root)
{
   if (root != NULL)
   {
      cout << root->data << "\t";
      NLR(root->pLeft);
      NLR(root->pRight);
   }
}
// Left - Node - Right
void LNR(Tree root)
{
   if (root != NULL)
   {
      LNR(root->pLeft);
      cout << root->data << "\t";
      LNR(root->pRight);
   }
}
// Left - Right - Node
void LRN(Tree root)
{
   if (root != NULL)
   {
      LRN(root->pLeft);
      LRN(root->pRight);
      cout << root->data << "\t";
   }
}
/* Tìm kiếm */
Tree searchNode(Tree root, int value)
{
   if (root == NULL)
      return NULL;
   if (root->data == value)
      return root;
   if (root->data > value)
      return searchNode(root->pLeft, value);
   else
      return searchNode(root->pRight, value);
}
/* Thêm Node vào cây */
void insertNode(Tree &root, int value)
{
   if (root == NULL)
      root = new Leaf(value);
   else
   {
      if (root->data == value)
         return;
      if (root->data > value)
         return insertNode(root->pLeft, value);
      else
         return insertNode(root->pRight, value);
   }
}
/* Xóa Node ra khỏi cây */
// Tìm Node nhỏ nhất cây con bên phải (cực trái)
void minValueNode(Tree &p, Tree &node)
{
   if (node->pLeft != NULL)
      return minValueNode(p, node->pLeft);
   else
   {
      p->data = node->data;
      p = node;
      node = node->pRight;
   }
}
// Tìm Node lớn nhất cây con bên trái (cực phải)
void maxValueNode(Tree &p, Tree &node)
{
   if (node->pRight != NULL)
      return maxValueNode(p, node->pRight);
   else
   {
      p->data = node->data;
      p = node;
      node = node->pLeft;
   }
}
bool deleteNode(Tree &root, int x)
{
   if (root == NULL)
      return false;
   if (root->data > x)
      return deleteNode(root->pLeft, x);
   else if (root->data < x)
      return deleteNode(root->pRight, x);
   else
   {
      Tree p = root;
      if (root->pLeft == NULL)
         root = root->pRight;
      else if (root->pRight == NULL)
         root = root->pLeft;
      else
         minValueNode(p, p->pRight);
      delete p;
      return true;
   }
}