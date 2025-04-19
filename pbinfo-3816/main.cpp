#include <iostream>
using namespace std;
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c && b==d)
        cout<<"Grafice echivalente";
    else if(a==c && b!=d)
        cout<<"Grafice paralele";
    else
    {
        double x=(d-b)/(a-c),y=a*((d-b)/(a-c))+b;
        int X=x*100,Y=y*100;
        if(X<0)
            cout<<"-",X=-X;
        cout<<X/100<<"."<<X/10%10<<X%10<<" ";
        if(Y<0)
            cout<<"-",Y=-Y;
        cout<<Y/100<<"."<<Y/10%10<<Y%10;
    }
    return 0;
}