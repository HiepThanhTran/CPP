#include <iostream>
#include <cstring>
using namespace std;

void tachHo(char*& ho)
{
	while (*ho != ' ')
	{
		cout << *ho;
		ho++;
	}
	ho++;
}
char* tachTen(char* ten)
{
	while (*ten != ' ')
		ten--;
	ten++;
	return ten;
}
void chuLot(char* p, char* ho, char* ten)
{
	for (int i = ho - p; i < ten - p; i++)
		cout << p[i];
}
int main()
{
	char ht[256];
	cout << "Nhap ho va ten: ";
	cin.getline(ht, 256);
	char* p = ht;
	char* ho = p;
	cout << "Ho: ";
	tachHo(ho);
	char* ten = tachTen(p + strlen(p) - 1);
	cout << "\nTen: " << ten;
	cout << "\nChu lot: ";
	chuLot(p, ho, ten);
	return 0;
}