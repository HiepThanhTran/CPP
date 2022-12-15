//#include<iostream>
//#include<fstream>
//#include<vector>
//using namespace std;
//
//vector<int> S, F;
//int L[3], C[3];
//int n, s, f;
//
//int getMoney(int distance) { return distance <= L[0] ? C[0] : distance <= L[1] ? C[1] : distance <= L[2] ? C[2] : -1; }
//void readData()
//{
//	ifstream inf("ticket.inp");
//	inf >> L[0] >> L[1] >> L[2];
//	inf >> C[0] >> C[1] >> C[2];
//	inf >> n;
//	S.assign(n + 1, 0); F.assign(n + 1, INT_MAX);
//	inf >> s >> f;
//	F[s] = 0;
//	for (int i = 2; i <= n; i++) inf >> S[i];
//	inf.close();
//}
//void solve()
//{
//	for (int i = s + 1; i <= f; i++)
//		for (int j = i - 1; j >= s; j--)
//			if (getMoney(S[i] - S[j]) != -1)
//				F[i] = min(getMoney(S[i] - S[j]) + F[j], F[i]);
//			else break;
//	ofstream outf("ticket.out");
//	outf << F[f] << endl;
//	outf.close();
//}
//int main()
//{
//	readData();
//	solve();
//	return 0;
//}