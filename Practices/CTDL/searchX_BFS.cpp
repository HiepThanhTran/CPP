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
   return q.front == NULL;
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
   if (isEmpty(q))
      exit(1);
   NODE *del = q.front;
   q.front = q.front->link;
   delete del;
}
int Peek(Qu q)
{
   if (isEmpty(q))
      return INT32_MIN;
   return q.front->data;
}
void input(int A[][MAX + 1], int &n)
{
   do
   {
      cout << "Nhap so dinh cua do thi: ";
      cin >> n;
      if (n < 1 || n > MAX)
         cout << "\n-- KHONG HOP LE --\n";
   } while (n < 1 || n > MAX);
   for (int i = 1; i <= n; i++)
   {
      cout << "\n- Nhap cac dinh ke cua " << i << ": ";
      for (int j = 1; j <= n; j++)
         cin >> A[i][j];
   }
}
void output(int A[][MAX + 1], int n)
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= n; j++)
         cout << A[i][j] << " ";
      cout << "\n";
   }
}
bool searchX_BFS(int A[][MAX + 1], int n, int i, int x)
{
   bool mark[MAX + 1] = {0};
   Qu q;
   Push(q, i);
   mark[i] = 1;
   while (!isEmpty(q))
   {
      int u = Peek(q);
      Pop(q);
      if (u == x)
         return true;
      for (int v = 1; v <= n; v++)
         if (A[u][v] == 1 && !mark[v])
         {
            mark[v] = 1;
            Push(q, v);
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
   int n = 14, x;
   cout << "\n- Nhap dinh can tim: ";
   cin >> x;
   if (searchX_BFS(A, n, 1, x))
      cout << "\n-- GIA TRI << " << x << " >> CO TRONG DO THi --\n";
   else
      cout << "\n-- GIA TRI << " << x << " >> KHONG CO TRONG DO THi --\n";
   getch();
   return 0;
}