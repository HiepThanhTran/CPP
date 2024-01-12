/*
Cho một danh sách như sau: (Tất cả sử dụng hàm)
a. Tạo một struct SanPham gồm tên sp, mã sp kiểu char tối đa 20 kí tự, đơn giá, số lượng và số lượng tồn kho kiểu int. Sau đó cấp phát động một mảng kiểu SanPham với tối đa là 50 sản phẩm.
b. Nhập thông tin cho 5 sản phẩm, chuẩn hóa tên sản phẩm rồi ghi xuống tệp Test.txt
c. Chép sang tệp mới những sản phẩm có số lượng tồn kho ít hơn 100.
d. Đệ quy tìm đơn giá có giá trị lớn nhất rồi in ra những sản phẩm có đơn giá bằng giá trị đó.
e. In ra thông tin sản phẩm dựa trên thứ tự sản phẩm người dùng nhập vào.
f. Cho phép sửa,xóa thông tin sản phẩm dựa trên vị trí người dùng nhập vào sau đó ghi lại xuống tệp Test.txt
g. Sắp xếp sản phẩm theo thứ tự tăng dần của đơn giá.
h. Biết rằng các sản phẩm đã được sản xuất từ 2011, tính số năm sản phẩm này đã sản xuất
i. Hàm main có menu để kiểm tra các hàm vừa xây dựng.
***Lưu ý:
+Không được sử dụng các hàm cctype.
+Tự kiểm soát điều kiện nhập
*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
using namespace std;
const int MAX = 50;

struct SanPham
{
   char tenSP[21], maSP[21];
   int donGia, soLuong, sLTonKho;
} typedef SP;

void ghiFile(SP *list, int n)
{
   ofstream outData("Test.txt");
   if (outData)
   {
      for (int i = 0; i < n; i++)
      {
         outData << list[i].tenSP << '#';
         outData << list[i].maSP << '#';
         outData << list[i].donGia << '#';
         outData << list[i].soLuong << '#';
         outData << list[i].sLTonKho << endl;
      }
      outData.close();
   }
   else
      cout << "\n**Khong mo duoc file**\n";
}
void nhap1SP(SP &sp)
{
   cin.ignore();
   cout << "Nhap ten san pham: ";
   cin.getline(sp.tenSP, 21);
   cout << "Nhap ma san pham: ";
   cin.getline(sp.maSP, 21);
   cout << "Nhap don gia: ";
   cin >> sp.donGia;
   cout << "Nhap so luong: ";
   cin >> sp.soLuong;
   cout << "Nhap so luong ton kho: ";
   cin >> sp.sLTonKho;
}
void nhapDSSP(SP *list, int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << "\n**Nhap thong tin san pham thu " << i + 1 << "**\n";
      nhap1SP(list[i]);
   }
}
int doDaiChuoi(char *p)
{
   int count = 0;
   while (*p)
   {
      count++;
      p++;
   }
   return count;
}
void xoa1KT(char *p, int pos)
{
   int n = doDaiChuoi(p);
   for (int i = pos; i < n; i++)
      p[i] = p[i + 1];
   p[n - 1] = '\0';
}
void chuanHoa1SP(char *p)
{
   int n = doDaiChuoi(p);
   for (int i = 0; i < n; i++)
      if (p[i] == ' ' && p[i + 1] == ' ')
      {
         xoa1KT(p, i);
         i--;
      }
   if (p[0] == ' ')
      xoa1KT(p, 0);
   if (p[doDaiChuoi(p) - 1] == ' ')
      xoa1KT(p, doDaiChuoi(p) - 1);
   if (p[0] >= 'a' && p[0] <= 'z')
      p[0] -= 32;
   for (int i = 1; i < n; i++)
   {
      if (p[i - 1] == ' ' && p[i] != ' ' && (p[i] >= 'a' && p[i] <= 'z'))
         p[i] -= 32;
      if (p[i - 1] != ' ' && p[i] != ' ' && (p[i] >= 'A' && p[i] <= 'Z'))
         p[i] += 32;
   }
}
void chuanHoaNSP(SP *list, int n)
{
   for (int i = 0; i < n; i++)
      chuanHoa1SP(list[i].tenSP);
}
void tonKho100(SP *list, int n)
{
   ofstream outData("newFile.txt");
   if (outData)
   {
      for (int i = 0; i < n; i++)
         if (list[i].sLTonKho < 100)
         {
            outData << list[i].tenSP << '#';
            outData << list[i].maSP << '#';
            outData << list[i].donGia << '#';
            outData << list[i].soLuong << '#';
            outData << list[i].sLTonKho << endl;
         }
      outData.close();
   }
   else
      cout << "\n**Khong mo duoc file**\n";
}
int donGiaMax(SP *list, int n)
{
   if (n == 1)
      list[0].donGia;
   if (list[n - 1].donGia > donGiaMax(list, n - 1))
      return list[n - 1].donGia;
   return donGiaMax(list, n - 1);
}
void xuat1SP(SP sp)
{
   cout << "Ten san pham: " << sp.tenSP << endl;
   cout << "Ma san pham: " << sp.maSP << endl;
   cout << "Don gia: " << sp.donGia << endl;
   cout << "So luong: " << sp.soLuong << endl;
   cout << "So luong ton kho: " << sp.sLTonKho << endl;
}
void xuatSPMAX(SP *list, int n)
{
   int max = donGiaMax(list, n);
   for (int i = 0; i < n; i++)
      if (list[i].donGia == max)
      {
         cout << "**Thong tin san pham thu " << i + 1 << "**\n";
         xuat1SP(list[i]);
      }
}
void inTTSP(SP *list, int n)
{
   int pos;
   do
   {
      cout << "- Nhap STT san pham can sua: ";
      cin >> pos;
      if (pos < 1 || pos > n)
         cout << "\n**VI TRI KHONG HOP LE**\n";
   } while (pos < 1 || pos > n);
   cout << "**Thong tin san pham thu " << pos << "**\n";
   xuat1SP(list[pos - 1]);
}
void suaTTSP(SP *list, int n)
{
   int option, pos;
   do
   {
      cout << "- Nhap STT san pham can sua: ";
      cin >> pos;
      if (pos < 1 || pos > n)
         cout << "\n**VI TRI KHONG HOP LE**\n";
   } while (pos < 1 || pos > n);
   do
   {
      system("cls");
      cout << "1- Sua ten san pham\n"
           << "2- Sua ma san pham\n"
           << "3- Sua don gia\n"
           << "4- Sua so luong\n"
           << "5- Sua so luong ton kho\n"
           << "6- Sua tat ca thong tin\n"
           << "7- Ket thuc viec sua\n"
           << "- Ban chon sua gi? ";
      cin >> option;
      switch (option)
      {
      case 1:
         cout << "Nhap ten san pham moi: ";
         cin.getline(list[pos - 1].tenSP, 256);
         break;
      case 2:
         cout << "Nhap ma san pham moi: ";
         cin.getline(list[pos - 1].maSP, 256);
         break;
      case 3:
         cout << "Nhap don gia moi: ";
         cin >> list[pos - 1].donGia;
         break;
      case 4:
         cout << "Nhap so luong moi: ";
         cin >> list[pos - 1].soLuong;
         break;
      case 5:
         cout << "Nhap so luong ton kho moi: ";
         cin >> list[pos - 1].sLTonKho;
         break;
      case 6:
         cout << "Nhap thong tin moi cho san pham thu " << pos << "\n";
         nhap1SP(list[pos - 1]);
         break;
      default:
         cout << "\n**KET THUC VIEC SUA THONG TIN**\n";
      }
      char s = _getch();
   } while (option >= 1 && option <= 6);
}
void xoa1SP(SP *list, int &n, int pos)
{
   for (int i = pos; i < n - 1; i++)
      list[i] = list[i + 1];
   n--;
}
void xoaNSP(SP *list, int n)
{
   int sl, pos;
   do
   {
      cout << "- Ban muon xoa bao nhieu san pham?";
      cin >> sl;
      if (sl < 1)
         cout << "\n**SO LUONG KHONG HOP LE**\n";
   } while (sl < 1);
   for (int i = 1; i <= sl; i++)
   {
      do
      {
         cout << "- Nhap STT san pham can xoa: ";
         cin >> pos;
         if (pos < 1 || pos > n)
            cout << "\n**VI TRI KHONG HOP LE**\n";
      } while (pos < 1 || pos > n);
      xoa1SP(list, n, pos - 1);
   }
}
void sapXep(SP *list, int n)
{
   for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
         if (list[i].donGia > list[j].donGia)
         {
            SP temp = list[i];
            list[i] = list[j];
            list[j] = temp;
         }
}
int main()
{
   bool input = false;
   SP *list = nullptr;
   int n = 0, luachon1 = 0, luachon2 = 0;
   do
   {
      system("cls");
      cout << "1- Nhap thong tin cho danh sach san pham\n"
           << "2- Chuan hoa ten san pham va ghi vao File\n"
           << "3- Chep danh sach nhung san pham co ton kho it hon 100 sang File moi\n"
           << "4- De quy tim nhung san pham co don gia lon nhat\n"
           << "5- In ra thong tin san pham theo thu tu\n"
           << "6- Sua/xoa thong tin san pham theo thu tu\n"
           << "7- Sap xep theo don gia tang dan\n"
           << "8- So nam san pham duoc san xuat\n"
           << "9- Thoat\n"
           << "- Ban chon chuc nang: ";
      cin >> luachon1;
      switch (luachon1)
      {
      case 1:
         nhapDSSP(list, n);
         input = true;
         cout << "\n**NHAP THONG TIN CHO DANH SACH SAN PHAM THANH CONG**\n";
         break;
      case 2:
         if (input)
         {
            chuanHoaNSP(list, n);
            ghiFile(list, n);
            cout << "\n**CHUAN HOA VA CHEP VAO FILE THANH CONG**\n";
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 3:
         if (input)
         {
            tonKho100(list, n);
            cout << "\n**CHEP THANH CONG CAC SAN PHAM CO TON KHO DUOI 100**\n";
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 4:
         if (input)
         {
            xuatSPMAX(list, n);
            cout << "\n**XUAT THONG TIN SAN PHAM CO DON GIA LON NHAT THANH CONG**\n";
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 5:
         if (input)
         {
            inTTSP(list, n);
            cout << "\n**IN THONG TIN SAN PHAM THANH CONG**\n";
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 6:
         if (input)
         {
            do
            {
               cout << "1- Sua thong tin san pham\n"
                    << "2- Xoa san pham\n"
                    << "3- Thoat\n"
                    << "- Ban chon chuc nang: ";
               cin >> luachon2;
               switch (luachon2)
               {
               case 1:
                  suaTTSP(list, n);
                  cout << "\n**SUA THONG TIN SAN PHAM THANH CONG**\n";
                  break;
               case 2:
                  xoaNSP(list, n);
                  cout << "\n**XOA SAN PHAM THANH CONG**\n";
                  break;
               default:
                  cout << "\n**KET THUC VIEC SUA/XOA SAN PHAM**\n";
               }
            } while (luachon2 >= 1 && luachon2 <= 2);
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 7:
         if (input)
         {
            sapXep(list, n);
            cout << "\n**SAP XEP DON GIA TANG DAN THANH CONG**\n";
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      case 8:
         if (input)
         {
         }
         else
            cout << "\n**VUI LONG NHAP THONG TIN SAN PHAM TRUOC**\n";
         break;
      default:
         cout << "\n**THOAT CHUONG TRINH**\n";
         delete[] list;
      }
      char s = _getch();
   } while (luachon1 >= 1 && luachon1 <= 8);
   return 0;
}