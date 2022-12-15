#include "..\resource\SingleLinkedList.h"
#include<iostream>
#include<cmath>
using namespace std;

bool checkEven(List list)
{
	Node* p = list.head;
	while (p != NULL)
	{
		if (p->data % 2 == 1) return false;
		p = p->nxt;
	}
	return true;
}
bool checkOdd(List list)
{
	Node* p = list.head;
	while (p != NULL)
	{
		if (p->data % 2 == 0) return false;
		p = p->nxt;
	}
	return true;
}
bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}
bool checkPrime(List list)
{
	Node* p = list.head;
	while (p != NULL)
	{
		if (!isPrime(p->data)) return false;
		p = p->nxt;
	}
	return true;
}
bool isSquare(int n)
{
	int sqr = sqrt(n);
	if (sqr * sqr == n) return true;
	return false;
}
bool checkSquare(List list)
{
	Node* p = list.head;
	while (p != NULL)
	{
		if (!isSquare(p->data)) return false;
		p = p->nxt;
	}
	return true;
}
int main()
{
	List newList;

	return 0;
}