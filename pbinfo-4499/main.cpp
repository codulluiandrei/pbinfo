#include <iostream>
using namespace std;
int main()
{
    int a,b,c,min,h,n;
    cin>>a>>b>>c>>h;
    h=h*100;
    min=a;
    if(b<min)
        min=b;
    if(c<min)
        min=c;
    n=h/min;
    cout<<n;
    return 0;
}