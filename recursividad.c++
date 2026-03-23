#include <iostream>

using namespace std;

int factorial(int n)
{
    if(n==0) //Caso base
    {
        n=1;
    }
    else
    {
        n=n*factorial(n-1); //Caso contrario
    }

    return n;
}

int main()
{
    int r=factorial(3);
    
    cout<<r<<endl;
    
    return 0;
}