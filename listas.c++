#include <bits/stdc++.h>

using namespace std;

struct nodo
{
    int dato;
    nodo* sig;
};

int main()
{
    int i;

    nodo* lista=NULL;

    for(i=0;i<5;i++)
    {
        nodo* nuevo=new nodo();

        cout<<"Crear nodo->"<<endl;

        cout<<"Proporciona valor:";
        cin>>nuevo->dato;

        nodo* aux1=lista;
        nodo* aux2;

        //Bloque que ordena y busca donde queda bien el nuevo valor en la lista
        while((aux1!=NULL)&&(aux1->dato<nuevo->dato))
        {
            aux2=aux1;
            aux1=aux1->sig;
        }

        if(lista == aux1)
        {
            lista=nuevo;
        }
        else
        {
            aux2->sig=nuevo;
        }

        nuevo->sig=aux1;

        cout<<"Elemento insertado correctamente!"<<endl;

    }

    cout<<"Imprimir->"<<endl;

    nodo* actual=NULL;

    actual=lista;

    while(actual!=NULL)
    {
        cout<<actual->dato<<endl;
        actual=actual->sig;
    }
    
    return 0;
}