    #include <iostream>
    #include <string.h>
    #include <windows.h>
    #include <conio.h>
    #include <C:\Users\Lorena Reyes\OneDrive\Escritorio\PROGRAMAS\PRUEBA\Programacion-Avanzada\cuadro.h>
    #include <fstream>

    using namespace std;

    struct paciente
    {
        int id;
        string nombre;
        string diagnostico;
        float pago;
    };

    int main()
    {
        paciente pacientes[10];

        int i=0,tam=8,o=0,opc,contador=0,opcelim,opcelim2,total=0,sigID=1,opcbusc,idbusc,idbuscbusc,bandera,pos,cambid,opscamb,nuevPag,id,pago,opclist;
        char a,contr[100],contra1[9]="holahola";
        string nombrebusc,nuevNom,nuevDiag,nombre,diagnostico;
        ofstream archivoesc;
        ifstream archivolec;

        for(i=0;i<30;i++)
        {
            gotoxy(i,2);
            cout<<"#";
        }

        for(i=0;i<30;i++)
        {
            gotoxy(i,6);
            cout<<"#";
        }

        for(i=3;i<6;i++)
        {
            gotoxy(0,i);
            cout<<"#";
        }

        for(i=3;i<6;i++)
        {
            gotoxy(29,i);
            cout<<"#";
        }

        gotoxy(2,4);
        cout<<"Programador: Ruben Carmona";

        for(i=0;i<2;i++)
        {
            Beep(800, 120);
            Beep(800, 120);
            Beep(1000, 250);
        }

        gotoxy(0,8);

        cout<<"Cargando..."<<endl;

        for(i=0;i<15;i++)
        {
            cout<<"+";
            Sleep(30);
            Beep(50,500);
        }

        cout<<endl<<"Listo!"<<endl;

        cout<<endl<<"Bienvenido al sistema"<<endl;

        cout<<"Ingresa la contra: ";

        while(a!=13)
        {
            a=getch();
            cout<<"*";

            if(a!=13)
            {
                contr[o]=a;
                o++;
            }
        }

        if(strlen(contr)<=tam)
        {
            if(strcmp(contr,contra1)==0)
            {
                do
                {
                    system("cls");

                    cout<<"Bienvenido al menu!!"<<endl;

                    cout<<"1. Alta"<<endl;
                    cout<<"2. Imprimir"<<endl;
                    cout<<"3. Borrar"<<endl;
                    cout<<"4. Buscar"<<endl;
                    cout<<"5. Cambios"<<endl;
                    cout<<"6. Salir"<<endl;
                    cout<<"Ingresa la opcion:";
                    cin>>opc;

                    switch(opc)
                    {
                        case 1:

                            system("cls");

                            cout<<"+-- Altas --+"<<endl;

                            pacientes[contador].id=sigID;
                            cout<<"ID: "<<pacientes[contador].id<<endl;

                            cout<<"Nombre:";
                            cin>>pacientes[contador].nombre;

                            cout<<"Diagnostico:";
                            cin>>pacientes[contador].diagnostico;

                            cout<<"Pago:";
                            cin>>pacientes[contador].pago;

                            cout<<"Paciente ingresado correctamente!"<<endl;

                            archivoesc.open("pacientes.txt",ios::app);

                            if(!archivoesc)
                            {
                                cout<<"No se pudo crear el archivo"<<endl;
                                return 1;
                            }

                            cout<<"Se creo correctamente"<<endl;

                            archivoesc<<pacientes[contador].id<<" ";
                            archivoesc<<pacientes[contador].nombre<<" ";
                            archivoesc<<pacientes[contador].diagnostico<<" ";
                            archivoesc<<pacientes[contador].pago<<endl;

                            archivoesc.close();

                            sigID++;
                            total++;
                            contador++;

                            system("pause");

                            break;

                        case 2:

                            system("cls");

                            cout<<"+-- Imprimir --+"<<endl;

                            cout<<"1.Struct"<<endl;
                            cout<<"2.Archivo"<<endl;

                            cout<<"Desde donde deseas imprimir:";
                            cin>>opclist;

                            switch(opclist)
                            {
                                case 1:

                                    cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                    cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                                    
                                    for(i=0;i<total;i++)
                                    {
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| "<<pacientes[i].id<<"  | "<<pacientes[i].nombre<<"\t"<<" | "<<pacientes[i].diagnostico<<"\t"<<"| "<<pacientes[i].pago<<"\t"<<"|"<<endl;
                                    }

                                    cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;

                                    system("pause");

                                    break;

                                case 2:

                                    archivolec.open("pacientes.txt");

                                    if(!archivolec)
                                    {
                                        cout<<"No se pudo abrir el archivo"<<endl;
                                        system("pause");
                                        break;
                                    }

                                    cout<<"Archivo correctamente abierto!"<<endl;

                                    cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                    cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;

                                    while(archivolec >> id >> nombre >> diagnostico >> pago)
                                    {
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| "<<id<<"  | "<<nombre<<"\t"<<" | "<<diagnostico<<"\t"<<"| "<<pago<<"\t"<<"|"<<endl;
                                    }
                                
                                    cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;

                                    system("pause");
                                    
                                    break;
                            }

                            break;

                        case 3:

                            system("cls");

                            cout<<"+-- Borrar --+"<<endl;

                            cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                            cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                            
                            for(i=0;i<total;i++)
                            {
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| "<<pacientes[i].id<<"  | "<<pacientes[i].nombre<<"\t"<<" | "<<pacientes[i].diagnostico<<"\t"<<"| "<<pacientes[i].pago<<"\t"<<"|"<<endl;
                            }

                            cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;

                            cout<<"Ingresa el id que desees eliminar:";
                            cin>>opcelim;

                            for(i=0;i<contador;i++)
                            {
                                if(pacientes[i].id==opcelim)
                                {
                                    bandera=1;
                                    pos=i;
                                    break;
                                }
                                else
                                {
                                    bandera=0;
                                }
                            }

                            if(bandera==1)
                            {
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| "<<pacientes[pos].id<<"  | "<<pacientes[pos].nombre<<"\t"<<" | "<<pacientes[pos].diagnostico<<"\t"<<"| "<<pacientes[pos].pago<<"\t"<<"|"<<endl;
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                            }
                            else
                            {
                                cout<<"Paciente no encontrado!"<<endl;
                            }

                            cout<<"Estas seguro de querer eliminar este registro?"<<endl;
                            cout<<"1. Si"<<endl;
                            cout<<"2. No"<<endl;
                            cout<<"Ingresa tu opcion:";
                            cin>>opcelim2;

                            if(opcelim2==1)
                            {
                                for(i=opcelim-1;i<contador-1;i++)
                                {
                                    pacientes[i].id=pacientes[i+1].id;
                                    pacientes[i].nombre=pacientes[i+1].nombre;
                                    pacientes[i].diagnostico=pacientes[i+1].diagnostico;
                                    pacientes[i].pago=pacientes[i+1].pago;
                                }

                                total--;
                                contador--;
                                cout<<"Registro eliminado con exito!"<<endl;
                            }
                            else
                            {
                                cout<<"Operacion abortada!"<<endl;
                            }

                            system("pause");

                            break;

                        case 4:

                            system("cls");

                            cout<<"+-- Buscar --+"<<endl;

                            cout<<"Por medio de que quieres buscar?"<<endl;
                            cout<<"1. ID"<<endl;
                            cout<<"2. Nombre"<<endl;
                            cout<<"Ingresa tu eleccion:";
                            cin>>opcbusc;

                            switch(opcbusc)
                            {
                                case 1:

                                    cout<<"Ingresa ID:";
                                    cin>>idbuscbusc;

                                    for(i=0;i<contador;i++)
                                    {
                                        if(pacientes[i].id==idbuscbusc)
                                        {
                                            bandera=1;
                                            pos=i;
                                            break;
                                        }
                                        else
                                        {
                                            bandera=0;
                                        }
                                    }

                                    if(bandera==1)
                                    {
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| "<<pacientes[pos].id<<"  | "<<pacientes[pos].nombre<<"\t"<<" | "<<pacientes[pos].diagnostico<<"\t"<<"| "<<pacientes[pos].pago<<"\t"<<"|"<<endl;
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Paciente no encontrado!"<<endl;
                                    }

                                    system("pause");

                                    break;

                                case 2:

                                    cout<<"Ingresa nombre:";
                                    cin>>nombrebusc;

                                    for(i=0;i<contador;i++)
                                    {
                                        if(pacientes[i].nombre==nombrebusc)
                                        {
                                            bandera=1;
                                            pos=i;
                                            break;
                                        }
                                        else
                                        {
                                            bandera=0;
                                        }
                                    }

                                    if(bandera==1)
                                    {
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                        cout<<"| "<<pacientes[pos].id<<"  | "<<pacientes[pos].nombre<<"\t"<<" | "<<pacientes[pos].diagnostico<<"\t"<<"| "<<pacientes[pos].pago<<"\t"<<"|"<<endl;
                                        cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Paciente no encontrado!"<<endl;
                                    }
                                
                                    break;

                                default:

                                    cout<<"Gracias por ocupar este sistema!! Jsjsjs"<<endl;
                                
                                    break;
                            }

                            system("pause");
                        
                            break;

                        case 5:

                            system("cls");

                            cout<<"+-- Cambios --+"<<endl;

                            cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                            cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                            
                            for(i=0;i<total;i++)
                            {
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| "<<pacientes[i].id<<"  | "<<pacientes[i].nombre<<"\t"<<" | "<<pacientes[i].diagnostico<<"\t"<<"| "<<pacientes[i].pago<<"\t"<<"|"<<endl;
                            }

                            cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;

                            cout<<"Ingresa el ID que desees modificar:";
                            cin>>cambid;

                            for(i=0;i<contador;i++)
                            {
                                if(pacientes[i].id==cambid)
                                {
                                    bandera=1;
                                    pos=i;
                                    break;
                                }
                                else
                                {
                                    bandera=0;
                                }
                            }

                            if(bandera==1)
                            {
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| ID |"<<" Nombre\t"<<" | "<<"Diagnostico\t"<<"|"<<" Pago  "<<"|"<<endl;
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                                cout<<"| "<<pacientes[pos].id<<"  | "<<pacientes[pos].nombre<<"\t"<<" | "<<pacientes[pos].diagnostico<<"\t"<<"| "<<pacientes[pos].pago<<"\t"<<"|"<<endl;
                                cout<<"+++++++++++++++++++++++++++++++++++++++++"<<endl;
                            }
                            else
                            {
                                cout<<"Paciente no encontrado!"<<endl;
                            }
   
                            cout<<"1.Nombre"<<endl;
                            cout<<"2.Diagnostico"<<endl;
                            cout<<"3.Pago"<<endl;
                            cout<<"Que deseas modificiar?"<<endl;
                            cin>>opscamb;

                            switch(opscamb)
                            {
                                case 1:

                                    cout<<"Nuevo nombre:"<<endl;
                                    cin>>nuevNom;

                                    cout<<"Estas seguro de querer modificar este dato?"<<endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl;
                                    cout<<"Ingresa tu opcion:";
                                    cin>>opcelim2;

                                    if(opcelim2==1)
                                    {
                                        pacientes[pos].nombre=nuevNom;
                                        cout<<"Registro modificado con exito!"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Operacion abortada!"<<endl;
                                    }

                                    break;

                                case 2:

                                    cout<<"Nuevo diagnostico:"<<endl;
                                    cin>>nuevDiag;

                                    cout<<"Estas seguro de querer modificar este dato?"<<endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl;
                                    cout<<"Ingresa tu opcion:";
                                    cin>>opcelim2;

                                    if(opcelim2==1)
                                    {
                                        pacientes[pos].diagnostico=nuevDiag;
                                        cout<<"Registro modificado con exito!"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Operacion abortada!"<<endl;
                                    }

                                    break;

                                case 3:

                                    cout<<"Nuevo pago:"<<endl;
                                    cin>>nuevPag;

                                    cout<<"Estas seguro de querer modificar este dato?"<<endl;
                                    cout<<"1. Si"<<endl;
                                    cout<<"2. No"<<endl;
                                    cout<<"Ingresa tu opcion:";
                                    cin>>opcelim2;

                                    if(opcelim2==1)
                                    {
                                        pacientes[pos].pago=nuevPag;
                                        cout<<"Registro modificado con exito!"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Operacion abortada!"<<endl;
                                    }
                                
                                    break;

                                default:

                                    cout<<"Gracias!"<<endl;

                                    break;
                            }
                            
                            break;

                        default:

                            cout<<"Gracias por ocupar el sistema!"<<endl;
                        
                            break;
                    }
                }while(opc!=6);
            }
            else
            {
                cout<<"Contrasena incorrecta!"<<endl;
            } 
        }
        else
        {
            cout<<endl<<"Tamano exedido xd"<<endl;
            cout<<strlen(contr)<<endl;
        }
        
        return 0;
    }