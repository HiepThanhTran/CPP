//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<vector<long>> A, F;
//vector<long> B;
//long n;
//
//void inData()
//{
//	cout << "Nhap n: ";
//	cin >> n;
//	B.assign(n + 1, 0);
//	A.assign(n + 1, B);
//	F.assign(n + 1, B);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> A[i][j];
//}
////int sumOfSubMatrix(int row1, int row2, int col1, int col2)
////{
////	int sum = 0;
////	for (int i = row1; i <= row2; i++)
////		for (int j = col1; j <= col2; j++)
////			sum += A[i][j];
////	return sum;
////}
////void solve2()
////{
////	int max = sumOfSubMatrix(0, 0, 0, 0);
////	for (int i = 0; i < n - 1; i++)
////		for (int j = 0; j < n - 1; j++)
////			for (int k = i + 1; k < n; k++)
////				for (int h = j + 1; h < n; h++)
////				{
////					if (i == 0 && j == 0 && k == n - 1 && h == n - 1) continue;
////					if (sumOfSubMatrix(i, k, j, h) > max)
////						max = sumOfSubMatrix(i, k, j, h);
////				}
////	cout << max << endl;
////}
//void solve()
//{
//	long sumMax = INT_MIN;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			F[i][j] = A[i][j] + F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1];
//	for(int i = 1; i <= n; i++)
//		for (int j = i; j <= n; j++)
//		{
//			long sum = 0, sumMin = 0;
//			for (int k = 1; k <= n; k++)
//			{
//				sum += F[j][k] - F[i - 1][k] - F[j][k - 1] + F[i - 1][k - 1];
//				sumMax = max(sum - sumMin, sumMax);
//				sumMin = min(sum, sumMin);
//			}
//		}
//	cout << sumMax << endl;
//}
//int main()
//{
//	inData();
//	solve();
//	return 0;
//}