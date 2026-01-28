#include <iostream>

using namespace std;

int main()
{
    int i,j,arr[10],arrv[10];

    for (i=0;i<10;i++)
    {
        cout<<"Ingresa el numero "<<i+1<<":";
        cin>>arr[i];
    }
    cout<<"Volteando arreglo"<<endl;
    for (i=0,j=9;i<10,j>=0;i++,j--)
    {
        arrv[j]=arr[i];
    }

    cout<<"Arreglo original:"<<endl;

    for (i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"Arreglo volteado:"<<endl;

    for (i=0;i<10;i++)
    {
        cout<<arrv[i]<<endl;
    }
    
    return 0;
}