#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;

int a[MAX], sp = -1;

bool isEmpty();
bool isFull();
int Push(int data);
int Pop(int& dat);

int main()
{
	int choice = 0;
	do {
		system("cls");
		cout << "1- Them phan tu vao stack\n"
			<< "2- Lay 1 phan tu trong stack\n"
			<< "3- Kiem tra stack co rong khong?\n"
			<< "4- Kiem tra stack co day chua?\n"
			<< "5- Thoat\n"
			<< "- Chon chuc nang: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int data;
			cout << "Nhap gia tri can them vao stack: ";
			cin >> data;
			if (Push(data) == 1) cout << "Them vao Stack thanh cong\n";
			else cout << "Stack day. Them khong thanh cong!\n";
			break;
		}
		case 2:
		{
			int data;
			if (Pop(data) == 1) cout << "Gia tri vua lay ra " << data << "\n";
			else cout << "Stack rong. Lay khong thanh cong!\n";
			break;
		}
		case 3:
			if (isEmpty()) cout << "Stack rong\n";
			else cout << "Stack khong rong\n";
			break;
		case 4:
			if (isFull()) cout << "Stack da day\n";
			else cout << "Stack chua day\n";
			break;
		default:
			cout << "\n== THOAT CHUONG TRINH ==\n";
		}
		_getch();
	} while (choice >= 1 && choice <= 4);
	return 0;
}
bool isEmpty()
{
	if (sp == -1) return true;
	return false;
}
bool isFull()
{
	if (sp == MAX - 1) return true;
	return false;
}
int Push(int data)
{
	if (!isFull())
	{
		a[++sp] = data;
		return 1;
	}
	return 0;
}
int Pop(int& data)
{
	if (!isEmpty())
	{
		data = a[sp--];
		return 1;
	}
	return 0;
}