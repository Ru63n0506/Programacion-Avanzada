#include <bits/stdc++.h>

using namespace std;

struct nodo
{
    int dato;
    nodo* sig;
};

int main()
{
    nodo* lista=NULL;
    nodo* fin=NULL;
    nodo* actual=NULL;
    nodo* aux1;
    nodo* aux2;

    int i,opc;

    do 
    {
        system("cls");

        cout<<"1.Lista ordenada"<<endl;
        cout<<"2.Lista desordenada"<<endl;
        cout<<"3.Salir"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Ingresa tu opcion:";
        cin>>opc;

        switch(opc)
        {
            case 1:

                for(i=0;i<5;i++)
                {
                    nodo* nuevo=new nodo();

                    cout<<"Crear nodo->"<<endl;

                    cout<<"Proporciona valor:";
                    cin>>nuevo->dato;

                    aux1=lista;

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

                actual=lista;

                while(actual!=NULL)
                {
                    cout<<actual->dato<<endl;
                    actual=actual->sig;
                }

                system("pause");

                break;

            case 2:


                for(i=0;i<5;i++)
                {
                    nodo* nuevo=new nodo();

                    cout<<"Crear nodo->"<<endl;

                    cout<<"Proporciona valor:";
                    cin>>nuevo->dato;

                    nuevo->sig=NULL;

                    if(lista==NULL)
                    {
                        lista=nuevo;
                    }
                    else
                    {
                        fin->sig=nuevo;
                    }
                    fin=nuevo;

                    cout<<"Elemento insertado correctamente!"<<endl;
                }

                cout<<"Imprimir->"<<endl;

                actual=NULL;

                actual=lista;

                while(actual!=NULL)
                {
                    cout<<actual->dato<<endl;
                    actual=actual->sig;
                }

                system("pause");

                break;

            default:

                cout<<"Gracias por ocupar el sistema!"<<endl;

                system("pause");

                break;
        }
    }while(opc!=3);
       
    return 0;
}