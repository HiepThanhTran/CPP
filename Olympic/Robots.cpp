//#include<iostream>
//#include<fstream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int SIZE = 9;
//const char TARGET[] = "TTTTTTTTT";
//
//// x luu so lan robot duoc goi
//int x[SIZE]{ 0 }, best[SIZE]{ 0 }, total = 0, totalBest = INT_MIN;
//char robots[SIZE][SIZE], rooms[SIZE];
//// XVXVXVTXT
//// XVXVXXXTT
//
//void readData()
//{
//	ifstream inData("robots.inp");
//	for (int i = 0; i < SIZE; i++)
//		inData >> robots[i];
//	inData >> rooms;
//	inData.close();
//	/*
//	robots[0] = 159
//	robots[1] = 123
//	robots[2] = 357
//	robots[3] = 147
//	robots[4] = 5
//	robots[5] = 369
//	robots[6] = 456
//	robots[7] = 789
//	robots[8] = 258
//	*/
//}
//void fillRooms(char room[], char robot[])
//{
//	for (int i = 0; i < strlen(robot); i++)
//	{
//		int r = int(robot[i] - 48) - 1;
//		switch (room[r])
//		{
//		case 'T':
//			room[r] = 'X';
//			break;
//		case 'X':
//			room[r] = 'V';
//			break;
//		case 'V':
//			room[r] = 'T';
//			break;
//		}
//	}
//}
//void update()
//{
//	if (total > totalBest)
//	{
//		totalBest = total;
//		copy(begin(x), end(x), begin(best));
//	}
//}
//int countWhite(char tmp[])
//{
//	int count = 0;
//	for (int i = 0; i < SIZE + 1; i++)
//		if (tmp[i] == 'T') count++;
//	return count;
//}
//int chooseRobot()
//{
//	int max = INT_MIN, imax = -1;
//	char tmp[SIZE + 1];
//	for (int i = 0; i < SIZE; i++)
//	{
//		strcpy_s(tmp, rooms);
//		if (x[i] < 2)
//		{
//			fillRooms(tmp, robots[i]);
//			int c = countWhite(tmp);
//			if (c > max)
//			{
//				max = c;
//				imax = i;
//			}
//		}
//	}
//	return imax;
//}
//void fill(int idx)
//{
//	int i = chooseRobot();
//	fillRooms(rooms, robots[i]);
//	x[i]++;
//	total++;
//	if (strcmp(rooms, TARGET) == 0)
//		update();
//	else
//		fill(idx + 1);
//	total--;
//	x[i]--;
//}
//void output()
//{
//	ofstream outData("robots.out");
//	for (int i = 0; i < SIZE; i++)
//		for (int j = 0; j < best[i]; j++)
//			outData << i + 1;
//	outData.close();
//}
//int main()
//{
//	readData();
//	fill(0);
//	output();
//	return 0;
//}