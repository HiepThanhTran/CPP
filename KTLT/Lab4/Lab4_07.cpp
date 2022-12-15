#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 256;

char* strSearch(char* p1, char* p2)
{
	int n1 = strlen(p1), n2 = strlen(p2);
	if (n2 > n1) return NULL;
	for (int i = 0; i <= n1 - n2; i++)
	{
		int pos = i;
		if (p2[0] == p1[i])
		{
			bool flag = true;
			for (int j = 0; j < n2; j++)
				if (p1[pos++] != p2[j])
				{
					flag = false;
					break;
				}
			if (flag) return &p1[i];
		}
	}
	return NULL;
}
void deleteStr(char* p1, char* p2, char* pos)
{
	char* tmp = pos;
	int lenp2 = strlen(p2);
	for (int i = 0; i < lenp2; i++)
	{
		int  n = strlen(p1);
		for (int j = pos - p1; j < n - 1; j++)
			p1[j] = p1[j + 1];
		p1[n - 1] = '\0';
		tmp++;
	}
}
char* replace(char* p1, char* p2, char* p3, char* pos)
{
	deleteStr(p1, p2, pos);
	if (strlen(p1) - strlen(p2) + strlen(p3) >= MAX) return NULL;
	int k = pos - p1;
	while (*p3)
	{
		int n = strlen(p1);
		for (int i = n; i > k; i--)
			p1[i] = p1[i - 1];
		p1[n + 1] = '\0';
		p1[k++] = *p3;
		p3++;
	}
	return p1;
}
int main()
{
	char s1[MAX], s2[MAX], s3[MAX];
	cout << "Nhap vao chuoi S1: ";
	cin.get(s1, MAX);
	cin.ignore(1);
	cout << "Nhap vao chuoi S2: ";
	cin.get(s2, MAX);
	cin.ignore(1);
	char* p1 = s1;
	char* p2 = s2;
	char* pos = strSearch(p1, p2);
	if (pos)
	{
		cout << "Dia chi xuat hien dau tien cua S2 trong S1: " << int(&pos) << endl;
		cout << "Tai vi tri dau tien trong S1: " << pos - p1 << endl;
		cout << "Nhap vao chuoi S3: ";
		cin.get(s3, MAX);
		char* p3 = s3;
		char* newStr = replace(p1, p2, p3, pos);
		if (newStr)
			cout << "Chuoi sau khi thay S2 bang S3 trong S1: " << newStr << endl;
		else
			cout << "Khong the thay S2 bang S3 trong S1\n";
	}
	else
		cout << "S2 khong xuat hien trong S1\n";
	return 0;
}