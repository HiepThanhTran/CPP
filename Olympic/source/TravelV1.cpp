//#include<iostream>
//#include<fstream>
//#define START 0
//using namespace std;
//
//int** a = 0, * x = 0, * best = 0, n = 0, total = 0, totalBest = INT_MAX;
//bool* d = 0;
//void readData()
//{
//	ifstream inData("travel.inp");
//	inData >> n;
//	a = new int* [n];
//	for (int i = 0; i < n; i++)
//		a[i] = new int[n];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			inData >> a[i][j];
//	inData.close();
//}
//void initData()
//{
//	readData();
//	x = new int[n] {0};
//	d = new bool[n];
//	best = new int[n];
//	x[0] = START;
//	for (int i = 0; i < n; i++)
//		d[i] = false;
//	d[START] = true;
//}
//void output()
//{
//	ofstream outData("travel.out");
//	for (int i = 0; i < n; i++)
//		outData << best[i] + 1 << " -> ";
//	outData << START + 1 << " - Total: " << totalBest << endl;
//}
//void update()
//{
//	if (a[x[n - 1]][START] > 0 && totalBest > total + a[x[n - 1]][START])
//	{
//		totalBest = total + a[x[n - 1]][START];
//		for (int i = 0; i < n; i++)
//			best[i] = x[i];
//	}
//}
//void Travel(int i)
//{
//	if (total > totalBest) return;
//	for (int j = 0; j < n; j++)
//		if (!d[j] && a[x[i - 1]][j] > 0)
//		{
//			x[i] = j;
//			d[j] = true;
//			total += a[x[i - 1]][j];
//			if (i == n - 1)
//				update();
//			else
//				Travel(i + 1);
//			d[j] = false;
//			total -= a[x[i - 1]][j];
//		}
//}
//int main()
//{
//	initData();
//
//	Travel(1);
//	output();
//
//	delete[] best;
//	delete[] d;
//	delete[] x;
//	for (int i = 0; i < n; i++)
//		delete[] a[i];
//	delete[] a;
//	return 0;
//}