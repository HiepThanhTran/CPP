//#include<iostream>
//using namespace std;
//const int MAX = 1000;
//
//int main()
//{
//	int SNT[MAX + 1] = { 0 }, m = 1;
//	bool a[MAX + 1];
//	a[1] = false;
//	for (int i = 2; i <= MAX; i++)
//		a[i] = true;
//	for (int i = 2; i <= MAX; i++)
//		if (a[i])
//		{
//			for (int j = 2 * i; j <= MAX; j += i)
//				a[j] = false;
//			SNT[m++] = SNT[m - 1] + i;
//		}
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		cout << SNT[n] << endl;
//	}
//	return 0;
//}