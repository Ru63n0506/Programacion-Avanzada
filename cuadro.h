#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

int i;

void gotoxy(int x, int y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hCon, pos);
}

void marcoysonido()
{
    for(i=0;i<30;i++)
    {
        gotoxy(i,2);
        cout<<"#";
    }

    for(i=0;i<30;i++)
    {
        gotoxy(i,6);
        cout<<"#";
    }

    for(i=3;i<6;i++)
    {
        gotoxy(0,i);
        cout<<"#";
    }

    for(i=3;i<6;i++)
    {
        gotoxy(29,i);
        cout<<"#";
    }

    gotoxy(2,4);
    cout<<"Programador: Ruben Carmona";

    for(i=0;i<2;i++)
    {
        Beep(800, 120);
        Beep(800, 120);
        Beep(1000, 250);
    }
}

void cargando()
{
    gotoxy(0,8);

    cout<<"Cargando..."<<endl;

    for(i=0;i<15;i++)
    {
        cout<<"+";
        Sleep(30);
        Beep(50,500);
    }

    cout<<endl<<"Listo!"<<endl;
}

string contrasena()
{
    string contr="";
    char a;

    while(true)
    {
        a=getch();

        if(a==13)
        {
            break;
        }

        contr+=a;
        cout<<"*";
    }

    return contr;
}