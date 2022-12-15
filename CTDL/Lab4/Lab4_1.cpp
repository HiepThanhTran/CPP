#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;

int a[MAX], front = -1, rear = -1;

bool isEmpty();
bool isFull();
int Push(int data);
int Pop(int &data);
int main()
{
	int choice;
	do
	{
		system("cls");
		cout << "1- Them 1 phan tu vao Queue\n";
		cout << "2- Xoa 1 phan tu khoi Queue\n";
		cout << "3- Kiem tra Queue co day khong?\n";
		cout << "4- Kiem tra Queue co rong khong?\n";
		cout << "5- Thoat\n";
		cout << "- Chon chuc nang: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int data;
			cout << "Nhap gia tri can them vao: ";
			cin >> data;
			if (Push(data) == 1)
				cout << "Them gia tri thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		}
		case 2:
		{
			int data;
			if (Pop(data) == 1)
				cout << "Gia tri vua lay ra " << data << "\n";
			else
				cout << "Lay khong thanh cong\n";
			break;
		}
		case 3:
			if (isFull())
				cout << "Queue da day\n";
			else
				cout << "Queue chua day\n";
			break;
		case 4:
			if (isEmpty())
				cout << "Queue rong\n";
			else
				cout << "Queue khong rong\n";
			break;
		default:
			cout << "\n-- THOAT CHUONG TRINH --\n";
		}
		_getch();
	} while (choice >= 1 && choice <= 4);
	return 0;
}
bool isEmpty()
{
	if (front == -1)
		return true;
	return false;
}
bool isFull()
{
	if (rear - front == MAX - 1 || rear - front == -1)
		return true;
	return false;
}
/*Phuong phap tinh tien*/
// int Push(int data)
//{
//	if (!isFull())
//	{
//		if (rear == MAX - 1)
//		{
//			for (int i = front; i <= rear; i++)
//				a[i - front] = a[i];
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		if (front == -1) front = 0;
//		a[++rear] = data;
//		return 1;
//	}
//	return 0;
// }
// int Pop(int& data)
//{
//	if (!isEmpty())
//	{
//		data = a[front++];
//		if (front > rear) front = rear = -1;
//		return 1;
//	}
//	return 0;
// }
/*Phuong phap vong*/
int Push(int data)
{
	if (!isFull())
	{
		if (rear == MAX - 1)
			rear = -1;
		if (front == -1)
			front = 0;
		a[++rear] = data;
		return 1;
	}
	return 0;
}
int Pop(int &data)
{
	if (!isEmpty())
	{
		data = a[front++];
		if (front - rear == 1)
			front = rear = -1;
		if (front == MAX)
			front = 0;
		return 1;
	}
	return 0;
}