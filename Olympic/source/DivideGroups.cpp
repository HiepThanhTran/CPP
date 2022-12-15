#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> A, G, T;
vector<bool> D;
long n, k, num = 1, s = 0, m = 0;

void readData()
{
   ifstream inData("groups.inp");
   inData >> n >> k;
   A.assign(n, 0);
   G.assign(n, 0);
   T.assign(n, 0);
   D.assign(n, false);
   for (auto &i : A)
      inData >> i;
}
void show()
{
   for (int i = 0; i < num; i++)
      cout << G[i] << " ";
   cout << endl;
}
int sum(vector<int> A, int m)
{
   int sum = 0;
   for (int i = 0; i < m; i++)
      sum += A[i];
   return sum;
}
void Try(int idx)
{
}
/*
5	3
1	4	6	9	10

1:		1
2:		4
3:		6
4:		9
5:		10

6:		1	4
7:		1	6
8:		1	9
9:		1	10
10:		4	6
11:		4	9
12:		4	10
13:		6	9
14:		6	10
15:		9	10

16:		1	4	6
17:		1	4	9
18:		1	4	10
19:		1	6	9
20:		1	6	10
21:		1	9	10
22:		4	6	9
23:		4	6	10
24:		4	9	10
25:		6	9	10

26:		1	4	6	9
27:		1	4	6	10
28:		1	4	9	10
29:		1	6	9	10
30:		4	6	9	10
31:		1	4	6	9	10
*/
// s == sum(A, n) / k
int main()
{
   readData();
   if (sum(A, n) % k != 0)
      cout << -1 << endl;
   else
      Try(0);
   return 0;
}