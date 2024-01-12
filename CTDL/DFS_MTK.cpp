#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 20;

struct STACK
{
   int data;
   STACK *link;
   STACK(int _data)
   {
      data = _data;
      link = NULL;
   }
} typedef St;
bool isEmpty(St *sp)
{
   return (sp == NULL);
}
void Push(St *&sp, int value)
{
   St *newValue = new St(value);
   newValue->link = sp;
   sp = newValue;
}
void Pop(St *&sp)
{
   if (isEmpty(sp))
      exit(1);
   St *p = sp;
   sp = sp->link;
   delete p;
}
int Peek(St *sp)
{
   if (!isEmpty(sp))
      return sp->data;
   exit(1);
}

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
void output(int A[][MAX + 1], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << A[i][j] << " ";
      cout << "\n";
   }
}
void DFS(int A[][MAX + 1], int n, int i)
{
   // int dfs[MAX + 1], ndfs = 0;
   bool mark[MAX + 1] = {false};
   St *sp = NULL;
   Push(sp, i);
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
            Push(sp, v);
            break;
         }
      if (u == Peek(sp))
         Pop(sp);
   }
   cout << "\n";
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
   cout << "\n--QUA TRINH DFS--\n";
   DFS(A, n, 1);
   _getch();
   return 0;
}