#include <iostream>
#include <vector>
using namespace std;

vector<vector<long>> a;
vector<long> b;
long k, n, brick = 1;

void inData()
{
   cout << "Nhap k: ";
   cin >> k;
   n = 1 << k;
   b.assign(n, 0);
   a.assign(n, b);
}
void layingBrickV1(long x, long y, long size, long t)
{
   if (size == 2)
   {
      if (t != 1)
         a[x][y] = brick;
      if (t != 2)
         a[x][y + 1] = brick;
      if (t != 3)
         a[x + 1][y + 1] = brick;
      if (t != 4)
         a[x + 1][y] = brick;
      brick++;
   }
   else
   {
      long p = size / 2;
      switch (t)
      {
      case 1:
         layingBrickV1(x, y + p, p, 4);
         layingBrickV1(x + p, y + p, p, 1);
         layingBrickV1(x + p, y, p, 2);
         layingBrickV1(x + p / 2, y + p / 2, p, 1);
         break;
      case 2:
         layingBrickV1(x, y, p, 3);
         layingBrickV1(x + p, y, p, 2);
         layingBrickV1(x + p, y + p, p, 1);
         layingBrickV1(x + p / 2, y + p / 2, p, 2);
         break;
      case 3:
         layingBrickV1(x, y, p, 3);
         layingBrickV1(x, y + p, p, 4);
         layingBrickV1(x + p, y, p, 2);
         layingBrickV1(x + p / 2, y + p / 2, p, 3);
         break;
      case 4:
         layingBrickV1(x, y, p, 3);
         layingBrickV1(x, y + p, p, 4);
         layingBrickV1(x + p, y + p, p, 1);
         layingBrickV1(x + p / 2, y + p / 2, p, 4);
         break;
      }
   }
}
void show()
{
   for (auto i : a)
   {
      for (int j : i)
         cout << j << "\t";
      cout << "\n\n";
   }
}
int main()
{
   inData();
   layingBrickV1(0, 0, n, 2);
   show();
   return 0;
}