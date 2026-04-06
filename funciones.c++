#include <iostream>
using namespace std;

//Por valor

int incrementarNumero(int numero)
{
    return numero+1;
}

//Por referencia

void incrementarNumero(int *numero)
{
    *numero=*numero+1;
}

int main()
{
    int n = 10;
    int res;
    //res=incrementarNumero(n);
    //cout<<res<<endl;
    incrementarNumero(&n);
    cout<<n<<endl;
    
    return 0;
}