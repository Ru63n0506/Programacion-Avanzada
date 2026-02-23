#include <iostream>

using namespace std;

int main()
{
    int arr[10],i,aux,j,opc;

    cout<<"Ingresa tus 10 numeros:"<<endl;

    for(i=0;i<10;i++)
    {
        cin>>arr[i];
    }

    do
    {
        cout<<"1. Ordenar ascendentemente"<<endl;
        cout<<"2. Ordenar descendentemente jaja"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingresa opc:";
        cin>>opc;

        switch(opc)
        {
            case 1:

                for(i=0;i<9;i++)
                {
                    for(j=0;j<9-i;j++)
                    {
                        if(arr[j]>arr[j+1])
                        {
                            aux=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=aux;
                        }
                    }
                }

                cout<<"Arreglo ordenado asc:"<<endl;

                for(i=0;i<10;i++)
                {
                    cout<<arr[i]<<endl;
                }

                break;

            case 2:

                for(i=0;i<10;i++)
                {
                    for(j=0;j<10;j++)
                    {
                        if(arr[j]<arr[j+1])
                        {
                            aux=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=aux;
                        }
                    }
                }

                cout<<"Arreglo ordenado desc:"<<endl;

                for(i=0;i<10;i++)
                {
                    cout<<arr[i]<<endl;
                }
                
                break;

            default:

                cout<<"Gracias por ocupar el sistema!"<<endl;

                break;

        }

    }while(opc!=3);

    return 0;
}