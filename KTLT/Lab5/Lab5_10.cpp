#include<iostream>
#include"GPG.h"
using namespace std;

void nhapGPG(GPG &time)
{
	int hours = 0, mins = 0, secs = 0;
	do {
		cout << "Nhap Gio: ";
		cin >> hours;
		cout << "Nhap Phut: ";
		cin >> mins;
		cout << "Nhap Giay: ";
		cin >> secs;
		if (hours < 0 || hours > 24 || mins < 0 || mins > 60 || secs < 0 || secs > 60)
			cout << "\nThoi gian khong hop le!\n";
	} while (hours < 0 || hours > 24 || mins < 0 || mins > 60 || secs < 0 || secs > 60);
	time.setTime(hours, mins, secs);
}
int main()
{
	GPG time1, time2;
	int sec1 = 0, sec2 = 0, kc = 0;
	nhapGPG(time1);
	cout << "\n";
	nhapGPG(time2);
	cout << "\nTime 1: " << time1.getH() << " gio " << time1.getM() << " phut " << time1.getS() << " giay\n";
	cout << "Time 2: " << time2.getH() << " gio " << time2.getM() << " phut " << time2.getS() << " giay\n";
	cout << "\nCach nhau 1 khoang thoi gian la: ";
	GPG result = result.KC(time1, time2);
	cout << result.getH() << " gio " << result.getM() << " phut " << result.getS() << " giay\n";
	return 0;
}