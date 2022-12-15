//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<long> A, L, T;
//long n;
//
//void inData()
//{
//	cout << "Nhap n: ";
//	cin >> n;
//	A.assign(n + 2, 0);
//	L.assign(n + 2, 0);
//	T.assign(n + 2, 0);
//	for (int i = 1; i <= n; i++)
//		cin >> A[i];
//	A[0] = INT_MIN;
//	A[n + 1] = INT_MAX;
//}
//void show()
//{
//	int i = T[0];
//	while (i != n + 1)
//	{
//		cout << A[i] << "\t";
//		i = T[i];
//	}
//	cout << endl;
//}
//void solve()
//{
//	L[n + 1] = 1;
//	for (int i = n; i >= 0; i--)
//	{
//		long jmax = L[n + 1];
//		for (int j = i + 1; j < n + 2; j++)
//			if (A[j] > A[i] && L[j] > L[jmax])
//				jmax = j;
//		L[i] = L[jmax] + 1;
//		T[i] = jmax;
//	}
//}
///*
//n = 7
//Index	0		1	2	3	4	5	6	7		8
//A =		MIN		2	1	9	8	15	10	11		MAX
//L =		6		5	5	4	4	2	3	2		1
//T =		1		3	3	6	6	8	7	8		0
//*/
//int main()
//{
//	inData();
//	solve();
//	show();
//	return 0;
//}