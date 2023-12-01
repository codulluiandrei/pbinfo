#include <iostream>
using namespace std;

int oglindit(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n=n/10;
    }
    return r;
}

int main()
{
    long long n,pmax=0,smax=0,p=1;
    cin>>n;
    while(p<=n*10)
    {
        if(n/p==oglindit(n/p) && n/p>pmax) 
            pmax=n/p;
        if(n%p==oglindit(n%p) && n%p>smax) 
            smax=n%p;
        p=p*10;
    }
    cout<<pmax<<" "<<smax;
    return 0;
}
