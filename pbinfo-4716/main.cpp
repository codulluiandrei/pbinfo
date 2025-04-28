#include <iostream>
using namespace std;
int main()
{
    unsigned long long n, nou, p;
    cin>>n;
    nou=0,p=1;
    while(n>=10)
    {
        p*=10;
        n/=10;
    }
    if(n==9) n=20;
    else n++;
    cout<<n*p;
    return 0;
}