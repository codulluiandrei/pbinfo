#include <iostream>
using namespace std;
int main()
{
    int a,b,x,y,ra=0,rb=0;
    cin>>a>>b;
    x=a; y=b;
    while(a>0)
    {
        ra=ra*10+a%10;
        a=a/10;
    }
    while(b>0)
    {
        rb=rb*10+b%10;
        b=b/10;
    }
    if(ra>rb || (ra==rb && x<y)) cout<<x;
    else cout<<y;
    return 0;
}