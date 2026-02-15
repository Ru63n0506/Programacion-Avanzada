#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream archivo;

    archivo.open("datos.txt");

    if(!archivo)
    {
        cout<<"No se abrio el archivo"<<endl;

        archivo<<"Hola mundo jsjs";
    }


    return 0;
}