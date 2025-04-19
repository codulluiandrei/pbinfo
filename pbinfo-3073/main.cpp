#include <iostream>
using namespace std;
int main()
{
    int  n,k,m,p,x,y,z,t,nre7,nre8,a,b;
    cin>>n>>k>>m>>p;
    a=nre7=n*k;
    b=nre8=m*p;
    while(a!=b)
        if(a>b)a=a-b;
        else b=b-a;
    t=a;
    y=nre7/t;
    z=nre8/t;
    x=y+z;
    cout<<x<<" "<<y<<" "<<z<<" "<<t;
    return 0;
}