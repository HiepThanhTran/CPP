#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

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

void readFile(int **&arr, int &n, char *&name)
{
   ifstream inf("../resource/DoThi_Cau_4");
   if (!inf.is_open())
   {
      cout << "\n--KHONG MO DUOC FILE--\n";
      return;
   }
   inf >> n;
   arr = new int *[n];
   name = new char[n + 1];
   for (int i = 0; i < n; i++)
   {
      inf >> name[i];
      arr[i] = new int[n];
   }
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         inf >> arr[i][j];
}
void output(int **arr, int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << arr[i][j] << " ";
      cout << endl;
   }
}
void DFS(int **arr, int n, int s, char *name)
{
   bool *mark = new bool[n]{false};
   STACK *st = NULL;
   Push_St(st, s);
   mark[s] = true;
   cout << name[s] << "\t";
   while (!isEmpty(st))
   {
      int u = Peek(st);
      for (int v = 1; v <= n; v++)
         if (arr[u][v] == 1 && !mark[v])
         {
            cout << name[v] << "\t";
            Push_St(st, v);
            mark[v] = true;
            break;
         }
      if (u == Peek(st))
         Pop(st);
   }
   cout << "\n";
}
void BFS(int **arr, int n, int s, char *name)
{
   bool *mark = new bool[n]{false};
   QUEUE q;
   Push_Qu(q, s);
   mark[s] = true;
   while (!isEmpty(q.front))
   {
      int u = Peek(q.front);
      Pop(q.front);
      cout << name[u] << "\t";
      for (int v = 1; v <= n; v++)
         if (arr[u][v] == 1 && !mark[v])
         {
            Push_Qu(q, v);
            mark[v] = true;
         }
   }
   cout << "\n";
}
int main()
{
   int **arr = 0, n = 0;
   char *name = 0;
   readFile(arr, n, name);
   output(arr, n);
   DFS(arr, n, 1, name);
   BFS(arr, n, 1, name);
   _getch();
   return 0;
}