//#include<iostream>
//using namespace std;
//
//void show(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << "\t";
//	cout << "\n";
//}
//void permutation(int *a, int *d, int n, int i)
//{
//	for (int k = 1; k <= n; k++)
//		if (d[k] == 0)
//		{
//			a[i] = k;
//			d[k] = 1;
//			if (i < n - 1)
//				permutation(a, d, n, i + 1);
//			else
//				show(a, n);
//			d[k] = 0;
//		}
//}
//int main()
//{
//	int* a, * d, n;
//	cout << "Nhap n: ";
//	cin >> n;
//	a = new int[n];
//	d = new int[n + 1]{0};
//	permutation(a, d, n, 0);
// 
//	delete[] a;
//	delete[] d;
//	return 0;
//}