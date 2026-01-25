#include <iostream>

using namespace std;

int main()
{
    int a,b,c;

    cout << "Ingresa el numero a: ";
    cin >> a;
    cout << "Ingresa el numero b: ";
    cin >> b;
    cout << "Ingresa el numero c: ";
    cin >> c;

    if (a>b&&a>c)
    {
        cout << "El numero a = " << a << " es mayor a los demas" << endl;
    }
    else if (b>a&&b>c)
    {
        cout << "El numero b = " << b << " es mayor a los demas" << endl;
    }
    else if (c>a&&c>b)
    {
        cout << "El numero c = " << c << " es mayor a los demas" << endl;
    }
}