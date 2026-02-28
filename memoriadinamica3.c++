#include <iostream>
#include <string>
#include <cstring>

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
    int opc,claelim,clabusq,opccamb,clanueva;
    string nomnuevo, artnuevo;
    float prenuevo;

    proveedor *pila = NULL;

    do
    {
        cout<<"+--Menu--+"<<endl;
        cout<<"1.Altas"<<endl;
        cout<<"2.Imprimir"<<endl;
        cout<<"3.Eliminar"<<endl;
        cout<<"4.Busqueda"<<endl;
        cout<<"5.Modificar"<<endl;
        cout<<"6.Salir"<<endl;
        cout<<"Ingresa tu opcion:";
        cin>>opc;

        switch(opc)
        {
            case 1:
            {
                cout<<"+--Altas--+"<<endl;

                proveedor *nuevo = new proveedor();

                cout<<"Clave:";
                cin>>nuevo->clave;
                cout<<"Nombre:";
                cin>>nuevo->nombre;
                cout<<"Articulo:";
                cin>>nuevo->articulo;
                cout<<"Precio:";
                cin>>nuevo->precio;
                
                nuevo->sig = pila;
                pila = nuevo;
            }
                break;

            case 2:
            {
                cout<<"Imprimir pila->"<<endl;

                proveedor *aux1 = pila;

                while(aux1 != NULL)
                {
                    cout<<"Clave:"<<aux1->clave<<endl;
                    cout<<"Nombre:"<<aux1->nombre<<endl;
                    cout<<"Articulo:"<<aux1->articulo<<endl;
                    cout<<"Precio:"<<aux1->precio<<endl;
                    cout<<"------------------"<<endl;

                    aux1 = aux1->sig;
                }
            }
                break;

            case 3:
            {
                cout<< "Eliminar dato ->"<<endl;
                cout<< "Ingresa la clave que desees borrar:";
                cin>>claelim;

                proveedor *aux1 = pila;
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
                        cout << "Elemento eliminado correctamente" << endl;
                        break;
                    }

                    aux2 = aux1;
                    aux1 = aux1->sig;
                }

                if(aux1 == NULL)
                {
                    cout << "No se encontro la clave" << endl;
                }
            }
                break;

            case 4:
            {
                cout<<"+--Busqueda--+"<<endl;
                cout<<"Ingresa la clave a buscar:";
                cin>>clabusq;

                proveedor* aux1;
                aux1=pila;

                while(aux1!=NULL)
                {
                    if((aux1->clave)==clabusq)
                    {
                        cout<<"Clave:"<<aux1->clave<<endl;
                        cout<<"Nombre:"<<aux1->nombre<<endl;
                        cout<<"Articulo:"<<aux1->articulo<<endl;
                        cout<<"Precio:"<<aux1->precio<<endl;

                        break;
                    }
                    aux1=aux1->sig;
                }
            }
                break;

            case 5:
            {
                cout<<"+--Modificar--+"<<endl;

                proveedor* aux1=NULL;

                while(aux1!=NULL)
                {
                    if((aux1->clave)==clabusq)
                    {
                        cout<<"Clave:"<<aux1->clave<<endl;
                        cout<<"Nombre:"<<aux1->nombre<<endl;
                        cout<<"Articulo:"<<aux1->articulo<<endl;
                        cout<<"Precio:"<<aux1->precio<<endl;
                        cout<<"----------------"<<endl;
                    }
                    aux1=aux1->sig;
                }

                int clamod;

                cout<<"Ingresa la clave a modificar:";
                cin>>clamod;

                proveedor* aux2=NULL;

                aux1=pila;

                while(aux1!=NULL)
                {
                    if((aux1->clave)==clamod)
                    {
                        aux2=aux1;

                        break;
                    }
                    aux1=aux1->sig;
                }

                cout<<"-----------------"<<endl;
                cout<<"1. Nombre"<<endl;
                cout<<"2. Articulo"<<endl;
                cout<<"3. Precio"<<endl;
                cout<<"Ingresa que deseas cambiar:";
                cin>>opccamb;

                switch(opccamb)
                {
                    case 1:

                        cout<<"Ingresa el nuevo valor:";
                        cin>>nomnuevo;

                        aux2->nombre=nomnuevo;

                        cout<<"Valor actualizado";

                        break;

                    case 2:

                        cout<<"Ingresa el nuevo valor:";
                        cin>>artnuevo;

                        aux2->articulo=artnuevo;

                        cout<<"Valor actualizado";

                        break;

                    case 3:

                        cout<<"Ingresa el nuevo valor:";
                        cin>>prenuevo;

                        aux2->precio=prenuevo;

                        cout<<"Valor actualizado";

                        break;

                    default:

                        cout<<"Opcion erronea!"<<endl;
                        
                        break;
                }
            
            }
                break;

            default:

                cout<<"Opcion equivocada"<<endl;
            
                break;

        }
    }while(opc!=6);

    cout<<"Gracias por ocupar el sistema!!"<<endl;

    return 0;
}