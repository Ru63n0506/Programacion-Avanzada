#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo* sig;
};

int main()
{
    cout<<"Crear nodos->"<<endl;

    nodo* frente=NULL;
    nodo* fin=NULL;

    for(int i=0;i<5;i++)
    {
        nodo* nuevo = new nodo();

        cin>>nuevo->dato;

        nuevo->sig=NULL;

        if(frente==NULL)
        {
            frente=nuevo;
            fin=nuevo;
        }
        else 
        {
            fin->sig=nuevo;
            fin=nuevo;
        }
    }

    cout<<"Enlistar nodos->"<<endl;

    nodo* aux = frente;

    while(aux!=NULL)
    {
        cout<<aux->dato<<endl;
        aux=aux->sig;
    }

    cout<<"Eliminar primer nodo->"<<endl;

    if(frente!=NULL)
    {
        nodo* borrar = frente;
        frente = frente->sig;
        delete borrar;
    }

    aux = frente;

    cout<<"Enlistar nodos->"<<endl;

    while(aux!=NULL)
    {
        cout<<aux->dato<<endl;
        aux=aux->sig;
    }
    
    return 0;
}