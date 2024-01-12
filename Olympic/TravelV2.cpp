// #include<iostream>
// #include<fstream>
// #include<vector>
// using namespace std;

// long k, n, r, routeCal = 0, costCal = 0, routeBest = INT_MAX;
// long** length, ** cost;

// void readData()
// {
// 	ifstream inData("roads.inp");
// 	inData >> k >> n >> r;
// 	length = new long* [n];
// 	cost = new long* [n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		length[i] = new long[n] {0};
// 		cost[i] = new long[n] {0};
// 	}
// 	long s, e, l, t;
// 	for (int i = 0; i < r; i++)
// 	{
// 		inData >> s >> e >> l >> t;
// 		length[s - 1][e - 1] = l;
// 		cost[s - 1][e - 1] = t;
// 	}
// }
// void output()
// {
// 	ofstream outData("roads.out");
// 	if (routeBest != INT_MAX)
// 		outData << routeBest << endl;
// 	else
// 		outData << -1 << endl;
// }
// void update()
// {
// 	if (costCal <= k && routeCal < routeBest)
// 		routeBest = routeCal;
// }
// void Try(int idx)
// {
// 	if (routeCal > routeBest || costCal > k) return;
// 	if (idx == n - 1)
// 		update();
// 	else
// 	{
// 		for (int i = 1; i < n; i++)
// 			if (length[idx][i] > 0)
// 			{
// 				routeCal += length[idx][i];
// 				costCal += cost[idx][i];
// 				Try(i);
// 				routeCal -= length[idx][i];
// 				costCal -= cost[idx][i];
// 			}
// 	}
// }
// int main()
// {
// 	readData();

// 	Try(0);
// 	output();

// 	for (int i = 0; i < n; i++)
// 	{
// 		delete[] cost[i];
// 		delete[] length[i];
// 	}
// 	delete[] cost;
// 	delete[] length;
// 	return 0;
// }