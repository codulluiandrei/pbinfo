#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long double a,b,c,d;
    int x;
    cin>>a>>b>>c>>d;
    x=(b*c-a*d)/(d-c)*100;
    cout<<x/100<<".";
    if(x<0)
        x*=-1;
    cout<<x/10%10<<x%10;
    return 0;
}