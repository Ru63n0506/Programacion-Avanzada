#include <iostream>
#include <windows.h>
#include <C:\Users\Lorena Reyes\OneDrive\Escritorio\PROGRAMAS\PRUEBA\Programacion-Avanzada\cuadro.h>

using namespace std;

void gotoxy(int x, int y);

int main()
{
    int i;

    for (i = 1; i <= 20; i++)
    {
        gotoxy(i, 2);
        cout << "*";
    }

    for (i = 1; i <= 20; i++)
    {
        gotoxy(i, 6);
        cout << "*";
    }

    for (i = 2; i <= 6; i++)
    {
        gotoxy(1, i);
        cout << "*";
    }

    for (i = 2; i <= 6; i++)
    {
        gotoxy(20, i);
        cout << "*";
    }

    cin.get();
    return 0;
}