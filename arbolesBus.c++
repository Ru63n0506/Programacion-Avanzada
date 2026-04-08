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

    archivo.open("camiones.txt",ios::app);

    if(!archivo)
    {
        cout<<"No se pudo crear el archivo"<<endl;
        return NULL;
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

autobus* buscar(autobus* raiz, int bViaje)
{
    if(raiz==NULL)
    {
        return NULL;
    }
    
    if(raiz->numViaje==bViaje)
    {
        cout<<"+- Bus Encontrado -+"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Numero de viaje: "<<raiz->numViaje<<endl;
        cout<<"Destino: "<<raiz->destino<<endl;
        cout<<"Hora de salida: "<<raiz->horaSal<<endl;
        cout<<"Nombre del chofer: "<<raiz->nomChofer<<endl;
        cout<<"Numero de anden: "<<raiz->numAnden<<endl;
        cout<<"----------------"<<endl;
            
        return raiz;
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

autobus* minimo(autobus* raiz)
{
    while(raiz->izquierda!=NULL)
    {
        raiz=raiz->izquierda;
    }
    return raiz;
}

autobus* eliminar(autobus* raiz, int elimViaje)
{
    if(raiz==NULL)
    {
        return raiz;
    }

    if(elimViaje<raiz->numViaje)
    {
        raiz->izquierda=eliminar(raiz->izquierda,elimViaje);
    }
    else if(elimViaje>raiz->numViaje)
    {
        raiz->derecha=eliminar(raiz->derecha,elimViaje);
    }
    else
    {
        if(raiz->izquierda==NULL && raiz->derecha==NULL)
        {
            delete raiz;
            return NULL;
        }
        else if(raiz->izquierda==NULL)
        {
            autobus* temp = raiz->derecha;
            delete raiz;
            return temp;
        }
        else if(raiz->derecha==NULL)
        {
            autobus* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }

        autobus* temp=minimo(raiz->derecha);

        raiz->numViaje=temp->numViaje;
        raiz->destino=temp->destino;
        raiz->horaSal=temp->horaSal;
        raiz->nomChofer=temp->nomChofer;
        raiz->numAnden=temp->numAnden;
        
        raiz->derecha=eliminar(raiz->derecha, temp->numViaje);
    }               
    return raiz;
}

autobus* modificar(autobus* raiz, int modViajeViejo)
{
    autobus* encontrado = buscar(raiz,modViajeViejo);
    
    if(encontrado != NULL)
    {
        int opcMod;

        cout<<"+-- Modificar Autobus --+"<<endl;
        cout<<"1. Destino"<<endl;
        cout<<"2. Hora"<<endl;
        cout<<"3. Chofer"<<endl;
        cout<<"4. Anden"<<endl;
        cout<<"+-----------------------+"<<endl;
        cout<<"Ingresa una opcion: ";
        cin>>opcMod;
        cin.ignore();

        switch(opcMod)
        {
            case 1:

                cout<<"Ingresa el nuevo destino:";
                getline(cin,encontrado->destino);
                cout<<"Destino modificado exitosamente!"<<endl;

                break;

            case 2:

                cout<<"Ingresa la nueva hora (HH:MM:SS):";
                getline(cin,encontrado->horaSal);
                cout<<"Hora modificada exitosamente!"<<endl;

                break;

            case 3:

                cout<<"Ingresa el nuevo nombre del chofer:";
                getline(cin,encontrado->nomChofer);
                cout<<"Chofer modificado exitosamente!"<<endl;

                break;

            case 4:

                cout<<"Ingresa el nuevo numero de anden:";
                cin>>encontrado->numAnden;
                cout<<"Numero de anden modificado correctamente!"<<endl;

                break;

            default:

                cout<<"De nada vuelva prontooo!"<<endl;

                break;
        }
    }
    else
    {
        cout<<"Autobus no encontrado"<<endl;
    }

    return raiz;
}

void imprimir(autobus* raiz)
{
    if(raiz==NULL)
    {
        return;
    }

    imprimir(raiz->izquierda);

    cout<<"-------------------"<<endl;
    cout<<"Numero de Viaje:"<<raiz->numViaje<<endl;
    cout<<"Hora de Salida:"<<raiz->horaSal<<endl;
    cout<<"Destino:"<<raiz->destino<<endl;
    cout<<"Chofer:"<<raiz->nomChofer<<endl;
    cout<<"Anden:"<<raiz->numAnden<<endl;
    
    imprimir(raiz->derecha);
}

int main()
{
    int opc,nViaje,bViaje,modViajeViejo,elimViaje;
    string dest,nChofer;

    autobus* raiz=NULL;

    do
    {
        system("cls");

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

                system("cls");

                cout<<"+-- Alta de Viaje --+"<<endl;
                cout<<"Ingrese el numero de viaje:";
                cin>>nViaje;
                cin.ignore();
                raiz=insertar(raiz,nViaje);

                system("pause");

                break;

            case 2:

                system("cls");

                cout<<"+-- Buscar Viaje --+"<<endl;
                cout<<"Ingrese el numero de viaje a buscar:";
                cin>>bViaje;
                cin.ignore();
                if(!buscar(raiz,bViaje))
                {
                    cout<<"Autobus no encontrado!"<<endl;
                }

                system("pause");

                break;

            case 3:

                system("cls");

                cout<<"+-- Modificar Viaje --+"<<endl;
                cout<<"Ingresa el numero de viaje a modificar:";
                cin>>modViajeViejo;
                raiz=modificar(raiz,modViajeViejo);

                system("pause");

                break;

            case 4:

                system("cls");

                cout<<"+-- Eliminar Viaje --+"<<endl;
                cout<<"Ingresa el numero de viaje que quieras eliminar:";
                cin>>elimViaje;
                raiz=eliminar(raiz,elimViaje);
                cout<<"Viaje eliminado con exito!"<<endl;

                system("pause");

                break;

            case 5:

                system("cls");

                cout<<"+-- Imprimir Viajes --+"<<endl;
                imprimir(raiz);

                system("pause");

                break;

            default:

                cout<<"Gracias por ocupar el sistema!"<<endl;

                break;
        }

    } while (opc!=6);

    return 0;
}