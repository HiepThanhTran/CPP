#include <iostream>
#include <conio.h>
using namespace std;
const int MAX = 100;

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
   return sp == NULL;
}
void Push(St *&sp, int value)
{
   St *newValue = new St(value);
   newValue->link = sp;
   sp = newValue;
}
void Pop(St *&sp)
{
   if (!isEmpty(sp))
   {
      St *del = sp;
      sp = sp->link;
      delete del;
   }
}
int Peek(St *sp)
{
   if(!isEmpty(sp))
      return sp->data;
   return INT32_MIN;
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
bool searchX_DFS(int A[][MAX + 1], int n, int i, int x)
{
   bool mark[MAX + 1] = {false};
   St *sp = NULL;
   Push(sp, i);
   mark[i] = true;
   while (!isEmpty(sp))
   {
      int u = Peek(sp);
      if(u == x)
         return true;
      for (int v = 1; v <= n; v++)
         if(A[u][v] == 1 && !mark[v])
         {
            Push(sp, v);
            mark[v] = true;
            break;
         }
      if(u == Peek(sp))
         Pop(sp);
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
   if (searchX_DFS(A, n, 1, x))
      cout << "\n-- GIA TRI << " << x << " >> CO TRONG DO THi --\n";
   else
      cout << "\n-- GIA TRI << " << x << " >> KHONG CO TRONG DO THi --\n";
   getch();
   return 0;
}