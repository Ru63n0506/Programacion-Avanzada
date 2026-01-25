#include <iostream>

using namespace std;

int main()
{
    
    int a;

    cout << "Ingresa un numero: ";
    cin>>a;

    if (a%2==0)
    {
        cout << "El numero es par" << endl;
    }
    else
    {
        cout << "El numero es impar" << endl;
    }

    if (a<0)
    {
        cout << "El numero es negativo" << endl;
    }
    else
    {
        cout << "El numero es positivo" << endl;
    }
    
    return 0;
}