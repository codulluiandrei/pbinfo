#include <iostream>
using namespace std;
int main()
{
    int a,b,p=1;
    cin>>a>>b;
    for(int i=1;i<=b;i++)
    {
        cout<<p<<" ";
        p=p*a;
    }
    return 0;
}