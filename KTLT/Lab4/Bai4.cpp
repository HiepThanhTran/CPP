#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char s1[51];
    char s2[] = " ";
    cout << "Nhap ho va ten: ";
    cin.get(s1, 51);
    char *tmp = strtok(s1, s2);
    while(tmp != NULL) {
        cout << tmp << endl;
        tmp = strtok(NULL, s2);
    }
    return 0;
}