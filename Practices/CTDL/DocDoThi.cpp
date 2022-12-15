#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX = 100;

/**/
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

void ReadFile(int A[][MAX + 1], int &n)
{
   ifstream inf("../resource/DoThi.txt");
   if (!inf.is_open())
   {
      cout << "\n--KHONG MO DUOC FILE--\n";
      return;
   }
   inf >> n;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
         inf >> A[i][j];
   inf.close();
}
void Display(int A[][MAX + 1], int n)
{
   cout << "\n";
   for (int i = 1; i <= n; i++)
   {
      cout << setw(25);
      for (int j = 1; j <= n; j++)
         cout << A[i][j] << " ";
      cout << "\n";
   }
}
void DFS(int A[][MAX + 1], int n, int s)
{
   bool mark[MAX + 1] = {false};
   STACK *st = NULL;
   Push_St(st, s);
   mark[s] = true;
   cout << s << "\t";
   while (!isEmpty(st))
   {
      int u = Peek(st);
      for (int v = 1; v <= n; v++)
         if (A[u][v] == 1 && !mark[v])
         {
            cout << v << "\t";
            Push_St(st, v);
            mark[v] = true;
            break;
         }
      if (u == Peek(st))
         Pop(st);
   }
   cout << "\n";
}
void BFS(int A[][MAX + 1], int n, int s)
{
   bool mark[MAX + 1] = {false};
   QUEUE q;
   Push_Qu(q, s);
   mark[s] = true;
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
void BFS_Recursion(int A[][MAX + 1], int n, bool mark[], QUEUE &q)
{
   if (isEmpty(q.front))
      return;
   int u = Peek(q.front);
   Pop(q.front);
   cout << u << "\t";
   for (int v = 1; v <= n; v++)
      if (A[u][v] == 1 && !mark[v])
      {
         Push_Qu(q, v);
         mark[v] = true;
      }
   BFS_Recursion(A, n, mark, q);
}
int main()
{
   int A[MAX + 1][MAX + 1], n = 0;
   bool mark[MAX + 1] = {false};
   QUEUE q;
   int s = 1;
   ReadFile(A, n);
   cout << setw(62) << "==DO THI DUOC BIEU DIEN DUOI DANG MA TRAN KE==\n";
   Display(A, n);
   cout << "\n- XUAT DO THI THEO DFS (Queue) -\n";
   // 1 2 7 8 13 14 9 3 6 4 5 10 12 11
   // 1 2 4 3 6 7 8 10 5 9 13 11 12
   DFS(A, n, s);
   cout << "\n- XUAT DO THI THEO BFS (Stack) -\n";
   // 1 2 3 4 7 6 5 8 9 10 11 13 14 12
   // 1 2 3 11 4 6 12 13 7 8 9 10 5
   BFS(A, n, s);
   cout << "\n- XUAT DO THI THEO BFS (Recursion) -\n";
   // 1 2 3 4 7 6 5 8 9 10 11 13 14 12
   // 1 2 3 11 4 6 12 13 7 8 9 10 5
   Push_Qu(q, s);
   mark[s] = true;
   BFS_Recursion(A, n, mark, q);
   getch();
   return 0;
}
/*
13
0 1 1 0 0 0 0 0 0 0 1 0 0
1 0 0 1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 0
0 1 0 1 0 0 1 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 1 0 1 1 0

14
0 1 1 1 0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0 0 0 0 0
1 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1 1 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 1 1
0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0
*/