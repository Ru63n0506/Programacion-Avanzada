#include <iostream>
#include <string>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

int main()
{
    nodo *pila = NULL;

    for(int i=0;i<5;i++)
    {
        nodo *nuevo = new nodo();

        cout<<"Ingresa un numero:";
        cin>>nuevo->dato;

        nuevo->sig=pila;
        pila=nuevo;
    }

    cout<<"Imprimir pila->"<<endl;

    nodo *aux = pila;

    while(aux!=NULL)
    {
        cout<<"Dato:";
        cout<<aux->dato<<endl;

        aux=aux->sig;
    }

    nodo *prev=NULL;


    
    return 0;
}