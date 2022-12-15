#include"../resource/MyStack.h"
#include<iostream>
#include<conio.h>
using namespace std;

void decToBin(int dec);
int main()
{
	int choice = 0;
	do {
		system("cls");
		cout << "1- Them phan tu vao stack\n"
			<< "2- Lay 1 phan tu trong stack\n"
			<< "3- Kiem tra stack co rong khong?\n"
			<< "4- Chuyen he thap phan sang nhi phan?\n"
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
			Push(data);
			cout << "Them vao Stack thanh cong\n";
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
		{
			int dec;
			cout << "Nhap so he thap phan: ";
			cin >> dec;
			decToBin(dec);
			break;
		}
		default:
			cout << "\n== THOAT CHUONG TRINH ==\n";
		}
		_getch();
	} while (choice >= 1 && choice <= 4);
	return 0;
}
void decToBin(int dec)
{
	while (dec != 0)
	{
		int tmp = dec % 2;
		dec /= 2;
		Push(tmp);
	}
	cout << "So he nhi phan: ";
	while (!isEmpty())
	{
		int data;
		Pop(data);
		cout << data;
	}
	cout << "\n";
}