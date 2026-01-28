#include <iostream>

using namespace std;

int main()
{
    int matr[4][4],i,j,suma=0;
    float prom;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cin>>matr[i][j];
            suma=suma+matr[i][j];
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout<<matr[i][j];
        }
        cout<<endl;
    }

    prom=suma/16;
    cout<<"Promedio: "<<prom;
    
    return 0;
}