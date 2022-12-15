#include "..\resource\SingleLinkedList.h"
#include<iostream>
using namespace std;
//Viết thủ tục cho biết các phần tử chẳn, lẻ có xuất hiện xen kẻ trong danh sách liên kết đơn hay không
bool check(List list)
{
	Node* p = list.head;
	while (p->nxt != NULL)
	{
		if ((p->data % 2 == 0 && p->nxt->data % 2 == 0) || (p->data % 2 != 0 && p->nxt->data % 2 != 0)) return false;
		p = p->nxt;
	}
	return true;
}
int main()
{
	List newList;
	insertLast(newList, 1);
	insertLast(newList, 2);
	insertLast(newList, 3);
	insertLast(newList, 4);
	insertLast(newList, 5);
	insertLast(newList, 6);
	insertLast(newList, 7);
	insertLast(newList, 8);
	insertLast(newList, 9);
	insertLast(newList, 10);
	output(newList);

	if (check(newList))
		cout << "Thoa yeu cau\n";
	else
		cout << "Khong thoa\n";
	return 0;
}