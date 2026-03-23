#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    string nombre;
    string telefono;
    nodo* sig;
};

int main()
{
    int i, opc, bandera=0;
    string nomBaja, busConsul, busMod, telMod;
    nodo* nuevo;
    nodo* lista=NULL;
    nodo* fin;
    nodo* aux1;
    nodo* actual;
    nodo* anterior=NULL;

    do
    {
        system("cls");

        cout<<"1.Alta"<<endl;
        cout<<"2.Baja"<<endl;
        cout<<"3.Cambios"<<endl;
        cout<<"4.Consulta"<<endl;
        cout<<"5.Imprimir"<<endl;
        cout<<"6.Salir"<<endl;
        cout<<"------------"<<endl;
        cout<<"Ingresa opcion:"<<endl;
        cin>>opc;
        cin.ignore();

        switch(opc)
        {
            case 1:

                system("cls");

                nuevo = new nodo();
                nuevo->sig = NULL;

                cout<<"Alta en agenda->"<<endl;
                cout<<"Ingresa nombre: "<<endl;
                getline(cin,nuevo->nombre);
                cout<<"Ingresa su telefono: "<<endl;
                cin>>nuevo->telefono;

                if(lista==NULL)
                {
                    lista=nuevo;
                    fin=nuevo;
                }
                else
                {
                    fin->sig=nuevo;
                    fin=nuevo;
                }

                cout<<"Contacto agregado exitosamente!"<<endl;

                system("pause");

                break;

            case 2:

                system("cls");

                cout<<"Eliminar->"<<endl;

                if(lista==NULL)
                {
                    cout<<"No hay datos para eliminar"<<endl;
                }
                else 
                {
                    cout<<"Agenda"<<endl;
                    cout<<"----------------"<<endl;

                    aux1=lista;

                    while(aux1!=NULL)
                    {
                        cout<<"Nombre:";
                        cout<<aux1->nombre<<endl;
                        cout<<"Numero:";
                        cout<<aux1->telefono<<endl;
                        cout<<"----------------"<<endl;

                        aux1=aux1->sig;
                    }

                    cout<<"A quien deseas eliminar:"<<endl;
                    cin>>nomBaja;
                    cin.ignore();

                    actual=lista;
                    anterior=NULL;
                    bandera=0;

                    while(actual!=NULL)
                    {
                        if(actual->nombre==nomBaja)
                        {
                            if(anterior==NULL)
                            {
                                lista=actual->sig;
                            }
                            else
                            {
                                anterior->sig=actual->sig;
                            }

                            if(actual==fin)
                            {
                                fin=anterior;
                            }

                            delete actual;
                            cout<<"Contacto eliminado!"<<endl;
                            bandera=1;
                            break;
                        }

                        anterior=actual;
                        actual=actual->sig;
                    }

                    if(bandera==0)
                    {
                        cout<<"Contacto no encontrado!"<<endl;
                    }
                }

                system("pause");
            
                break;

            case 3:

                system("cls");

                aux1=lista;

                cout<<"Cambios->"<<endl;
                cout<<"A quien vas a modificar?:";
                getline(cin,busMod);

                while(aux1!=NULL)
                {
                    if(busMod==aux1->nombre)
                    {
                        cout<<"-----------------"<<endl;
                        cout<<"Contacto"<<endl;
                        cout<<"-----------------"<<endl;
                        cout<<"Nombre: "<<aux1->nombre<<endl;
                        cout<<"Tel: "<<aux1->telefono<<endl;
                        cout<<"-----------------"<<endl;

                        cout<<"Cual es su numero nuevo?:"<<endl;
                        cin>>telMod;

                        aux1->telefono=telMod;

                        cout<<"Contacto modificado!"<<endl;
                    }

                    aux1=aux1->sig;
                }

                system("pause");

                break;

            case 4:

                system("cls");

                aux1=lista;

                cout<<"Consulta->"<<endl;
                cout<<"A quien buscas?:";
                getline(cin,busConsul);

                while(aux1!=NULL)
                {
                    if(busConsul==aux1->nombre)
                    {
                        cout<<"-----------------"<<endl;
                        cout<<"Contacto"<<endl;
                        cout<<"-----------------"<<endl;
                        cout<<"Nombre: "<<aux1->nombre<<endl;
                        cout<<"Tel: "<<aux1->telefono<<endl;
                        cout<<"-----------------"<<endl;
                        bandera=1;
                    }

                    aux1=aux1->sig;
                }

                if(bandera==0)
                {
                    cout<<"Contacto no encontrado!"<<endl;
                }
                else
                {
                    cout<<"Si estuvo jeje!"<<endl;
                }

                system("pause");

                break;

            case 5:

                system("cls");

                cout<<"Agenda"<<endl;
                cout<<"----------------"<<endl;

                aux1=lista;

                while(aux1!=NULL)
                {
                    cout<<"Nombre:";
                    cout<<aux1->nombre<<endl;
                    cout<<"Numero:";
                    cout<<aux1->telefono<<endl;
                    cout<<"----------------"<<endl;

                    aux1=aux1->sig;
                }

                system("pause");
            
                break;

            default:

                cout<<"Gracias por ocupar el sistema!"<<endl;

                system("pause");

                break;
        }

    }while(opc!=6);

    return 0;
}