#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
const int MAXN = 100;

void readFile(int G[][MAXN], int &n)
{
   ifstream inf("../resource/prim.txt");
   if (!inf.is_open())
   {
      cout << "\n==KHONG MO DUOC FILE==\n";
      return;
   }
   inf >> n;
   for (int j = 0; j < n; j++)
      for (int i = 0; i < n; i++)
         inf >> G[i][j];
}
void Display(int G[][MAXN], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << G[i][j] << " ";
      cout << "\n";
   }
}
int minValue(int key[], int n)
{
   int min = key[0], minPos = 0;
   for (int i = 1; i < n; i++)
      if (key[i] < min)
      {
         min = key[i];
         minPos = i;
      }
   return minPos;
}
void Prim(int G[][MAXN], int n)
{
}
int main()
{
   int G[MAXN][MAXN], n;
   readFile(G, n);
   Display(G, n);
   getch();
   return 0;
}