//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<int> col(n + 1, -(1e9 + 7));
//	vector<vector<int>> A(m + 2, col);
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> A[i][j];
//	for (int i = 2; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			A[j][i] += max(max(A[j - 1][i - 1], A[j][i - 1]), A[j + 1][i - 1]);
//	int max = A[1][n];
//	for (int i = 2; i <= m; i++)
//		max = (max < A[i][n]) ? A[i][n] : max;
//	cout << max << endl;
//	return 0;
//}