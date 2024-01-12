#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

Node *sp = NULL;

bool isEmpty()
{
	if (sp == NULL)
		return true;
	return false;
}
void Push(int data)
{
	Node *p = new Node(data);
	p->nxt = sp;
	sp = p;
}
int Pop(int &data)
{
	if (!isEmpty())
	{
		Node *p = sp;
		data = p->data;
		sp = sp->nxt;
		delete p;
		return 1;
	}
	return 0;
}