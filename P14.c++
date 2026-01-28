#include <iostream>

using namespace std;

int main()
{
    int arr[10],i,temp;

    for(i=0;i<10;i++)
    {
        cout<<"Ingresa un numero:";
        cin>>arr[i];
    }

    temp=arr[0];

    for(i=0;i<10;i++)
    {
        if (temp<arr[i])
        {
            temp=arr[i];
        }
    }

    cout<<"Numero mayor:"<<temp<<endl;
    
    return 0;
}