//#include<iostream>
//using namespace std;
//const int MAX = 100000;
//
//int main()
//{
//	int A[MAX] = { 0 }, B[MAX] = { 0 }, F[24] = { 0 };
//	int n, m = 0, res = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> A[i] >> B[i];
//	for(int i = 0; i < n - 1; i++)
//		for (int j = i + 1; j < n; j++)
//			if (B[i] > B[j] || (B[i] == B[j] && (B[i] - A[i]) > (B[j] - A[j])))
//			{
//				swap(A[i], A[j]);
//				swap(B[i], B[j]);
//			}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		F[m] = B[i] - A[i];
//		int d = i;
//		for (int j = i - 1; j >= 0; j--)
//			if (B[j] <= A[i])
//			{
//				F[m] += (B[j] - A[j]);
//				i = j;
//			}
//		res = max(res, F[m]);
//		i = d;
//		m++;
//	}
//	cout << res << endl;
//	return 0;
//}