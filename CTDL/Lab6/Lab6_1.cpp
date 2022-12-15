#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX = 100;

void nhapDS(int arr[], int &size)
{
	do
	{
		cout << "Nhap so luong phan tu: ";
		cin >> size;
	} while (size < 1 || size > MAX);
	// cout << "Nhap " << size << " phan tu: ";
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (100 - 50 + 1) + 50;
}
void xuatDS(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
void quickSortMedian_Descending(int arr[], int left, int right)
{
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;
	while (i <= j)
	{
		while (arr[i] > pivot)
			i++;
		while (arr[j] < pivot)
			j--;
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	if (left < j)
		quickSortMedian_Descending(arr, left, j);
	if (i < right)
		quickSortMedian_Descending(arr, i, right);
}
void quickSortFirst_Ascending(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i = left + 1, j = right;
	while (i <= j)
	{
		while (i <= j && arr[i] < pivot)
			i++;
		while (j >= i && arr[j] > pivot)
			j--;
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[left], arr[j]);
	if (left < j)
		quickSortFirst_Ascending(arr, left, j);
	if (i < right)
		quickSortFirst_Ascending(arr, i, right);
}
void quickSortLast_Ascending(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = left, j = right - 1;
	while (i <= j)
	{
		while (i <= j && arr[i] < pivot)
			i++;
		while (j >= i && arr[j] > pivot)
			j--;
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[i], arr[right]);
	if (left < j)
		quickSortLast_Ascending(arr, left, j);
	if (i < right)
		quickSortLast_Ascending(arr, i, right);
}
void heapify(int arr[], int size, int i)
{
	int m = i;			 // Node root
	int l = 2 * i + 1; // Node ben trai
	int r = 2 * i + 2; // Node ben phai

	// Tim vi tri co gia tri lon nhat trong: arr[i], arr[l], arr[r]
	if (l < size && arr[l] > arr[m])
		m = l;
	if (r < size && arr[r] > arr[m])
		m = r;

	// Dieu kien dung de quy
	if (m != i)
	{
		swap(arr[i], arr[m]);
		heapify(arr, size, m); // Xet lai su lan truyen
	}
}
void heapSort(int arr[], int size)
{
	// Tao heap ban dau
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	// Bat dau sap xep
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
	srand(time(NULL));
	bool input = false;
	int A[MAX], n;
	int choice;
	do
	{
		system("cls");
		cout << "1- Nhap danh sach\n";
		cout << "2- Xuat danh sach\n";
		cout << "3- Sap xep giam dan (QuickSort With Pivot Median)\n";
		cout << "4- Sap xep tang dan (QuickSort With Pivot First/Last)\n";
		cout << "5- Sap xep tang dan (HeapSort)\n";
		cout << "6- Ket thuc\n";
		cout << "- Chon chuc nang: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			nhapDS(A, n);
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Danh sach dang luu tru: ";
				xuatDS(A, n);
			}
			else
				cout << "\n-- Nhap danh sach truoc khi thao tac --\n";
			break;
		case 3:
			if (input)
			{
				cout << "Danh sach dang luu tru: ";
				quickSortMedian_Descending(A, 0, n - 1);
				xuatDS(A, n);
			}
			else
				cout << "\n-- Nhap danh sach truoc khi thao tac --\n";
			break;
		case 4:
		{
			if (input)
			{
				int option4;
				do
				{
					cout << "1- QuickSort With Pivot First\n";
					cout << "2- QuickSort With Pivot Last\n";
					cout << "3- Quay lai\n";
					cout << "- Chon chuc nang: ";
					cin >> option4;
					switch (option4)
					{
					case 1:
						cout << "Danh sach dang luu tru: ";
						quickSortFirst_Ascending(A, 0, n - 1);
						xuatDS(A, n);
						break;
					case 2:
						cout << "Danh sach dang luu tru: ";
						quickSortLast_Ascending(A, 0, n - 1);
						xuatDS(A, n);
						break;
					}
				} while (option4 >= 1 && option4 <= 2);
			}
			else
				cout << "\n-- Nhap danh sach truoc khi thao tac --\n";
			break;
		}
		case 5:
			if (input)
			{
				cout << "Danh sach dang luu tru: ";
				heapSort(A, n);
				xuatDS(A, n);
			}
			else
				cout << "\n-- Nhap danh sach truoc khi thao tac --\n";
			break;
		default:
			cout << "\n==KET THUC CHUONG TRINH==\n";
		}
		_getch();
	} while (choice >= 1 && choice <= 5);
	return 0;
}