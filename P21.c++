#include <iostream>
#include <string>

using namespace std;

struct estudiante
{
    int id;
    string nombre_completo;
    int semestre;
    float promedio;
};

void menup()
{
    cout<<"--Menu--"<<endl;
    cout<<"1.Altas"<<endl;
    cout<<"2.Eliminar"<<endl;
    cout<<"3.Modificar"<<endl;
    cout<<"4.Consultar"<<endl;
    cout<<"5.Imprimir"<<endl;
    cout<<"6.Salir"<<endl;
    cout<<"--Selecciona una opc:";
}

void menumod()
{
    cout<<"Que campo deseas modificar?"<<endl;
    cout<<"1.Semestre"<<endl;
    cout<<"2.Promedio"<<endl;
    cout<<"Ingresa tu opcion:";
}

void menuconfirmacionbajas()
{
    cout<<"Estas seguro que quieres eliminar al alumno anterior?"<<endl;
    cout<<"1.Si"<<endl;
    cout<<"2.No"<<endl;
    cout<<"Ingresa tu opcion:";
}

void listaregistros(estudiante arr[], int contest)
{
    cout<<"+----------------+"<<endl;
    cout<<"Lista de Registros"<<endl;
    cout<<"+----------------+"<<endl;
                
    for(int i=0;i<contest;i++)
    {
        cout<<"Id:"<<arr[i].id<<endl;
        cout<<"Nombre:"<<arr[i].nombre_completo<<endl;
        cout<<"+--------------+"<<endl;                   
    }
}

void imprimir(estudiante arr[], int contest)
{
    cout<<"--------------"<<endl;
    cout<<"+++Imprimir+++"<<endl;
    cout<<"--------------"<<endl;
                
    for(int i=0;i<contest;i++)
    {
        cout<<"Id:"<<arr[i].id<<endl;
        cout<<"Nombre:"<<arr[i].nombre_completo<<endl;
        cout<<"Semestre:"<<arr[i].semestre<<endl;
        cout<<"Promedio:"<<arr[i].promedio<<endl;
        cout<<"----------------"<<endl;                   
    }
}

void imprimirdatosid(estudiante arr[],int contest,int id)
{
    for(int i=0;i<contest;i++)
    {
        if(arr[i].id==id)
        {
            cout<<"----------------"<<endl; 
            cout<<"Id:"<<arr[i].id<<endl;
            cout<<"Nombre:"<<arr[i].nombre_completo<<endl;
            cout<<"Semestre:"<<arr[i].semestre<<endl;
            cout<<"Promedio:"<<arr[i].promedio<<endl;
            cout<<"----------------"<<endl;
            return;
        }
    }

    cout<<"Alumno no encontrado!"<<endl;
}

void recorridobajas(int &contest, int opceli,estudiante arr[])
{
    for(int i=0;i<contest;i++)
    {
        if(arr[i].id==opceli)
        {
            for(int a=i;a<contest-1;a++)
            {
                arr[a].id=arr[a+1].id;
                arr[a].nombre_completo=arr[a+1].nombre_completo;
                arr[a].promedio=arr[a+1].promedio;
                arr[a].semestre=arr[a+1].semestre;
            }

            contest--;
            cout<<"Alumno eliminado correctamente!"<<endl;
        }
    }
}

void encabezadoconsultar()
{
    cout<<"-------------"<<endl;
    cout<<"++Consultar++"<<endl;
    cout<<"-------------"<<endl;
}

void encabezadomodificar()
{
    cout<<"-------------"<<endl;
    cout<<"+-Modificar-+"<<endl;
    cout<<"-------------"<<endl;
}

void encabezadobajas()
{
    cout<<"+++++++++++"<<endl;
    cout<<"---Bajas---"<<endl;
    cout<<"+++++++++++"<<endl;
}

int main()
{
    int i,opc,contest=0,opcconsul,opcmod,opcmod2,nvsemes,opceli,desieli,a;
    struct estudiante arr[10];
    float nvprom;

    do
    {
        menup();
        cin>>opc;

        switch (opc)
        {
            case 1:
            
                cout<<"---Altas---"<<endl;

                arr[contest].id=contest+1;
                cout<<"ID:"<<arr[contest].id<<endl;

                cout<<"Nombre completo:";
                cin.ignore();
                getline (cin,arr[contest].nombre_completo);

                cout<<"Semestre:";
                cin>>arr[contest].semestre;

                cout<<"Promedio:";
                cin>>arr[contest].promedio;

                cout<<"------------"<<endl;
                cout<<"Alumno agregado exitosamente!"<<endl;
                cout<<"------------"<<endl;

                contest++;
            
                break;

            case 2:

                encabezadobajas();

                cout<<"Ingresa el ID del alumno a eliminar:"<<endl;
                cin>>opceli;

                imprimirdatosid(arr,contest,opceli);

                menuconfirmacionbajas();
                cin>>desieli;

                if(desieli==1)
                {
                    recorridobajas(contest,opceli,arr);
                }
                else
                {
                    cout<<"Va pues!";
                    break;
                }
                
            
                break;

            case 3:

                encabezadomodificar();
            
                listaregistros(arr,contest);

                cout<<"Ingresa el ID del alumno a modificar:"<<endl;
                cin>>opcmod;

                imprimirdatosid(arr,contest,opcmod);

                menumod();
                cin>>opcmod2;

                switch (opcmod2)
                {
                    case 1:

                        for(i=0;i<contest;i++)
                        {
                            if (arr[i].id==opcmod)
                            {
                                cout<<"----------------"<<endl; 
                                cout<<"Semestre:"<<arr[i].semestre<<endl;
                                cout<<"----------------"<<endl;
                                cout<<"Valor actualizado:";
                                cin>>nvsemes;
                                arr[i].semestre=nvsemes;
                            }                 
                        }

                        cout<<"Valor actualizado con exito!!"<<endl;

                        break;

                    case 2:

                        for(i=0;i<contest;i++)
                        {
                            if (arr[i].id==opcmod)
                            {
                                cout<<"----------------"<<endl; 
                                cout<<"Promedio:"<<arr[i].promedio<<endl;
                                cout<<"----------------"<<endl;
                                cout<<"Valor actualizado:";
                                cin>>nvprom;
                                arr[i].promedio=nvprom;
                            }                 
                        }

                        cout<<"Valor actualizado con exito!!"<<endl;

                        break;
                
                    default:

                        cout<<"Modificaciones realizadas!"<<endl;

                        break;
                }

                break;

            case 4:

                encabezadoconsultar();

                listaregistros(arr,contest);

                cout<<"Ingresa el ID del alumno a consultar:"<<endl;
                cin>>opcconsul;

                imprimirdatosid(arr,contest,opcconsul);

                break;

            case 5:

                imprimir(arr,contest);

                break;
        
            default:
                break;
        }

    } while (opc!=6);
    
    return 0;
}