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
    int opc,claelim;

    proveedor *pila = NULL;

    do
    {
        cout<<"+--Menu--+"<<endl;
        cout<<"1.Altas"<<endl;
        cout<<"2.Imprimir"<<endl;
        cout<<"3.Eliminar"<<endl;
        cout<<"4.Salir"<<endl;
        cout<<"Ingresa tu opcion:";
        cin>>opc;

        switch(opc)
        {
            case 1:
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

            default:

                cout<<"Opcion equivocada"<<endl;
            
                break;


        }
    }while(opc!=4);
    return 0;
}