#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;

int a[MAX], sp = -1;

bool isEmpty();
bool isFull();
int Push(int data);
int Pop(int& dat);

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
int main()
{
	int dec;
	cout << "Nhap so he thap phan: ";
	cin >> dec;
	decToBin(dec);
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