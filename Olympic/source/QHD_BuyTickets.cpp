//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> T(n + 1, 0), R(n + 1, 0), F(n + 1, 0);
//	for (int i = 1; i <= n; i++)
//		cin >> T[i];
//	for (int i = 1; i < n; i++)
//		cin >> R[i];
//	F[1] = T[1];
//	for (int i = 2; i <= n; i++)
//		if (F[i - 1] + T[i] > F[i - 2] + R[i - 1])
//			F[i] = F[i - 2] + R[i - 1];
//		else
//			F[i] = F[i - 1] + T[i];
//	cout << F[n] << endl;
//	return 0;
//}