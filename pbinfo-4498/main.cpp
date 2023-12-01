#include <iostream>
using namespace std;

int main()
{
    int n,m,a,b,c,x,y,z,maxs,maxz,maxu;
    cin>>n>>m;
    a=n/100;
    b=n/10%10;
    c=n%10;
    x=m/100;
    y=m/10%10;
    z=m%10;
    if(a>x)
        maxs=a*10+x;
    else
        maxs=x*10+a;
    if(b>y)
        maxz=b*10+y;
    else
        maxz=y*10+b;
    if(c>z)
        maxu=c*10+z;
    else
        maxu=z*10+c;
    cout<<maxs<<" "<<maxz<<" "<<maxu;
    return 0;
}
