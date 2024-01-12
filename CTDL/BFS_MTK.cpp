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
   if (q.front == NULL)
      exit(1);
   NODE *del = q.front;
   q.front = q.front->link;
   delete del;
}
int Peek(Qu q)
{
   if (q.front != NULL)
      return q.front->data;
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
void BFS(int A[][MAX + 1], int n, int i)
{
   // int bfs[MAX], nbfs = 0;
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
         if (A[u][v] == 1 && !mark[v])
         {
            Push(q, v);
            mark[v] = true;
         }
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
   cout << "\n--QUA TRINH BFS--\n";
   BFS(A, n, 1);
   _getch();
   return 0;
}