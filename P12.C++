#include <iostream>

using namespace std;

int main()
{
    int i,n,sum=0;

    cin>>n;
    for (i=0;i<=n;i++)
    {
        if (i%2==1)
        {
            sum=sum+i;
        }
        else
        {
            sum=sum-i;
        }
    }
    cout<<sum;   
    return 0;
}