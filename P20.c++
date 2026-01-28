#include <iostream>

using namespace std;

int main()
{
    int matr1[4][4],matr2[4][4],matr3[4][4],i,j;

    cout<<"Ingresa los valores de la primera matriz:"<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>matr1[i][j];
        }
    }

    /*
    cout<<"Matriz uno"<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<matr1[i][j];
        }
        cout<<endl;
    }
    */

    cout<<"Ingresa los valores de la segunda matriz:"<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>matr2[i][j];
        }
    }

    /*
    cout<<"Matriz dos"<<endl;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<matr2[i][j];
        }
        cout<<endl;
    }
    */

    /*
    cout<<"Sumando matrices"<<endl;
    */

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            matr3[i][j]=matr1[i][j]+matr2[i][j];
        }
    }

    /*
    cout << "Ya quedo la suma, mostrando matriz sumada"<<endl;
    */

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<matr3[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}