#include <iostream>

using namespace std;

int main()
{
    int arr[5],i,aux,pos;

    for(i=0;i<5;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<5;i++)
    {
        pos=i;
        aux=arr[i];

        while(pos>0 && arr[pos-1]>aux)
        {
            arr[pos]=arr[pos-1];
            pos--;
        }

        arr[pos]=aux;

    }

    for(i=0;i<5;i++)
    {
        cout<<arr[i];
    }
    
    return 0;
}