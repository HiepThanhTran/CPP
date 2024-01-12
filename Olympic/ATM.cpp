#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int *t, *tmax, *x, *best, n, s, num = 0, numBest = INT32_MAX, total = 0;
bool *d;
void readData()
{
	ifstream inData("atm.inp");
	inData >> n >> s;
	t = new int[n];
	for (int i = 0; i < n; i++)
		inData >> t[i];
}
void initData()
{
	readData();
	x = new int[n];
	best = new int[n];
	d = new bool[n];
	tmax = new int[n];
	for (int i = 0; i < n; i++)
		d[i] = false;
	tmax[n - 1] = t[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		tmax[i] = tmax[i + 1];
		if (t[i] > tmax[i])
			tmax[i] = t[i];
	}
}
void output()
{
	for (int i = 0; i < numBest; i++)
		cout << best[i] << " ";
	cout << endl;
}
void update()
{
	if (numBest > num)
	{
		numBest = num;
		for (int i = 0; i < num; i++)
			best[i] = x[i];
	}
}
void getMoney(int idx)
{
	if (num + (s - total) / tmax[idx] > numBest)
		return;
	for (int i = 0; i < n; i++)
		if (!d[i])
		{
			d[i] = true;
			x[idx] = t[i];
			total += x[idx];
			num++;
			if (total == s)
				update();
			else
				getMoney(idx + 1);
			d[i] = false;
			total -= x[idx];
			num--;
		}
}
int main()
{
	initData();

	getMoney(0);
	output();

	delete[] tmax;
	delete[] d;
	delete[] best;
	delete[] x;
	delete[] t;
	getch();
	return 0;
}
