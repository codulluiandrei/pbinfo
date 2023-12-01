#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long double a,b,c,d,Atriunghi,htriunghi,p;
    cin>>a>>b>>c>>d;
    if(a+b+c>d && b+c+d>a && a+c+d>b && a+b+d>c && d+b>abs(c-a) && d+abs(c-a)>b && b+abs(c-a)>d)
    {
        p=(d+b+abs(c-a))/2;
        Atriunghi=sqrt(p*(p-d)*(p-b)*(p-abs((c-a))));
        htriunghi=(2*Atriunghi)/abs(c-a);
        unsigned long long int A=((a+c)*htriunghi/2)*100;
        cout<<A/100<<"."<<A/10%10<<A%10;
    }
    else
        cout<<"Imposibil";
    return 0;
}