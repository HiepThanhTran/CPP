#include "..\resource\SingleLinkedList.h"
#include <iostream>
using namespace std;

void insert(int *arr, int &sz, int x)
{
	int i = sz;
	while (i >= 0 && arr[i - 1] > x)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[i] = x;
	sz++;
}
int search(int *arr, int sz, int target)
{
	int i = 0;
	while (i < sz && arr[i] != target)
		i++;
	if (i == sz)
		return -1;
	return i;
}
int searchAndDelete(int *arr, int &sz, int target)
{
	int j = search(arr, sz, target);
	if (j == -1)
		return 0;
	for (int i = j; i < sz - 1; i++)
		arr[i] = arr[i + 1];
	sz--;
	return 1;
}
void output(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int changes(List list, int *&arr)
{
	int sz = getSize(list), i = 0;
	arr = new int[sz];
	Node *p = list.head;
	while (p != NULL)
	{
		arr[i++] = p->data;
		p = p->nxt;
	}
	return sz;
}
int main()
{
	List newList;
	int *arr = NULL, sz, x;
	insertLast(newList, 2);
	insertLast(newList, 6);
	insertLast(newList, 9);
	insertLast(newList, 10);
	insertLast(newList, 13);
	insertLast(newList, 15);
	insertLast(newList, 17);
	insertLast(newList, 19);
	insertLast(newList, 32);
	insertLast(newList, 45);
	output(newList);
	sz = changes(newList, arr);
	cout << "Nhap gia tri can chen: ";
	cin >> x;
	insert(arr, sz, x);
	output(arr, sz);

	cout << "Nhap gia tri can tim: ";
	cin >> x;
	int kq1 = search(arr, sz, x);
	if (kq1 == -1)
		cout << "Khong tim thay phan tu trong danh sach\n";
	else
		cout << "Tim thay phan tu o vi tri " << kq1 + 1 << "\n";

	cout << "Nhap gia tri can tim va xoa: ";
	cin >> x;
	int kq2 = searchAndDelete(arr, sz, x);
	if (kq2 == 0)
		cout << "Phan tu khong co trong danh sach\n";
	else
	{
		cout << "Tim thay va xoa thanh cong\n";
		output(arr, sz);
	}
	return 0;
}