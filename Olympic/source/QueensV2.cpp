//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<algorithm>
//#include<conio.h>
//using namespace std;
//const int SIZE = 8;
//
//int A[SIZE][SIZE], X[SIZE], best[SIZE], total = 0, totalBest = 0;
//bool d[SIZE] = { false };
//
//void readData()
//{
//	ifstream inData("queens.inp");
//	for (int i = 0; i < SIZE; i++)
//		for (int j = 0; j < SIZE; j++)
//			inData >> A[i][j];
//}
//void show()
//{
//	for (int i = 0; i < SIZE; i++)
//		cout << best[i] << " ";
//	cout << "\n" << totalBest << "\n";
//}
//bool canPutQueen(int i, int j)
//{
//	for (int k = 0; k < i; k++)
//		if (X[k] == j || abs(k - i) == abs(X[k] - j))
//			return false;
//	return true;
//}
//void update()
//{
//	if (total > totalBest)
//	{
//		totalBest = total;
//		for (int i = 0; i < SIZE; i++)
//			best[i] = X[i];
//	}
//}
//int chooseQueen(int i)
//{
//	int max = INT_MIN, jmax = -1;
//	for (int j = 0; j < SIZE; j++)
//		if (canPutQueen(i, j) && A[i][j] > max)
//		{
//			max = A[i][j];
//			jmax = j;
//		}
//	return jmax;
//}
//void Try(int idx)
//{
//	int j = chooseQueen(idx);
//	if (j < 0) return;
//	X[idx] = j;
//	total += A[idx][j];
//	if (idx == SIZE - 1)
//		update();
//	else
//		Try(idx + 1);
//	total -= A[idx][j];
//}
//int main()
//{
//	readData();
//	Try(0);
//	show();
//	return 0;
//}