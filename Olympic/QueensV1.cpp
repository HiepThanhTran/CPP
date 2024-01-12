//#include<iostream>
//#include<conio.h>
//using namespace std;
//const int SIZE = 8;
//
//void show(int queens[])
//{
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//			if (queens[i] == j)
//				cout << "Q\t";
//			else
//				cout << "-\t";
//		cout << "\n\n";
//	}
//	cout << "Tiep tuc? (y): ";
//	if (_getch() == 'y' || _getch() == 'Y')
//	{
//		cout << "\n";
//		cin.ignore(1);
//	}
//	else
//		exit(1);
//}
//bool canPutQueen(int queens[], int r, int c)
//{
//	for (int i = 0; i < r; i++)
//		if (queens[i] == c || abs(i - r) == abs(queens[i] - c))
//			return false;
//	return true;
//}
//void putQueen(int queens[], int i)
//{
//	for (int j = 0; j < SIZE; j++)
//		if (canPutQueen(queens, i, j))
//		{
//			queens[i] = j;
//			if (i < SIZE - 1)
//				putQueen(queens, i + 1);
//			else
//				show(queens);
//		}
//}
//int main()
//{
//	int queens[SIZE];
//	putQueen(queens, 0);
//	return 0;
//}