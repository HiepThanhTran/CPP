#include <iostream>
#include <conio.h>
using namespace std;
const int XY[8][8] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
const int SIZE = 8;

void show(int a[][SIZE])
{
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
         cout << a[i][j] << "\t";
      cout << "\n\n";
   }
   cout << "Tiep tuc? (y/n): ";
   if (_getch() == 'y')
   {
      cout << "\n";
      cin.ignore(1);
   }
   else
      exit(0);
}
void knightTour(int a[][SIZE], int x, int y, int i)
{
   if (i > SIZE * SIZE)
      show(a);
   else
   {
      for (int j = 0; j < 8; j++)
      {
         int r = x + XY[j][0];
         int c = y + XY[j][1];
         if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && a[r][c] == 0)
         {
            a[r][c] = i;
            knightTour(a, r, c, i + 1);
            a[r][c] = 0;
         }
      }
   }
}
int main()
{
   int a[SIZE][SIZE] = {0};
   a[0][0] = 1;
   knightTour(a, 0, 0, 2);
   return 0;
}