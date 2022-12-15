//Viết chương trình có giao diện là một menu lựa chọn 1 trong 4 phép tính (+ - * / ) và lựa chọn thoát.
//Khi người dùng chọn lựa chọn nào sẽ xử lý tương ứng. 

#include<iostream>

using namespace std;

int main()
{
	double a, b;
	char c;
	cout << "Hay lua chon phep tinh hoac lua chon thoat\n";
	cout << "(+) _ (-) _ Exit _ (*) _ (/) : ";
	cin >> c;
	if(c=='+' || c=='-' || c=='*' || c=='/') {
		while(c=='+' || c=='-' || c=='*' || c=='/') {
			cout << "Nhap a = ";
			cin >> a;
			cout << "Nhap b = ";
			cin >> b;
			switch(c) {
			case '+':
				cout << a << " + " << b << " = " << a+b;
				break;
			case '-':
				cout << a << " - " << b << " = " << a-b;
				break;
			case '*':
				cout << a << " * " << b << " = " << a*b;
				break;
			case '/':
				if(b==0) {
					cout << "Loi chia 0";
				}else{
					cout << a << " / " << b << " = " << a/b;
				}
				break;
			}
			cout << endl;
			cout << "Hay lua chon phep tinh hoac lua chon thoat\n";
			cout << "(+) _ (-) _ Exit _ (*) _ (/) : ";
			cin >> c;
		}
		cout << "Ket thuc chuong trinh\n";
		return 0;
	}else{
		cout << "Ket thuc chuong trinh\n";
		return 0;
	}
	return 0;
}