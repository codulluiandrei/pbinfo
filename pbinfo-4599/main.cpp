#include <iostream>
using namespace std;
long long sumdiv(int n)
{
    long long s=0;
    for(int d=1;d*d<=n;d++)
        if(n%d==0)
        {
            s=s+d;
            if(d*d!=n) s=s+n/d;
        }
    return s;
}
int sumfact(int n)
{
    int s=0,d=2;
    while(n>1)
    {
        if(n%d==0)
        {
            s=s+d;
            while(n%d==0) n=n/d;
        }
        else d++;
        if(d*d>n) d=n;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<sumdiv(n)-sumfact(n);
    return 0;
}