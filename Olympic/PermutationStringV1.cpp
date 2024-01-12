//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//vector<char> res;
//vector<int> cnt;
//string str;
//long n;
//
//void inItData()
//{
//	cout << "Nhap chuoi: ";
//	cin >> str;
//	n = str.size();
//	res.assign(n, ' ');
//	cnt.assign(26, 0);
//	for (int i = 0; i < n; i++)
//		cnt[str[i] - 'A'] = 1;
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
//	for(int i = 0; i < 26; i++)
//		if (cnt[i] == 1)
//		{
//			res[idx] = i + 'A';
//			cnt[i] = 0;
//			if (idx == n - 1)
//				output();
//			else
//				Try(idx + 1);
//			cnt[i] = 1;
//		}
//}
//int main()
//{
//	inItData();
//	Try(0);
//	return 0;
//}