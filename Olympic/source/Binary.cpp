#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<long> ans;
long n;
int counter = 1;

void output()
{
   cout << counter << ": ";
   for (int i = 0; i < n; i++)
      cout << ans[i];
   cout << endl;
   counter++;
}
void Try(int idx)
{
   for (int i = 0; i < 2; i++)
   {
      ans[idx] = i;
      if (idx == n - 1)
         output();
      else
         Try(idx + 1);
   }
}
int main()
{
   cout << "Nhap n: ";
   cin >> n;
   ans.assign(n, 0);
   Try(0);
   return 0;
}