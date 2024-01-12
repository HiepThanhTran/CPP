#include <iostream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

void TextColor(int color);
void gotoXY(int x, int y);
void Ox(int x1, int x2, int y);
void Oy(int y1, int y2, int x, int d);
void Table(int x, int y, int *a, int b, int m, int n, int color);
int setX = 20, setY = 5;
int setColorText = 15;
int setColorTable = 11;

class PKM
{
public:
    int id;
    string name;
    string properties;
    string type;
    int hp;
    int mp;
    int hpMax;
    int mpMax;
    int speed;
    int speedp;
    string primary_move;
    string secondary_move;
    string third_move;
    int buff; //
    void Learn()
    {
        this->buff = 0;
        if (this->type == "Bay")
        {
            this->primary_move = "Song tram " + this->properties; // 10 damg - xac suat chi mang 25%
            this->secondary_move = "Canh " + this->properties;    // tang x2 damg - 10mpMax - 3 luot - speed -5
            this->third_move = this->properties + " khong kich";  // 40 damg - 15mpMax - xac suat chi mang 50% - tang x1.5 damg - speed -8
        }
        else
        {
            this->primary_move = "Tung " + this->properties;   // 10 damg - 5mpMax - xac suat chi mang 25%
            this->secondary_move = "Giap " + this->properties; // giam 50% damg - 10mpMax - 3 luot - speed -5
            this->third_move = "Tru " + this->properties;      // 30 damg - 15mpMax - xac suat mien nhiem st trong 3 luot - 75% - speed -8
        }
    }
    bool InputFile(ifstream &cin)
    {
        if (!(cin >> this->id))
            return false;
        cin.ignore();
        getline(cin, this->name);
        getline(cin, this->properties);
        getline(cin, this->type);
        cin >> this->hpMax >> this->mpMax >> this->speed;
        this->hp = this->hpMax;
        this->mp = this->mpMax;
        this->Learn();
    }
    friend istream &operator>>(istream &cin, PKM &pkm)
    {
        int size[2] = {70};
        Table(setX - 3, setY - 2, size, 2, 1, 1, setColorTable);
        TextColor(setColorText);
        gotoXY(setX + 15, setY - 1);
        cout << "Nhap thong tin";
        size[0] = 40, size[1] = 30;
        Table(setX - 3, setY, size, 2, 7, 2, setColorTable);
        TextColor(setColorText);
        int j = 0;
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap id: ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap ten: ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap thuoc tinh(nuoc/lua/thuc vat): ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap loai(Bay/Bo): ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap hpMax: ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap mpMax: ";
        gotoXY(setX, setY + 2 * j++ + 1);
        cout << "Nhap Speed: ";
        j = 0;
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        cin >> pkm.id;
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        cin.ignore();
        getline(cin, pkm.name);
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        getline(cin, pkm.properties);
        gotoXY(setX + 30, setY + 2 * j++ + 1);
        getline(cin, pkm.type);
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        cin >> pkm.hpMax;
        pkm.hp = pkm.hpMax;
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        cin >> pkm.mpMax;
        pkm.mp = pkm.mpMax;
        gotoXY(setX + 40, setY + 2 * j++ + 1);
        cin >> pkm.speed;
        pkm.Learn();
    }
    void Xuat(int X, int Y)
    {
        int size[1] = {50};
        Table(X - 3, Y - 2, size, 2, 1, 1, setColorTable);
        TextColor(setColorText);
        gotoXY(X + 10, Y - 1);
        cout << "Pokemon - id: " << this->id << "   ";
        Table(X - 3, Y, size, 2, 6, 1, setColorTable);
        TextColor(setColorText);
        int j = 0;
        gotoXY(X, Y + 2 * j++ + 1);
        TextColor(setColorText);
        cout << "Ten: ";
        TextColor(7);
        cout << this->name << "                   ";
        if (this->properties == "Nuoc")
            TextColor(3);
        else if (this->properties == "Lua")
            TextColor(4);
        else
            TextColor(2);
        gotoXY(X, Y + 2 * j++ + 1);
        cout << "Thuoc tinh: " << this->properties << "       ";
        gotoXY(X, Y + 2 * j++ + 1);
        cout << "Loai: " << this->type << "     ";
        gotoXY(X, Y + 2 * j++ + 1);
        TextColor(12);
        cout << "Hp: " << this->hp << "/" << this->hpMax;
        gotoXY(X, Y + 2 * j++ + 1);
        TextColor(9);
        cout << "Mp: " << this->mp << "/" << this->mpMax;
        gotoXY(X, Y + 2 * j++ + 1);
        TextColor(6);
        cout << "Speed: " << this->speed;
        size[0] = 110;
        Table(X - 3, Y + 2 * j + 6, size, 2, 4, 1, setColorTable);
        if (this->properties == "Nuoc")
            TextColor(3);
        else if (this->properties == "Lua")
            TextColor(4);
        else
            TextColor(2);
        gotoXY(X + 25, Y + 2 * j++ + 7);
        cout << "Chieu thuc";
        gotoXY(X, Y + 2 * j++ + 7);
        cout << this->primary_move << ": 10 dmg, 25% Critical                                                    ";
        if (this->type == "Bay")
        {
            gotoXY(X, Y + 2 * j++ + 7);
            cout << this->secondary_move << ": Increase X2 attack in 3 times, 10mp, -5 speed                          ";
            gotoXY(X, Y + 2 * j++ + 7);
            cout << this->third_move << ": 40 dmg, 15 mp, critical probability of 50%, increase x2 attack in 3 times, -12 speed";
        }
        else
        {
            gotoXY(X, Y + 2 * j++ + 7);
            cout << this->secondary_move << ": 50% off attack in 3 times, 10mp, -5 speed                          ";
            gotoXY(X, Y + 2 * j++ + 7);
            cout << this->third_move << ": 30 dmg, 15 mp, the damage immunity rate in 3: 75%, -15 speed                                   ";
        }
    }
    void ChiSo(int X, int Y)
    {
        TextColor(15);
        gotoXY(X, Y - 1);
        cout << this->name;
        for (int j = 0; j < 20; j++)
        {
            if (j < 20 * this->hp / this->hpMax)
                TextColor(199);
            else
                TextColor(247);
            gotoXY(X + j, Y);
            cout << " ";
            // getch();
        }
        for (int j = 0; j < 20; j++)
        {
            if (j < 20 * this->mp / this->mpMax)
                TextColor(183);
            else
                TextColor(247);
            gotoXY(X + j, Y + 1);
            cout << " ";
            // getch();
        }
        if (this->hp < 0)
            this->hp = 0;
        if (this->mp < 0)
            this->mp = 0;
        gotoXY(X + 20, Y);
        TextColor(4);
        cout << this->hp << "/" << this->hpMax << "  ";
        gotoXY(X + 20, Y + 1);
        TextColor(3);
        cout << this->mp << "/" << this->mpMax << "   ";
        int Ybuff1 = this->buff % 10;
        int Ybuff2 = (this->buff % 100) / 10; // - Ybuff1;
        int Ybuff3 = this->buff / 1000;
        if (Ybuff1 > 3)
        {
            Ybuff1 = 3;
        }
        if (Ybuff2 > 3)
        {
            Ybuff2 = 3;
        }
        if (Ybuff3 > 3)
        {
            Ybuff3 = 3;
        }
        this->buff = Ybuff3 * 1000 + Ybuff2 * 10 + Ybuff1;
        int j = 0, i = 27;
        gotoXY(X + i, Y);
        cout << "                   ";
        gotoXY(X + i, Y + 1);
        cout << "                   ";
        gotoXY(X + i, Y + 2);
        cout << "                   ";
        if (Ybuff1 > 0)
        {
            TextColor(6);
            gotoXY(X + i, Y);
            cout << "x2 damage: " << Ybuff1;
        }
        if (Ybuff2 > 0)
        {
            TextColor(2);
            gotoXY(X + i, Y + 1);
            cout << "50% off attack: " << Ybuff2;
        }
        if (Ybuff3 > 0)
        {
            TextColor(5);
            gotoXY(X + i, Y + 2);
            cout << "immunity rate: " << Ybuff3;
        }
    }
    void Index(int X1, int Y1, int X2, int Y2, PKM &a)
    {
        TextColor(6);
        gotoXY(X2, Y2);
        cout << "Boss - speed: " << a.speedp << "                ";
        TextColor(4);
        gotoXY(X1, Y1);
        cout << "You - speed: " << this->speedp << "                ";
    }
    void Buff(PKM &a)
    {
        if ((this->properties == "Lua" && a.properties == "Nuoc") || (this->properties == "Nuoc" && a.properties == "Thuc vat") || this->properties == "Thuc Vat" && a.properties == "Lua")
        {
            this->hp -= 40;
            this->mp -= 20;
            a.hp += 30;
            a.mp += 30;
        }
    }
    bool Attack(int X1, int Y1, int X2, int Y2, PKM &a)
    {
        this->buff = 0;
        a.buff = 0;
        this->Buff(a);
        a.Buff(*this);
        int X = 30, Y = 25, j = 0;
        this->ChiSo(X1, Y1);
        a.ChiSo(X2, Y2 - 2);
        this->speedp = 20 - this->speed;
        a.speedp = 20 - a.speed;
        int d = 1;
        while (this->hp > 0 && a.hp > 0)
        {
            if (this->speedp < a.speedp || (this->speedp == a.speedp && d == 1))
            {
                a.speedp -= this->speedp;
                this->speedp = 0;
                int chuc_nang = 0, color;
                int size[] = {110};
                Table(X - 3, Y, size, 2, 4, 1, setColorTable);
                if (this->properties == "Nuoc")
                    color = 3;
                else if (this->properties == "Lua")
                    color = 4;
                else
                    color = 2;
                j = 0;
                TextColor(15);
                gotoXY(X + 25, Y + 2 * j++ + 1);
                cout << "Chieu thuc";
                TextColor(15);
                if (chuc_nang == j)
                    ;
                TextColor(color);
                gotoXY(X, Y + 2 * j++ + 1);
                cout << this->primary_move << ": 10 dmg, 25% Critical                                                    ";
                if (this->type == "Bay")
                {
                    gotoXY(X, Y + 2 * j++ + 1);
                    if (chuc_nang == j)
                        ;
                    TextColor(15);
                    cout << this->secondary_move << ": Increase X2 attack in 3 times, 10mp, -5 speed                          ";
                    gotoXY(X, Y + 2 * j++ + 1);
                    if (chuc_nang == j)
                        ;
                    TextColor(15);
                    cout << this->third_move << ": 40 dmg, 15 mp, critical probability of 50%, increase x2 attack in 3 times, -12 speed";
                }
                else
                {
                    gotoXY(X, Y + 2 * j++ + 1);
                    if (chuc_nang == j)
                        ;
                    TextColor(15);
                    cout << this->secondary_move << ": 50% off attack in 3 times, 10mp, -5 speed                          ";
                    gotoXY(X, Y + 2 * j++ + 1);
                    if (chuc_nang == j)
                        ;
                    TextColor(15);
                    cout << this->third_move << ": 30 dmg, 15 mp, the damage immunity rate in 3: 75%, -15 speed                                   ";
                }
                while (1)
                {
                    if (kbhit())
                    {
                        char c = getch();
                        // cout << "hi";
                        switch (c)
                        {
                        case 72:
                        {
                            chuc_nang--;
                            if (chuc_nang == -1)
                                chuc_nang = 2;
                            break;
                        }
                        case 80:
                        {
                            chuc_nang++;
                            if (chuc_nang == 3)
                                chuc_nang = 0;
                            break;
                        }
                        case 13:
                        {
                            switch (chuc_nang)
                            {
                            case 0:
                            {
                                int dame = 1, def = 1, defs = 1;

                                int Abuff1 = a.buff % 10;
                                int Abuff2 = (a.buff % 100) / 10;
                                int Abuff3 = a.buff / 1000;

                                int Ybuff1 = this->buff % 10;
                                int Ybuff2 = (this->buff % 100) / 10;
                                int Ybuff3 = this->buff / 1000;
                                if (Ybuff1 > 0)
                                {
                                    this->buff--;
                                    dame = 2;
                                }
                                if (Abuff2 > 0)
                                {
                                    a.buff -= 10;
                                    def = 2;
                                }
                                if (Abuff3 > 0)
                                {
                                    a.buff -= 1000;
                                    defs = 0;
                                }
                                int r = rand() % 3;
                                int hp;
                                if (r == 2)
                                    hp = defs * 15 * dame / def;
                                else
                                    hp = defs * 10 * dame / def;
                                a.hp -= hp;
                                // this->mp -= 5;
                                this->speedp += 20 - this->speed;
                                TextColor(15);
                                gotoXY(X1, Y1 + 3);
                                cout << this->primary_move;
                                Sleep(200);
                                gotoXY(X2, Y2);
                                TextColor(4);
                                cout << -hp;
                                Sleep(1000);
                                gotoXY(X2, Y2);
                                cout << "      ";
                                TextColor(0);
                                gotoXY(X1, Y1 + 3);
                                cout << "                         ";
                                break;
                            }
                            case 1:
                            {
                                if (this->mp < 10)
                                {
                                    cout << "Khong du mana!";
                                }
                                else
                                {
                                    if (this->type == "Bay")
                                        this->buff += 3;
                                    else
                                        this->buff += 30;
                                    int dame = 1, def = 1, defs = 1;
                                    int Abuff1 = a.buff % 10;
                                    int Abuff2 = (a.buff % 100) / 10;
                                    int Abuff3 = a.buff / 1000;

                                    int Ybuff1 = this->buff % 10;
                                    int Ybuff2 = (this->buff % 100) / 10;
                                    int Ybuff3 = this->buff / 1000;
                                    if (Ybuff1 > 0)
                                    {
                                        this->buff--;
                                        dame = 2;
                                    }
                                    if (Abuff2 > 0)
                                    {
                                        a.buff -= 10;
                                        def = 2;
                                    }
                                    if (Abuff3 > 0)
                                    {
                                        a.buff -= 1000;
                                        defs = 0;
                                    }
                                    this->mp -= 10;
                                    this->speedp += 20 - this->speed + 5;
                                    TextColor(15);
                                    gotoXY(X1, Y1 + 3);
                                    cout << this->secondary_move;
                                    Sleep(1000);
                                    gotoXY(X1, Y1 + 3);
                                    cout << "                         ";
                                }
                                break;
                            }
                            case 2:
                            {
                                if (this->mp < 15)
                                {
                                    cout << "Khong du mana!";
                                }
                                else
                                {
                                    int dame1;
                                    if (this->type == "Bay")
                                    {
                                        int r1 = rand() % 1;
                                        if (r1 == 1)
                                            dame1 = 60;
                                        else
                                            dame1 = 40;
                                        this->buff += 3;
                                        this->speedp += 20 - this->speed + 12;
                                    }
                                    else
                                    {
                                        int r1 = rand() % 4;
                                        if (r1 != 1)
                                            this->buff += 3000;
                                        dame1 = 30;
                                        this->speedp += 20 - this->speed + 15;
                                    }

                                    int dame = 1, def = 1, defs = 1;
                                    int Abuff1 = a.buff % 10;
                                    int Abuff2 = (a.buff % 100) / 10;
                                    int Abuff3 = a.buff / 1000;

                                    int Ybuff1 = this->buff % 10;
                                    int Ybuff2 = (this->buff % 100) / 10;
                                    int Ybuff3 = this->buff / 1000;
                                    if (Ybuff1 > 0)
                                    {
                                        this->buff--;
                                        dame = 2;
                                    }
                                    if (Abuff2 > 0)
                                    {
                                        a.buff -= 10;
                                        def = 2;
                                    }
                                    if (Abuff3 > 0)
                                    {
                                        a.buff -= 1000;
                                        defs = 0;
                                    }
                                    int hp;
                                    hp = defs * dame1 * dame / def;
                                    a.hp -= hp;
                                    this->mp -= 15;
                                    // this->speedp += 20 - this->speed;
                                    TextColor(15);
                                    gotoXY(X1, Y1 + 3);
                                    cout << this->third_move;
                                    Sleep(200);
                                    gotoXY(X2, Y2);
                                    TextColor(4);
                                    cout << -hp;
                                    Sleep(1000);
                                    gotoXY(X2, Y2);
                                    cout << "      ";
                                    TextColor(0);
                                    gotoXY(X1, Y1 + 3);
                                    cout << "                         ";
                                }
                                break;
                            }
                            }
                            // d = 0;
                            goto OUT1;
                            // break;
                        }
                        }
                        j = 0;
                        TextColor(15);
                        gotoXY(X + 25, Y + 2 * j++ + 1);
                        cout << "Chieu thuc";
                        // TextColor(15);
                        gotoXY(X, Y + 2 * j++ + 1);
                        cout << this->primary_move << ": 10 dmg, 25% Critical                                                    ";
                        if (this->type == "Bay")
                        {
                            gotoXY(X, Y + 2 * j++ + 1);
                            cout << this->secondary_move << ": Increase X2 attack in 3 times, 10mp, -5 speed                          ";
                            gotoXY(X, Y + 2 * j++ + 1);
                            cout << this->third_move << ": 40 dmg, 15 mp, critical probability of 50%, increase x2 attack in 3 times, -12 speed";
                        }
                        else
                        {
                            gotoXY(X, Y + 2 * j++ + 1);
                            cout << this->secondary_move << ": 50% off attack in 3 times, 10mp, -5 speed                          ";
                            gotoXY(X, Y + 2 * j++ + 1);
                            cout << this->third_move << ": 30 dmg, 15 mp, the damage immunity rate in 3: 75%, -15 speed                                   ";
                        }

                        j = 0;
                        TextColor(15);
                        gotoXY(X + 25, Y + 2 * j++ + 1);
                        cout << "Chieu thuc";
                        if (chuc_nang == 0)
                            TextColor(color);
                        gotoXY(X, Y + 2 * j++ + 1);
                        cout << this->primary_move << ": 10 dmg, 25% Critical                                                    ";
                        if (this->type == "Bay")
                        {
                            gotoXY(X, Y + 2 * j++ + 1);
                            TextColor(15);
                            if (chuc_nang == 1)
                                TextColor(color);
                            cout << this->secondary_move << ": Increase X2 attack in 3 times, 10mp, -5 speed                          ";
                            gotoXY(X, Y + 2 * j++ + 1);
                            TextColor(15);
                            if (chuc_nang == 2)
                                TextColor(color);
                            cout << this->third_move << ": 40 dmg, 15 mp, critical probability of 50%, increase x2 attack in 3 times, -12 speed";
                        }
                        else
                        {
                            gotoXY(X, Y + 2 * j++ + 1);
                            TextColor(15);
                            if (chuc_nang == 1)
                                TextColor(color);
                            cout << this->secondary_move << ": 50% off attack in 3 times, 10mp, -5 speed                          ";
                            gotoXY(X, Y + 2 * j++ + 1);
                            TextColor(15);
                            if (chuc_nang == 2)
                                TextColor(color);
                            cout << this->third_move << ": 30 dmg, 15 mp, the damage immunity rate in 3: 75%, -15 speed                                   ";
                        }
                    }
                }
            OUT1:
                d = 0;
            }
            else
            {
                this->speedp -= a.speedp;
                a.speedp = 0;
            ComeBack:
                int chieu_thuc = rand() % 2;
                switch (chieu_thuc)
                {
                case 0:
                {
                    int dame = 1, def = 1, defs = 1;
                    int Abuff1 = a.buff % 10;
                    int Abuff2 = (a.buff % 100) / 10;
                    int Abuff3 = a.buff / 1000;

                    int Ybuff1 = this->buff % 10;
                    int Ybuff2 = (this->buff % 100) / 10;
                    int Ybuff3 = this->buff / 1000;
                    if (Abuff1 > 0)
                    {
                        a.buff--;
                        dame = 2;
                    }
                    if (Ybuff2 > 0)
                    {
                        this->buff -= 10;
                        def = 2;
                    }
                    if (Ybuff3 > 0)
                    {
                        this->buff -= 1000;
                        defs = 0;
                    }
                    int hp;
                    int r = rand() % 3;
                    if (r == 2)
                        hp = defs * 15 * dame / def;
                    else
                        hp = defs * 10 * dame / def;
                    this->hp -= hp;
                    // gotoXY(0, 0);
                    // cout << this->hp;
                    // a.mp -= 5;
                    a.speedp += 20 - a.speed;
                    TextColor(15);
                    gotoXY(X2, Y2 + 1);
                    cout << a.primary_move;
                    Sleep(200);
                    gotoXY(X1, Y1 + 2);
                    TextColor(4);
                    cout << -hp;
                    Sleep(1000);
                    gotoXY(X1, Y1 + 2);
                    cout << "      ";
                    TextColor(0);
                    gotoXY(X2, Y2 + 1);
                    cout << "                         ";
                    break;
                }
                case 1:
                {
                    if (a.mp < 10 || (a.buff % 100) / 10 >= 2)
                    {
                        goto ComeBack;
                    }
                    else
                    {
                        if (a.type == "Bay")
                            a.buff += 3;
                        else
                            a.buff += 30;
                        int dame = 1, def = 1, defs = 1;
                        int Abuff1 = a.buff % 10;
                        int Abuff2 = (a.buff % 100) / 10;
                        int Abuff3 = a.buff / 1000;

                        int Ybuff1 = this->buff % 10;
                        int Ybuff2 = (this->buff % 100) / 10;
                        int Ybuff3 = this->buff / 1000;
                        if (Abuff1 > 0)
                        {
                            a.buff--;
                            dame = 2;
                        }
                        if (Ybuff2 > 0)
                        {
                            this->buff -= 10;
                            def = 2;
                        }
                        if (Ybuff3 > 0)
                        {
                            this->buff -= 1000;
                            defs = 0;
                        }
                        a.mp -= 10;
                        a.speedp += 20 - a.speed + 5;
                        TextColor(15);
                        gotoXY(X2, Y2 + 1);
                        cout << a.secondary_move;
                        Sleep(1000);
                        TextColor(0);
                        gotoXY(X2, Y2 + 1);
                        cout << "                         ";
                    }
                    break;
                }
                case 2:
                {
                    if (a.mp < 15)
                    {
                        goto ComeBack;
                    }
                    else
                    {
                        int dame1;
                        if (a.type == "Bay")
                        {
                            int r1 = rand() % 1;
                            if (r1 == 1)
                                dame1 = 60;
                            else
                                dame1 = 40;
                            a.buff += 3;
                            a.speedp += 20 - a.speed + 12;
                        }
                        else
                        {
                            int r1 = rand() % 4;
                            if (r1 != 1)
                                a.buff += 3000;
                            dame1 = 30;
                            a.speedp += 20 - a.speed + 15;
                        }

                        int dame = 1, def = 1, defs = 1;
                        int Abuff1 = a.buff % 10;
                        int Abuff2 = (a.buff % 100) / 10;
                        int Abuff3 = a.buff / 1000;

                        int Ybuff1 = this->buff % 10;
                        int Ybuff2 = (this->buff % 100) / 10;
                        int Ybuff3 = this->buff / 1000;
                        if (Abuff1 > 0)
                        {
                            a.buff--;
                            dame = 2;
                        }
                        if (Ybuff2 > 0)
                        {
                            this->buff -= 10;
                            def = 2;
                        }
                        if (Ybuff3 > 0)
                        {
                            this->buff -= 1000;
                            defs = 0;
                        }
                        int hp;
                        hp = defs * dame1 * dame / def;
                        this->hp -= hp;
                        // gotoXY(0, 0);
                        // cout << this->hp;
                        a.mp -= 15;
                        // a.speedp += 20 - this->speed;
                        TextColor(15);
                        gotoXY(X2, Y2 + 1);
                        cout << a.third_move;
                        Sleep(200);
                        gotoXY(X1, Y1 + 2);
                        TextColor(4);
                        cout << -hp;
                        Sleep(1000);
                        gotoXY(X1, Y1 + 2);
                        cout << "      ";
                        TextColor(0);
                        gotoXY(X2, Y2 + 1);
                        cout << "                         ";
                    }
                    break;
                }
                }
                d = 1;
            }
            // OUT1:
            this->ChiSo(X1, Y1);
            a.ChiSo(X2, Y2 - 2);
            this->Index(X1, Y1 - 2, X2, Y2 - 4, a);
            Sleep(500);
        }
        this->buff = 0;
        a.buff = 0;
        this->speedp = this->speed;
        a.speedp = a.speed;
        if (this->hp > 0)
            return true;
        return false;
    }
};
void Input(vector<PKM> *Thuoc_tinh);
void Init(vector<PKM> *boss, vector<PKM> *Thuoc_tinh);
int Menu_choose1(int X, int Y, vector<PKM> *Thuoc_tinh);
int Menu_choose2(int X, int Y, vector<PKM> a);
void Init(int X, int Y, vector<PKM> &NV, vector<PKM> *Thuoc_tinh);
void DSPKM(int X, int Y, vector<PKM> a);
bool War(int X1, int Y1, int X2, int Y2, vector<PKM> NV, vector<PKM> Boss);
int Menu(int X, int Y, vector<PKM> *Boss)
{
    string Tieu_de[] = {"Boss 1", "Boss 2", "Boss 3", "Boss 4"};
    int size[] = {40};
    Table(X - 3, Y - 2, size, 2, 5, 1, setColorTable);
    TextColor(15);
    gotoXY(X + 10, Y - 1);
    cout << "Boss";
    int chuc_nang = 0;
    for (int i = 0; i < 4; i++)
    {
        TextColor(setColorText);
        if (Boss[i].size() == 0)
            TextColor(8);
        if (i == chuc_nang)
            TextColor(10);
        gotoXY(X, Y + 2 * i + 1);
        cout << Tieu_de[i];
    }
    while (1)
    {
        if (kbhit())
        {
            char c = getch();
            // cout << int(c) << endl;
            switch (c)
            {
            case 72:
            {
                chuc_nang--;
                if (chuc_nang == -1)
                    chuc_nang = 3;
                break;
            }
            case 80:
            {
                chuc_nang++;
                if (chuc_nang == 4)
                    chuc_nang = 0;
                break;
            }
            case 13:
            {
                if ((chuc_nang != 3 && Boss[chuc_nang].size() != 0) || (chuc_nang == 3 && Boss[0].size() == 0 && Boss[1].size() == 0 && Boss[2].size() == 0))
                {
                    return chuc_nang;
                }
            }
            }
            for (int i = 0; i < 4; i++)
            {
                TextColor(setColorText);
                if (Boss[i].size() == 0)
                    TextColor(8);
                if (i == chuc_nang)
                    TextColor(10);
                gotoXY(X, Y + 2 * i + 1);
                cout << Tieu_de[i];
            }
        }
    }
}
int main()
{
    srand(time(0));
    system("cls");
    vector<PKM> Thuoc_tinh[3];
    vector<PKM> NV, boss[4];
    Input(Thuoc_tinh);
    Init(boss, Thuoc_tinh);
    Init(4, setY, NV, Thuoc_tinh);
    for (int j = 0; j < 4; j++)
    {
        system("cls");
        int nBoss = Menu(setX, setY, boss);
        TextColor(6);
        for (int i = 3; i >= 0; i--)
        {
            gotoXY(40, 15);
            cout << i;
            Sleep(1000);
        }
        gotoXY(40, 15);
        TextColor(4);
        cout << "START";
        Sleep(1000);
        system("cls");
        if (War(setX + 20, setY - 2, setX + 60, setY + 15, NV, boss[nBoss]) == true)
        {
            boss[nBoss].erase(boss[nBoss].begin(), boss[nBoss].begin() + 3);
        }
        else
        {
            gotoXY(20, 20);
            TextColor(4);
            cout << "LOSE";
            return 0;
        }
    }
    gotoXY(20, 20);
    TextColor(14);
    cout << "WIN";
    return 0;
}

void TextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Ox(int x1, int x2, int y)
{
    for (int j = x1; j <= x2; j += 2)
    {
        gotoXY(j, y);
        cout << "-";
    }
}
void Oy(int y1, int y2, int x, int d)
{
    for (int j = y1; j <= y2; j++)
    {
        gotoXY(x, j);
        if ((j - y1) % d == 0)
            cout << "+";
        else
            cout << "|";
    }
}
void Table(int x, int y, int *a, int b, int m, int n, int color)
{
    TextColor(color);
    // dong
    int size = 0;
    for (int i = 0; i < n; i++)
        size += a[i];
    for (int i = 0; i <= m; i++)
        Ox(x, x + size, y + b * i);
    // cot
    Oy(y, y + m * b, x, b);
    Oy(y, y + m * b, x + size, b);
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        Oy(y, y + m * b, x + d + a[i], b);
        d += a[i];
    }
}
void Input(vector<PKM> *Thuoc_tinh)
{
    ifstream fileIn("input.txt");
    PKM x;
    while (x.InputFile(fileIn))
    {
        if (x.properties == "Nuoc")
            Thuoc_tinh[0].push_back(x);
        else if (x.properties == "Lua")
            Thuoc_tinh[1].push_back(x);
        else
            Thuoc_tinh[2].push_back(x);
        // x.Xuat();
        // getch();
    }
}
void Init(vector<PKM> *boss, vector<PKM> *Thuoc_tinh)
{
    boss[0].push_back(Thuoc_tinh[0][rand() % Thuoc_tinh[0].size()]);
    boss[0].push_back(Thuoc_tinh[0][rand() % Thuoc_tinh[0].size()]);
    boss[0].push_back(Thuoc_tinh[0][rand() % Thuoc_tinh[0].size()]);
    // for(int i=0; i<3; i++){
    //     boss[0][i].Xuat();
    //     getch();
    //     system("cls");
    // }
    boss[1].push_back(Thuoc_tinh[1][rand() % Thuoc_tinh[1].size()]);
    boss[1].push_back(Thuoc_tinh[1][rand() % Thuoc_tinh[1].size()]);
    boss[1].push_back(Thuoc_tinh[1][rand() % Thuoc_tinh[1].size()]);
    // for(int i=0; i<3; i++){
    //     boss[1][i].Xuat();
    //     getch();
    //     system("cls");
    // }
    boss[2].push_back(Thuoc_tinh[2][rand() % Thuoc_tinh[2].size()]);
    boss[2].push_back(Thuoc_tinh[2][rand() % Thuoc_tinh[2].size()]);
    boss[2].push_back(Thuoc_tinh[2][rand() % Thuoc_tinh[2].size()]);
    // for(int i=0; i<3; i++){
    //     boss[2][i].Xuat();
    //     getch();
    //     system("cls");
    // }
    boss[3].push_back(Thuoc_tinh[0][rand() % Thuoc_tinh[0].size()]);
    boss[3][0].hpMax += 20, boss[3][0].mpMax += 10, boss[3][0].speed += 2, boss[3][0].mp += 10, boss[3][0].hp += 20;
    boss[3].push_back(Thuoc_tinh[1][rand() % Thuoc_tinh[1].size()]);
    boss[3][1].hpMax += 30, boss[3][1].mpMax += 20, boss[3][1].speed += 3, boss[3][1].mp += 20, boss[3][1].hp += 30;
    boss[3].push_back(Thuoc_tinh[2][rand() % Thuoc_tinh[2].size()]);
    boss[3][2].hpMax += 50, boss[3][2].speed += 1;
    boss[3][2].hp += 50;

    // for(int i=0; i<3; i++){
    //     boss[3][i].Xuat();
    //     getch();
    //     system("cls");
    // }
}
int Menu_choose1(int X, int Y, vector<PKM> *Thuoc_tinh)
{
    string Tieu_de[] = {"Nuoc", "Lua", "Thuc vat"};
    int size[] = {20};
    Table(X - 3, Y - 2, size, 2, 4, 1, setColorTable);
    TextColor(15);
    gotoXY(X + 2, Y - 1);
    cout << "Thuoc tinh";
    int chuc_nang = 0;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
        {
            TextColor(3);
            break;
        }
        case 1:
        {
            TextColor(4);
            break;
        }
        case 2:
        {
            TextColor(2);
            break;
        }
        }
        if (i == chuc_nang)
            TextColor(15);
        gotoXY(X, Y + 2 * i + 1);
        cout << Tieu_de[i] << ": " << Thuoc_tinh[i].size() << " PKM";
    }
    while (1)
    {
        if (kbhit())
        {
            char c = getch();
            // cout << int(c) << endl;
            switch (c)
            {
            case 72:
            {
                chuc_nang--;
                if (chuc_nang == -1)
                    chuc_nang = 2;
                break;
            }
            case 80:
            {
                chuc_nang++;
                if (chuc_nang == 3)
                    chuc_nang = 0;
                break;
            }
            case 13:
            {
                return chuc_nang;
            }
            }
            for (int i = 0; i < 3; i++)
            {
                switch (i)
                {
                case 0:
                {
                    TextColor(3);
                    break;
                }
                case 1:
                {
                    TextColor(4);
                    break;
                }
                case 2:
                {
                    TextColor(2);
                    break;
                }
                }
                if (i == chuc_nang)
                    TextColor(15);
                gotoXY(X, Y + 2 * i + 1);
                cout << Tieu_de[i] << ": " << Thuoc_tinh[i].size() << " PKM";
            }
        }
    }
}
int Menu_choose2(int X, int Y, vector<PKM> a)
{
    system("cls");
    int size[] = {40};
    Table(X - 3, Y - 2, size, 2, a.size() + 1, 1, setColorTable);
    TextColor(15);
    gotoXY(X + 2, Y - 1);
    cout << "He: " << a[0].properties;
    int chuc_nang = 0;
    for (int i = 0; i < a.size(); i++)
    {
        TextColor(15);
        if (i == chuc_nang)
            if (a[0].properties == "Nuoc")
                TextColor(3);
            else if (a[0].properties == "Lua")
                TextColor(4);
            else
                TextColor(2);
        gotoXY(X, Y + 2 * i + 1);
        cout << "ID: " << a[i].id << " - " << a[i].name;
    }
    a[chuc_nang].Xuat(X + 50, Y);
    while (1)
    {
        if (kbhit())
        {
            char c = getch();
            // cout << int(c) << endl;
            switch (c)
            {
            case 72:
            {
                chuc_nang--;
                if (chuc_nang == -1)
                    chuc_nang = a.size() - 1;
                break;
            }
            case 80:
            {
                chuc_nang++;
                if (chuc_nang == a.size())
                    chuc_nang = 0;
                break;
            }
            case 13:
            {
                return chuc_nang;
            }
            }
            for (int i = 0; i < a.size(); i++)
            {
                TextColor(15);
                if (i == chuc_nang)
                    if (a[0].properties == "Nuoc")
                        TextColor(3);
                    else if (a[0].properties == "Lua")
                        TextColor(4);
                    else
                        TextColor(2);
                gotoXY(X, Y + 2 * i + 1);
                cout << "ID: " << a[i].id << " - " << a[i].name;
            }
            a[chuc_nang].Xuat(X + 50, Y);
        }
    }
}
void Init(int X, int Y, vector<PKM> &NV, vector<PKM> *Thuoc_tinh)
{
    int chuc_nang;
    while (1)
    {
        system("cls");
        chuc_nang = Menu_choose1(X, Y, Thuoc_tinh);
        NV.push_back(Thuoc_tinh[chuc_nang][Menu_choose2(X, Y, Thuoc_tinh[chuc_nang])]);
        if (NV.size() == 3)
            return;
    }
}
void DSPKM(int X, int Y, vector<PKM> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i].ChiSo(X, Y + 4 * i);
    }
}
bool War(int X1, int Y1, int X2, int Y2, vector<PKM> NV, vector<PKM> Boss)
{
    int nv = 0, boss = 0;
    while (nv < 3 && boss < 3)
    {
        DSPKM(3, setY, NV);
        DSPKM(setX + 100, setY, Boss);
        if (NV[nv].Attack(X1, Y1, X2, Y2, Boss[boss]))
            boss++;
        else
            nv++;
    }
    if (nv < 3)
        return true;
    return false;
}
