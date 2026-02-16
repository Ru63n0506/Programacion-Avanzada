#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream archivo;

    char nombre[20];
    int edad;

    archivo.open("prueba.txt");

    if(!archivo)
    {
        cout<<"No se pudo crear el archivo"<<endl;
        return 1;
    }

    cout<<"Se creo correctamente"<<endl;

    cout<<"Proporciona el nombre:";
    cin.getline(nombre,20);

    archivo<<nombre<<endl;

    cout<<"Proporciona la edad:";
    cin>>edad;

    archivo<<edad<<endl;

    archivo.close();

    return 0;
}