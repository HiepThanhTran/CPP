#include<iostream>
#include<conio.h>
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
bool isEmpty(NODE *p)
{
   return p == NULL;
}
void Push(NODE *&p, int value)
{
   NODE *newNode = new NODE(value);
   newNode->link = p;
   p = newNode;
}
void Pop(NODE *&st)
{
   if(!isEmpty(st))
   {
      NODE *p = st;
      st = st->link;
      delete p;
   }
}
int Peek(NODE *st)
{
   if(!isEmpty(st))
      return st->data;
   return INT32_MIN;
}

bool search(NODE *p, int target)
{
   NODE *curr = p;
   while(curr != NULL)
   {
      if(curr->data == target)
         return true;
      curr = curr->link;
   }
   return false;
}
void input(NODE *A[MAX + 1], int &n)
{
   int m;
   do{
      cout << "\n- Nhap so dinh cua do thi: ";
      cin >> n;
      if(n < 1 || n > MAX)
         cout << "\n--KHONG HOP LE--\n";
   } while (n < 1 || n > MAX);
   cout << "\n- Nhap so canh cua do thi: ";
   cin >> m;
   for (int i = 1; i <= m; i++)
   {
      int u, v;
      cout << "\n- Nhap canh thu " << i << ": ";
      cin >> u >> v;
      Push(A[u], v);
   }
}
void processList(NODE *p)
{
   if(!isEmpty(p))
   {
      NODE *curr = p;
      while(curr != NULL)
      {
         cout << curr->data << " ";
         curr = curr->link;
      }
      cout << "\n";
   }
   else
      cout << "\n--DANH SACH RONG--\n";
}
void output(NODE *A[MAX + 1], int n)
{
   for(int i = 1; i <= n; i++)
   {
      cout << "\n--DANH SACH THU " << i << "--\n";
      processList(A[i]);
   }
}
void DFS(NODE *A[MAX + 1], int n, int i)
{
   bool mark[MAX + 1] = {false};
   NODE *st = NULL;
   Push(st, i);
   mark[i] = true;
   cout << i << "\t";
   while(!isEmpty(st))
   {
      int u = Peek(st);
      for (int v = 1; v <= n; v++)
         if(search(A[u], v) && !mark[v])
         {
            cout << v << "\t";
            Push(st, v);
            mark[v] = true;
            break;
         }
      if(u == Peek(st))
         Pop(st);
   }
   cout << "\n";
}
/*
n = 14
m = 14
1 2
1 3
1 4
2 7
3 6
4 5
7 8
7 9
6 10
5 10
5 11
8 13
8 14
10 12
*/
// 1 2 7 8 13 14 9 3 6 10 5 11 12 4
int main()
{
   NODE *A[MAX + 1] = {NULL};
   int n = 0;
   input(A, n);
   cout << "\n--QUA TRINH DFS--\n";
   DFS(A, n, 1);
   getch();
   return 0;
}