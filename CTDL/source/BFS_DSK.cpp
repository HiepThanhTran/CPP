#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;

struct NODE
{
   int data;
   NODE *link;
   NODE(int _data)
   {
      data = _data;
      link = NULL;
   }
};
struct QUEUE
{
   NODE *front = NULL;
   NODE *back = NULL;
} typedef Qu;
bool isEmpty(Qu q)
{
   return (q.front == NULL);
}
void Push(Qu &q, int value)
{
   NODE *newValue = new NODE(value);
   if (q.front == NULL)
   {
      q.front = q.back = newValue;
      return;
   }
   q.back->link = newValue;
   q.back = newValue;
}
void Pop(Qu &q)
{
   if (!isEmpty(q))
   {
      NODE *del = q.front;
      q.front = q.front->link;
      delete del;
   }
}
int Peek(Qu q)
{
   if (!isEmpty(q))
      return q.front->data;
   return INT32_MIN;
}

bool search(NODE *head, int target)
{
   NODE *curr = head;
   while (curr != NULL)
   {
      if (curr->data == target)
         return true;
      curr = curr->link;
   }
   return false;
}
void insertFirst(NODE *&head, int value)
{
   NODE *newNode = new NODE(value);
   newNode->link = head;
   head = newNode;
}
void input(NODE *A[MAX + 1], int &n)
{
   int d, m, x;
   do
   {
      cout << "\n- Nhap so dinh cua do thi: ";
      cin >> n;
      if (n < 1 || n > MAX)
         cout << "\n-- KHONG HOP LE --\n";
   } while (n < 1 || n > MAX);
   cout << "\n- Nhap so canh cua do thi: ";
   cin >> m;
   for (int i = 1; i <= m; i++)
   {
      int u, v;
      cout << "\n- Nhap canh thu " << i << ": ";
      cin >> u >> v;
      insertFirst(A[u], v);
      // cout << "\n- Nhap dinh thu " << i << ": ";
      // cin >> d;
      // insertFirst(A[i], d);
      // cout << "\n- Nhap so dinh ke voi " << d << ": ";
      // cin >> m;
      // cout << "\n- Nhap cac dinh ke cua " << i << ": ";
      // for (int j = 1; j <= m; j++)
      // {
      //    cin >> x;
      //    insertFirst(A[i], x);
      // }
   }
}
void processList(NODE *head)
{
   if (head != NULL)
   {
      NODE *curr = head;
      while (curr != NULL)
      {
         cout << curr->data << "\t";
         curr = curr->link;
      }
      cout << "\n";
   }
}
void output(NODE *A[MAX + 1], int n)
{
   for (int i = 1; i <= n; i++)
   {
      cout << "\n-- DANH SACH THU " << i << " --\n";
      processList(A[i]);
   }
}
void BFS(NODE *A[MAX + 1], int n, int i)
{
   bool mark[MAX + 1] = {false};
   Qu q;
   Push(q, i);
   mark[i] = true;
   while (!isEmpty(q))
   {
      int u = Peek(q);
      Pop(q);
      cout << u << "\t";
      for (int v = 1; v <= n; v++)
         if (search(A[u], v) && !mark[v])
         {
            Push(q, v);
            mark[v] = true;
         }
   }
   cout << "\n";
}
int main()
{
   NODE *A[MAX + 1] = {NULL};
   int n = 0;
   input(A, n);
   cout << "\n--QUA TRINH BFS--\n";
   BFS(A, n, 1);
   getch();
   return 0;
}