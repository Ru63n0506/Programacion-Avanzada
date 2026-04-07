#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct autobus
{
    int numViaje;
    string destino;
    string horaSal;
    string nomChofer;
    int numAnden;

    autobus* derecha;
    autobus* izquierda;
};

autobus* crearNodo(int nViaje)
{
    time_t ahora = time(0);
    tm* tiempo = localtime(&ahora);
    
    
    autobus* nuevo = new autobus();
    nuevo->numViaje=nViaje;
    cout<<"Ingresa el destino: ";
    getline(cin,nuevo->destino);
    nuevo->horaSal=to_string(tiempo->tm_hour)+":"+to_string(tiempo->tm_min)+":"+to_string(tiempo->tm_sec);
    cout<<"Ingresa el nombre del chofer: ";
    getline(cin,nuevo->nomChofer);
    cout<<"Ingresa el numero del anden: ";
    cin>>nuevo->numAnden;
    nuevo->izquierda=NULL;
    nuevo->derecha=NULL;

    ofstream archivo;

    archivo.open("camiones.txt");

    if(!archivo)
    {
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }

    cout<<"Se creo correctamente"<<endl;

    archivo<<"----------------"<<endl;
    archivo<<"Numero de viaje: "<<nuevo->numViaje<<endl;
    archivo<<"Destino: "<<nuevo->destino<<endl;
    archivo<<"Hora de salida: "<<nuevo->horaSal<<endl;
    archivo<<"Nombre del chofer: "<<nuevo->nomChofer<<endl;
    archivo<<"Numero de anden: "<<nuevo->numAnden<<endl;
    archivo<<"----------------"<<endl;

    archivo.close();

    return nuevo;
}

autobus* insertar(autobus* raiz, int nViaje)
{
    if(raiz == NULL)
    {
        return crearNodo(nViaje);
    }

    if(nViaje<raiz->numViaje)
    {
        raiz->izquierda=insertar(raiz->izquierda,nViaje);
    }
    else if(nViaje>raiz->numViaje)
    {
        raiz->derecha=insertar(raiz->derecha,nViaje);
    }

    return raiz;
}

int buscar(autobus* raiz, int bViaje)
{
    if(raiz==NULL)
    {
        return 0;
    }
    
    if(raiz->numViaje==bViaje)
    {
        return 1;
    }

    if(bViaje<raiz->numViaje)
    {
        return buscar(raiz->izquierda,bViaje);
    }
    else
    {
        return buscar(raiz->derecha,bViaje);
    }
}

int main()
{
    int opc,nViaje,bViaje;
    string dest,nChofer;

    autobus* raiz=NULL;

    do
    {
        cout<<"+-- Ruta --+"<<endl;
        cout<<"1. Alta de viaje"<<endl;
        cout<<"2. Buscar viaje"<<endl;
        cout<<"3. Modificar viaje"<<endl;
        cout<<"4. Eliminar viaje"<<endl;
        cout<<"5. Imprimir viajes"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"+----------+"<<endl;
        cout<<"Ingresa una opcion: ";
        cin>>opc;

        switch(opc)
        {
            case 1:

                cout<<"+-- Alta de Viaje --+"<<endl;
                cout<<"Ingrese el numero de viaje:";
                cin>>nViaje;
                raiz=insertar(raiz,nViaje);

                break;

            case 2:

                cout<<"+-- Buscar Viaje --+"<<endl;
                cout<<"Ingrese el numero de viaje a buscar:";
                cin>>bViaje;
                if(buscar(raiz,bViaje))
                {
                    cout<<"Autobus encontrado!"<<endl;
                }
                else
                {
                    cout<<"Autobus no encontrado!"<<endl;
                }

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            default:

                cout<<"Gracias por ocupar el sistema!"<<endl;

                break;
        }

    } while (opc!=6);
    

    time_t ahora = time(0);
    tm* tiempo = localtime(&ahora);
    
    cout<<"Hola"<<tiempo->tm_hour<<":"<<tiempo->tm_min<<":"<<tiempo->tm_sec<<endl;

    return 0;
}