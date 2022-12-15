//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<conio.h>
//using namespace std;
//
//void buildL(vector<vector<int>> &L, vector<int> A, vector<int> B, int m, int n)
//{
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= n; j++)
//			if (A[i] == B[j])
//				L[i][j] = L[i - 1][j - 1] + 1;
//			else
//				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
//}
//void show(vector<vector<int>> L, vector<int> A, vector<int> B, int m, int n)
//{
//	vector<int> trace(m > n ? n : m, 0);
//	int count = 0, i = m, j = n;
//	while (i > 0 && j > 0)
//	{
//		if (A[i] == B[j])
//		{
//			trace[count++] = A[i];
//			i--;
//			j--;
//		}
//		else if (L[i][j - 1] > L[i - 1][j])
//			j--;
//		else
//			i--;
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			cout << L[i][j] << "\t";
//		cout << "\n";
//	}
//	for (int i = count - 1; i >= 0; i--)
//		cout << trace[i] << "\t";
//	cout << "\n";
//}
//int main()
//{
//	// A[] = 3 1 5 6 8 2
//	// B[] = 1 2 4 3 6 8
//	int m, n;
//	cin >> m >> n;
//	vector<int> A(m + 1, 0);
//	vector<int> B(n + 1, 0);
//	vector<vector<int>> L(m + 1, B);
//	for (int i = 1; i <= m; i++)
//		cin >> A[i];
//	for (int i = 1; i <= n; i++)
//		cin >> B[i];
//	buildL(L, A, B, m, n);
//	show(L, A, B, m, n);
//	return 0;
//}