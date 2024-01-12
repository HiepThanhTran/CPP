//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<char> res;
//long n;
//
//void inItData()
//{
//	cout << "Nhap n: ";
//	cin >> n;
//	res.assign(n, ' ');
//}
//int counter = 1;
//void output()
//{
//	cout << counter << ": ";
//	for (int i = 0; i < n; i++)
//		cout << res[i];
//	cout << endl;
//	counter++;
//}
//void Try(int idx)
//{
//	if (idx == n)
//		output();
//	else
//		for (int i = 0; i < 2; i++)
//		{
//			res[idx] = i + 'A';
//			if (!(i == 1 && idx > 0 && res[idx - 1] == 'B'))
//				Try(idx + 1);
//		}
//}
//int main()
//{
//	inItData();
//	Try(0);
//	return 0;
//}