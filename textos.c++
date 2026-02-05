#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int l,res,n1;
    char pal[20],cop[20],cadena[30],cad1[20],cad2[20],cad3[20]="Hola que tal ",cad4[20];
    char pali[20],pali2[20],cad5[20]="HOLA",cad6[20]="hola",nombre[30];
    char cad7[20]="hola como estas",cad8[20],cadprueba[20],entero[30],real[30];
    string palesp,oracion;
    float n2,n3;

    cout << "Digite la palabra:";
    cin >> pal;

    cout<<"Palabra:"<<pal<<endl;
    cout<<"Longitud de la palabra:"<<strlen(pal)<<endl;

    for(int i=0;i<strlen(pal);i++)
    {
        cout<<pal[i]<<endl;
    }

    cout << "Palabra con espacios:";
    cin.ignore();
    getline(cin,palesp);
    cout<<palesp;

    cout<<endl<<"Ingresa una oracion:";
    getline(cin,oracion);
    cout<<oracion;

    strcpy(cop,pal);
    
    cout<<endl<<"Palabra copiada:"<<cop;

    cout<<endl<<"Digita una cadena:";
    cin.getline(cadena,30,'\n');
    l=strlen(cadena);

    if(l>10)
    {
        cout<<cadena<<endl;
    }
    else
    {
        cout<<l;
    }

    cout<<endl<<"Palabra copiada:"<<cop<<endl;

    cout<<"Digita una cadena:";
    cin.getline(cad1,20,'\n');
    cout<<"Digita otra cadena:";
    cin.getline(cad2,20,'\n');
    cout<<endl;

    if(strcmp(cad1,cad2)==0)
    {
        cout<<"Ambas cadenas son iguales"<<endl;
    }
    else if(strcmp(cad1,cad2)<0)
    {
        cout<<"La palabra "<<cad1<<" va antes que "<<cad2<<endl;
    }
    else if(strcmp(cad1,cad2))
    {
        cout<<"La palabra "<<cad1<<" va despues que "<<cad2<<endl;
    }

    cout<<"Digite su nombre: ";
    cin.getline(cad4,20,'\n');
    strcat(cad3,cad4);
    cout<<cad3<<endl;

    cout<<"Digite una palabra: ";
    cin.getline(pali,20,'\n');
    if(strcmp(pali,strrev(pali))==0)
    {
        cout<<"La palabra es palindroma"<<endl;
    }
    else
    {
        cout<<"La palabra no es palindroma"<<endl;
    }

    strupr(cad5);
    strupr(cad6);

    if(strcmp(cad5,cad6)==0)
    {
        cout<<"Ambas cadenas son iguales"<<endl;
    }
    else if(strcmp(cad5,cad6)<0)
    {
        cout<<"No son iguales"<<endl;
    }

    cout<<"Digite su nombre en mayusculas: ";
    cin.getline(nombre,30,'\n');
    if(nombre[0]=='A')
    {
        strlwr(nombre);
    }
    cout<<nombre<<endl;

    cout<<"Proporciona la segunda cadena:";
    cin.getline(cad8,20,'\n');

    res=strcmp(cad7,cad8);
    cout<<res<<endl;

    if (res==0)
    {
        cout<<"Cadenas iguales"<<endl;
    }

    strcat(cad7,cad8);

    cout<<cad7<<endl;

    cout<<"Ingresa una palabra:"<<endl;
    cin.getline(cadprueba,20,'\n');

    cout<<"INVERSA QUEDA:"<<endl;
    strrev(cadprueba);
    cout<<cadprueba<<endl;

    cout<<"EN MAYUSCULAS QUEDA:"<<endl;
    strupr(cadprueba);
    cout<<cadprueba<<endl;

    cout<<"EN MINUSCULAS QUEDA:"<<endl;
    strlwr(cadprueba);
    cout<<cadprueba<<endl;

    cout<<"Digite un numero entero:";
    cin.getline(entero,30,'\n');
    cout<<"Digite un numero real:";
    cin.getline(real,30,'\n');

    n1=atoi(entero);
    n2=atof(real);
    n3=n1+n2;

    cout<<n3<<endl;

    return 0;
}