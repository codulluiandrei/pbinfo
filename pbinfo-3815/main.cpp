#include <iostream>
using namespace std;
long long v[1000001];
int main()
{
    long long s=0,n,maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i],s+=v[i],maxx=max(maxx,v[i]);
    if(s-maxx>maxx)
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}