#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;
    float cuad;

    while (num!=0)
    {
        cout << "Ingresa un numero: " ;
        cin >>num;
        cuad=sqrt(num);
        cout << "La raiz del numero es: " << cuad <<endl;

    }

    cout<<"Lo siento, ingresaste 0."<<endl;
    cout<<"El programa a termiando"<<endl;
    return 0;
}