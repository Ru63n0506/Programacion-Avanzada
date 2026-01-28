#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i,num,cuad,sum=0;
    
    for (i=0;i<10;i++)
    {
        cout << "Ingresa el numero " << i+1 << ": ";
        cin>>num;

        if (num>0)
        {
            cout<<"Numero valido"<<endl;
            cuad=pow(num,2);
            sum=sum+cuad;
        }
        else
        {
            cout<<"Numero invalido"<<endl;
        }
    }

    cout<<"La suma de los cuadrados de los numeros ingresados es: " << sum << endl;
    return 0;
}