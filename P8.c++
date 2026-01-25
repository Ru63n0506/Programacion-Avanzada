#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, opc, res;

    cout << "Ingresa el numero:";
    cin >> a;

    cout << "Operaciones:" << endl;
    cout << "1. Cubo del numero" << endl;
    cout << "2. Raiz cuadrada del numero" << endl;
    cout << "3. Salir" << endl;
    cout << "Selecciona alguna opcion:";
    cin >> opc;

    switch (opc)
    {
        case 1:
        
            res = pow(a,2);

            cout << "El resultado de la operacion es:" << res << endl;

            break;

        case 2:

            res = sqrt(a);

            cout << "El resultado de la operacion es:" << res << endl;
            
            break;

        default:
            
            cout << "Gracias por ocupar el sistema" << endl;
            
            break;
    }
    
    return 0;
}