    #include <iostream>
    #include <string.h>
    #include <windows.h>
    #include <conio.h>
    #include <C:\Users\Lorena Reyes\OneDrive\Escritorio\PROGRAMAS\PRUEBA\Programacion-Avanzada\cuadro.h>

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

        int i=0,tam=8,o=0;
        char a,contr[100],contra1[9]="holahola";

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
                cout<<endl<<endl<<"Bienvenido al menu!!"<<endl;
            } 
        }
        else
        {
            cout<<endl<<"Tamano exedido xd"<<endl;
            cout<<strlen(contr)<<endl;
        }

        cout<<endl;

        return 0;
    }