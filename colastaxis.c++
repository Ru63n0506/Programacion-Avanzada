#include <bits/stdc++.h>

using namespace std;

struct taxi
{
    int numLlegada;
    string placa;
    string nomChofer;

    int dia,mes,anio,hora,minutos,segundos;
    
    taxi* sig;
};

int main()
{
    int cont=0,opc;
    taxi* frente=NULL;
    taxi* fin=NULL;

    do
    {
        cout<<"Bienvenido a Taxis La Central"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1. Entrada de taxis"<<endl;
        cout<<"2. Mostrar registros"<<endl;
        cout<<"3. Salida de taxi"<<endl;
        cout<<"4. Buscar taxi"<<endl;
        cout<<"5. Modificar taxi"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Ingresa tu opcion:";
        cin>>opc;
        cin.ignore(); // Limpiar el buffer

        switch(opc)
        {
            case 1:
            {
                cout<<"Crear taxis->"<<endl;

                taxi* nuevo = new taxi();

                nuevo->numLlegada=cont+1;
                cout<<"Ingresa la placa del taxi:";
                getline(cin,nuevo->placa);
                cout<<"Ingresa el nombre del chofer:";
                getline(cin,nuevo->nomChofer);

                time_t ahora = time(0);
                tm* tiempo = localtime(&ahora);

                nuevo->dia=tiempo->tm_mday;
                nuevo->mes=tiempo->tm_mon+1;
                nuevo->anio=tiempo->tm_year + 1900;
                nuevo->hora=tiempo->tm_hour;
                nuevo->minutos=tiempo->tm_min;
                nuevo->segundos=tiempo->tm_sec;

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

                cont++;

                ofstream archivo("taxis.txt", ios::app);
                if(archivo.is_open())
                {
                    archivo << "Numero de Llegada: " << nuevo->numLlegada << endl;
                    archivo << "Placa: " << nuevo->placa << endl;
                    archivo << "Nombre del Chofer: " << nuevo->nomChofer << endl;
                    archivo << "Fecha: " << nuevo->dia << "/" << nuevo->mes << "/" << nuevo->anio << endl;
                    archivo << "Hora: " << nuevo->hora << ":" << nuevo->minutos << ":" << nuevo->segundos << endl;
                    archivo << endl;
                    archivo.close();
                    cout<<"Registro guardado correctamente!"<<endl;
                }
                else
                {
                    cout << "Error al abrir el archivo taxis.txt" << endl;
                }
            
                break;
            }

            case 2:
            {
                cout<<"Enlistar taxis->"<<endl;

                if(frente==NULL)
                {
                    cout<<"No hay taxis registrados."<<endl;
                }
                else
                {
                    taxi* aux = frente;

                    while(aux!=NULL)
                    {
                        cout<<"Num. Llegada:";
                        cout<<aux->numLlegada;
                        cout<<endl<<"Placas:";
                        cout<<aux->placa;
                        cout<<endl<<"Nom. Chofer:";
                        cout<<aux->nomChofer;
                        cout<<endl<<"Fecha Llegada:"<<endl;
                        cout << aux->dia << "/" << aux->mes << "/" << aux->anio << " ";
                        cout<<endl<<"Hora Llegada:"<<endl;
                        cout << aux->hora << ":" << aux->minutos << ":" << aux->segundos << endl;
                        aux=aux->sig;
                    }
                }
            
                break;
            }

            case 3:
            {
                cout<<"Salida de taxi->"<<endl;

                if(frente==NULL)
                {
                    cout<<"No hay taxis en espera."<<endl;
                }
                else
                {
                    int numEliminar;
                    cout<<"Ingresa el numero de llegada del taxi a eliminar: ";
                    cin>>numEliminar;
                    cin.ignore();

                    if(frente->numLlegada == numEliminar)
                    {
                        taxi* temp = frente;
                        frente = frente->sig;
                        if(frente == NULL)
                        {
                            fin = NULL;
                        }
                        cout<<"Taxi salido: "<<temp->placa<<" - "<<temp->nomChofer<<endl;
                        delete temp;
                    }
                    else
                    {
                        taxi* aux = frente;
                        bool encontrado = false;
                        while(aux->sig != NULL && aux->sig->numLlegada != numEliminar)
                        {
                            aux = aux->sig;
                        }
                        if(aux->sig != NULL)
                        {
                            taxi* temp = aux->sig;
                            aux->sig = temp->sig;
                            if(temp == fin)
                            {
                                fin = aux;
                            }
                            cout<<"Taxi salido: "<<temp->placa<<" - "<<temp->nomChofer<<endl;
                            delete temp;
                            encontrado = true;
                        }
                        if(!encontrado)
                        {
                            cout<<"Taxi con numero de llegada "<<numEliminar<<" no encontrado."<<endl;
                        }
                    }
                }
            
                break;
            }

            case 4:
            {
                cout<<"Buscar taxi->"<<endl;

                string buscar;
                cout<<"Ingresa la placa a buscar:";
                getline(cin,buscar);

                taxi* aux = frente;
                bool encontrado=false;

                while(aux!=NULL)
                {
                    if(aux->placa == buscar)
                    {
                        cout<<"Encontrado!"<<endl;
                        cout<<"Llegada:"<<aux->numLlegada<<endl;
                        cout<<"Placa:"<<aux->placa<<endl;
                        cout<<"Nom. Chofer:"<<aux->nomChofer<<endl;
                        encontrado=true;
                        break;
                    }
                    aux=aux->sig;
                }

                if(!encontrado)
                {
                    cout<<"Taxi no encontrado."<<endl;
                }
            
                break;
            }

            case 5:
            {
                cout<<"Modificar taxi->"<<endl;

                string placaBuscar;
                cout<<"Ingresa la placa del taxi a modificar:";
                getline(cin,placaBuscar);

                taxi* aux = frente;
                bool mod=false;

                while(aux!=NULL)
                {
                    if(aux->placa == placaBuscar)
                    {
                        cout<<"Modificando taxi con placa "<<aux->placa<<endl;
                        cout<<"Nuevo nombre del chofer:";
                        getline(cin,aux->nomChofer);
                        mod=true;
                        cout<<"Nombre modificado correctamente!"<<endl;
                        break;
                    }
                    aux=aux->sig;
                }

                if(!mod)
                {
                    cout<<"Taxi no encontrado."<<endl;
                }
            
                break;
            }

            case 6:
            {
                cout<<"Gracias por ocupar el sistema!"<<endl;
            
                break;
            }

            default:
            {
                cout<<"Opcion invalida."<<endl;
            
                break;
            }
        }
        
    } while (opc!=6);
    
    return 0;
}