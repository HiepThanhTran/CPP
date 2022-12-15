#include "SingleLinkedList.h"
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