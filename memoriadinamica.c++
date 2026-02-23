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

    proveedor *aux = pila;

    while(aux!=NULL)
    {
        cout<<"Clave:";
        cout<<aux->clave<<endl;
        cout<<"Nombre:";
        cout<<aux->nombre<<endl;
        cout<<"Articulo:";
        cout<<aux->articulo<<endl;
        cout<<"Precio:";
        cout<<aux->precio<<endl;

        aux=aux->sig;
    }

    proveedor *prev=NULL;

    
    return 0;
}

