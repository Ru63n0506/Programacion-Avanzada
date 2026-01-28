#include <iostream>

using namespace std;

int main()
{
    int i,arrnum1[5],arrmult[5];

    for (i=0;i<5;i++)
    {
        cin>>arrnum1[i];
        arrmult[i]=arrnum1[i]*2;
    }

    cout << "Arreglo original:";

    for(i=0;i<5;i++)
    {
        cout<<arrnum1[i]<<",";
    }

    cout <<endl<<"Arreglo duplicado:";

    for(i=0;i<5;i++)
    {
        cout<<arrmult[i]<<",";
    }
    
    return 0;
}