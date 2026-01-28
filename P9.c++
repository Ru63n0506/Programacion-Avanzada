#include <iostream>

using namespace std;

int main()
{
    int i,num[5],acum=0;
    float prom;

    for(i=0;i<5;i++)
    {
        cout << "Ingresa el numero " << i+1 << ":" ;
        cin >> num[i];
        acum=acum+num[i];
        prom=acum/5;
    }

    prom=acum/5;
    cout<<"El promedio es igual a:"<<prom<<endl;

    if (prom>=7)
    {
        cout<<"Alumno aprobado"<<endl;
    }
    else
    {
        cout<<"Alumno reprobado"<<endl;
    }
    
    return 0;
}