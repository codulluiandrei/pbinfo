#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,d,A,s;
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/2;
    A=sqrt((s-a)*(s-b)*(s-c)*(s-d));
    int Arie=A*1000;
    cout<<Arie/1000<<"."<<Arie/100%10<<Arie/10%10<<Arie%10;
    return 0;
}