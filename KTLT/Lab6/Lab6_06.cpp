#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    char kt;
    inFile.open("BT4.txt");
    outFile.open("BT6.txt", ios::app);
    if (inFile.is_open())
    {
        while (inFile >> kt)
        {
            if (kt == 'u' || kt == 'e' || kt == 'o' || kt == 'a' || kt == 'i' ||
                kt == 'U' || kt == 'E' || kt == 'O' || kt == 'A' || kt == 'I')
            {
                outFile << kt << endl;
            }
        }
        cout << "Doc/ghi file thanh cong!\n";
        inFile.close();
        outFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    system("pause");
    return 0;
}