#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    FILE *fd;
    char nombre[20];
    int edad;

    fd=fopen("prueba.txt","w");

    if(fd==NULL)
    {
        cout<<"No se pudo crear el archivo"<<endl;
    }
    else
    {
        cout<<"Se creo correctamente"<<endl;
    }

    cout<<"Proporciona el nombre:";
    cin.getline(nombre,20,'\n');
    fprintf(fd,"%s",nombre);

    cout<<"Proporciona la edad:";
    cin>>edad;
    fprintf(fd,"%i",edad);

    fclose(fd);

    return 0;
}