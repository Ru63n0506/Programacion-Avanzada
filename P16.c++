#include <iostream>

using namespace std;

int main()
{
    int arr[10],i,res=1;

    for (i=0;i<10;i++)
    {
        cout<<"Ingresa numero "<<i+1<<":";
        cin>>arr[i];
        res=res*arr[i];
    }

    cout<<"Multiplicacion acumulada:"<<res;
    return 0;    
}