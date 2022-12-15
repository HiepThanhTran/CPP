#include<iostream>
#include<fstream>
using namespace std;

int n, k, num = 0, total = 0, weight = 0, numBest = 0, totalBest = INT_MIN, weightBest = 0;
int* w, * v, * x, * best;
bool* d;
void readData()
{
	ifstream inData("items.inp");
	inData >> n;
	w = new int[n];
	v = new int[n];
	for (int i = 0; i < n; i++)
		inData >> w[i] >> v[i];
	inData >> k;
}
void initData()
{
	readData();
	d = new bool[n] {false};
	x = new int[n];
	best = new int[n];
}
void output()
{
	ofstream outData("items.out");
	outData << totalBest << endl;
	for (int i = 0; i < numBest; i++)
		outData << best[i] + 1 << " ";
}
void update()
{
	if (total > totalBest)
	{
		totalBest = total;
		weightBest = weight;
		numBest = num;
		for (int i = 0; i < num; i++)
			best[i] = x[i];
	}
}
void getItems(int idx)
{
	if (weight + w[idx] > k) return;
	for (int i = 0; i < n; i++)
		if (!d[i])
		{
			x[idx] = i;
			d[i] = true;
			weight += w[i];
			total += v[i];
			num++;
			if (weight <= k)
				update();
			getItems(idx + 1);
			x[idx] = -1;
			d[i] = false;
			weight -= w[i];
			total -= v[i];
			num--;
		}
}
int main()
{
	initData();

	getItems(0);
	output();

	delete[] best;
	delete[] x;
	delete[] d;
	delete[] v;
	delete[] w;
	return 0;
}