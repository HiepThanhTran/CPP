//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<vector<long>> a;
//vector<long> b;
//long k, n, xi, yi, flo, brick = 0;
//
//void inData()
//{
//	cout << "Nhap k: ";
//	cin >> k;
//	cout << "Nhap toa do vien gach bi khuyet (x, y): ";
//	cin >> xi >> yi;
//	n = 1 << k;
//	b.assign(n, 0);
//	a.assign(n, b);
//}
//int getPos(int startX, int startY, int size, int xi, int yi)
//{
//	int p = size / 2;
//	if (xi < startX + p)
//	{
//		if (yi < startY + p)
//			return 1;
//		else
//			return 2;
//	}
//	else
//	{
//		if (yi < startY + p)
//			return 4;
//		else
//			return 3;
//	}
//}
//void lay3Brick(int x1, int x2, int x3, int y1, int y2, int y3)
//{
//	a[x1][y1] = brick;
//	a[x2][y2] = brick;
//	a[x3][y3] = brick;
//}
//void layingBrickV2(long startX, long startY, long xi, long yi, long size)
//{
//	flo = getPos(startX, startY, size, xi, yi);
//	brick++;
//	if (size == 2)
//	{
//		if (flo != 1)
//			a[startX][startY] = brick;
//		if (flo != 2)
//			a[startX][startY + 1] = brick;
//		if (flo != 3)
//			a[startX + 1][startY + 1] = brick;
//		if (flo != 4)
//			a[startX + 1][startY] = brick;
//	}
//	else
//	{
//		long p = size / 2;
//		switch (flo)
//		{
//		case 1:
//			lay3Brick(startX + p - 1, startX + p, startX + p, startY + p, startY + p, startY + p - 1);
//			layingBrickV2(startX, startY, xi, yi, p);
//			layingBrickV2(startX, startY + p, startX + p - 1, startY + p, p);
//			layingBrickV2(startX + p, startY + p, startX + p, startY + p, p);
//			layingBrickV2(startX + p, startY, startX + p, startY + p - 1, p);
//			break;
//		case 2:
//			lay3Brick(startX + p - 1, startX + p, startX + p, startY + p - 1, startY + p, startY + p - 1);
//			layingBrickV2(startX, startY, startX + p - 1, startY + p - 1, p);
//			layingBrickV2(startX, startY + p, xi, yi, p);
//			layingBrickV2(startX + p, startY + p, startX + p, startY + p, p);
//			layingBrickV2(startX + p, startY, startX + p, startY + p - 1, p);
//			break;
//		case 3:
//			lay3Brick(startX + p - 1, startX + p - 1, startX + p, startY + p - 1, startY + p, startY + p - 1);
//			layingBrickV2(startX, startY, startX + p - 1, startY + p - 1, p);
//			layingBrickV2(startX, startY + p, startX + p - 1, startY + p, p);
//			layingBrickV2(startX + p, startY + p, xi, yi, p);
//			layingBrickV2(startX + p, startY, startX + p, startY + p - 1, p);
//			break;
//		case 4:
//			lay3Brick(startX + p - 1, startX + p - 1, startX + p, startY + p - 1, startY + p, startY + p);
//			layingBrickV2(startX, startY, startX + p - 1, startY + p - 1, p);
//			layingBrickV2(startX, startY + p, startX + p - 1, startY + p, p);
//			layingBrickV2(startX + p, startY + p, startX + p, startY + p, p);
//			layingBrickV2(startX + p, startY, xi, yi, p);
//			break;
//		}
//	}
//}
//void show()
//{
//	for (auto i : a)
//	{
//		for (auto j : i)
//			cout << j << "\t";
//		cout << "\n\n";
//	}
//}
//int main()
//{
//	inData();
//	layingBrickV2(0, 0, xi, yi, n);
//	show();
//	return 0;
//}