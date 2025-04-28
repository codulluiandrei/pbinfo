#include <iostream>
using namespace std;
int echilibrat(int n)
{
    int di=0,dp=0;
    for(int d=1;d*d<=n;d++)
        if(n%d==0)
        {
            if(d%2==0) dp++;
            else di++;
            if(d*d!=n)
                if(n/d%2==0) dp++;
                else di++;
        }
    return di==dp;
}
int main()
{
    int a,b;
    long long s=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
        if(echilibrat(i)) s=s+i;
    cout<<s;
    return 0;
}