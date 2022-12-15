#include<iostream>
#include<math.h>

using namespace std;
const int MAXSIZE = 100;

void input(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri phan tu arr[" << i << "] = ";
		cin >> arr[i];
	}
}
void output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
}
void tangDan(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}
void giamDan(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}
int main()
{
	int arr[MAXSIZE];
	int n;
	cout << "Nhap so phan tu hien co: ";
	cin >> n;
	cout << "------------------------------\n";
	input(arr, n);
	cout << "\nCac phan tu trong mang: ";
	output(arr, n);
	cout << "\n------------------------------\n";
	tangDan(arr, n);
	cout << "Mang sau khi sap xep tang dan: ";
	output(arr, n);
	giamDan(arr, n);
	cout << "\nMang sau khi sap xep giam dan: ";
	output(arr, n);
	cout << "\n";
	system("pause");
	return 0;
}