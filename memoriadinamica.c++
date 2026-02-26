//Generar 5 elementos en una pila
#include <iostream>
#include <string>
using namespace std;

struct proveedor
{
    int clave;
    string nombre;
    string articulo;
    float precio;
    proveedor *sig;
};

int main()
{
    proveedor *pila=NULL;

    for(int i=0;i<5;i++)
    {
        proveedor *nuevo = new proveedor();

        cout<<"Clave:";
        cin>>nuevo->clave;
        cout<<"Nombre:";
        cin>>nuevo->nombre;
        cout<<"Articulo:";
        cin>>nuevo->articulo;
        cout<<"Precio:";
        cin>>nuevo->precio;
        
        nuevo->sig=pila;

        pila=nuevo;
    }

    cout<<"Imprimir pila->"<<endl;

    proveedor *aux1 = pila;

    while(aux1!=NULL)
    {
        cout<<"Clave:";
        cout<<aux1->clave<<endl;
        cout<<"Nombre:";
        cout<<aux1->nombre<<endl;
        cout<<"Articulo:";
        cout<<aux1->articulo<<endl;
        cout<<"Precio:";
        cout<<aux1->precio<<endl;

        aux1=aux1->sig;
    }

    int claelim;

    cout<< "Eliminar dato ->"<<endl;

    cout<< "Ingresa la clave que desees borrar:";
    cin>>claelim;

    proveedor *aux2 = NULL;

    while(aux1 != NULL)
    {
        if(aux1->clave == claelim)
        {
            if(aux2 == NULL)
            {
                pila = aux1->sig;
            }
            else
            {
                aux2->sig = aux1->sig;
            }

            delete aux1;
            cout << "Elemento eliminado correctamente." << endl;
            break;
        }

        aux2 = aux1;
        aux1 = aux1->sig;
    }

    if(aux1 == NULL)
    {
        cout << "No se encontró la clave." << endl;
    }
    
    return 0;
}

