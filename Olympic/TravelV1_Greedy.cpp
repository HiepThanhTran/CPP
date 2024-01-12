#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int START = 0;

vector<vector<long>> a;
vector<long> b, x;
vector<bool> d;
long n, total = 0;

void readData()
{
   ifstream inData("travel.inp");
   inData >> n;
   b.assign(n, 0);
   a.assign(n, b);
   x.assign(n, 0);
   d.assign(n, false);
   x[0] = START;
   d[START] = true;
   for (auto &i : a)
      for (auto &j : i)
         inData >> j;
}
void Greedy()
{
   for (long i = 1; i < n; i++)
   {
      int min = INT32_MAX, xi = -1;
      for (long j = 0; j < n; j++)
         if (!d[j] && a[x[i - 1.0]][j] > 0 && a[x[i - 1.0]][j] < min)
         {
            min = a[x[i - 1.0]][j];
            xi = j;
         }
      if (xi != -1)
      {
         x[i] = xi;
         total += min;
         d[xi] = true;
      }
   }
   total += a[x[n - 1.0]][START];
}
void output()
{
   for (auto i : x)
      cout << i + 1 << " -> ";
   cout << START + 1 << endl;
   cout << "Total: " << total << endl;
}
int main()
{
   readData();
   Greedy();
   output();
   return 0;
}