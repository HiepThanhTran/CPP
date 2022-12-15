#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 20;

struct NODE
{
   int data;
   NODE *link;
   NODE(int _data)
   {
      data = _data;
      link = NULL;
   }
} typedef STACK;
struct QUEUE
{
   NODE *front = NULL;
   NODE *back = NULL;
};
bool isEmpty(NODE *p)
{
   return p == NULL;
}
void Pop(NODE *&p)
{
   if (!isEmpty(p))
   {
      NODE *curr = p;
      p = p->link;
      delete curr;
   }
}
int Peek(NODE *p)
{
   if (!isEmpty(p))
      return p->data;
   return INT32_MIN;
}
void Push_St(STACK *&st, int value)
{
   STACK *newValue = new STACK(value);
   newValue->link = st;
   st = newValue;
}
void Push_Qu(QUEUE &qu, int value)
{
   NODE *newValue = new NODE(value);
   if (qu.front == NULL)
   {
      qu.front = qu.back = newValue;
      return;
   }
   qu.back->link = newValue;
   qu.back = newValue;
}
////////////////////////////////////
// Câu a
void input(int A[][MAX + 1], int &n)
{
   do
   {
      cout << "Nhap so dinh cua do thi: ";
      cin >> n;
      if (n < 1 || n > MAX)
         cout << "\n--KHONG HOP LE--\n";
   } while (n < 1 || n > MAX);
   for (int i = 0; i < n; i++)
   {
      cout << "- Nhap cac dinh ke cua dinh " << i + 1 << ": ";
      for (int j = 0; j < n; j++)
         cin >> A[i][j];
   }
}
// Câu b
void output(int A[][MAX + 1], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << A[i][j] << " ";
      cout << "\n";
   }
}
// Câu c
void BFS(int A[][MAX + 1], int n, int i)
{
   // int bfs[MAX], nbfs = 0;
   bool mark[MAX + 1] = {false};
   QUEUE q;
   Push_Qu(q, i);
   mark[i] = true;
   while (!isEmpty(q.front))
   {
      int u = Peek(q.front);
      Pop(q.front);
      cout << u << "\t";
      for (int v = 1; v <= n; v++)
         if (A[u][v] == 1 && !mark[v])
         {
            Push_Qu(q, v);
            mark[v] = true;
         }
   }
   cout << "\n";
}
// Câu d
void DFS(int A[][MAX + 1], int n, int i)
{
   // int dfs[MAX + 1], ndfs = 0;
   bool mark[MAX + 1] = {false};
   STACK *sp = NULL;
   Push_St(sp, i);
   mark[i] = true;
   cout << i << "\t";
   while (!isEmpty(sp))
   {
      int u = Peek(sp);
      for (int v = 1; v <= n; v++)
         if (A[u][v] == 1 && !mark[v])
         {
            cout << v << "\t";
            mark[v] = true;
            Push_St(sp, v);
            break;
         }
      if (u == Peek(sp))
         Pop(sp);
   }
   cout << "\n";
}
// Câu e
bool searchX_BFS(int A[][MAX + 1], int n, int i, int x)
{
   bool mark[MAX + 1] = {0};
   QUEUE q;
   Push_Qu(q, i);
   mark[i] = 1;
   while (!isEmpty(q.front))
   {
      int u = Peek(q.front);
      Pop(q.front);
      if (u == x)
         return true;
      for (int v = 1; v <= n; v++)
         if (A[u][v] == 1 && !mark[v])
         {
            mark[v] = 1;
            Push_Qu(q, v);
         }
   }
   return false;
}
int main()
{
   int A[MAX + 1][MAX + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}};
   int n = 14;
   // int A[MAX + 1][MAX + 1], n = 0;
   // input(A, n);
   output(A, n);
   cout << "\n--QUA TRINH BFS--\n";
   BFS(A, n, 1);
   cout << "\n--QUA TRINH DFS--\n";
   DFS(A, n, 1);
   int x;
   cout << "\n- Nhap dinh can tim: ";
   cin >> x;
   if (searchX_BFS(A, n, 1, x))
      cout << "\n-- GIA TRI << " << x << " >> CO TRONG DO THi --\n";
   else
      cout << "\n-- GIA TRI << " << x << " >> KHONG CO TRONG DO THi --\n";
   _getch();
   return 0;
}