#include <iostream>

using namespace std;

int main()
{
    char arr1[100],arr2[100],arr3[100];
    int i,num,cont1=0,cont2=0,total,cont3=0,j;

    for(i=0;i<5;i++)
    {
        cout<<"Ingresa el primer arreglo:";
        cin>>arr1[i];
        cont1++;
    }

    for(i=0;i<5;i++)
    {
        cout<<"Ingresa el segundo arreglo:";
        cin>>arr2[i];
        cont2++;
    }

    total=cont1+cont2;

    for(i=0,j=0;i<total,j<cont1;i++,j++)
    {
        if(cont3<cont1)
        {
            arr3[i]=arr1[j];
            cont3++;
        }
    }

    for(i=0;i<total;i++)
    {
        if (cont3<total)
        {
            arr3[cont3]=arr2[i];
            cont3++;
        }
        
    }

    cout << "Arreglo 1: ";
    for (i=0;i<cont1;i++)
    {
        cout<<arr1[i];
    }

    cout << endl<<"Arreglo 2: ";
    for (i=0;i<cont2;i++)
    {
        cout<<arr2[i];
    }

    cout << endl<< "Arreglo conjunto: ";
    for (i=0;i<total;i++)
    {
        cout<<arr3[i];
    }
    


    
    return 0;
}