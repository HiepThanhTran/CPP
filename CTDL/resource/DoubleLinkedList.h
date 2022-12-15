#include <iostream>
using namespace std;
// Cau truc 1 Node
struct Node
{
	int data;
	Node *nxt, *prv;
	// Khoi tao gia tri cho Node
	Node(int _data)
	{
		data = _data;
		nxt = NULL;
		prv = NULL;
	}
};
// Cau truc 1 danh sach
struct List
{
	Node *head = NULL;
	Node *tail = NULL;
};
// Kiem tra danh sach rong
bool isEmpty(List list)
{
	if (list.head == NULL)
		return true;
	return false;
}
// Lay so luong Node hien co
int getSize(List list)
{
	int sz = 0;
	while (list.head != NULL)
	{
		sz++;
		list.head = list.head->nxt;
	}
	return sz;
}
// Tim kiem Node co gia tri xac dinh
Node *searchDataNode(List list, int target)
{
	Node *p = list.head;
	while (p != NULL && p->data != target)
		p = p->nxt;
	return p;
}
// Tim kiem Node tai vi tri xac dinh
Node *searchNode(List list, int pos)
{
	Node *p = list.head;
	for (int i = 1; i < pos; i++)
		p = p->nxt;
	return p;
}
// Them Node vao dau danh sach
void insertFirst(List &list, int data)
{
	Node *p = new Node(data);
	if (list.head == NULL)
	{
		list.head = list.tail = p;
		return;
	}
	p->nxt = list.head;
	list.head->prv = p;
	list.head = p;
}
// Them Node vao cuoi danh sach
void insertLast(List &list, int data)
{
	Node *p = new Node(data);
	if (list.head == NULL)
	{
		list.head = list.tail = p;
		return;
	}
	list.tail->nxt = p;
	p->prv = list.tail;
	list.tail = p;
}
// Them Node sau 1 Node xac dinh
void insertAfter(List &list, int pos, int data)
{
	Node *node = searchNode(list, pos);
	if (node == list.tail)
	{
		insertLast(list, data);
		return;
	}
	Node *p = new Node(data);
	p->nxt = node->nxt;
	p->prv = node;
	node->nxt->prv = p;
	node->nxt = p;
}
// Them Node truoc 1 Node xac dinh
void insertBefore(List &list, int pos, int data)
{
	Node *node = searchNode(list, pos);
	if (node == list.head)
	{
		insertFirst(list, data);
		return;
	}
	Node *p = new Node(data);
	p->nxt = node;
	p->prv = node->prv;
	node->prv->nxt = p;
	node->prv = p;
}
// Xoa Node dau danh sach
bool deleteFirst(List &list)
{
	if (list.head != NULL)
	{
		Node *p = list.head;
		list.head = list.head->nxt;
		if (list.head == NULL)
			list.tail = NULL;
		delete p;
		return true;
	}
	return false;
}
// Xoa Node cuoi danh sach
bool deleteLast(List &list)
{
	if (list.head != NULL)
	{
		Node *p = list.tail;
		list.tail = list.tail->prv;
		if (list.tail == NULL)
			list.head = NULL;
		else
			list.tail->nxt = NULL;
		delete p;
		return true;
	}
	return false;
}
// Xoa Node sau 1 Node xac dinh
bool deleteAfter(List &list, int pos)
{
	Node *p = searchNode(list, pos);
	if (list.head != NULL && p->nxt != NULL)
	{
		Node *node = p->nxt;
		if (node == list.tail)
			deleteLast(list);
		else
		{
			p->nxt = node->nxt;
			node->nxt->prv = p;
		}
		delete node;
		return true;
	}
	return false;
}
// Xoa Node truoc 1 Node xac dinh
bool deleteBefore(List &list, int pos)
{
	Node *p = searchNode(list, pos);
	if (list.head != NULL && p->prv != NULL)
	{
		Node *node = p->prv;
		if (node == list.head)
			deleteFirst(list);
		else
		{
			p->prv = node->prv;
			node->prv->nxt = p;
		}
		delete node;
		return true;
	}
	return false;
}
// Xoa 1 Node xac dinh
bool deleteNode(List &list, int pos)
{
	if (list.head != NULL)
	{
		Node *node = searchNode(list, pos);
		if (node == list.head)
			deleteFirst(list);
		else if (node == list.tail)
			deleteLast(list);
		else
		{
			node->prv->nxt = node->nxt;
			node->nxt->prv = node->prv;
			delete node;
		}
		return true;
	}
	return false;
}
// Xoa ca danh sach
bool deleteList(List &list)
{
	if (list.head != NULL)
	{
		Node *p = list.head;
		while (list.head != NULL)
		{
			p = p->nxt;
			delete list.head;
			list.head = p;
		}
		return true;
	}
	return false;
}
// Hien thi danh sach ra man hinh
void output(List list)
{
	cout << "Danh sach dang luu tru: ";
	while (list.head != NULL)
	{
		cout << list.head->data << " ";
		list.head = list.head->nxt;
	}
	cout << "\n";
}