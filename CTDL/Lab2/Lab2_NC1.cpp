#include "..\resource\SingleLinkedList.h"
#include <iostream>
using namespace std;

bool insertAfterMax(List &list, int x)
{
	if (list.head != NULL)
	{
		int max = list.head->data, cnt = 0, pos = 0;
		Node *p = list.head->nxt;
		while (p != NULL)
		{
			cnt++;
			if (p->data > max)
			{
				max = p->data;
				pos = cnt;
			}
			p = p->nxt;
		}
		insertAfter(list, pos, x);
		return true;
	}
	return false;
}
int main()
{
	List newList;
	int x;
	insertLast(newList, 9);
	insertLast(newList, 4);
	insertLast(newList, 7);
	// insertLast(newList, 30);
	insertLast(newList, 1);
	insertLast(newList, 15);
	output(newList);
	cout << "Nhap gia tri x: ";
	cin >> x;
	insertAfterMax(newList, x);
	output(newList);
	return 0;
}