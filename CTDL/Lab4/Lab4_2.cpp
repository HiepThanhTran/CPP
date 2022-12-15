#include "..\resource\SingleLinkedList.h"
#include <iostream>
using namespace std;

List q;

bool isEmpty()
{
	if (q.head == NULL)
		return true;
	return false;
}
void Push(int data)
{
	Node *p = new Node(data);
	if (q.tail == NULL)
		q.head = p;
	else
		q.tail->nxt = p;
	q.tail = p;
	// insertLast(q, data);
}
int Pop(int &data)
{
	if (!isEmpty())
	{
		Node *p = q.head;
		data = q.head->data;
		q.head = q.head->nxt;
		delete p;
		// deleteFirst(q);
		return 1;
	}
	return 0;
}
int main()
{
	int choice, data, x;
	do
	{
		cout << "1- Kiem tra queue rong?\n"
			  << "2- Them 1 phan tu vao queue\n"
			  << "3- Xoa 1 phan tu khoi queue\n"
			  << "4- Thoat\n"
			  << "- Chon chuc nang: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (isEmpty())
				cout << "Queue rong\n";
			else
				cout << "Queue khong rong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them vao queue: ";
			cin >> data;
			Push(data);
			break;
		case 3:
			if (Pop(x) == 1)
				cout << "Xoa phan tu ra khoi queue thanh cong\nPhan tu vua duoc lay ra: " << x << "\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		default:
			cout << "\n==KET THUC CHUONG TRINH==\n";
		}
	} while (choice >= 1 && choice <= 3);
	return 0;
}