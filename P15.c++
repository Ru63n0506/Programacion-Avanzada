#include <iostream>

using namespace std;

int main()
{
    int i,j,contvoc=0,contcons=0;
    char palabra[10],vocpal[10],conspal[10];
    
    for(i=0;i<10;i++)
    {
        cin>>palabra[i];      
    }

    for(i=0;i<10;i++)
    {
        if(palabra[i]=='a'||palabra[i]=='e'||palabra[i]=='i'||palabra[i]=='o'||palabra[i]=='u')
        {
            vocpal[contvoc]=palabra[i];
            contvoc++;
        }
        else
        {
            conspal[contcons]=palabra[i];
            contcons++;
        }                     
    }

    cout << "Palabra original: ";

    for(i=0;i<10;i++)
    {
        cout<<palabra[i];
    }

    cout <<endl<< "Vocales: ";

    for (i=0;i<contvoc;i++)
    {
        cout<<vocpal[i];
    }

    cout <<endl<< "Consonantes: ";

    for (i=0;i<contcons;i++)
    {
        cout<<conspal[i];
    }
    
    return 0;
}